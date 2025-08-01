class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]){ 
            return 0;
        }

        int m =obstacleGrid.size() ,n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            if(obstacleGrid[0][i]){
                break;
            }
            dp[0][i] =1;
        }

        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0]){
                break;
            }
            dp[i][0] =1;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(!obstacleGrid[i][j]){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};