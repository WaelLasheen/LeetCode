#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<tuple<int, int, char, int>> robots;
        
        // Combine positions, healths, directions and their indices
        for (int i = 0; i < n; ++i) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }
        
        // Sort robots by positions
        sort(robots.begin(), robots.end());
        
        stack<tuple<int, int, char, int>> rightMovingRobots; // Stack to keep right-moving robots
        
        // Array to store the final health of robots, initialized to -1
        vector<int> finalHealths(n, -1);
        
        for (auto& robot : robots) {
            int position = get<0>(robot);
            int health = get<1>(robot);
            char direction = get<2>(robot);
            int index = get<3>(robot);
            
            if (direction == 'R') {
                rightMovingRobots.push(robot);
            } else {
                while (!rightMovingRobots.empty() && get<2>(rightMovingRobots.top()) == 'R') {
                    auto rightRobot = rightMovingRobots.top();
                    if (get<1>(rightRobot) > health) {
                        health = 0;
                        rightMovingRobots.pop();
                        rightMovingRobots.push({get<0>(rightRobot), get<1>(rightRobot) - 1, 'R', get<3>(rightRobot)});
                        break;
                    } else if (get<1>(rightRobot) < health) {
                        health -= 1;
                        rightMovingRobots.pop();
                    } else {
                        health = 0;
                        rightMovingRobots.pop();
                        break;
                    }
                }
                
                if (health > 0) {
                    finalHealths[index] = health;
                }
            }
        }
        
        // Process remaining right-moving robots in the stack
        while (!rightMovingRobots.empty()) {
            auto robot = rightMovingRobots.top();
            rightMovingRobots.pop();
            finalHealths[get<3>(robot)] = get<1>(robot);
        }
        
        // Collect the healths of surviving robots in the order they were given in the input
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (finalHealths[i] != -1) {
                result.push_back(finalHealths[i]);
            }
        }
        
        return result;
    }
};
