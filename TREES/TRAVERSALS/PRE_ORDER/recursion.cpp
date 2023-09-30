#include<iostream>
using namespace std;
#include <vector>
#include <stack>

//  Define a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

void preorderTraversal(Node* node, vector<int>& ans) {
    // Base case: If the node is NULL, return
    if (node == NULL) return;

    // Add the current node's data to the result vector
    ans.push_back(node->data);

    // Recursively traverse the left subtree
    preorderTraversal(node->left, ans);

    // Recursively traverse the right subtree
    preorderTraversal(node->right, ans);
}

// Function to return a list containing the preorder traversal of the tree.
vector<int> preorder(Node* root) {
    // Create a vector to store the result
    vector<int> ans;

    // Call the recursive preorderTraversal function to populate the result vector
    preorderTraversal(root, ans);

    // Return the result vector containing preorder traversal
    return ans;
}
