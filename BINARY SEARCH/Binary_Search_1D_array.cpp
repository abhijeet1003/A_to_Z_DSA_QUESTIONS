/*
Given a sorted array of size N and an integer K, 
find the position(0-based indexing) at which K is present in the array using binary search.
*/

/*
Input:
N = 5
arr[] = {1 2 3 4 5} 
K = 4
Output: 3
Explanation: 4 appears at index 3.
*/

#include <iostream>

class Solution {
private:
    // Helper function to perform binary search
    int solve(int arr[], int start, int end, int key) {
        if (start > end) {
            return -1; // Element not found, return -1
        }

        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            return mid; // Key found, return its index
        }

        if (arr[mid] < key) {
            return solve(arr, mid + 1, end, key); // Search in the right subarray
        } else {
            return solve(arr, start, mid - 1, key); // Search in the left subarray
        }
    }

public:
    // Function to perform binary search on a sorted array
    int binarysearch(int arr[], int n, int k) {
        int res = solve(arr, 0, n, k); // Call the helper function to perform binary search
        return res; // Return the result
    }
};

int main() {
    Solution solution;
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    int result = solution.binarysearch(arr, n, key);

    if (result != -1) {
        std::cout << "Element " << key << " found at index " << result << std::endl;
    } else {
        std::cout << "Element " << key << " not found in the array" << std::endl;
    }

    return 0;
}