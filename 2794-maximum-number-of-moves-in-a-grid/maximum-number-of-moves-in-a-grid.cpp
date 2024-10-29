class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int r=grid.size() ,c=grid[0].size();
        vector<vector<int>> dp(r,vector<int>(c,0));
        int res=0;
        for(int j=c-2;j>=0;j--){
            for(int i=r-1;i>=0;i--){
                if(i && grid[i][j]<grid[i-1][j+1]){
                    dp[i][j]=max(dp[i][j],dp[i-1][j+1]+1);
                }
                if(j+1<c && grid[i][j]<grid[i][j+1]){
                    dp[i][j]=max(dp[i][j],dp[i][j+1]+1);
                }
                if(i+1<r && grid[i][j]<grid[i+1][j+1]){
                    dp[i][j]=max(dp[i][j],dp[i+1][j+1]+1);
                }

                if(!j){
                    res=max(res,dp[i][j]);
                }
            }
        }

        return res;
    }
};
