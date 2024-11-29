class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1] >1 && grid[1][0]>1) return -1;

        int r=grid.size() ,c=grid[0].size();
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};    // better than 4 if
        vector<vector<bool>> v(r, vector<bool>(c, false));
        priority_queue<vector<int> ,vector<vector<int>> ,greater<>> pq;
        pq.push({0,0,0});

        while(pq.size()){
            vector<int> curr = pq.top();
            pq.pop();
            int t=curr[0] ,i=curr[1] ,j=curr[2];

            if(i==r-1 && j==c-1){
                return t;
            }

            if(!v[i][j]){
                v[i][j]=true;
                for(vector<int> d:directions){
                    int ni=i+d[0] ,nj=j+d[1];
                    if(isValid(ni,nj,r,c) && !v[ni][nj]){
                        int wait = (grid[ni][nj]-t+1)&1;
                        int next = max(grid[ni][nj]+wait ,t+1);
                        pq.push({next,ni,nj});
                    }
                }
            }
        }

        return 0;   // just to end
    }

    private:
        bool isValid(int i,int j ,int r ,int c){
            return i>=0 && i<r && j>=0 && j<c;
        }
};