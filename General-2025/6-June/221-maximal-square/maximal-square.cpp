class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m= matrix.size() ,n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        int mx=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    dp[i][j]=1;
                    if(!i || !j){
                        dp[i][j]=1;
                    }
                    else if(dp[i-1][j] && dp[i][j-1] && dp[i-1][j-1]){
                        int x = min({dp[i-1][j] ,dp[i][j-1] ,dp[i-1][j-1]});
                        x = sqrt(x)+1;
                        dp[i][j] = x*x;
                    }

                    mx=max(mx,dp[i][j]);
                }
            }
        }

        return mx;
    }
};

// [
//     ["1","1","1","1","0"],
//     ["1","1","1","1","0"],
//     ["1","1","1","1","1"],
//     ["1","1","1","1","1"],
//     ["0","0","1","1","1"]
// ]