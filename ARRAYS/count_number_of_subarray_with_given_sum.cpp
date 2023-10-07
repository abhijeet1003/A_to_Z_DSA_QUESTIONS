// QUESTIONS


/*
Given an unsorted array of integers, find the number of continuous
 subarrays having sum exactly equal to a given number k.
*/


/*
Input:
N = 5
Arr = {10 , 2, -2, -20, 10}
k = -10
Output: 3
Explaination: 
Subarrays: arr[0...3], arr[1...4], arr[3..4]
have sum exactly equal to -10.
*/

#include <iostream>
#include <unordered_map> // Include the unordered_map header for using hash maps.

class Solution {
public:
    // Function to find the count of subarrays whose sum equals 'k'.
    int findSubArraySum(int arr[], int n, int k) {
        // Create a hash map to store the prefix sums and their counts.
        std::unordered_map<int, int> mp;

        // Initialize the count of subarrays and the prefix sum.
        int prefixsum = 0;
        int count = 0;

        // Initialize the prefix sum with zero count.
        mp[0] = 1;

        // Iterate through the array to compute prefix sums and count subarrays.
        for (int i = 0; i < n; i++) {
            // Calculate the prefix sum up to the current element.
            prefixsum = prefixsum + arr[i];

            // Calculate the sum that needs to be removed to reach 'k'.
            int removes = prefixsum - k;

            // Update the count by adding the count of subarrays with the 'removes' sum.
            count = count + mp[removes];

            // Increment the count of the current prefix sum in the hash map.
            mp[prefixsum] = mp[prefixsum] + 1;
        }

        // Return the final count of subarrays with the sum 'k'.
        return count;
    }
};

int main() {
    // Example usage of the findSubArraySum function.
    int arr[] = {3, 4, 7, 2, -3, 1, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 7;

    Solution solution;
    int result = solution.findSubArraySum(arr, n, k);

    std::cout << "Number of subarrays with sum " << k << ": " << result << std::endl;

    return 0;
}
