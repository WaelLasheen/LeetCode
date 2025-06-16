class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mn ,mx ,res=-1;
        mn=mx=nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i] < mn){
                mn=mx=nums[i];
            }
            if(nums[i] > mx){
                mx=nums[i];
                res= max(res, mx-mn);
            }
        }

        return res;
    }
};