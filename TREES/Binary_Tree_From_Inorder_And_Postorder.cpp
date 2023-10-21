/*
Given inorder and postorder traversals of a Binary Tree in the arrays in[] and post[] 
respectively. The task is to construct the binary tree from these traversals.
*/

/*
Input:
N = 8
in[] = 4 8 2 5 1 6 3 7
post[] =8 4 5 2 6 7 3 1
Output: 1 2 4 8 5 3 6 7
Explanation: For the given postorder and
inorder traversal of tree the  resultant
binary tree will be
           1
       /      \
     2         3
   /  \      /  \
  4    5    6    7
   \
     8
*/

#include <iostream>
#include <map>
using namespace std;

// Definition of a binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree using inorder and postorder traversals
Node* build(int inorder[], int instart, int inend, int postorder[], int poststart, int postend, map<int, int>& mpp) {
    if (poststart > postend || instart > inend) {
        return NULL; // Base case: If the traversals are empty or invalid, return NULL
    }

    Node* node = new Node(postorder[postend]); // Create a new node using the last element of postorder
    int inroot = mpp[postorder[postend]]; // Find the index of the root node in the inorder traversal
    int numsleft = inroot - instart; // Calculate the number of nodes in the left subtree

    // Recursively build the left and right subtrees
    node->left = build(inorder, instart, inroot - 1, postorder, poststart, poststart + numsleft - 1, mpp);
    node->right = build(inorder, inroot + 1, inend, postorder, poststart + numsleft, postend - 1, mpp);

    return node; // Return the constructed node
}

// Function to build a binary tree from inorder and postorder traversals
Node* buildTree(int inorder[], int postorder[], int n) {
    map<int, int> mpp;

    // Create a mapping of values to their positions in the inorder traversal
    for (int i = 0; i < n; i++) {
        mpp[inorder[i]] = i;
    }

    // Start building the tree from the root node
    return build(inorder, 0, n - 1, postorder, 0, n - 1, mpp);
}

// Function for inorder traversal to verify the constructed tree
void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left); // Recursively traverse the left subtree
        cout << root->data << " "; // Print the data of the current node
        inorderTraversal(root->right); // Recursively traverse the right subtree
    }
}

int main() {
    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    // Build the binary tree from the provided inorder and postorder traversals
    Node* root = buildTree(inorder, postorder, n);

    cout << "Inorder traversal of the constructed tree: ";
    inorderTraversal(root); // Perform an inorder traversal to verify the tree
    cout << endl;

    return 0;
}
