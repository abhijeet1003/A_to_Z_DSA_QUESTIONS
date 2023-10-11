//                                  QUESTIONS

/*
Given an array having both positive and negative integers.
 The task is to compute the length of the largest subarray with sum 0
*/

/*

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}

Output: 5

Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.

*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Function to find the maximum length of a subarray with zero sum
    int maxLen(vector<int>& A, int n) {
        int maxi = 0; // Initialize the maximum length to 0
        int sum = 0; // Initialize the current sum to 0
        unordered_map<int, int> hash; // Create a hash map to store the sum and its corresponding index
        for (int i = 0; i < n; i++) {
            sum = sum + A[i]; // Calculate the current sum by adding the element at index i

            if (sum == 0) {
                maxi = i + 1; // If the current sum is 0, update the maximum length
            } else {
                if (hash.find(sum) != hash.end()) {
                    // If the current sum exists in the hash map, update the maximum length
                    maxi = max(maxi, i - hash[sum]);
                } else {
                    // Otherwise, store the current sum and its index in the hash map
                    hash[sum] = i;
                }
            }
        }
        return maxi; // Return the maximum length of a subarray with zero sum
    }
};

int main() {
    Solution solution;
    vector<int> inputArray = {15, -2, 2, -8, 1, 7, 10, 23}; // Sample input array
    int n = inputArray.size(); // Get the size of the input array

    // Call the maxLen function to find the maximum length of a subarray with zero sum
    int maxLength = solution.maxLen(inputArray, n);

    // Display the result
    cout << "Maximum Length of Subarray with Zero Sum: " << maxLength << endl;

    return 0; // Return 0 to indicate successful program execution
}
