class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp = {{1},{1,1}};
        if(rowIndex <2) return dp[rowIndex];
        for(int i=2;i<=rowIndex;i++){
            vector<int> sub(i+1,1);
            for(int j=1;j<i;j++){
                sub[j] = dp[i-1][j]+dp[i-1][j-1];
            }
            dp.push_back(sub);
        }

        return dp[rowIndex];
    }
};