#define l long

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        l sum= accumulate(nums.begin(), nums.end(), 0L);
        l rem= sum%p;
        if(!rem) return 0;
        sum=0;
        map<l,int> pref;
        pref[0] = -1;
        l len=LONG_MAX;
        for(int i=0;i<nums.size();i++) {
            sum= (sum+l(nums[i]))%p;
            l tar=(p+sum-rem)%p;
            if(pref.count(tar)) {
                len= min(len, l(i)-pref[tar]);
            }
            
            pref[sum] = i;
        }

        return len==LONG_MAX || len==nums.size() ? -1 : len;
    }
};