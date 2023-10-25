#include <iostream>
#include <stack>
#include <algorithm> 
#include<iostream>
using namespace std;
class Solution {
public:
    // Function to check if the given array can represent a Binary Search Tree (BST).
    int canRepresentBST(int arr[], int N) {
        int k = 0; // Initialize a variable to keep track of the maximum value allowed in the left subtree.
        stack<int> st; // Create a stack to simulate the traversal of the BST.
        
        for (int i = 0; i < N; i++) {
            if (st.empty() || arr[i] < st.top()) {
                // If the stack is empty or the current element is smaller than the top of the stack,
                // it means it's part of the left subtree.
                if (k > arr[i])
                    return 0;  // If k is greater than the current element, the array cannot represent a BST.
                st.push(arr[i]); // Push the current element onto the stack.
            } else {
                // If the current element is greater than the top of the stack, it's part of the right subtree.
                while (!st.empty() && st.top() < arr[i]) {
                    // Pop elements from the stack and update k until we find the correct place for the current element.
                    k = st.top(); // Update k to the maximum value in the left subtree.
                    st.pop();
                }
                st.push(arr[i]); // Push the current element onto the stack.
            }
        }
        return 1;  // If the array can represent a BST, return 1; otherwise, return 0.
    }
};

int main() {
    Solution solution;
    int arr[] = {2, 4, 3};
    int N = sizeof(arr) / sizeof(arr[0]);

    int result = solution.canRepresentBST(arr, N);
    
    if (result == 1)
        cout << "The array can represent a Binary Search Tree." << endl;
    else
        cout << "The array cannot represent a Binary Search Tree." << endl;

    return 0;
}
