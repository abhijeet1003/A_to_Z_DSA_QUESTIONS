/*
You are given an array of integers nums and an integer K,
 your task is to find the smallest positive integer divisor,
  such that upon dividing all the elements of the given array by it,
   the sum of the division's result is less than or equal to the given integer K.


Each result of the division is rounded to the nearest integer 
greater than or equal to that element. For Example: 7/3 = 3.
*/


/*
Example:
Input: 
A = [1 2 5 9]
6
Output:
5
Explanation:
If the divisor is 5 the sum will be 5 (1+1+1+2), which is less than 6.
*/

#include <iostream>
#include <vector>
#include <algorithm>  // Required for 'max' function
#include <cmath>      // Required for 'ceil' function
#include<bits/stdc++.h>

using namespace std;  // Simplify the use of standard C++ libraries

class Solution {
public:
    // Function to find the maximum value in a vector
    int findmax(vector<int> &arr) {
        int ans = INT_MIN;  // Initialize the answer to the smallest possible integer
        for (int i = 0; i < arr.size(); i++) {
            ans = max(ans, arr[i]);  // Update 'ans' with the maximum value
        }
        return ans;  // Return the maximum value in the vector
    }

    // Function to calculate the sum of elements after dividing by 'div' and rounding up
    int check(vector<int> &arr, int div) {
        int sum = 0;  // Initialize the sum to zero
        for (int i = 0; i < arr.size(); i++) {
            sum += ceil((double)arr[i] / (double)div);  // Add the rounded-up result to 'sum'
        }
        return sum;  // Return the total sum of elements after division
    }

    // Function to find the smallest divisor such that the sum after division is less than or equal to 'K'
    int smallestDivisor(vector<int>& arr, int K) {
        int low = 1;  // Initialize 'low' with the minimum divisor of 1
        int high = findmax(arr);  // Initialize 'high' with the maximum value in the vector

        while (low <= high) {
            int mid = (low + high) / 2;  // Calculate the midpoint

            if (check(arr, mid) <= K)
                high = mid - 1;  // Update 'high' if the sum is less than or equal to 'K'
            else
                low = mid + 1;  // Update 'low' if the sum exceeds 'K'
        }
        return low;  // Return the smallest divisor that satisfies the condition
    }
};

int main() {
    Solution solution;

    // Example usage:
    vector<int> arr = {9, 7, 17};
    int K = 7;

    int result = solution.smallestDivisor(arr, K);
    cout << "Smallest divisor: " << result << endl;

    return 0;
}
