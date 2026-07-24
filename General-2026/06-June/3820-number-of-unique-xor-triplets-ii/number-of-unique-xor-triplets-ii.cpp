class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> res,xor2;
        int s=nums.size();
        for(int i=0;i<s;i++){
            for(int j=i;j<s;j++){
                xor2.insert(nums[i]^nums[j]);
            }
        }
        for(int i=0;i<s;i++){
            for(int j:xor2){
                res.insert(nums[i]^j);
            }
        }

        return res.size();
    }
};