// QUESTIONS
/*
Given a boolean matrix of size RxC where each cell contains either
 0 or 1, modify it such that if a matrix cell matrix[i][j] is 1 
 then all the cells in its ith row and jth column will become 1.
*/

#include<iostream>
#include<vector>
using namespace std;


class Solution
{
public:
    // Function to modify the matrix such that if a matrix cell matrix[i][j]
    // is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        int n = matrix.size();  // Get the number of rows in the matrix
        int m = matrix[0].size();  // Get the number of columns in the matrix

        int row[n] = {0};  // Create an array to track rows with 1
        int col[m] = {0};  // Create an array to track columns with 1

        // Loop through the matrix to identify cells with value 1
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 1)
                {
                    col[j] = 1;  // Mark the jth column as containing 1
                    row[i] = 1;  // Mark the ith row as containing 1
                }
            }
        }

        // Loop through the matrix again to update cells based on row and column markings
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (row[i] == 1 || col[j] == 1)
                {
                    matrix[i][j] = 1;  // If the row or column contains 1, update the cell to 1
                }
            }
        }
    }
};
