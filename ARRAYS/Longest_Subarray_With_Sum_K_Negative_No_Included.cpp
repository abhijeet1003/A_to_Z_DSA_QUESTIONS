//           QUESTION

/*
Given an array containing N integers and an integer K., Your task is to find the length of the 
longest Sub-Array with the sum of the elements equal to the given value K.
*/

// EXAMPLE
/*
A[] = {-10, 5, 2, 7, 1, -9}
K = 15
Output : 4
Explanation:
The sub-array is {5, 2, 7, 1}.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution{
public:
    // Function to find the length of the longest subarray with a given sum 'k'.
    int lenOfLongSubarr(int A[], int n, int k) 
    { 
        int sum = 0;         // Initialize the current sum.
        int maxlen = 0;      // Initialize the maximum length of the subarray.
        
        unordered_map<int, int> mp; // Create an unordered map to store prefix sums and their positions.
        
        for (int i = 0; i < n; i++) {
            sum = sum + A[i]; // Add the current element to the sum.
            
            if (sum == k) {
                maxlen = max(maxlen, i + 1); // Update the maximum length if the sum equals 'k'.
            }
            
            int rem = sum - k; // Calculate the remainder to check for a subarray with sum 'k'.
            
            if (mp.find(rem) != mp.end()) {
                maxlen = max(maxlen, i - mp[rem]); // Update the maximum length based on the current subarray.
            }
            
            if (mp.find(sum) == mp.end()) {
                mp[sum] = i; // Store the position of the current prefix sum in the map.
            }
        }
        
        return maxlen; // Return the maximum length of the subarray.
    } 
};
