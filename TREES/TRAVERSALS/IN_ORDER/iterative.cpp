#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Define a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to perform inorder traversal of a binary tree
vector<int> inorderTraversal(Node* root) {
    // Create a vector to store the result
    vector<int> ans;

    // Create a stack to assist in traversal
    stack<Node*> st;

    // Start from the root node
    Node* node = root;

    while (true) {
        // Traverse the left subtree and push nodes onto the stack
        if (node != NULL) {
            st.push(node);
            node = node->left;
        } else {
            // If the stack is empty, we're done
            if (st.empty() == true) break;

            // Pop a node from the stack and add its data to the result vector
            node = st.top();
            st.pop();
            ans.push_back(node->data);

            // Move to the right subtree
            node = node->right;
        }
    }

    // Return the result vector containing inorder traversal
    return ans;
}