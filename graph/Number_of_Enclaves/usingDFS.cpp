
//                              QUESTIONS

// You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
// Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.


//                                 ANSWERS

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // Depth-first search function to explore connected land cells
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int row, int col, int n, int m) {
        vis[row][col] = 1; // Mark the current cell as visited
        int delr[] = {-1, 0, 1, 0}; // Offsets to explore neighboring cells
        int delc[] = {0, 1, 0, -1};
        
        // Explore all four neighboring cells
        for (int i = 0; i < 4; i++) {
            int newr = row + delr[i];
            int newc = col + delc[i];
            
            // Check if the neighboring cell is within bounds and is land and not visited
            if (newr >= 0 && newr < n && newc >= 0 && newc < m && vis[newr][newc] == 0 && grid[newr][newc] == 1) {
                // Recursively explore the connected land cell
                dfs(grid, vis, newr, newc, n, m);
            }
        }
    }

    // Function to count the number of enclaves
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0)); // Initialize a 2D array for visited cells
        
        // Iterate through the boundary cells to identify land cells connected to the boundary
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if (grid[i][j] == 1) {
                        // If a boundary cell contains land, start a DFS from there
                        dfs(grid, vis, i, j, n, m);
                    }
                }
            }
        }

        int count = 0; // Initialize a count for unvisited land cells
        
        // Count the number of unvisited land cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    count++;
                }
            }
        }

        return count; // Return the count of enclaves
    }
};
