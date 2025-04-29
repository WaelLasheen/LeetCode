#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int s=nums.size();
        int mx= *max_element(nums.begin(),nums.end());
        ll res=0;
        int l=0 ,r=0;
        unordered_map<int,int>mp;
        while(r<s){
            mp[nums[r++]]++;
            while(mp[mx]>=k){
                res += s-r+1;
                mp[nums[l++]]--;
            }
        }
        
        return res;
    }
};