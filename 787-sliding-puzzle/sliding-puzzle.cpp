class Solution {
public:
    struct BoardState {
        std::vector<std::vector<int>> board;
        int x;
        int y; 
        int level; 

        BoardState(const std::vector<std::vector<int>>& initBoard, int zeroX, int zeroY, int bfsLevel): board(initBoard), x(zeroX), y(zeroY), level(bfsLevel) {}
    };

    int slidingPuzzle(vector<vector<int>>& board) {
        int x=0,y=0;
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                if(!board[i][j]){
                    x=i;
                    y=j;
                    break;
                }
            }
        }

        BoardState state(board, x, y, 0);
        vector<vector<int>> end = {{1,2,3},{4,5,0}};
        queue<BoardState> bfs;
        bfs.push(state);
        set<string> v;
        v.insert(boardToString(board));

        while(bfs.size()){
            BoardState curr = bfs.front();
            bfs.pop();

            if(curr.board==end){
                return curr.level;
            }

            // you can use loop to make code shorter, but I use if to each case to make it easy to understoud

            // go up
            if(curr.x !=0){
                vector<vector<int>> arr = curr.board;
                swap(arr[curr.x][curr.y] ,arr[curr.x-1][curr.y]);
                if(!(v.count(boardToString(arr)))){
                    BoardState next(arr, curr.x-1, curr.y, curr.level+1);
                    bfs.push(next);
                    v.insert(boardToString(arr));
                }
            }
            // go left
            if(curr.y !=0){
                vector<vector<int>> arr = curr.board;
                swap(arr[curr.x][curr.y] ,arr[curr.x][curr.y-1]);
                if(!(v.count(boardToString(arr)))){
                    BoardState next(arr, curr.x, curr.y-1, curr.level+1);
                    bfs.push(next);
                    v.insert(boardToString(arr));
                }
            }
            // go down
            if(curr.x !=1){
                vector<vector<int>> arr = curr.board;
                swap(arr[curr.x][curr.y] ,arr[curr.x+1][curr.y]);
                if(!(v.count(boardToString(arr)))){
                    BoardState next(arr, curr.x+1, curr.y, curr.level+1);
                    bfs.push(next);
                    v.insert(boardToString(arr));
                }
            }
            // go right
            if(curr.y !=2){
                vector<vector<int>> arr = curr.board;
                swap(arr[curr.x][curr.y] ,arr[curr.x][curr.y+1]);
                if(!(v.count(boardToString(arr)))){
                    BoardState next(arr, curr.x, curr.y+1, curr.level+1);
                    bfs.push(next);
                    v.insert(boardToString(arr));
                }
            }
        }

        return -1;
    }

    private:
    string boardToString(const vector<vector<int>>& board) {
        string res;
        for (const auto& row : board) {
            for (int num : row) {
                res += to_string(num) + ",";
            }
        }
        return res;
    }
};