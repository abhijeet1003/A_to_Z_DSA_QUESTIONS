//              QUESTIONS

/*
Given a matrix of size r*c. Traverse the matrix in spiral form.

Example 1:
Input:
r = 4, c = 4
matrix[][] = {{1, 2, 3, 4},
             {5, 6, 7, 8},
             {9, 10, 11, 12},
             {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
*/

class Solution
{   
public: 
    // Function to return a list of integers denoting spiral traversal of a matrix.
    vector<int> spirallyTraverse(vector<vector<int> > arr, int r, int c) 
    {
        vector<int> ans;
        int left = 0;
        int right = c - 1;
        int top = 0;
        int bottom = r - 1;
        
        // Loop to traverse the matrix in a spiral order.
        while (left <= right && top <= bottom) {
            // Traverse the top row from left to right.
            for (int i = left; i <= right; i++) {
                ans.push_back(arr[top][i]);
            }
            top++;
            
            // Traverse the rightmost column from top to bottom.
            for (int i = top; i <= bottom; i++) {
                ans.push_back(arr[i][right]);
            }
            right--;
            
            // Check if there is a bottom row to traverse.
            if (top <= bottom) {
                // Traverse the bottom row from right to left.
                for (int i = right; i >= left; i--) {
                    ans.push_back(arr[bottom][i]);
                }
                bottom--;
            }
            
            // Check if there is a leftmost column to traverse.
            if (left <= right) {
                // Traverse the leftmost column from bottom to top.
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(arr[i][left]);
                }
                left++;
            }
        }
        
        return ans;
    }
};
