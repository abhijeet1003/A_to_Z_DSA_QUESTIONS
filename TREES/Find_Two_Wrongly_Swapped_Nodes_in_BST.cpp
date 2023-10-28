/*
You are given the root of a binary search tree(BST), where exactly two nodes were swapped by mistake.
 Fix (or correct) the BST by swapping them back. Do not change the structure of the tree.

Note: It is guaranteed that the given input will form BST, except for 2 nodes that will be wrong.
 All changes must be reflected in the original linked list.
*/

/*
Input:
         11
       /    \
      3      17
       \    /
        4  10
Output: 1 
Explanation: 
By swapping nodes 11 and 10, the BST 
can be fixed.
*/

#include <iostream>
#include <algorithm>  // Include the algorithm header for swap function
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    Node* first;
    Node* middle;
    Node* prev;
    Node* last;

    // Helper function to perform in-order traversal and identify misplaced nodes
        // Helper function to perform in-order traversal and identify misplaced nodes
void inorder(Node* root) {
    if (root == nullptr) return;

    // Traverse the left subtree
    inorder(root->left);

    // Check for misplaced nodes in the current node and update pointers
    if (prev != nullptr && root->data < prev->data) {
        if (first == nullptr) {
            first = prev;   // Set 'first' to the first misplaced node
            middle = root;  // Set 'middle' to the current misplaced node
        } else {
            last = root;    // Set 'last' to the last misplaced node
        }
    }

    prev = root;  // Update 'prev' to the current node

    // Traverse the right subtree
    inorder(root->right);
}


public:
    // Function to correct a BST (Binary Search Tree)
    void correctBST(Node* root) {
        first = middle = last = prev = nullptr;
        inorder(root);

        if (last) {
            // Swap the first and last misplaced elements
            swap(first->data , last->data); 
        } else {
            // Swap the first and middle misplaced elements
            swap(first->data , middle->data);
        }
    }
};

int main() {
    // Create a binary search tree with a violation
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(5);

    // Initialize the Solution class and correct the BST
    Solution solver;
    solver.correctBST(root);

    cout << "Corrected BST In-order Traversal: " << std::endl;
    // Perform an in-order traversal to check if the BST is corrected
    

    // Don't forget to free the allocated memory (implement your own logic for memory deallocation).
    return 0;
}
