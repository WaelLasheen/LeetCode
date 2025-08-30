class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // chick rows && colum
        for(int i=0;i<9;i++){
            map<char,int> r,c;
            for(int j=0;j<9;j++){
                // skip empty
                if(board[i][j]!='.'){
                    // row
                    r[board[i][j]]++;
                }
                if(board[j][i]!='.'){
                    // colum
                    c[board[j][i]]++;
                }
                if(c[board[j][i]] >1 || r[board[i][j]] >1) return false;
            }
        }
        // small grid
        for(int i=0;i<9;i+=3){
        for(int z=0;z<9;z+=3){
            map<char,int> g;
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    // skip empty
                    if(board[i+j][z+k]!='.'){
                        g[board[i+j][z+k]]++;
                    }
                    if(g[board[i+j][z+k]] >1) return false;
                }
            }
        }}
        
        return true;
    }
};