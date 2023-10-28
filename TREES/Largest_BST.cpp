/*
Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.
*/

/*
Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1
Explanation: There's no sub-tree with size
greater than 1 which forms a BST. All the
leaf Nodes are the BSTs with size equal
to 1.
*/


class node1
{
    public:
    int isbst;  // flag to indicate if the subtree is a binary search tree
    int size;   // size of the subtree
    int mini;     // minimum value in the subtree
    int maxi;     // maximum value in the subtree
};

// Recursive function to check if a binary tree is a binary search tree and return information about the subtree.
 node1 bst(struct Node *root)
{
    node1 x; // create a node1 struct
    if(root == NULL) {  // if the root is NULL (empty subtree)
        // set the attributes of x to represent an empty subtree
        x.isbst = 1;
        x.size = 0;
        x.mini = 1000000;
        x.maxi = 0;
        return x;  // return x
    }
     node1 left = bst(root->left);   // recursively call bst on the left subtree
     node1 right = bst(root->right); // recursively call bst on the right subtree
    if(left.isbst == 1 && right.isbst == 1 && root->data > left.maxi && root->data < right.mini) { // if both subtrees are binary search trees and the root value is within the range of the left and right subtrees
        // set the attributes of x to represent a binary search tree
        x.isbst = 1;
        x.size = 1 + left.size + right.size;  // size is the sum of sizes of left and right subtrees plus 1 for the root node
        x.maxi = max(root->data,right.maxi);      // maximum value is the maximum of the root value and the maximum of the right subtree
        x.mini = min(root->data,left.mini);       // minimum value is the minimum of the root value and the minimum of the left subtree
    }
    else {
        // set the attributes of x to represent a non-binary search tree
        x.isbst = 0;
        x.size = max(left.size,right.size);    // size is the maximum of the sizes of the left and right subtrees
        x.mini = 1000000;                         // invalid minimum value
        x.maxi = 0;                                // invalid maximum value
    }
    return x;  // return x
};

class Solution{
    public:
    int largestBst(Node *root)
    {
        return bst(root).size;   // call the bst function and return the size of the largest binary search tree
    }
};