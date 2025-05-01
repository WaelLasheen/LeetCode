class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r=board.size() ,c=board[0].size();
        vector<vector<char>> res(r,vector<char>(c,'X'));
        for(int it=0;it<c;it++){
            if(board[0][it]=='O'){
                connect(board,res,0,it);
            }

            if(board[r-1][it]=='O'){
                connect(board,res,r-1,it);
            }
        }

        for(int it=0;it<r;it++){
            if(board[it][0]=='O'){
                connect(board,res,it,0);
            }

            if(board[it][c-1]=='O'){
                connect(board,res,it,c-1);
            }
        }

        board=res;
    }

private:
    void connect(vector<vector<char>>& board ,vector<vector<char>>& res ,int i ,int j){
        vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        int r=board.size() ,c=board[0].size();
        board[i][j]='X';
        res[i][j]='O';
        queue<pair<int,int>> q;
        q.push({i,j});
        while(q.size()){
            i= q.front().first;
            j= q.front().second;
            q.pop();
            for(auto d:dir){
                if(!outOfRange(r,c,i+d[0],j+d[1]) && board[i+d[0]][j+d[1]] !='X'){
                    board[i+d[0]][j+d[1]] ='X';
                    res[i+d[0]][j+d[1]]='O';
                    q.push({i+d[0] ,j+d[1]});
                }
            }
        }
    }

    bool outOfRange(int r ,int c ,int i ,int j){
        return i<0 || j<0 || i==r || j==c;
    }
};