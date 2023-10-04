// this better approaach uses SORTING O(nlogn) to solve the question


// QUESTIONS

/*
Given an array of positive integers. Find the length of the longest sub-sequence such that 
elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
*/





class Solution {
public:
    // arr[]: the input array
    // N: size of the array arr[]

    // Function to return the length of the longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N) {
        // Sort the input array in ascending order.
        sort(arr, arr + N);

        int count = 0; // Initialize a variable to count the current consecutive integers.
        int longest = 1; // Initialize the variable to store the length of the longest subsequence.
        int lastSmaller = INT_MIN; // Initialize a variable to keep track of the last smaller number encountered.

        // Iterate through the sorted array.
        for (int i = 0; i < N; i++) {
            if (arr[i] == lastSmaller) {
                continue; // Skip duplicates.
            } else if (arr[i] - 1 == lastSmaller) {
                count = count + 1; // Increment the count for consecutive integers.
                lastSmaller = arr[i]; // Update the last smaller number.
            } else {
                count = 1; // Reset the count if the current number is not consecutive.
                lastSmaller = arr[i]; // Update the last smaller number.
            }
            
            // Update the longest subsequence length if needed.
            longest = max(longest, count);
        }

        return longest; // Return the length of the longest consecutive subsequence.
    }
};
