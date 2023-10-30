/*
A sorted(in ascending order) array A[ ] with distinct elements
 is rotated at some unknown point, the task is to find the minimum element in it.
*/


/*
Input:
N = 7
arr[] = {10, 20, 30, 40, 50, 5, 7}
Output: 5
Explanation: Here 5 is the minimum element.
*/

#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    // Function to find the minimum element in a rotated sorted array.
    int findMin(int arr[], int n) {
        int low = 0;
        int high = n - 1;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[low] <= arr[mid]) {
                // If the left subarray is sorted, update the minimum value.
                ans = min(ans, arr[low]);
                low = mid + 1;
            } else {
                // If the right subarray is sorted, update the minimum value.
                ans = min(ans, arr[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution solution;
    int minValue = solution.findMin(arr, n);

    cout << "Minimum value in the rotated sorted array: " << minValue << endl;

    return 0;
}
