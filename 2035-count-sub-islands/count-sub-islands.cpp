class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int r=grid1.size() ,c=grid1[0].size();
        int res=0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid2[i][j]){
                    queue<pair<int,int>>next;
                    next.push({i,j});
                    bool island=true;
                    grid2[i][j]=0;
                    while(next.size()){
                        int row = next.front().first , col=next.front().second;
                        next.pop();

                        if(!grid1[row][col]){
                            island=false;
                        }

                        if(row-1 > -1 && grid2[row-1][col]) {next.push({row-1 ,col}); grid2[row-1][col]=0;}
                        if(row+1 <  r && grid2[row+1][col]) {next.push({row+1 ,col}); grid2[row+1][col]=0;}
                        if(col-1 > -1 && grid2[row][col-1]) {next.push({row ,col-1}); grid2[row][col-1]=0;}
                        if(col+1 <  c && grid2[row][col+1]) {next.push({row ,col+1}); grid2[row][col+1]=0;}
                    }

                    if(island){
                        res++;
                    }
                }
            }
        }

        return res;
    }
};