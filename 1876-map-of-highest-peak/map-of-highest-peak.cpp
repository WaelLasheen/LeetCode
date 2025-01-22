class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m= isWater.size() ,n=isWater[0].size();
        vector<vector<int>> res(m,vector<int>(n,-1));
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]){
                    res[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(q.size()){
            int k=q.size();
            while(k--){
                int r=q.front().first ,c=q.front().second;
                q.pop();
                if(isValid(res,r-1,c)){
                    q.push({r-1,c});
                    res[r-1][c] = res[r][c]+1;
                }
                if(isValid(res,r+1,c)){
                    q.push({r+1,c});
                    res[r+1][c] = res[r][c]+1;
                }
                if(isValid(res,r,c-1)){
                    q.push({r,c-1});
                    res[r][c-1] = res[r][c]+1;
                }
                if(isValid(res,r,c+1)){
                    q.push({r,c+1});
                    res[r][c+1] = res[r][c]+1;
                }
            }
        }

        return res;
    }

    bool isValid(vector<vector<int>>& grid,int r ,int c){
        return r>-1 && c>-1 && r<grid.size() && c<grid[0].size() && grid[r][c]==-1;
    }
};