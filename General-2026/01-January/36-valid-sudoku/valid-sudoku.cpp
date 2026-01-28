class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> frr(9,vector<int>(9,0)) ,frc(9,vector<int>(9,0));
        vector<vector<vector<int>>> frs(3,vector<vector<int>>(3,vector<int>(9,0)));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] !='.'){
                    int r = ++frr[i][board[i][j]-'1'];
                    int c = ++frc[j][board[i][j]-'1'];
                    int s = ++frs[i/3][j/3][board[i][j]-'1'];
                    
                    if(r>1 || c>1 || s>1){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};