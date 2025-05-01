#define l long
class Solution {
public:
    int solve(vector<vector<int>>& arr ,int i ,int j ,vector<vector<l>>& dp){
        if(i==arr.size() || j==arr[i].size()){
            return 0;
        }

        if(dp[i][j] != INT_MIN){
            return dp[i][j];
        }

        return dp[i][j] = arr[i][j] + min(solve(arr,i+1,j,dp) ,solve(arr,i+1,j+1,dp));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<l>> dp(triangle.size());
        for(int i=0;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                dp[i].push_back(INT_MIN);
            }
        }

        return solve(triangle,0,0,dp);
    }
};