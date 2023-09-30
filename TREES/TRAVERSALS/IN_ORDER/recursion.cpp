#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// Define a Node of tree
 struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 

class Solution {

public:
    // Helper function to perform the inorder traversal and store values in 'ans'
    void inorderTraversal(Node* node, vector<int>& ans) {
        if (node == NULL)
            return;

        // Traverse the left subtree
        inorderTraversal(node->left, ans);

        // Add the current node's data to 'ans'
        ans.push_back(node->data);

        // Traverse the right subtree
        inorderTraversal(node->right, ans);
    }

    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int> ans;  // Create a vector to store the inorder traversal result
        inorderTraversal(root, ans);  // Call the helper function to perform the traversal
        return ans;  // Return the result
    }
};
