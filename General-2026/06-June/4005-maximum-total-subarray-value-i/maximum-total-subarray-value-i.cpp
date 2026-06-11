class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mx= nums[0] ,mn= nums[0];
        for(int i:nums){
            mx=max(mx,i);
            mn=min(mn,i);
        }

        return (mx-mn)*1LL * k;
    }
};