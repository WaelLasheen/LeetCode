class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<int> dirX = {0, 1, 0, -1}; // North, East, South, West
        vector<int> dirY = {1, 0, -1, 0}; // North, East, South, West
        set<pair<int, int>> obstacleSet;
        for (const auto& obs : obstacles) {
            obstacleSet.insert({obs[0], obs[1]});
        }
        
        int x = 0, y = 0, direction = 0;
        int maxDist = 0;
        
        for (int cmd : commands) {
            if (cmd == -1) {
                direction = (direction + 1) % 4; // Turn right
            } else if (cmd == -2) {
                direction = (direction + 3) % 4; // Turn left
            } else {
                for (int step = 0; step < cmd; ++step) {
                    int nextX = x + dirX[direction];
                    int nextY = y + dirY[direction];
                    if (obstacleSet.find({nextX, nextY}) == obstacleSet.end()) {
                        x = nextX;
                        y = nextY;
                        maxDist = max(maxDist, x * x + y * y);
                    } else {
                        break; // Stop if there's an obstacle
                    }
                }
            }
        }
        
        return maxDist;
    }
};
