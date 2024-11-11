class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<bool> n(1000,true);
        vector<int> prim;
        for(int i=2;i<1000;i++){
            if(n[i]){
                prim.push_back(i);
                for(int j=i*i;j<1000;j+=i){
                    n[j]=false;
                }
            }
        }

        for(int i=nums.size()-2;i>-1;i--){
            if(nums[i] >= nums[i+1]){
                // remove 1 and use upper bound or add 1 and use lower bound
                int diff = nums[i] - nums[i+1];
                auto it = upper_bound(prim.begin(),prim.end(),diff);
                if(it == prim.end()) return false;
                nums[i] -= *it;
                if(nums[i] <= 0) return false;
            }
        }

        return true;
    }
};