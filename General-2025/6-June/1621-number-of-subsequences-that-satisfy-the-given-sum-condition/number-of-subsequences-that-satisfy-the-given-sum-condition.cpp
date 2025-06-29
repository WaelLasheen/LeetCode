#define ll long long
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int res=0;

        // O(n*log(n))
        for(int i=0;i<nums.size();i++){     // O(N)
            int mn = nums[i];
            int mxi = upper_bound(nums.begin(),nums.end(),target - mn)- nums.begin() -1;    // O(log(N))

            if(mxi>=i){
                res = (res + fastPower(2,mxi-i))% MOD;
            }
        }

        return res;
    }

private:
    const ll MOD = 1e9+7;

    int fastPower(ll base, ll e) {
        ll res = 1;
        while (e>0) {
            if (e & 1) {
                res = (res%MOD * base%MOD) % MOD;
            }
            base = (base% MOD * base% MOD) % MOD;
            e >>= 1;
        }
        return res;
    }

};
