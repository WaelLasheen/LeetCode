class Solution {
public:
    void processDiagonal(vector<vector<int>>& grid, int i, int j, bool negate) {
        int n = grid.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        int x = i, y = j;
        while (x < n && y < n) {
            pq.push(negate ? -grid[x][y] : grid[x][y]);
            x++;
            y++;
        }

        x = i, y = j;
        while (x < n && y < n) {
            int val = pq.top(); pq.pop();
            grid[x][y] = negate ? -val : val;
            x++;
            y++;
        }
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        for (int it = 0; it < n; it++) {
            processDiagonal(grid, it, 0, true);
            if(it){
                processDiagonal(grid, 0, it, false);
            }
        }

        return grid;
    }
};
