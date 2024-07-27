#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();
        if (n != target.size()) {
            return -1;
        }

        // Create a graph representation of the transformations
        unordered_map<char, vector<pair<char, int>>> graph;
        for (int i = 0; i < original.size(); ++i) {
            graph[original[i]].emplace_back(changed[i], cost[i]);
        }

        // Function to use Dijkstra's algorithm to find the minimum cost to transform 'start' to all other characters
        auto dijkstra = [&](char start) {
            vector<long long> dist(26, LLONG_MAX);
            dist[start - 'a'] = 0;
            priority_queue<pair<long long, char>, vector<pair<long long, char>>, greater<>> pq;
            pq.emplace(0, start);

            while (!pq.empty()) {
                auto [currentCost, currentChar] = pq.top();
                pq.pop();

                if (currentCost > dist[currentChar - 'a']) {
                    continue;
                }

                for (auto& [nextChar, nextCost] : graph[currentChar]) {
                    long long newCost = currentCost + nextCost;
                    if (newCost < dist[nextChar - 'a']) {
                        dist[nextChar - 'a'] = newCost;
                        pq.emplace(newCost, nextChar);
                    }
                }
            }

            return dist;
        };

        // Precompute the minimum cost to transform each character to every other character
        vector<vector<long long>> minCost(26);
        for (char c = 'a'; c <= 'z'; ++c) {
            minCost[c - 'a'] = dijkstra(c);
        }

        long long totalCost = 0;

        // Calculate the total cost to transform source to target
        for (int i = 0; i < n; ++i) {
            if (source[i] == target[i]) {
                continue;
            }

            long long cost = minCost[source[i] - 'a'][target[i] - 'a'];
            if (cost == LLONG_MAX) {
                return -1; // Transformation not possible
            }
            totalCost += cost;
        }

        return totalCost;
    }
};
