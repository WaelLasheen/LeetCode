class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        vector<vector<int>>arr(row-2,vector<int>(col-2));
        int it=1;
        for(int i=row-1;i>-1;i--){
            for(int j=col-1;j>1;j--){
                grid[i][j]=max({grid[i][j] ,grid[i][j-1] ,grid[i][j-2]});
                if(it>2){
                    arr[i][j-2]=max({grid[i][j] ,grid[i+1][j] ,grid[i+2][j]});
                }
            }
            it++;
        }
        
        return arr;
    }
};