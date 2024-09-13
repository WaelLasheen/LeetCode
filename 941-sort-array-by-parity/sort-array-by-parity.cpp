class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int eve=0;
        for(int i=0;i<nums.size();i++){
            if(!(nums[i]&1)){
                swap(nums[eve] ,nums[i]);
                eve++;
            }
        }

        return nums;
    }
};