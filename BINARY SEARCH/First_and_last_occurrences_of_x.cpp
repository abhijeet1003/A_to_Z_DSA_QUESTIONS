/*
Given a sorted array arr containing n elements with possibly some duplicate, the task is to find the first and last occurrences of an element x in the given array.
Note: If the number x is not found in the array then return both the indices as -1.
*/

/*
Input:
n=9, x=5
arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
Output:  
2 5
Explanation: 
First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5. 
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    // Helper function to perform binary search
    int solve(int arr[], int start, int last, int key) {
        // If the start index is greater than the last index, return -1 (not found)
        if (start > last) {
            return -1;
        }
        
        // Calculate the middle index
        int mid = start + (last - start) / 2;

        // If the middle element matches the key, return its index
        if (arr[mid] == key) {
            return mid;
        }

        // If the middle element is less than the key, search the right half
        if (arr[mid] < key) {
            return solve(arr, mid + 1, last, key);
        }
        // If the middle element is greater than the key, search the left half
        else {
            return solve(arr, start, mid - 1, key);
        }
    }

public:
    // Function to find the positions of a target element in an array
    vector<int> find(int arr[], int n, int x) {
        vector<int> res;
        int last = n - 1;
        int start = 0;

        // Find the index of the target element using binary search
        int ans = solve(arr, start, last, x);
        int temp = ans;

        // If the target element is not found, push -1 to the result vector
        if (ans == -1) {
            res.push_back(ans);
        }

        // Find the leftmost occurrence of the target element
        while (arr[temp - 1] == x) {
            temp--;
        }

        // Find the rightmost occurrence of the target element
        while (arr[ans + 1] == x) {
            ans++;
        }

        // Push the leftmost and rightmost indices to the result vector
        res.push_back(temp);
        res.push_back(ans);

        return res;
    }
};

int main() {
    Solution solution;
    int arr[] = {1, 2, 2, 2, 3, 4, 4, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 4;

    // Call the find function to get the positions of the target element
    vector<int> result = solution.find(arr, n, x);

    cout << "Positions of " << x << " in the array: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
