/*
Given a sorted and rotated array A of N elements which 
is rotated at some point, and may contain duplicates and given an
 element key. Check whether the key exist in the array A or not.
*/

/*
Input:
N = 7
A[] = {2,5,6,0,0,1,2}
key = 0
Output:
1
Explanation:
0 is found at index 3.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to search for a key in a rotated sorted array.
    bool Search(int N, vector<int>& A, int key) {
        int low = 0;
        int high = N - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (A[mid] == key)
                return true;  // Key found in the array.

            // Handling the case when elements at low, mid, and high are equal.
            if (A[low] == A[mid] && A[mid] == A[high]) {
                low++;
                high--;
                continue;
            }

            if (A[low] <= A[mid]) {
                // Check if the key is in the left half.
                if (A[low] <= key && key <= A[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                // Check if the key is in the right half.
                if (A[mid] <= key && key <= A[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return false;  // Key not found in the array.
    }
};

int main() {
    int N = 8;
    vector<int> A = {2, 5, 6, 0, 0, 1, 2, 2};
    int key = 0;

    Solution solution;
    bool found = solution.Search(N, A, key);

    if (found)
        cout << "Key " << key << " found in the array." << endl;
    else
        cout << "Key " << key << " not found in the array." << endl;

    return 0;
}
