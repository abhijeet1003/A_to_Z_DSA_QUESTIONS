/*                                      QUESTION                            */

/*Question: Explain the purpose and logic of the longestSubarrayWithSumK function 
in your code, which finds the length of the longest subarray in the given array 
'a' with a sum equal to 'k'.*/


/*                                ANSWER                                       */

//             using UNORDERED_MAP approach

#include<vector>
#include<map>

// Function to find the length of the longest subarray with a given sum 'k'
int longestSubarrayWithSumK(std::vector<int> a, long long k) {
    std::map<long long , int > mp; // Create a map to store prefix sums and their corresponding indices
    long long sum = 0 ; // Initialize the current sum
    int maxlen = 0; // Initialize the maximum subarray length
    for(int i=0; i < a.size(); i++) { // Loop through the input array 'a'
        sum = sum + a[i]; // Update the current sum by adding the current element

        if(sum == k) { // If the current sum equals 'k'
            maxlen = std::max(maxlen, i + 1); // Update the maximum length
        }
        
        long long rem = sum - k; // Calculate the remainder needed to reach 'k' from the current sum
        
        if(mp.find(rem) != mp.end()) { // If the remainder is found in the map
            int len = i - mp[rem]; // Calculate the length of the subarray with sum 'k'
            maxlen = std::max(maxlen, len); // Update the maximum length
        }

        if(mp.find(sum) == mp.end()) { // If the current sum is not in the map
            mp[sum] = i; // Store the current sum and its index in the map
        }
    }
    
    return maxlen; // Return the length of the longest subarray with sum 'k'
}










// using TWO POINTER APPROACH

#include <vector>
#include <map>

// Function to find the length of the longest subarray with a given sum 'k'


int longestSubarrayWithSumK(std::vector<int> a, long long k) {
    int right = 0; // Initialize the right pointer
    int left = 0;  // Initialize the left pointer
    int maxl = 0;  // Initialize the maximum subarray length
    long long sum = a[0]; // Initialize the current sum
    int n = a.size(); // Get the size of the input array 'a'

    while (right < n) { // Loop through the array from left to right
        while (left <= right && sum > k) { // Shrink the subarray if the sum exceeds 'k'
            sum = sum - a[left]; // Remove elements from the left
            left++;
        }

        if (sum == k) { // If the current sum equals 'k'
            maxl = std::max(maxl, right - left + 1); // Update the maximum length
        }

        right++; // Expand the subarray by moving the right pointer
        if (right < n) {
            sum = sum + a[right]; // Add elements from the right to the current sum
        }
    }

    return maxl; // Return the length of the longest subarray with sum 'k'
}
