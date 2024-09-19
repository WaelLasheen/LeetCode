class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=nums.size()-1;
        return nums[l]*nums[l-1] - nums[0]*nums[1];
    }
};