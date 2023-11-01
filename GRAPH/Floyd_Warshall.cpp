/*
The problem is to find the shortest distances between every pair
 of vertices in a given edge-weighted directed graph. The graph is
 represented as an adjacency matrix of size n*n. Matrix[i][j] denotes
 the weight of the edge from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j.
Do it in-place.
*/

/*
Input: matrix = {{0,1,43},{1,0,6},{-1,-1,0}}

Output: {{0,1,7},{1,0,6},{-1,-1,0}}

Explanation: We can reach 2 from 0 as 0->1->2
and the cost will be 1+6=7 which is less than 
43.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void shortest_distance(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Initialize matrix: Replace -1 with a large value and set diagonal to 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = 1e9;
                }
                if (i == j) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Apply Floyd-Warshall algorithm to find the shortest distances
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = min(matrix[i][j], (matrix[i][k] + matrix[k][j]));
                }
            }
        }

        // Check for negative cycles
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1) {
                    cout << "Negative cycle encountered, and no minimum distance can be found." << endl;
                    return;
                }
            }
        }

        // Convert large values back to -1 for matrix entries
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1e9) {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};

int main() {
    int n = 4;
    vector<vector<int>> matrix = {
        {0, -1, 3, -1},
        {2, 0, -1, -1},
        {-1, 7, 0, 1},
        {6, -1, -1, 0}
    };
    
    Solution solution;
    solution.shortest_distance(matrix);
    
    cout << "Shortest distance matrix after applying Floyd-Warshall algorithm:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
