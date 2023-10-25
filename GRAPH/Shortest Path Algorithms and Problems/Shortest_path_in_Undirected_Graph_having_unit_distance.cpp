/*
You are given an Undirected Graph having unit weight,
 Find the shortest path from src to all the vertex and if it is unreachable to
  reach any vertex, then return -1 for that vertex.
*/


/*
Input:
n = 9, m= 10
edges=[[0,1],[0,3],[3,4],[4 ,5]
,[5, 6],[1,2],[2,6],[6,7],[7,8],[6,8]] 
src=0
Output:
0 1 2 1 2 3 3 4 4
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to find the shortest distances from a source node to all other nodes in a graph.
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        vector<int> dis(N, 1e9); // Initialize distances to a large value.

        vector<int> adj[N];

        // Create an adjacency list to represent the graph based on provided edges.
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        dis[src] = 0; // Distance from the source to itself is 0.

        queue<int> q;
        q.push(src);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (auto it : adj[curr]) {
                if (dis[curr] + 1 < dis[it]) {
                    dis[it] = dis[curr] + 1; // Update the distance if a shorter path is found.
                    q.push(it);
                }
            }
        }

        vector<int> ans(N, -1);
        for (int i = 0; i < N; i++) {
            if (dis[i] != 1e9) {
                ans[i] = dis[i]; // Copy valid distances to the result vector.
            }
        }

        return ans; // Return the shortest distances from the source node to all other nodes.
    }
};

int main() {
    Solution solution;

    int N = 5; // Number of nodes
    int M = 6; // Number of edges
    int src = 0; // Source node

    // Define the edges in the graph as source and destination nodes
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {3, 4}, {2, 4}, {4, 0}};

    vector<int> shortestDistances = solution.shortestPath(edges, N, M, src);

    cout << "Shortest distances from node " << src << " to all other nodes:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Node " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}
