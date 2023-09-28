#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <limits.h>

// Here is the function that helps us calculate the max rectangle area of a given matrix using the concept of largest area of rectangle in Histogram

class Solution
{
public:
    // Function to find the next smaller element to the right for each element
    vector<int> nextSmallest(int *arr, int n)
    {
        stack<int> st;
        st.push(-1);        // Initialize the stack with -1 to handle boundary cases
        vector<int> ans(n); // Initialize a vector to store the next smaller elements
        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i]; // Current element being processed
            while (st.top() != -1 && arr[st.top()] >= curr)
                st.pop();      // Pop elements from the stack until a smaller element is found
            ans[i] = st.top(); // Store the index of the next smaller element in the vector
            st.push(i);        // Push the current index onto the stack for future comparisons
        }
        return ans; // Return the vector containing the indices of next smaller elements
    }

    // Function to find the next smaller element to the left for each element
    vector<int> prevSmallest(int *arr, int n)
    {
        stack<int> st;
        st.push(-1);        // Initialize the stack with -1 to handle boundary cases
        vector<int> ans(n); // Initialize a vector to store the previous smaller elements
        for (int i = 0; i < n; i++)
        {
            int curr = arr[i]; // Current element being processed
            while (st.top() != -1 && arr[st.top()] >= curr)
                st.pop();      // Pop elements from the stack until a smaller element is found
            ans[i] = st.top(); // Store the index of the previous smaller element in the vector
            st.push(i);        // Push the current index onto the stack for future comparisons
        }
        return ans; // Return the vector containing the indices of previous smaller elements
    }

    // Function to find the largest rectangular area in a histogram
    int largestAreaInHistogram(int *arr, int n)
    {
        // Compute the "next smaller element to the right" for each element
        vector<int> next(n);
        next = nextSmallest(arr, n);

        // Compute the "next smaller element to the left" for each element
        vector<int> prev(n);
        prev = prevSmallest(arr, n);

        int area = INT_MIN; // Initialize the maximum area variable

        for (int i = 0; i < n; i++)
        {
            int length = arr[i]; // Length of the rectangle

            // If there is no next smaller element to the right, assume it's the end of the array
            if (next[i] == -1)
                next[i] = n;

            int breadth = next[i] - prev[i] - 1; // Breadth of the rectangle

            int maxarea = length * breadth; // Calculate the area of the rectangle
            area = max(area, maxarea);      // Update the maximum area if needed
        }

        return area; // Return the maximum area
    }

    // Function to find the maximum area rectangle in a binary matrix
    int maxArea(int M[MAX][MAX], int n, int m)
    {
        // Find the largest area in the first row of the matrix
        int area = largestAreaInHistogram(M[0], m);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (M[i][j] != 0)
                    // Add the previous row's value to the current row to form a histogram
                    M[i][j] = M[i][j] + M[i - 1][j];
                else
                    M[i][j] = 0; // Reset to 0 if the element is 0
            }
            // Update the maximum area with the largest area in the current row
            area = max(area, largestAreaInHistogram(M[i], m));
        }

        return area; // Return the maximum area in the binary matrix
    }
};
