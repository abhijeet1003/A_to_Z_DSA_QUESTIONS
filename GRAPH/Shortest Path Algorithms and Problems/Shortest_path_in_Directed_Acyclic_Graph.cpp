/*
Given a Directed Acyclic Graph of N vertices from 0 to N-1 
and a 2D Integer array(or vector) edges[ ][ ] of length M, 
where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) 
vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.
*/

/*
Input:
N = 6, M = 7
edge = [[0,1,2],[0,4,1],[4,5,4],[4,2,2],[1,2,3],[2,3,6],[5,3,1]]
Output:
0 2 3 6 1 5
Explanation:
Shortest path from 0 to 1 is 0->1 with edge weight 2. 
Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3.
Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6.
Shortest path from 0 to 4 is 0->4 with edge weight 1.
Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.
*/


#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Solution {
public:
    // Depth-First Search (DFS) to topologically sort the nodes and push them onto the stack.
    void dfs(vector<pair<int, int>> adj[], int vis[], stack<int> &st, int i) {
        vis[i] = 1; // Mark the node as visited.
        for (auto it : adj[i]) {
            int node = it.first;

            if (!vis[node]) {
                dfs(adj, vis, st, node);
            }
        }
        st.push(i); // Push the current node onto the stack.
    }

    // Function to find the shortest path from the source node (0) to all other nodes in the graph.
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        // Create an adjacency list to represent the graph.
        vector<pair<int, int>> adj[N];

        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v, w}); // Add an edge to the adjacency list.
        }

        stack<int> st; // Initialize a stack to hold topologically sorted nodes.
        int vis[N] = {0}; // Initialize an array to track visited nodes.

        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                dfs(adj, vis, st, i); // Perform DFS to topologically sort nodes.
            }
        }

        vector<int> dis(N, INT_MAX); // Initialize an array to store shortest distances.

        dis[0] = 0; // The shortest distance from the source node to itself is 0.

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            for (auto it : adj[node]) {
                int newnode = it.first;
                int weight = it.second;

                if (weight + dis[node] < dis[newnode]) {
                    dis[newnode] = dis[node] + weight; // Relaxation step to update shortest distances.
                }
            }
        }

        for (int i = 0; i < N; i++) {
            if (dis[i] == INT_MAX) {
                dis[i] = -1; // Set unreachable nodes to -1 in the result.
            }
        }
        return dis; // Return the shortest distances from the source node to all other nodes.
    }
};

int main() {
    Solution solution;

    int N = 5; // Number of nodes
    int M = 6; // Number of edges

    // Define the edges in the graph as source, destination, and weight
    vector<vector<int>> edges = {{0, 1, 5}, {0, 2, 4}, {1, 3, 7}, {3, 4, 2}, {2, 4, 6}, {4, 0, 1}};

    vector<int> shortestDistances = solution.shortestPath(N, M, edges);

    cout << "Shortest distances from node 0 to all other nodes:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Node " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}
