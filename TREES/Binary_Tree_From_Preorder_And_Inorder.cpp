/*
Given 2 Arrays of Inorder and preorder traversal.
 The tree can contain duplicate elements. Construct a tree and print the Postorder traversal. 
*/

/*
Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5
*/

#include <iostream>
using namespace std;

// Definition of a binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    // Helper function to find the index of an element in the inorder array
    int findindex(int inorder[], int x, int end) {
        for (int i = end; i >= 0; i--) {
            if (inorder[i] == x) return i; // Return the index if found
        }
        return -1; // Return -1 if the element is not found
    }

    // Recursive function to build the binary tree
    Node* buildTree(int preorder[], int inorder[], int start, int end, int& ptr) {
        if (start > end) return nullptr; // Base case: If the subtree is empty, return NULL

        Node* newnode = new Node(preorder[ptr]); // Create a new node using the current preorder value
        int curr_ind = findindex(inorder, preorder[ptr], end); // Find the index of the current value in inorder

        ptr++; // Move to the next value in the preorder traversal

        // Recursively build the left and right subtrees
        newnode->left = buildTree(preorder, inorder, start, curr_ind - 1, ptr);
        newnode->right = buildTree(preorder, inorder, curr_ind + 1, end, ptr);

        return newnode; // Return the constructed node
    }

public:
    // Public function to build a binary tree from inorder and preorder traversals
    Node* buildTree(int in[], int pre[], int n) {
        int ptr = 0; // Initialize a pointer for the preorder traversal
        return buildTree(pre, in, 0, n - 1, ptr); // Call the recursive function to build the tree
    }
};

// Function to perform inorder traversal of the tree and print the elements
void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data << " "; // Print the data of the current node
        inorderTraversal(root->right);
    }
}

int main() {
    Solution solution;

    int inorder[] = {9, 3, 15, 20, 7};
    int preorder[] = {3, 9, 20, 15, 7};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    // Build the binary tree from the provided inorder and preorder traversals
    Node* root = solution.buildTree(inorder, preorder, n);

    cout << "Inorder traversal of the constructed tree: ";
    inorderTraversal(root); // Perform an inorder traversal to verify the tree
    cout << endl;

    return 0;
}
