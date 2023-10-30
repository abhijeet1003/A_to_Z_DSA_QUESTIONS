/*
Given an unsorted array Arr[] of N integers and an integer X,
 find floor and ceiling of X in Arr[0..N-1].

Floor of X is the largest element which is smaller than or equal to X.
 Floor of X doesn’t exist if X is smaller than smallest element of Arr[].

Ceil of X is the smallest element which is greater than or equal to X.
 Ceil of X doesn’t exist if X is greater than greatest element of Arr[].
*/

/*
Input:
N = 8, X = 10
Arr[] = {5, 6, 8, 9, 6, 5, 5, 6}
Output: 9 -1
Explanation:
Floor of 10 is 9 but ceil of 10 is not 
possible.
*/

#include <iostream>
#include <algorithm>
#include <utility>

namespace std;

// Function to find the floor and ceiling of a value x in a sorted array arr.
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // Sort the array in ascending order.
    sort(arr, arr + n);
    int low = 0;
    int high = n - 1;
    int floor = -1;
    int ceil = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x) {
            // If the middle element is greater or equal to x, update the ceiling.
            ceil = arr[mid];
            high = mid - 1;
        } else {
            // If the middle element is less than x, update the floor.
            floor = arr[mid];
            low = mid + 1;
        }
    }

    return {floor, ceil};
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements in the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int x;
    cout << "Enter the value to find floor and ceiling for: ";
    cin >> x;

    pair<int, int> result = getFloorAndCeil(arr, n, x);

    cout << "Floor of " << x << " is: " << result.first << endl;
    cout << "Ceiling of " << x << " is: " << result.second << endl;

    return 0;
}
