#define ll long long
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        ll k = 1LL * k1 + k2;
        
        vector<ll> count(1e5+5, 0);
        ll max_diff = 0;
        
        for (int i = 0; i < n; i++) {
            ll diff = abs(nums1[i] - nums2[i]);
            count[diff]++;
            max_diff = max(max_diff, diff);
        }
        
        for (ll i = max_diff; i > 0 && k > 0; i--) {
            if (count[i] == 0) continue;
            
            ll needed = count[i];
            
            if (k >= needed) {
                k -= needed;
                count[i - 1] += count[i];
                count[i] = 0;
            } else {
                count[i] -= k;
                count[i - 1] += k;
                k = 0;
            }
        }
        
        
        ll res = 0;
        for (ll i = 1; i <= max_diff; i++) {
            res += count[i] * i * i;
        }
        
        return res;
    }
};