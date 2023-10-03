//  Question

/*
Given an unsorted array Arr of N positive and negative numbers. Your task is to 
create an array of alternate positive and negative numbers without changing the 
relative order of positive and negative numbers.
Note: Array should start with a positive number and 0 (zero) should be considered a positive element.
*/

/*
Input: 
N = 9
Arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2}
Output:
9 -2 4 -1 5 -5 0 -3 2
*/

//  SOLUTIONS

#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution{
public:
    // Function to rearrange an array such that positive and negative elements alternate.
    void rearrange(int arr[], int n) {
        vector<int> posA, negA; // Create vectors to store positive and negative elements.

        // Separate positive and negative elements into different vectors.
        for(int i = 0; i < n; i++) {
            if(arr[i] >= 0) {
                posA.push_back(arr[i]); // Store positive elements in the positive vector.
            } else {
                negA.push_back(arr[i]); // Store negative elements in the negative vector.
            }
        }

        if(posA.size() > negA.size()) {
            // If there are more positive elements, arrange them alternately with negative elements.
            for(int i = 0; i < negA.size(); i++) {
                arr[2 * i] = posA[i];       // Place a positive element at even indices.
                arr[2 * i + 1] = negA[i];   // Place a negative element at odd indices.
            }

            int index = negA.size() * 2; // Start index for remaining positive elements.
            for(int i = negA.size(); i < posA.size(); i++) {
                arr[index] = posA[i];      // Place remaining positive elements in the array.
                index++;
            }
        } else {
            // If there are more negative elements, arrange them alternately with positive elements.
            for(int i = 0; i < posA.size(); i++) {
                arr[2 * i] = posA[i];       // Place a positive element at even indices.
                arr[2 * i + 1] = negA[i];   // Place a negative element at odd indices.
            }

            int index = posA.size() * 2; // Start index for remaining negative elements.
            for(int i = posA.size(); i < negA.size(); i++) {
                arr[index] = negA[i];      // Place remaining negative elements in the array.
                index++;
            }
        }
    }
};
