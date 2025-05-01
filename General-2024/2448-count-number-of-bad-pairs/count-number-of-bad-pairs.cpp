#define ll long long

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // count good pair: j-i == nums[j]-nums[i]
        //  |--> i == nums[i]+shift
        //  |--> same shift is good pair

        unordered_map<long,int> mp;
        ll s = nums.size();
        for(long i=0;i<s;i++){
            mp[nums[i]-i]++;
        }
        
        ll gp=0;    // good pairs
        for(auto i:mp){
            ll n=i.second;
            gp += (n-1)*n/2;
        }

        return s*(s-1)/2 - gp;
    }
};