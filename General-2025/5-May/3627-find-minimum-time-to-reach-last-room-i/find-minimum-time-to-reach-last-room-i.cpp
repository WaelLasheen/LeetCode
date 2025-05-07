class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        vector<vector<int>> dir ={{0,1},{1,0},{0,-1},{-1,0}};
        priority_queue<vector<int> ,vector<vector<int>>, greater<>> pq;
        pq.push({0,0,0});
        moveTime[0][0]=-1;  // mark as visit before

        while(pq.size()){
            int t = pq.top()[0];
            int r = pq.top()[1];
            int c = pq.top()[2];
            pq.pop();

            if(r+1== moveTime.size() && c+1== moveTime[0].size()){
                return t;
            }

            for(int i=0;i<4;i++){
                if(r+dir[i][0]>-1 && r+dir[i][0]<moveTime.size() && c+dir[i][1]>-1 && c+dir[i][1]<moveTime[0].size() && moveTime[r+dir[i][0]][c+dir[i][1]] !=-1){
                    int nt= max(moveTime[r+dir[i][0]][c+dir[i][1]] ,t)+1;
                    pq.push({nt ,r+dir[i][0] ,c+dir[i][1]});
                    moveTime[r+dir[i][0]][c+dir[i][1]] =-1; // mark as visit before
                }
            }
        }

        return -1;
    }
};