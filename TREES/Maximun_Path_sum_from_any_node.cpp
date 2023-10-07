#include <iostream>  // Include the necessary standard library for input/output
#include <climits>   // Include the necessary standard library for INT_MIN
using namespace std;  // Allow the use of standard library components without prefixing with "std::"

// Define your Node class here (you should include its definition).

class Node {
public:
    int data;        // Data stored in the node
    Node* left;      // Pointer to the left child node
    Node* right;     // Pointer to the right child node

    Node(int val) : data(val), left(nullptr), right(nullptr) {}  // Constructor to initialize the node
};

class Solution {
public:
    int solve(Node* root, int& maxi) {
        if (root == NULL) return 0;  // If the node is null, return 0

        int lh = max(0, solve(root->left, maxi));
        int rh = max(0, solve(root->right, maxi));
        
        maxi = max(maxi, lh + rh + root->data);  // Update the maximum path sum if a new maximum is found

        return root->data + max(lh, rh);  // Return the maximum sum of the path including the current node
    }

    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root) {
        int maxi = INT_MIN;  // Initialize the maximum path sum to the smallest possible integer
        solve(root, maxi);   // Call the helper function to find the maximum path sum
        return maxi;         // Return the maximum path sum
    }
};

int main() {
    // Create a sample binary tree for testing
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    Solution solution;                      // Create an instance of the Solution class
    int result = solution.findMaxSum(root);  // Find the maximum path sum

    cout << "Maximum Path Sum: " << result << endl;  // Print the maximum path sum

    // Clean up memory (don't forget to delete allocated nodes)
    // ...

    return 0;  // Return 0 to indicate successful program execution
}
