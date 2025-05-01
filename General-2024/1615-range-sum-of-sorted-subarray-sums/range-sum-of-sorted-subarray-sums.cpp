class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int mod = 1e9 + 7;
        vector<int> arr;

        // Generate all subarray sums
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                arr.push_back(sum);
            }
        }

        // Sort the array of subarray sums
        sort(arr.begin(), arr.end());

        // Compute the sum from index left to right (1-based indexing)
        int result = 0;
        for (int i = left - 1; i < right; i++) {
            result = (result + arr[i]) % mod;
        }

        return result;
    }
};
