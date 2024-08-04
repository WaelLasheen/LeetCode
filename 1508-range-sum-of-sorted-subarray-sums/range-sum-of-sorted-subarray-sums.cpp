class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int mod = 1e9+7;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum +=nums[j];
                arr.push_back(sum);
            }
        }
        sort(arr.begin(),arr.end());
        int sum =0;
        while(left <= right){
            sum = (sum%mod + arr[left-1]%mod)%mod;
            left++;
        }

        return sum;
    }
};