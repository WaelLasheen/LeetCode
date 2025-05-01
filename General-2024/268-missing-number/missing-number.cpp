class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expected_Sum = n * (n + 1) / 2;
        int actual_Sum = accumulate(nums.begin(), nums.end(), 0);
        return expected_Sum - actual_Sum;
    }
};
