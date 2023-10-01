//  Question

// Given an array Arr[] of N integers. Find the contiguous 
// sub-array(containing at least one number) which has the
//  maximum sum and return its sum.


// this uses a famous algorithm KADANE's ALGORITHM


// in this code u can also store the start and the end index of 
// the subarray giving maximum sum


#include <climits>  // Include the header for INT_MIN (to initialize maxi).

long long maxSubarraySum(int arr[], int n) {
    int startindex, endindex; // Initialize variables to track the start and end indices of the maximum subarray.

    long long sum = 0;       // Initialize sum to keep track of the current subarray sum.
    long long maxi = INT_MIN; // Initialize maxi with the minimum possible integer value.
    int start;               // Initialize a variable to track the start of the current subarray.

    for (int i = 0; i < n; i++) {
        // If the current subarray sum becomes zero, update the start index.
        if (sum == 0) {
            start = i;
        }
        
        // Add the current element to the current subarray sum.
        sum = sum + arr[i];

        // If the current subarray sum is greater than maxi, update startindex, endindex, and maxi.
        if (sum > maxi) {
            startindex = start; // Update startindex to the start of the current subarray.
            endindex = i;       // Update endindex to the end of the current subarray.
            maxi = sum;         // Update maxi with the current subarray sum.
        }

        // If the current subarray sum becomes negative, reset it to zero.
        if (sum < 0) {
            sum = 0;
        }
    }

    


 