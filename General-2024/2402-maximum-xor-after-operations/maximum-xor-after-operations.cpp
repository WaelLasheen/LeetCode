class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int s = nums.size();
        for(int i=1;i<s;i++){
            nums[i] |= nums[i-1];
        }
        return nums[s-1];
    }
};