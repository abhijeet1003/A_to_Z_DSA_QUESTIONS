/*
Given a weighted, undirected and connected graph of V vertices and an adjacency list
 adj where adj[i] is a list of lists containing two integers where the first integer 
 of each list j denotes there is edge between i and j , second integers corresponds 
 to the weight of that  edge . You are given the source vertex S and You to Find the
  shortest distance of all the vertex's from the source vertex S. You have to return
 a list of integers denoting shortest distance between each node and Source vertex S.

Note: The Graph doesn't contain any negative weight cycle.
*/

/*
Input:
V = 3, E = 3
adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}
S = 2

Output:
4 3 0

Explanation:

For nodes 2 to 0, we can follow the path-
2-1-0. This has a distance of 1+3 = 4,
whereas the path 2-0 has a distance of 6. So,
the Shortest path from 2 to 0 is 4.
The shortest distance from 0 to 1 is 1 .
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        // Create a set to store pairs of (distance, node) where the node is the destination vertex
        // and distance is the shortest distance from the source vertex to the destination.
        set<pair<int, int>> s;

        // Initialize the set with the source vertex S and a distance of 0.
        s.insert({0, S});

        // Create a vector to store the shortest distances from the source to all vertices.
        vector<int> dis(V, 1e9);

        // Set the shortest distance from the source to itself as 0.
        dis[S] = 0;

        while (!s.empty()) {
            // Get the vertex with the shortest distance from the set.
            auto it = *(s.begin());
            int node = it.second;
            int dist = it.first;

            // Remove the vertex from the set.
            s.erase(it);

            // Iterate through the adjacent vertices of the current vertex.
            for (auto neighbor : adj[node]) {
                int adjnode = neighbor[0]; // Get the adjacent vertex.
                int weight = neighbor[1];  // Get the weight (distance) to the adjacent vertex.

                // Check if the path through the current vertex is shorter than the current known distance to the adjacent vertex.
                if (dist + weight < dis[adjnode]) {
                    if (dis[adjnode] != 1e9) {
                        // If the adjacent vertex was already in the set, remove it to update its distance.
                        s.erase({dis[adjnode], adjnode});
                    }

                    // Update the shortest distance to the adjacent vertex and add it to the set.
                    dis[adjnode] = weight + dist;
                    s.insert({dist + weight, adjnode});
                }
            }
        }

        // Return the vector of shortest distances from the source to all vertices.
        return dis;
    }
};

int main() {
    Solution solution;

    // Define the number of vertices.
    int V = 6;

    // Create an adjacency list to represent the graph with weights on edges.
    vector<vector<int>> adj[V];
    adj[0] = {{1, 2}, {2, 4}};
    adj[1] = {{0, 2}, {2, 5}, {3, 10}};
    adj[2] = {{0, 4}, {1, 5}, {3, 2}};
    adj[3] = {{1, 10}, {2, 2}, {4, 7}};
    adj[4] = {{3, 7}, {5, 6}};
    adj[5] = {{4, 6}};

    // Define the source vertex.
    int source = 0;

    // Call the Dijkstra function to find the shortest distances.
    vector<int> shortestDistances = solution.dijkstra(V, adj, source);

    // Print the shortest distances from the source to all vertices.
    cout << "Shortest Distances from Source " << source << " to All Vertices:" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}
