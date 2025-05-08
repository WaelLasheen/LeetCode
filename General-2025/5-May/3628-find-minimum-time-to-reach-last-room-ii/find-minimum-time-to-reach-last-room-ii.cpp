class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        vector<vector<int>> dir ={{0,1},{1,0},{0,-1},{-1,0}};
        priority_queue<vector<int> ,vector<vector<int>>, greater<>> pq;
        pq.push({0,0,0,1});
        moveTime[0][0]=-1;  // mark as visit before
        int res= INT_MAX;

        while(pq.size()){
            int t = pq.top()[0];
            int r = pq.top()[1];
            int c = pq.top()[2];
            int s = pq.top()[3];
            pq.pop();

            if(r+1== moveTime.size() && c+1== moveTime[0].size()){
                res=min(res,t);
            }

            for(int i=0;i<4;i++){
                int nr= r+dir[i][0];
                int nc= c+dir[i][1];
                int ns= s==1?2:1;
                if(nr>-1 && nr<moveTime.size() && nc>-1 && nc<moveTime[0].size() && moveTime[nr][nc] !=-1){
                    int nt= max(moveTime[nr][nc] ,t)+s;
                    pq.push({nt ,nr ,nc ,ns});
                    moveTime[nr][nc] =-1; // mark as visit before
                }
            }
        }

        return res;
    }
};