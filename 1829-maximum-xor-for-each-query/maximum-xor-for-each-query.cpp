class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int mx = (1<<maximumBit)-1;
        for(int i=1;i<nums.size();i++){
            nums[i] ^=nums[i-1];
        }
        for(int i=nums.size()-1;i>-1;i--){
            nums[i] ^= mx;
        }
        reverse(nums.begin(),nums.end());

        return nums;
    }
};