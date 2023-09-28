
//                              QUESTIONS

// You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
// Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.


//                                 ANSWERS

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        queue<pair<int,int>> q; // Create a queue to perform breadth-first search
        int n = grid.size(); // Get the number of rows in the grid
        int m = grid[0].size(); // Get the number of columns in the grid
        vector<vector<int>> vis(n, vector<int>(m, 0)); // Create a 2D array to mark visited cells
        
        // Iterate through the boundary cells and initialize the BFS from land cells on the boundary
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if(grid[i][j] == 1) {
                        q.push({i, j}); // Add boundary land cells to the queue
                        vis[i][j] = 1; // Mark them as visited
                    }
                }
            }
        }
        
        // Perform breadth-first search to visit connected land cells
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int delr[] = {-1, 0, 1, 0}; // Offsets to explore neighboring cells
            int delc[] = {0, 1, 0, -1};
            for(int i = 0; i < 4; i++) {
                int newr = row + delr[i];
                int newc = col + delc[i];
                // Check if the neighboring cell is within bounds, unvisited, and is land
                if(newr >= 0 && newr < n && newc >= 0 && newc < m && vis[newr][newc] == 0 && grid[newr][newc] == 1) {
                    vis[newr][newc] = 1; // Mark it as visited
                    q.push({newr, newc}); // Add it to the queue for further exploration
                }
            }
        }
        
        int count = 0; // Initialize a count for unvisited land cells
        
        // Count the number of unvisited land cells (enclaves)
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && vis[i][j] == 0)
                    count++;
            }
        }
        
        return count; // Return the count of enclaves
    }
};
