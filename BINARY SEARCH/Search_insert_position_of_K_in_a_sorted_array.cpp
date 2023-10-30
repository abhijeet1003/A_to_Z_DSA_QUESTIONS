/*
Given a sorted array Arr[](0-index based) consisting of N distinct integers and 
an integer k, the task is to find the index of k, if its present in the array Arr[].
 Otherwise, find the index where k must be inserted to keep the array sorted.

*/

/*
Input:
N = 4
Arr = {1, 3, 5, 6}
k = 2
Output: 1
Explaination: Since 2 is not present in 
the array but can be inserted at index 1 
to make the array sorted.
*/

#include <iostream>
#include <vector>

class Solution {
public:
    // Function to find the index where 'k' should be inserted in the sorted array 'Arr'.
    int searchInsertK(std::vector<int> Arr, int N, int k) {
        int low = 0;
        int high = N - 1;
        int ans = N;  // Initialize the answer to the end of the array.

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (Arr[mid] >= k) {
                ans = mid;  // Update the answer when the current element is greater or equal to 'k'.
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;  // Return the index where 'k' should be inserted.
    }
};

int main() {
    Solution solution;
    std::vector<int> Arr = {1, 3, 5, 7, 9};  // Sorted array
    int N = Arr.size();
    int k = 6;  // Element to search or insert

    int result = solution.searchInsertK(Arr, N, k);

    std::cout << "Insert position for " << k << " in the array: " << result << std::endl;

    return 0;
}
