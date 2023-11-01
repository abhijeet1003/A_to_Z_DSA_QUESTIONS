/*
You are in a city that consists of n intersections numbered 
from 0 to n - 1 with bi-directional roads between some intersections. 
The inputs are generated such that you can reach any intersection from 
any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where
roads[i] = [ui, vi, timei] means that there is a road between
intersections ui and vi that takes timei minutes to travel. 
You want to know in how many ways you can travel from intersection
0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination
in the shortest amount of time. Since the answer may be large, 
return it modulo 109 + 7.
*/

/*
Input:
n=7, m=10
edges= [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]

Output:
4
Explaination:

The four ways to get there in 7 minutes are:
- 0  6
- 0  4  6
- 0  1  2  5  6
- 0  1  3  5  6
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Create an adjacency list for the graph
        vector<pair<long long, long long>> adj[n];
        
        // Populate the adjacency list with road information
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        // Initialize time and ways arrays
        vector<long long> time(n, 1e18); // Initialize time with a large value
        vector<long long> ways(n, 0);
        
        time[0] = 0; // Starting point has zero time
        ways[0] = 1; // Starting point has one way
        
        // Priority queue for Dijkstra's algorithm
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0, 0}); // Push the starting point
        
        long long mod = (long long)(1e9 + 7); // Modulus value
        
        // Dijkstra's algorithm
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            long long timetaken = it.first;
            long long node = it.second;
            
            for (auto it : adj[node]) {
                long long cost = it.second;
                long long newnode = it.first;
                
                if (timetaken + cost < time[newnode]) {
                    time[newnode] = timetaken + cost;
                    ways[newnode] = ways[node];
                    pq.push({timetaken + cost, newnode});
                } else if (timetaken + cost == time[newnode]) {
                    ways[newnode] = (ways[newnode] + ways[node]) % mod;
                }
            }
        }
        
        // Return the number of ways to reach the last node modulo 'mod'
        return ways[n - 1] % mod;
    }
};

int main() {
    int n = 4;
    vector<vector<int>> roads = {{0, 1, 2}, {0, 2, 4}, {1, 2, 1}, {1, 3, 3}, {2, 3, 2}};
    
    Solution solution;
    int result = solution.countPaths(n, roads);
    
    cout << "Number of ways to reach the last node: " << result << endl;
    
    return 0;
}
