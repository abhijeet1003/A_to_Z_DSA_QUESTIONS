//                                        question


/*Given an unsorted array A of size N that contains only positive integers, find a continuous sub-array that adds to a given number S and return the left and right index(1-based indexing) of that subarray.*/

/*
N = 5, S = 12
A[] = {1,2,3,7,5}
Output: 2 4
Explanation: The sum of elements 
from 2nd position to 4th position 
is 12.
*/


vector<int> subarraySum(vector<int> arr, int n, long long s)
{
    int sum = 0;         // Initialize a variable to store the current sum.
    vector<int> ans;     // Initialize an empty vector to store the result.
    int j = 0;           // Initialize a pointer for the start of the subarray.

    // Question: What is the purpose of checking if 's' is zero?
    if (s == 0) {
        return {-1};     // If 's' is zero, return [-1].
    }
    else {
        // Iterate through the elements of the array.
        for (int i = 0; i < n; i++) {
            sum = sum + arr[i];  // Add the current element to the sum.

            // Keep removing elements from the start of the subarray
            // until the sum is less than or equal to 's'.
            while (sum > s) {
                sum = sum - arr[j];  // Subtract the element at 'j' from the sum.
                j++;                // Move the start pointer to the right.
            }

            // If the current sum equals 's', it means we found a subarray.
            if (sum == s) {
                ans.push_back(j + 1);  // Add the start index of the subarray to 'ans'.
                ans.push_back(i + 1);  // Add the end index of the subarray to 'ans'.
                return ans;            // Return the result vector.
            }
        }
    }

    return {-1};  // If no subarray is found, return [-1].

    // Answer: The purpose of checking if 's' is zero is to handle the special case where
    // the target sum 's' is zero. In this case, there won't be any subarray with a sum
    // equal to zero (since all elements are positive integers), so we return [-1] to
    // indicate that no subarray with the desired sum exists.
}
