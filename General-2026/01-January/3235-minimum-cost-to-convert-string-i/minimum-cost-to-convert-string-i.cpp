#define ll long long

class Solution {
public:
    ll minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();
        vector<vector<int>> changeCost(26,vector<int>(26,INT_MAX));
        vector<vector<int>> dp(26,vector<int>(26,INT_MAX));
        vector<unordered_set<int>> adj(26);
        ll res=0;

        for(int i=0;i<n;i++){
            int c1 = original[i]-'a' ,c2 = changed[i]-'a';
            changeCost[c1][c2] = min(changeCost[c1][c2] ,cost[i]);
            adj[c1].insert(c2);
        }

        for(int i=0;i<source.size();i++){
            if(source[i] == target[i]) continue;

            priority_queue<pair<ll,int> ,vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
            vector<bool> v(26,false);
            pq.push({0,source[i]-'a'});
            bool success = false;

            if(dp[source[i]-'a'][target[i]-'a'] != INT_MAX){
                res += dp[source[i]-'a'][target[i]-'a'];
                continue;
            }

            while(pq.size()){
                ll tw = pq.top().first;
                int u = pq.top().second;
                pq.pop();

                if(u == target[i]-'a'){
                    res += tw;
                    success = true;
                    dp[source[i]-'a'][target[i]-'a'] = tw;
                    break;
                }
                
                if(!v[u]){
                    for(int c:adj[u]){
                        if(!v[c]){
                            pq.push({tw+changeCost[u][c] ,c});
                        }
                    }
                    v[u]=true;
                }
            }

            if(!success) return -1;
        }

        return res;
    }
};