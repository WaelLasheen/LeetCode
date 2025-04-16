#define ll long long

class Solution {
public:
    ll countGood(vector<int>& nums, int k) {
        ll res = 0;
        int l = 0, cnt = 0;
        unordered_map<int, int> mp;
        
        for(int r = 0; r < nums.size(); r++) {
            cnt -= (ll)mp[nums[r]] * (mp[nums[r]]-1) / 2;
            cnt += (ll)++mp[nums[r]] * (mp[nums[r]]-1) / 2;
            
            while(cnt >= k) {
                res += nums.size() - r;
                cnt -= (ll)mp[nums[l]] * (mp[nums[l]]-1) / 2;
                cnt += (ll)--mp[nums[l]] * (mp[nums[l]]-1) / 2;
                l++;
            }
        }
        return res;
    }
};