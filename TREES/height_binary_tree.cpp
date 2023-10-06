// QUESTIONS

/*
Given a binary tree, find its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path
 from the root node down to the farthest leaf node.
*/

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution{
public:
    /*You are required to complete this method*/

    // Function to calculate the maximum depth (height) of a binary tree.
    int maxDepth(Node *root) {
        // If the root node is NULL, return a depth of 0 (base case).
        if(root == NULL) return 0;
        
        // Recursively calculate the maximum depth of the left subtree.
        int lh = maxDepth(root->left);
        
        // Recursively calculate the maximum depth of the right subtree.
        int rh = maxDepth(root->right);
        
        // Return 1 plus the maximum depth between the left and right subtrees.
        // This accounts for the current level of the tree.
        return 1 + max(lh, rh);
    }
};
