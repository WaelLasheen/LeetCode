class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(forget+1 ,0);
        dp[1]=1;
        const int mod = 1e9+7;

        for(int day=2;day<=n;day++){
            int know=0;
            for(int i=forget-1;i>0;i--){
                dp[i+1] = dp[i];
                if(i+1 > delay){
                    know = (know + dp[i+1])%mod;
                }
            }
            dp[1]= know;
        }

        int res=0;
        for(int i=1;i<dp.size();i++){
            res = (res + dp[i])%mod;
        }

        return res;
    }
};