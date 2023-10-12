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
using namespace std;

class Solution {
public:
    // Function to swap elements between the arrays if necessary.
    void swapGreater(long long nums1[], long long nums2[], int idx1, int idx2) {
        if (nums1[idx1] > nums2[idx2])
            swap(nums1[idx1], nums2[idx2]);
    }

    // Function to merge two arrays.
    void merge(long long nums1[], long long nums2[], int n, int m) {
        // Calculate the total length of the merged array.
        int len = n + m;
        // Initialize the gap for comparing elements.
        int gap = (len / 2) + (len % 2);

        while (gap > 0) {
            int left = 0;
            int right = left + gap;

            while (right < len) {
                // Check which part of the arrays to compare and swap if needed.
                if (left < n && right >= n) {
                    swapGreater(nums1, nums2, left, right - n);
                } else if (left >= n && right >= n) {
                    swapGreater(nums2, nums2, left - n, right - n);
                } else {
                    swapGreater(nums1, nums1, left, right);
                }

                right++;
                left++;
            }

            if (gap == 1)
                break;
            gap = (gap / 2) + (gap % 2);
        }
    }
};

int main() {
    Solution solution;

    int n, m;
    cout << "Enter the size of the first array (n): ";
    cin >> n;
    cout << "Enter the size of the second array (m): ";
    cin >> m;

    long long nums1[n], nums2[m];

    cout << "Enter " << n << " elements for the first array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }

    cout << "Enter " << m << " elements for the second array: ";
    for (int i = 0; i < m; i++) {
        cin >> nums2[i];
    }

    // Call the merge function to merge the two arrays.
    solution.merge(nums1, nums2, n, m);

    cout << "Merged array 1: ";
    for (int i = 0; i < n; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;

    cout << "Merged array 2: ";
    for (int i = 0; i < m; i++) {
        cout << nums2[i] << " ";
    }
    cout << endl;

    return 0;
}
