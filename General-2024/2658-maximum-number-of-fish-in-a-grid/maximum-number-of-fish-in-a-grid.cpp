class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    res = max(res,bfs(grid,i,j));
                }
            }
        }

        return res;
    }

private:
    int bfs(vector<vector<int>>& grid ,int i,int j){
        int res=0;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(q.size()){
            int k=q.size();
            while(k--){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                res += grid[r][c];
                grid[r][c]=0;   // assign it as visited

                if(r-1>-1 && grid[r-1][c]){
                    q.push({r-1,c});
                }
                if(r+1<grid.size() && grid[r+1][c]){
                    q.push({r+1,c});
                }
                if(c-1>-1 && grid[r][c-1]){
                    q.push({r,c-1});
                }
                if(c+1<grid[0].size() && grid[r][c+1]){
                    q.push({r,c+1});
                }
            }
        }

        return res;
    }
};