class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r=board.size() ,c=board[0].size();
        vector<vector<bool>> v(r,vector<bool>(c,false));
        vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){  
                if(v[i][j] || board[i][j] =='X') continue;

                int row=i ,col=j;
                bool change= true;
                v[i][j]=true;
                queue<pair<int,int>> q ,memory;
                q.push({row,col});
                memory.push({row,col});
                while(q.size()){
                    row= q.front().first;
                    col= q.front().second;
                    q.pop();
                    for(auto d:dir){
                        if(!outOfRange(r,c,row+d[0],col+d[1]) && board[row+d[0]][col+d[1]]=='O' && !v[row+d[0]][col+d[1]]){
                            v[row+d[0]][col+d[1]] =true;
                            q.push({row+d[0] ,col+d[1]});
                            if(change) memory.push({row+d[0] ,col+d[1]});
                        }
                    }

                    if(change && atEdge(r,c,row,col)){
                        change=false;
                    }
                }

                while(change && memory.size()){
                    int a= memory.front().first;
                    int b= memory.front().second;
                    board[a][b]='X';
                    memory.pop();
                }
            }
        }
    }

private:
    bool outOfRange(int r ,int c ,int i ,int j){
        return i<0 || j<0 || i==r || j==c;
    }

    bool atEdge(int r ,int c ,int i ,int j){
        return !i || !j || i==r-1 || j==c-1;
    }
};