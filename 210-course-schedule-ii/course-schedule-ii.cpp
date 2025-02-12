class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> pre(numCourses,0);  // pre-requires
        // vector<bool> v(numCourses,false);  // visited
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
            pre[i[0]]++;
        }

        // start toposort with BFS
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(!pre[i]){
                q.push(i);
            }
        }
        
        vector<int> topo;   // this is the answer
        while(q.size()){
            int curr= q.front();
            q.pop();
            // v[curr]=true;
            if(!pre[curr]) topo.push_back(curr);
            for(int i:adj[curr]){
                pre[i]--;
                if(!pre[i]){
                    q.push(i);
                }
            }
        }

        if(topo.size()<numCourses){
            topo={};
        }

        return topo;
    }
};