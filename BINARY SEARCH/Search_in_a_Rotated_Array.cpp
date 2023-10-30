/*
Given a sorted and rotated array A of N distinct elements which 
is rotated at some point, and given an element key. The task is
 to find the index of the given element key in the array A. The 
 whole array A is given as the range to search.
*/

/*
Input:
N = 9
A[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}
key = 10
l = 0 , h = 8
Output:
5
Explanation: 10 is found at index 5.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    // Function to search for the target element in a rotated sorted array.
    int search(int arr[], int l, int h, int target) {
        int low = l;  // Initialize the lower index.
        int high = h; // Initialize the higher index.

        while (low <= high) { // Continue the search until the lower index is less than or equal to the higher index.
            int mid = (low + high) / 2; // Calculate the middle index.

            if (arr[mid] == target) {
                return mid; // Target found in the array; return the index.
            }

            if (arr[low] <= arr[mid]) {
                // Check if the array is sorted in the left half.
                if (arr[low] <= target && target <= arr[mid]) {
                    high = mid - 1; // Adjust the higher index for the left half.
                } else {
                    low = mid + 1; // Adjust the lower index for the right half.
                }
            } else {
                // Check if the array is sorted in the right half.
                if (arr[mid] <= target && target <= arr[high]) {
                    low = mid + 1; // Adjust the lower index for the right half.
                } else {
                    high = mid - 1; // Adjust the higher index for the left half.
                }
            }
        }

        return -1; // Target not found in the array; return -1.
    }
};

int main() {
    Solution solution;
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 0;

    int result = solution.search(arr, 0, n - 1, target);

    if (result != -1) {
        cout << "Target " << target << " found at index " << result << endl;
    } else {
        cout << "Target " << target << " not found in the array." << endl;
    }

    return 0;
}
