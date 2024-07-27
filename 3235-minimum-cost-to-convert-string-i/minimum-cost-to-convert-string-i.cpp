#include <vector>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();
        if (n != target.size()) {
            return -1;
        }
        
        // Initialize the cost matrix
        vector<vector<long long>> minCost(26, vector<long long>(26, LLONG_MAX));
        
        // Set the cost to transform a character to itself to 0
        for (int i = 0; i < 26; ++i) {
            minCost[i][i] = 0;
        }
        
        // Fill in the given transformation costs
        for (int i = 0; i < original.size(); ++i) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            minCost[from][to] = min(minCost[from][to], (long long)cost[i]);
        }
        
        // Floyd-Warshall algorithm to find the minimum cost between all pairs of characters
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (minCost[i][k] != LLONG_MAX && minCost[k][j] != LLONG_MAX) {
                        minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j]);
                    }
                }
            }
        }
        
        long long totalCost = 0;
        
        // Calculate the total cost to transform source to target
        for (int i = 0; i < n; ++i) {
            if (source[i] == target[i]) {
                continue;
            }
            
            int from = source[i] - 'a';
            int to = target[i] - 'a';
            if (minCost[from][to] == LLONG_MAX) {
                return -1; // Transformation not possible
            }
            totalCost += minCost[from][to];
        }
        
        return totalCost;
    }
};
