class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp = {{1}};
        for(int i=1;i<numRows;i++){
            vector<int> sub(i+1,1);
            for(int j=1;j<i;j++){
                sub[j] = dp[i-1][j]+dp[i-1][j-1];
            }
            dp.push_back(sub);
        }

        return dp;
    }
};