//  QUESTIONS

/*
Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest
 distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 

If the path is not possible between source cell and destination cell, then return -1.

Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side.
 In other words, you can move in one of the four directions, Up, Down, Left and Right. The source and destination cell are based on the zero based indexing.
*/



#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;


class Solution {
public:
    // Function to find the shortest path in a grid from source to destination.
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src, pair<int, int> destination) {
        // Check if the source and destination are the same, return 0 if they are.
        if (src.first == destination.first && src.second == destination.second) {
            return 0;
        }

        int n = grid.size(); // Number of rows in the grid.
        int m = grid[0].size(); // Number of columns in the grid.

        vector<vector<int>> dis(n, vector<int>(m, 1e9)); // Create a 2D matrix to store distances.
        queue<pair<int, pair<int, int>>> q; // Create a queue to perform BFS.

        int delr[] = {-1, 0, 1, 0}; // Array for row direction changes (up, right, down, left).
        int delc[] = {0, 1, 0, -1}; // Array for column direction changes (up, right, down, left).

        dis[src.first][src.second] = 0; // Initialize the distance for the source cell as 0.

        q.push({0, {src.first, src.second}}); // Push the source cell into the queue.

        while (!q.empty()) {
            auto it = q.front(); // Get the front cell from the queue.
            q.pop();
            int dist = it.first; // Extract the distance.
            int row = it.second.first; // Extract the row of the current cell.
            int col = it.second.second; // Extract the column of the current cell.

            for (int i = 0; i < 4; i++) { // Iterate through neighboring cells (up, right, down, left).
                int newr = row + delr[i]; // Calculate the new row.
                int newc = col + delc[i]; // Calculate the new column.

                // Check if the new cell is within bounds, is a valid path (grid[newr][newc] == 1),
                // and has a shorter distance than the previously recorded distance.
                if (newr >= 0 && newc >= 0 && newr < n && newc < m && grid[newr][newc] == 1 && dist + 1 < dis[newr][newc]) {
                    dis[newr][newc] = dist + 1; // Update the distance for the new cell.
                    if (newr == destination.first && newc == destination.second) {
                        return dist + 1; // If the destination is reached, return the shortest distance.
                    }
                    q.push({dist + 1, {newr, newc}}); // Push the new cell into the queue.
                }
            }
        }

        return -1; // If no path to the destination is found, return -1.
    }
};
