class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // g:guard
        // w:wall
        // t:guarded
        // f:not guarded
        vector<vector<char>> grid(m,vector<char>(n,'f'));
        for(vector<int>& i:walls){
            grid[i[0]][i[1]] = 'w';
        }
        for(vector<int>& i:guards){
            grid[i[0]][i[1]] = 'g';
        }

        for(vector<int>& i:guards){
            // move right
            for(int r=i[1]+1;r<n;r++){
                if(grid[i[0]][r] =='w' || grid[i[0]][r] =='g'){
                    break;
                }
                grid[i[0]][r] ='t';
            }
            // move left
            for(int l=i[1]-1;l>=0;l--){
                if(grid[i[0]][l] =='w' || grid[i[0]][l] =='g'){
                    break;
                }
                grid[i[0]][l] ='t';
            }
            // move down
            for(int d=i[0]+1;d<m;d++){
                if(grid[d][i[1]] =='w' || grid[d][i[1]] =='g'){
                    break;
                }
                grid[d][i[1]] ='t';
            }
            // move up
            for(int u=i[0]-1;u>=0;u--){
                if(grid[u][i[1]] =='w' || grid[u][i[1]] =='g'){
                    break;
                }
                grid[u][i[1]] ='t';
            }
        }

        int res=0;
        for(vector<char> i:grid){
            for(char j:i){
                if(j=='f'){
                    res++;
                }
            }
        }

        return res;
    }
};