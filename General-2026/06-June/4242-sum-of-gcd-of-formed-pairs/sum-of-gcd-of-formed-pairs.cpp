#define ll long long
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx= nums[0] ,len =nums.size();
        vector<int> prefGcd(len,0);
        for(int i=0 ;i<len;i++){
            mx = max(mx,nums[i]);
            prefGcd[i] = __gcd(mx,nums[i]);
        }
        sort(prefGcd.begin(),prefGcd.end());
        
        ll res=0;
        for(int i=0;i<len/2;i++){
            res += __gcd(prefGcd[i] ,prefGcd[len-i-1]);
        }

        return res;
    }
};