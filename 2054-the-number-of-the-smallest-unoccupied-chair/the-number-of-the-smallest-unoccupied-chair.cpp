class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int want=times[targetFriend][0];
        priority_queue<int,vector<int>, greater<int>> leve;
        priority_queue<pair<int,int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;   // leaving time & index
        sort(times.begin(),times.end());
        int it=0;
        for(int i=0;i<times.size();i++){
            while(pq.size() && times[i][0] >= pq.top().first){
                leve.push(pq.top().second);
                pq.pop();
            }
            if(times[i][0] == want){
                return leve.size()?leve.top():it;
            }

            if(leve.size()){
                pq.push({times[i][1] ,leve.top()});
                leve.pop();
            }
            else{
                pq.push({times[i][1] ,it});
                it++;
            }
        }

        return -1;
    }
};