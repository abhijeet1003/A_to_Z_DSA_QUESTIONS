/*
Given a Binary Search Tree (with all values unique) 
and two node values n1 and n2 (n1!=n2). Find the Lowest Common Ancestors of
 the two nodes in the BST.
*/


/*
Input:
              5
            /   \
          4      6
         /        \
        3          7
                    \
                     8
n1 = 7, n2 = 8
Output: 7
*/

#include <iostream>

// Definition of a binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to find the Lowest Common Ancestor (LCA) of two nodes with values n1 and n2.
    Node* LCA(Node *root, int n1, int n2)
    {
        if(root == NULL) return NULL; // If the root is null, there is no LCA.
        int curr = root->data; // Get the data value of the current node.
        if(curr > n1 && curr > n2) {
            return LCA(root->left, n1, n2); // If both n1 and n2 are smaller, the LCA is in the left subtree.
        }
        if(curr < n1 && curr < n2) {
            return LCA(root->right, n1, n2); // If both n1 and n2 are larger, the LCA is in the right subtree.
        }
        return root; // Otherwise, the current node is the LCA.
    }
};

int main() {
    Solution solution;

    // Create a sample binary tree for testing
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(35);

    int n1 = 5;
    int n2 = 15;

    Node* lca = solution.LCA(root, n1, n2);

    if (lca != NULL) {
        std::cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " is: " << lca->data << std::endl;
    } else {
        std::cout << "Lowest Common Ancestor not found." << std::endl;
    }

    return 0;
}
