
// QUESTIONS
/*
Given an array A of positive integers. Your task is to find the leaders in the array.
 An element of array is leader if it is greater than or equal to all the
 elements to its right side. The rightmost element is always a leader. 
*/

/*
n = 6
A[] = {16,17,4,3,5,2}
Output: 17 5 2
*/




#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    // Function to find the leaders in the array.
    vector<int> leaders(int arr[], int n) {
        vector<int> ans; // Create a vector to store the leader elements.
        
        int max = arr[n - 1]; // Initialize the maximum element as the last element.
        
        ans.push_back(max); // The last element is always a leader, so add it to the result.

        // Start from the second-to-last element and move towards the beginning of the array.
        for (int i = n - 2; i >= 0; i--) {
            // Check if the current element is greater than or equal to the current maximum.
            if (arr[i] >= max) {
                max = arr[i]; // Update the maximum element.
                ans.push_back(max); // Add the current maximum (leader) to the result.
            }
        }

        reverse(ans.begin(), ans.end()); // Reverse the result to get it in the original order.

        return ans; // Return the vector containing the leader elements.
    }
};
