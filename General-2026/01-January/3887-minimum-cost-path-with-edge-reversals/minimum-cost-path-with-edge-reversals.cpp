class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<int> cost(n,INT_MAX);
        cost[0] =0;
        map<int,vector<pair<int,int>>> adj;
        for(vector<int> n:edges){
            adj[n[0]].push_back({n[2],n[1]});
            adj[n[1]].push_back({2*n[2],n[0]});
        }

        priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<>> pq; // w u
        pq.push({0,0});

        while(pq.size()){
            int tw = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if(u==n-1) return tw;
            
            for(pair<int,int> i:adj[u]){
                int v = i.second;
                int w = i.first;
                if(tw+w < cost[v]){
                    cost[v] = tw+w;
                    pq.push({tw+w ,v});
                }
            }
        }

        return cost[n-1]==INT_MAX? -1:cost[n-1];
    }
};