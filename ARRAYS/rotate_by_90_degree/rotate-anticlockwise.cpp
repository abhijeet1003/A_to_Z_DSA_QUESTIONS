//                                      QUESTIONS

/*
Given a square matrix of size N x N. The task is to rotate it by 90
 degrees in anti-clockwise direction without using any extra space.
*/

/*

N = 3
matrix[][] = {{1, 2, 3},
              {4, 5, 6}
              {7, 8, 9}}

Output:
Rotated Matrix:

 7 4 1
 8 5 2
 9 6 3

*/

//                                          APPROACH

//  while rotating the matrix clockwise first do reverse of the
// rows and at last transpose  the matrix

#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution
{
public:
    // Function to rotate a matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>> &matrix, int n)
    {
        // Step 1: Reverse each row of the matrix.
        // This effectively flips each row horizontally.
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }

        // Step 2: Transpose the matrix.
        // Swap elements across the main diagonal (top-left to bottom-right).
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
