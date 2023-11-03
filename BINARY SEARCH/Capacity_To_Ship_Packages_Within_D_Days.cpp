/*
Given an array arr[] of N weights. Find the least weight capacity of a boat to ship all weights within D days.
The ith weight has a weight of arr[i]. Each day, we load the boat with weights given by arr[i].We may not load more weight than the maximum weight capacity of the ship.

Note: You have to load weights on the boat in the given order.
*/

/*
Input:
N = 3
arr[] = {9, 8, 10}
D = 3
Output:
10
Explanation:
We can ship the weights in 3 days
in the following way:-
Day 1- 9
Day 2- 8
Day 3- 10
*/

#include <iostream>
#include <algorithm>  // Required for 'max' function
#include<bits/stdc++.h>
using namespace std;  // Simplify the use of standard C++ libraries

class Solution {
public:
    // Function to find the maximum value in an array
    int findmax(int arr[], int n) {
        int ans = INT_MIN;  // Initialize the answer to the smallest possible integer
        for (int i = 0; i < n; i++) {
            ans = max(ans, arr[i]);  // Update 'ans' with the maximum value
        }
        return ans;  // Return the maximum value in the array
    }

    // Function to calculate the sum of all elements in an array
    int sumofall(int arr[], int n) {
        int sum = 0;  // Initialize the sum to zero
        for (int i = 0; i < n; i++) {
            sum += arr[i];  // Add each element to 'sum'
        }
        return sum;  // Return the total sum of elements in the array
    }

    // Function to find the minimum number of days required to ship 'D' units of weight
    int finddays(int arr[], int n, int cap) {
        int days = 1;  // Initialize the number of days to 1
        int load = 0;  // Initialize the current load to 0
        for (int i = 0; i < n; i++) {
            if (load + arr[i] > cap) {
                days += 1;  // Increment days if the current load exceeds capacity
                load = arr[i];  // Reset the load to the current element's weight
            } else {
                load += arr[i];  // Add the current element's weight to the load
            }
        }
        return days;  // Return the minimum number of days required
    }

    // Function to find the least weight capacity required to ship 'D' units of weight
    int leastWeightCapacity(int arr[], int N, int D) {
        int low = findmax(arr, N);  // Initialize 'low' with the maximum weight
        int high = sumofall(arr, N);  // Initialize 'high' with the total weight

        while (low <= high) {
            int mid = (low + high) / 2;  // Calculate the midpoint

            int days = finddays(arr, N, mid);  // Calculate the number of days required for 'mid' capacity

            if (days <= D)
                high = mid - 1;  // Update 'high' if the number of days is less than or equal to 'D'
            else
                low = mid + 1;  // Update 'low' if the number of days exceeds 'D'
        }
        return low;  // Return the minimum weight capacity required
    }
};

int main() {
    Solution solution;

    // Example usage:
    int N = 6;
    int D = 3;
    int arr[] = {1, 2, 3, 4, 5, 6};

    int result = solution.leastWeightCapacity(arr, N, D);
    cout << "Minimum weight capacity required: " << result << endl;

    return 0;
}
