//                           QUESTIONS
/*
Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order.
 Merge them in sorted order without using any extra space. Modify arr1 so that it contains
  the first N elements and modify arr2 so that it contains the last M elements.
*/


/*
Input: 
n = 4, arr1[] = [1 3 5 7] 
m = 5, arr2[] = [0 2 6 8 9]
Output: 
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]
Explanation:
After merging the two 
non-decreasing arrays, we get, 
0 1 2 3 5 6 7 8 9.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m) {
    int i = n - 1; // Initialize an index for the last element of the first array
    int j = 0;     // Initialize an index for the first element of the second array

    // Merge the two arrays
    while (i >= 0 && j < m) {
        if (arr1[i] > arr2[j]) {
            // Swap the elements if the element from the first array is greater
            swap(arr1[i], arr2[j]);
            i--; // Move to the next element in the first array
            j++; // Move to the next element in the second array
        } else {
            break; // If the element from the first array is not greater, exit the loop
        }
    }

    // Sort the merged arrays
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

int main() {
    int n, m;
    cout << "Enter the size of the first array (n): ";
    cin >> n;
    cout << "Enter the size of the second array (m): ";
    cin >> m;

    long long arr1[n], arr2[m];

    cout << "Enter " << n << " elements for the first array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cout << "Enter " << m << " elements for the second array: ";
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    merge(arr1, arr2, n, m);

    cout << "Merged array 1: ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "Merged array 2: ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}

