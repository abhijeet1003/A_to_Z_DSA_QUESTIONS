// this optimal approach uses unordered_set data structure to store  to store data and 
// also find data in the unordered_set in O(1) time so its optimal apprach



// QUESTIONS

/*
Given an array of positive integers. Find the length of the longest
 sub-sequence such that elements in the subsequence are consecutive 
 integers, the consecutive numbers can be in any order.
*/

class Solution {
public:
    // arr[]: the input array
    // N: size of the array arr[]

    // Function to return the length of the longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N) {
        if (N == 0) return 0; // If the array is empty, return 0 as there are no consecutive elements.

        unordered_set<int> st; // Create an unordered set to store unique elements from the array.
        int longest = 1; // Initialize the variable to store the length of the longest subsequence.
        int count = 0; // Initialize a variable to count the length of the current subsequence.

        for (int i = 0; i < N; i++) {
            st.insert(arr[i]); // Insert each element of the array into the set to remove duplicates.
        }

        for (auto it : st) { // Iterate through the unique elements in the set.
            if (st.find(it - 1) == st.end()) { // Check if the previous consecutive element is not present in the set.
                count = 1; // Reset the count to 1 for the current element.
                int x = it; // Initialize a variable to track the current element.
                while (st.find(x + 1) != st.end()) { // Continue counting consecutive elements.
                    count = count + 1; // Increment the count.
                    x = x + 1; // Move to the next consecutive element.
                }
                longest = max(longest, count); // Update the longest subsequence length if needed.
            }
        }
        return longest; // Return the length of the longest consecutive subsequence.
    }
};

