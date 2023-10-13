//                                      QUESTIONS
/*
Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) 
the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

*/


/*
Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).
*/




#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // Function to merge two sorted subarrays arr[low..mid] and arr[mid+1..high] and count inversions.
    void merge(long long arr[], long long low, long long mid, long long high, long long int &count) {
        // Temporary vector to store merged elements.
        vector<long long> temp;

        long long left = low;
        long long right = mid + 1;

        // Merge elements from both subarrays into temp[] in sorted order.
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                count = count + (mid - left + 1);
                right++;
            }
        }

        // Copy the remaining elements of the left subarray (if any).
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        // Copy the remaining elements of the right subarray (if any).
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // Copy elements from temp[] back to arr[].
        for (long long i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    // Recursive function to perform merge sort and count inversions.
    void mergeSort(long long arr[], long long low, long long high, long long int &count) {
        if (low >= high)
            return;
        long long mid = (low + high) / 2;
        mergeSort(arr, low, mid, count);
        mergeSort(arr, mid + 1, high, count);
        merge(arr, low, mid, high, count);
    }

    // Function to count inversions in an array.
    long long int inversionCount(long long arr[], long long n) {
        long long int count = 0;
        mergeSort(arr, 0, n - 1, count);
        return count;
    }
};

int main() {
    Solution solution;

    long long n;
    cout << "Enter the size of the array: ";
    cin >> n;

    long long arr[n];
    cout << "Enter the elements of the array: ";
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long int count = solution.inversionCount(arr, n);
    cout << "Inversion Count: " << count << endl;

    return 0;
}
