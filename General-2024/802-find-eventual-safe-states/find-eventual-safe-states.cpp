class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> safe(n,-1); // -1:not visited ,0:false ,1:true
        vector<int> res;
        for(int i=0;i<n;i++){
            if(dfs(graph,safe,i)){
                res.push_back(i);
            }
        }

        return res;
    }
    
private:
    bool dfs(vector<vector<int>>& graph ,vector<int>& safe ,int i){
        if(safe[i]!=-1){
            return safe[i];
        }

        safe[i]=0;
        for(int next:graph[i]){
            if(!dfs(graph,safe,next)){
                return false;
            }
        }
        safe[i]=1;
        return true;
    }
};