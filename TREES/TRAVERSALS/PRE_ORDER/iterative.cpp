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

class Solution {
public:
    // Function to perform iterative pre-order traversal
    vector<int> iterativePreOrderTraversal(Node* root) {
        vector<int> res;          // Create a vector to store the result
        stack<Node*> st;          // Create a stack for iterative traversal

        if (root == NULL)         // Check if the root is NULL, return an empty result
            return res;

        st.push(root);            // Push the root node onto the stack

        while (!st.empty()) {     // Start iterative pre-order traversal
            Node* node = st.top(); // Pop the top node from the stack
            st.pop();

            res.push_back(node->data);  // Add the node's data to the result vector

            if (node->right != NULL)    // Push the right child onto the stack (if exists)
                st.push(node->right);

            if (node->left != NULL)     // Push the left child onto the stack (if exists)
                st.push(node->left);
        }

        return res; // Return the result vector containing pre-order traversal
    }
};
