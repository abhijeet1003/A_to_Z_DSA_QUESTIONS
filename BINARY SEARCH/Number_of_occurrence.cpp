/*
Given a sorted array Arr
 of size N and a number X, you need to find the number of occurrences of X in Arr.
*/

/*
Input:
N = 7, X = 2
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 4
Explanation: 2 occurs 4 times in the
given array.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    // Function to count the occurrences of x in the sorted array arr[].
    int count(int arr[], int n, int x) {
        int start = 0;       // Initialize the starting index.
        int end = n - 1;     // Initialize the ending index.

        while (start <= end) { // Continue the search until the start index is less than or equal to the end index.
            int mid = (start + end) / 2; // Calculate the middle index.

            if (arr[start] == x && arr[end] == x) {
                // If the start and end elements are both x, all elements in the range are x.
                return end - start + 1;
            }

            if (arr[mid] == x) {
                if (arr[start] != x) {
                    start++; // Move the start index to the right if it's not equal to x.
                }
                if (arr[end] != x) {
                    end--; // Move the end index to the left if it's not equal to x.
                }
            } else if (arr[mid] > x) {
                end = mid - 1; // Adjust the end index to search in the left half.
            } else if (arr[mid] < x) {
                start = mid + 1; // Adjust the start index to search in the right half.
            }
        }
        return 0; // Return 0 if x is not found in the array.
    }
};

int main() {
    Solution solution;
    int arr[] = {2, 2, 2, 3, 4, 5, 6, 6, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 6;

    int result = solution.count(arr, n, x);

    cout << "Count of " << x << " in the array: " << result << endl;

    return 0;
}
