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
        
        // Initialize col0 to keep track of the first column's status separately,
        // as the matrix[0][0] element serves as a marker for both row and column.
        int col0 = 0;

        // Loop through the matrix to identify cells with value 1 and mark corresponding rows and columns.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 1)
                {
                    // Store 1 in the first column of the current row to mark it.
                    matrix[i][0] = 1;

                    // Store 1 in the first row of the current column to mark it,
                    // but handle the case where j=0 (first column) separately using col0.
                    if (j != 0)
                    {
                        matrix[0][j] = 1;
                    }
                    else
                    {
                        col0 = 1;
                    }
                }
            }
        }

        // Loop through the matrix again to update cells based on row and column markings.
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] != 1)
                {
                    // If the cell is not already marked as 1, check if its row or column is marked.
                    if (matrix[i][0] == 1 || matrix[0][j] == 1)
                    {
                        matrix[i][j] = 1;
                    }
                }
            }
        }

        // Handle the first row and first column separately, using the markers col0 and matrix[0][0].
        if (matrix[0][0] == 1)
        {
            // If the marker at matrix[0][0] is 1, set all elements in the first row to 1.
            for (int j = 0; j < m; j++)
            {
                matrix[0][j] = 1;
            }
        }

        if (col0 == 1)
        {
            // If col0 is 1, set all elements in the first column to 1.
            for (int i = 0; i < n; i++)
            {
                matrix[i][0] = 1;
            }
        }
    }
};
