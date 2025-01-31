class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n= grid.size() ,res=0;
        vector<vector<bool>> v(n,vector<bool>(n,false));
        vector<vector<pair<int,int>>> arr(n,vector<pair<int,int>>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               arr[i][j]={grid[i][j] ,0};   // val in grid , island number
            }
        }

        int num=1;  // island number
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!v[i][j] && grid[i][j]){
                    res= max(res ,bfs(arr,v,i,j ,num));
                    num++;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!grid[i][j]){
                    unordered_map<int,int> mp;    // island number : island size
                    if(i-1>-1 && arr[i-1][j].first){
                        mp[arr[i-1][j].second] = arr[i-1][j].first;
                    }
                    if(i+1<n && arr[i+1][j].first){
                        mp[arr[i+1][j].second] = arr[i+1][j].first;
                    }
                    if(j-1>-1 && arr[i][j-1].first){
                        mp[arr[i][j-1].second] = arr[i][j-1].first;
                    }
                    if(j+1<n && arr[i][j+1].first){
                        mp[arr[i][j+1].second] = arr[i][j+1].first;
                    }

                    int sum=1;
                    for(auto it:mp){
                        sum += it.second;
                    }

                    res=max(res,sum);
                }
            }
        }
        

        return res;
    }

private:
    int bfs(vector<vector<pair<int,int>>>& grid ,vector<vector<bool>>& v ,int i,int j ,int num){
        queue<pair<int,int>> q;
        vector<pair<int,int>> collect;
        int n= grid.size();
        q.push({i,j});
        while(q.size()){
            int k=q.size();
            while(k--){
                i=q.front().first;
                j=q.front().second;
                q.pop();
                v[i][j]= true;
                collect.push_back({i,j});

                if(i-1>-1 && !v[i-1][j] && grid[i-1][j].first){
                    q.push({i-1,j});
                    v[i-1][j]= true;
                }
                if(i+1<n && !v[i+1][j] && grid[i+1][j].first){
                    q.push({i+1,j});
                    v[i+1][j]= true;
                }
                if(j-1>-1 && !v[i][j-1] && grid[i][j-1].first){
                    q.push({i,j-1});
                    v[i][j-1]= true;
                }
                if(j+1<n && !v[i][j+1] && grid[i][j+1].first){
                    q.push({i,j+1});
                    v[i][j+1]= true;
                }
            }
        }

        for(pair<int,int> it:collect){
            i=it.first;
            j=it.second;
            grid[i][j].first = collect.size();
            grid[i][j].second = num;
        }

        return collect.size();
    }
};