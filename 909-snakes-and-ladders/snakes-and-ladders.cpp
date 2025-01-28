class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        unordered_map<int,int> mp;
        vector<bool> v(n*n+1,false);
        bool rev=false;
        int num=1;
        for(int i=n-1;i>=0;i--){
            for(int j=(rev? n-1 : 0); rev? j>=0 : j<n; rev? j--:j++){
                if(board[i][j] != -1){
                    mp[num] = board[i][j];
                }

                num++;
            }
            rev = !rev;
        }

        // start BFS
        int l=1;
        queue<int> q;
        q.push(1);
        while(q.size()){
            int k=q.size();
            while(k--){
                // roll dice
                for(int i=1;i<=6;i++){
                    num = q.front()+i;
                    if(num> n*n){
                        break;
                    }
                    
                    if(mp[num]){
                        num = mp[num];
                    }
                    
                    if(num == n*n){
                        return l;
                    }

                    if(!v[num]){
                        q.push(num);
                        v[num]=true;
                    }
                }
                q.pop();
            }

            l++;
        }

        return -1;
    }
};