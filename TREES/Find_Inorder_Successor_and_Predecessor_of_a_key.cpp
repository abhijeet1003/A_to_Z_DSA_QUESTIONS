/*

There is BST given with the root node with the key part as an integer only.
 You need to find the in-order successor and predecessor of a given key. 
 If either predecessor or successor is not found, then set it to NULL.

Note:- In an inorder traversal the number just smaller than the target is
 the predecessor and the number just greater than the target is the successor.
*/


/*
Input:
        10
      /   \
     2    11
   /  \ 
  1    5
      /  \
     3    6
      \
       4
key = 8
Output: 
6 10
Explanation: 
In the given BST the inorder predecessor of 8 is 6 and inorder successor of 8 is 10.
*/

#include <iostream>

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int val) : key(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to find the predecessor and successor of a given key in a BST.
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        suc = NULL; // Initialize successor as NULL
        pre = NULL; // Initialize predecessor as NULL
        Node* curr = root;

        // Search for the key and set the successor and predecessor accordingly.
        while (curr != NULL) {
            if (key >= curr->key) {
                suc = curr;  // Set current node as successor
                curr = curr->right; // Move to the right sub-tree
            } else {
                pre = curr;  // Set current node as predecessor
                curr = curr->left; // Move to the left sub-tree
            }
        }
    }
};

int main() {
    Solution solution;
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    int key = 3;

    Node* pre = nullptr;
    Node* suc = nullptr;

    solution.findPreSuc(root, pre, suc, key);

    if (pre)
        std::cout << "Predecessor: " << pre->key << std::endl;
    else
        std::cout << "No predecessor found." << std::endl;

    if (suc)
        std::cout << "Successor: " << suc->key << std::endl;
    else
        std::cout << "No successor found." << std::endl;

    // Don't forget to free the allocated memory (implement your own logic for memory deallocation).
    return 0;
}
