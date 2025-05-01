class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // {cost, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<bool>> v(m, vector<bool>(n, false));

        // dir
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        pq.push({0, 0, 0});
        
        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            
            int cost = curr[0], x = curr[1], y = curr[2];
            
            if (x == m - 1 && y == n - 1){
                return cost;
            }

            if (!v[x][y]){
                v[x][y] = true;

                // Add valid neighbors
                for (int d=0;d<4;d++) {
                    int nx = x+dir[d].first;
                    int ny = y + dir[d].second;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                        // same dir =>0 else 1
                        int add = d + 1 != grid[x][y];
                        pq.push({cost + add, nx, ny});
                    }
                }
            }
        }
        // any value as there is always an answer 
        return -1;
    }
};
