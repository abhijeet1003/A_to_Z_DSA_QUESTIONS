/*
Given a Binary Tree with all unique values and two nodes value, n1 and n2. 
The task is to find the lowest common ancestor of the given two nodes. We may assume that either
 both n1 and n2 are present in the tree or none of them are present.

LCA: It is the first common ancestor of both the nodes n1 and n2 
from bottom of tree.
*/


/*
Input:
n1 = 3 , n2 = 4
           5    
          /    
         2  
        / \  
       3   4
Output: 2
Explanation:
LCA of 3 and 4 is 2. 
*/


#include <iostream>

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Class to implement a solution for finding the lowest common ancestor in a binary tree
class Solution {
public:
    // Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root, int n1, int n2) {
        // If the root is NULL or one of the target values is found at the root, return the root.
        if (root == NULL || root->data == n1 || root->data == n2) {
            return root;
        }

        // Recursively find the lowest common ancestor in the left subtree.
        Node* left = lca(root->left, n1, n2);
        // Recursively find the lowest common ancestor in the right subtree.
        Node* right = lca(root->right, n1, n2);

        // If the left result is NULL, return the right result.
        if (left == NULL) return right;
        // If the right result is NULL, return the left result.
        else if (right == NULL) return left;
        // If both left and right results are not NULL, the current root is the lowest common ancestor.
        else {
            return root;
        }
    }
};

int main() {
    // Create a sample binary tree for testing
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    Solution solution;
    int n1 = 5;
    int n2 = 1;
    
    // Find the lowest common ancestor of n1 and n2 using the lca function
    Node* result = solution.lca(root, n1, n2);

    // Print the result
    std::cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " is: " << result->data << std::endl;

    // Clean up the allocated memory (this part is not shown in the code)
    // You should delete the tree nodes to avoid memory leaks
    // DeleteTree(root);

    return 0;
}
