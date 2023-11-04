/*
Given an array arr of positive integers sorted in a 
strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.
*/


/*
Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. 
The 2nd missing positive integer is 6.
*/

#include <iostream>  // Include the input-output stream header.
#include<vector>
#include<bits/stdc++.h>
using namespace std;  // Use the standard namespace for standard library functions.

class Solution {
public:
    // Function to find the Kth missing positive integer in an array.
    int findKthPositive(vector<int>& a, int k) {
        int n = a.size();  // Get the size of the array.
        int low = 0;       // Initialize the low pointer.
        int high = n - 1;  // Initialize the high pointer.

        // Binary search loop to find the missing integer.
        while (low <= high) {
            int mid = (low + high) / 2;  // Calculate the middle index.

            int missing = a[mid] - (mid + 1);  // Calculate the number of missing elements up to the current index.

            if (missing < k) low = mid + 1;  // If missing elements are less than k, update the low pointer.
            else high = mid - 1;             // If missing elements are greater or equal to k, update the high pointer.
        }

        return k + high + 1;  // Return the Kth missing positive integer.
    }
};

int main() {
    Solution solution;  // Create an instance of the Solution class.

    // Sample array and value of k.
    vector<int> a = {2, 3, 4, 7, 11};
    int k = 5;

    int result = solution.findKthPositive(a, k);  // Call the findKthPositive function.

    // Print the result to the console.
    cout << "Kth missing positive integer: " << result << endl;

    return 0;
}
