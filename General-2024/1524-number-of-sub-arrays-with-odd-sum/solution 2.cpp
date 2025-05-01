class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        vector<vector<int>> dp(2,vector<int>(arr.size()+1,0));
        //   1 3 5
        // 0 1 1 0       even
        // 1 2 1 1       odd
        // if curr is even -> pass value as it in i+1 and for oven ++
        // if curr is odd -> pass value in reverse -even to odd and odd to even- i+1 and for odd ++

        int res=0 ,mod =1e9+7;
        for(int i=arr.size()-1;i>-1;i--){
            if(arr[i] &1){
                dp[1][i] = (dp[0][i+1]+1)%mod;
                dp[0][i] = (dp[1][i+1])%mod;
            } else{
                dp[1][i] = (dp[1][i+1])%mod;
                dp[0][i] = (dp[0][i+1]+1)%mod;
            }
            
            res = (res + dp[1][i])%mod;
        }

        return res;
    }
};