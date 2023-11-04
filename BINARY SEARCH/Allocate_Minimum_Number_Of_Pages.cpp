/*
You have N books, each with A[i] number of pages. 
M students need to be allocated contiguous books, with each student getting at least one book.
Out of all the permutations, the goal is to find the permutation where the student with the most
 books allocated to him gets the minimum number of pages, out of all possible permutations.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous
 order (see the explanation for better understanding).
*/

/*
Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:113
Explanation:Allocation can be done in 
following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90} Maximum Pages =113.
Therefore, the minimum of these cases is 113,
which is selected as the output.
*/

#include <iostream>  // Include the input-output stream header.
#include<bits/stdc++.h>
#include<limits>
using namespace std;  // Use the standard namespace for standard library functions.

class Solution {
public:
    // Function to find the maximum value in an array.
    int findMax(int A[], int n) {
        int ans = INT_MIN;  // Initialize the answer to the minimum integer value.
        for (int i = 0; i < n; i++) {
            ans = max(ans, A[i]);  // Update the answer with the maximum value.
        }
        return ans;  // Return the maximum value.
    }

    // Function to find the sum of elements in an array.
    int findSum(int A[], int n) {
        int ans = 0;  // Initialize the answer to 0.
        for (int i = 0; i < n; i++) {
            ans += A[i];  // Add each element to the answer.
        }
        return ans;  // Return the sum of elements.
    }

    // Function to count the number of students required for given pages.
    int countStd(int A[], int pages, int n) {
        int std = 1;           // Initialize the number of students to 1.
        long long studentpages = 0;  // Initialize the pages allocated to a student to 0.

        // Iterate through the books to distribute pages to students.
        for (int i = 0; i < n; i++) {
            if (A[i] + studentpages <= pages) {
                studentpages += A[i];  // Allocate pages to the current student.
            } else {
                std++;                 // If pages exceed the limit, increment the student count.
                studentpages = A[i];  // Start allocating pages to a new student.
            }
        }
        return std;  // Return the total number of students needed.
    }

    // Function to find the minimum number of pages needed to be allocated.
    int findPages(int A[], int N, int M) {
        if (M > N) return -1;  // If students are more than books, return -1.

        int low = findMax(A, N);   // Initialize the lower bound with the maximum book pages.
        int high = findSum(A, N);  // Initialize the upper bound with the sum of all book pages.

        // Binary search to find the minimum number of pages to be allocated.
        while (low <= high) {
            int mid = (low + high) / 2;  // Calculate the middle value for pages.

            int student = countStd(A, mid, N);  // Count students needed for the given pages.

            if (student > M)
                low = mid + 1;  // If more students are needed, update the lower bound.
            else
                high = mid - 1;  // If fewer or equal students are needed, update the upper bound.
        }
        return low;  // Return the minimum number of pages to be allocated.
    }
};

int main() {
    Solution solution;  // Create an instance of the Solution class.

    // Sample book pages and number of students.
    int A[] = {12, 34, 67, 90};
    int M = 2;

    int result = solution.findPages(A, sizeof(A) / sizeof(A[0]), M);  // Call the findPages function.

    // Print the result to the console.
    cout << "Minimum number of pages to be allocated: " << result << endl;

    return 0;
}
