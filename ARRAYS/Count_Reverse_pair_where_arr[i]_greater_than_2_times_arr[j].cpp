//                              QUESTIONS

/*
Count Reverse Pairs
*/

/*
You are given an array of N integers arr, find the count of reverse pairs. 

A pair of indices (i, j) is said to be a reverse pair if both the following conditions are met:

 1.  0<= i < j < N 
2.  arr[i] > 2 * arr[j]

*/

/*
Input:
N = 6
arr = [3, 2, 4, 5, 1, 20]
Output:
3
Explanation:
The Reverse pairs are 
(i)  (0, 4), arr[0] = 3, arr[4] = 1, 3 > 2(1) 
(ii) (2, 4), arr[2] = 4, arr[4] = 1, 4 > 2(1) 
(iii)(3, 4), arr[3] = 5, arr[4] = 1, 5 > 2(1)
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int count = 0;

    // Merges two halves of the array and counts reverse pairs
    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; // Temporary array
        int left = low;    // Starting index of the left half of arr
        int right = mid + 1; // Starting index of the right half of arr

        // Storing elements in the temporary array in a sorted manner
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
                
                // When an element in the right half is smaller, it forms reverse pairs
                count = count + (mid - left + 1);
            }
        }

        // If elements on the left half are still left
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        // If elements on the right half are still left
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // Transferring all elements from the temporary array to arr
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    // Counts the number of reverse pairs
    void getCount(vector<int> &arr, int low, int mid, int high) {
        int right = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > 2 * arr[right]) {
                right++;
            }
            count = count + (right - (mid + 1));
        }
    }

    // Sorts the array using the merge sort algorithm and counts reverse pairs
    void mergeSort(vector<int> &arr, int low, int high) {
        if (low >= high) return;
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);  // Sort the left half
        mergeSort(arr, mid + 1, high); // Sort the right half
        getCount(arr, low, mid, high);  // Count the required inversion count
        merge(arr, low, mid, high);  // Merge sorted halves
    }

    // Main function to count reverse pairs
    int countRevPairs(int n, vector<int> arr) {
        mergeSort(arr, 0, n - 1);  // Sort the array and count reverse pairs
        return count;
    }
};

int main() {
    Solution solution;
    
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = solution.countRevPairs(n, arr);
    cout << "Count of reverse pairs: " << count << endl;

    return 0;
}
