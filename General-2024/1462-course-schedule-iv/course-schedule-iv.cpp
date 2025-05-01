class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;
        for(vector<int> i:prerequisites){
            adj[i[0]].push_back(i[1]);
        }

        int s=queries.size();
        vector<bool> ans(s);
        for(int i=0;i<s;i++){
            vector<bool> v(numCourses,false);
            ans[i] = helper(adj,v,queries[i][0],queries[i][1],false);
        }

        return ans;
    }

private:
    bool helper(unordered_map<int,vector<int>>& adj ,vector<bool>& v ,int src ,int end ,bool ans){
        v[src]=true;
        if(src == end){
            // v[src]=false;
            return true;
        }

        for(int i:adj[src]){
            if(!v[i]){
                ans = ans || helper(adj,v,i,end,ans);
                if(ans){
                    // v[src]=false;
                    return true;
                }
            }
        }

        // v[src]=false;
        return false;
    }
};