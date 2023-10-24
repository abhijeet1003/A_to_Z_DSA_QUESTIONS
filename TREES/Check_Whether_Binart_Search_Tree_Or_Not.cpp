#include <iostream>
#include <climits> // Include for INT_MIN and INT_MAX

// Definition of a binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
/*
Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
A BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/


/*
Input:
  2
   \
    7
     \
      6
       \
        5
         \
          9
           \
            2
             \
              6
Output: 0 
Explanation: 
Since the node with value 7 has right subtree 
nodes with keys less than 7, this is not a BST.
*/




class Solution {
public:
    // Recursive function to check if a binary tree is a BST within a specified range.
    bool valid(Node* root, int min, int max) {
        if (root == NULL) return true; // If the node is null, it's a valid BST.

        // Check if the current node's value is within the valid range.
        if (root->data <= min || root->data >= max) return false;

        // Recursively check the left and right subtrees with updated range constraints.
        return (valid(root->left, min, root->data) && valid(root->right, root->data, max));
    }

    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        // Call the 'valid' function with the initial range constraints of INT_MIN and INT_MAX.
        return valid(root, INT_MIN, INT_MAX);
    }
};

int main() {
    Solution solution;

    // Create a sample binary tree for testing
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    // Call the 'isBST' function to check if the tree is a Binary Search Tree (BST).
    bool isBSTResult = solution.isBST(root);

    // Print the result to the console.
    if (isBSTResult) {
        std::cout << "The given binary tree is a Binary Search Tree (BST)." << std::endl;
    } else {
        std::cout << "The given binary tree is not a Binary Search Tree (BST)." << std::endl;
    }

    return 0;
}
