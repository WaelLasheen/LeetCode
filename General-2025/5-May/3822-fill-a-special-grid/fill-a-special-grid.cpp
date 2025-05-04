class Solution {
public:
    vector<vector<int>> specialGrid(int n) {
        int s=1<<n;
        vector<vector<int>> grid(s,vector<int>(s,0));
        solve(grid,0,0,s,0);
        return grid;
    }

    void solve(vector<vector<int>>& grid ,int i ,int j ,int s ,int val){
        if(s==1){
            grid[i][j]=val;
            return;
        }

        int half = s>>1;
        int add = half * half;

        solve(grid ,i ,j+half ,half ,val);
        solve(grid ,i+half ,j+half ,half ,add + val);
        solve(grid ,i+half ,j ,half ,2*add + val);
        solve(grid ,i ,j ,half ,3*add + val);
        
    }
};