#define ll long long

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        ll res=0 ,sum=0;
        // we will use variable sliding window, but with constrain on its size
        int l=0 ,r=0;
        while(r<nums.size()){
            if(mp[nums[r]]){
                while(l<=r && mp[nums[r]]){
                    mp[nums[l]]--;
                    sum -= nums[l];
                    l++;
                }
            }

            mp[nums[r]]++;
            sum += nums[r];

            if(r-l+1 ==k){
                res =max(res,sum);
                mp[nums[l]]--;
                sum -= nums[l];
                l++;
            }

            r++;
        }

        return res;
    }
};