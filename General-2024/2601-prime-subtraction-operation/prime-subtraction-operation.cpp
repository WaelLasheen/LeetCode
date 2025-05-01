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
                int it=0;
                while(it < prim.size() && prim[it] < nums[i] && nums[i] - prim[it] >= nums[i+1]){
                    it++;
                }

                if(!(it < prim.size() && prim[it] < nums[i])){
                    return false;
                }

                nums[i] -= prim[it];
            }
        }

        return true;
    }
};