class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int,vector<pair<int,double>>> adj;
        for(int i=0 ;i< edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start});
        unordered_set<int> visit;

        while(pq.size()){
            double prob = pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            visit.insert(cur);

            if(cur == end){
                return prob;
            }

            for(pair<int,double> node : adj[cur]){
                if(visit.find(node.first) == visit.end()){
                    pq.push({prob * node.second , node.first});
                }
            }
        }

        return 0;
    }
};