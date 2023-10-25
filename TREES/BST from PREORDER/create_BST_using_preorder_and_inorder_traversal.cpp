
#include <unordered_map>
#include<iostream>
using namespace std;
#include<vector>
#include <algorithm> 
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive function to build a binary tree from preorder and inorder traversal arrays.
TreeNode* build(
    vector<int>& preorder, int prestart, int preend,
    vector<int>& inorder, int instart, int inend,
    unordered_map<int, int>& mpp) {

    // Base case: If the start indices are greater than the end indices, return NULL.
    if (prestart > preend || instart > inend) {
        return nullptr;
    }

    // Create a new TreeNode with the value from the current preorder element.
    TreeNode* node = new TreeNode(preorder[prestart]);

    // Find the index of the current node's value in the inorder traversal.
    int inroot = mpp[node->val];

    // Calculate the number of nodes on the left side of the current node.
    int numsleft = inroot - instart;

    // Recursively build the left and right subtrees.
    node->left = build(preorder, prestart + 1, prestart + numsleft, inorder, instart, inroot - 1, mpp);
    node->right = build(preorder, prestart + numsleft + 1, preend, inorder, inroot + 1, inend, mpp);

    return node;
}

// Function to construct a binary tree from a preorder traversal.
TreeNode* preOrderTree(vector<int>& preorder) {
    // Create a copy of the preorder as inorder to sort it and build a map for easy lookup.
    vector<int> inorder = preorder;
    sort(inorder.begin(),inorder.end());
    // Create a map to store the indices of values in the inorder traversal.
    unordered_map<int, int> mpp;
    for (int i = 0; i < inorder.size(); i++) {
        mpp[inorder[i]] = i;
    }

    // Call the build function to construct the binary tree.
    return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mpp);
}

int main() {
    // Example usage and testing can be done here.
    return 0;
}
