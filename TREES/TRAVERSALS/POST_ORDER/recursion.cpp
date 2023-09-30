
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

// Recursive function to perform postorder traversal
void postorderTraversal(Node* root, vector<int>& ans) {
    // Base case: If the node is NULL, return
    if (root == NULL) return;

    // Recursively traverse the left subtree
    postorderTraversal(root->left, ans);

    // Recursively traverse the right subtree
    postorderTraversal(root->right, ans);

    // Add the current node's data to the result vector
    ans.push_back(root->data);
}

// Function to return a list containing the postorder traversal of the tree.
vector<int> postOrder(Node* root) {
    // Create a vector to store the result
    vector<int> ans;

    // Call the recursive postorderTraversal function to populate the result vector
    postorderTraversal(root, ans);

    // Return the result vector containing postorder traversal
    return ans;
}