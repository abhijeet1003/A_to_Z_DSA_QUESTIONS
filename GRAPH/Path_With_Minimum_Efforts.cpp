
//                QUESTIONS


/*
You are a hiker preparing for an upcoming hike. You are given heights,
 a 2D array of size rows x columns, where heights[row][col] represents
  the height of cell (row, col). You are situated in the top-left cell,
   (0, 0), and you hope to travel to the bottom-right cell, 
   (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left,
    or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between 
two consecutive cells of the route
*/


#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int MinimumEffort(vector<vector<int>>& heights) {
    priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
    
    // Create a priority queue to store pairs of the form {difference, {row, col}}.
    // 'difference' represents the maximum effort required to reach the cell at (row, col).
    
    int n = heights.size(); // Number of rows in the 'heights' matrix.
    int m  = heights[0].size(); // Number of columns in the 'heights' matrix.
    
    vector<vector<int>> dis(n,vector<int>(m,1e9)); // Create a 2D matrix to store effort values.
    
    int delr[]={-1,0,1,0}; // Array for row direction changes (up, right, down, left).
    int delc[]={0,1,0,-1}; // Array for column direction changes (up, right, down, left).
    
    pq.push({0,{0,0}}); // Push the starting cell (0,0) into the priority queue.
    dis[0][0]=0; // Initialize the effort for the starting cell as 0.
    
    while(!pq.empty()){
        auto it = pq.top(); // Get the cell with the minimum effort from the priority queue.
        pq.pop();
        int diff = it.first; // Extract the maximum effort required.
        int row = it.second.first; // Extract the row of the current cell.
        int col = it.second.second; // Extract the column of the current cell.
        
        if(row == n-1 && col == m-1) return diff; // If we reach the last cell, return the maximum effort.
        
        // Iterate through neighboring cells (up, right, down, left).
        for(int i=0;i<4;i++){
            int newr = row+delr[i]; // Calculate the new row.
            int newc = col+delc[i]; // Calculate the new column.
            
            // Check if the new cell is within bounds.
            if(newr >= 0 && newr < n && newc >= 0 && newc < m){
                // Calculate the maximum effort required to move to the new cell.
                int maxefforts = max(abs(heights[row][col]-heights[newr][newc]), diff);
                
                // Check if the new effort is less than the previously recorded effort.
                if(maxefforts < dis[newr][newc]){
                    dis[newr][newc] = maxefforts; // Update the effort for the new cell.
                    pq.push({maxefforts, {newr, newc}}); // Push the new cell into the priority queue.
                }
            }
        }
    }
    
    return 0; // If no path to the last cell is found (should not happen in practice), return 0.
}
