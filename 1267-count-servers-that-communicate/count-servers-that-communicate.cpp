class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int res=0;
        int m=grid.size() ,n=grid[0].size();
        vector<int> rows(m,0) ,cols(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rows[i] +=grid[i][j];
                cols[j] +=grid[i][j];
                res +=grid[i][j];
            }
        }

        // we will subtract the servers that has no communication
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] && rows[i]==1 && cols[j]==1){
                    res--;
                }
            }
        }

        return res;
    }
};