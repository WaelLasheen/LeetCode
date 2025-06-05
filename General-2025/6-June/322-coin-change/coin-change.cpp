class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,1e5); 
        dp[0]=0;

        for(int i=1;i<=amount;i++){
            for(int c:coins){
                if(c<= i){
                    dp[i]=min(dp[i],dp[i-c]+1);
                }
            }
        }

        return dp.back()==1e5? -1: dp.back();
    }
};