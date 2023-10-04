

// QUESTIONS

/*
Implement the next permutation, which rearranges the list of numbers into Lexicographically
 next greater permutation of list of numbers. If such arrangement is not possible, it must be 
 rearranged to the lowest possible order i.e. sorted in an ascending order. You are given an 
 list of numbers arr[ ] of size N.
*/

/*
Input: N = 6
arr = {1, 2, 3, 6, 5, 4}
Output: {1, 2, 4, 3, 5, 6}
*/


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> nextPermutation(int n, vector<int> arr) {
        // Step 1: Find the index of the first element from the right that is smaller
        // than the element to its right. This is the index where the next permutation
        // will start from.
        int index = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] < arr[i + 1]) {
                index = i;
                break;
            }
        }

        // Step 2: If no such index is found, it means the array is in descending order,
        // and this is the largest permutation. So, reverse the array to get the smallest
        // permutation.
        if (index == -1) {
            reverse(arr.begin(), arr.end());
            return arr;
        }

        // Step 3: Find the smallest element to the right of the index that is greater
        // than the element at the index. Swap these two elements.
        for (int i = n - 1; i > index; i--) {
            if (arr[i] > arr[index]) {
                swap(arr[i], arr[index]);
                break;
            }
        }

        // Step 4: Reverse the subarray to the right of the index to get the next
        // lexicographically greater permutation.
        reverse(arr.begin() + index + 1, arr.end());

        // Return the updated array as the next permutation.
        return arr;
    }
};
