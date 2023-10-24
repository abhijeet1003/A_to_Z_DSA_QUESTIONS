/*
Given a BST and an integer K. Find the Kth Smallest element in the BST using O(1) extra space
*/

/*
Input:
      2
    /   \
   1     3
K = 2
Output: 2
Explanation: 2 is the 2nd smallest element in the BST
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
    // Function to find the Kth smallest element in a BST.
    int KthSmallestElement(Node *root, int K) {
        Node* curr = root;
        int cnt = 0;
        
        while (curr) {
            if (curr->left == NULL) {
                cnt++;
                if (cnt == K) return curr->data; // If the count matches K, return the current node's data.
                curr = curr->right; // Move to the right subtree.
            } else {
                Node* last = curr->left;
                
                while (last->right != NULL && last->right != curr) last = last->right;
                
                if (last->right == NULL) {
                    last->right = curr;
                    curr = curr->left; // Move to the left subtree.
                } else {
                    cnt++;
                    if (cnt == K) return curr->data; // If the count matches K, return the current node's data.
                    last->right = NULL;
                    curr = curr->right; // Move to the right subtree.
                }
            }
        }
        
        return -1; // Return -1 if the Kth smallest element is not found.
    }
};

int main() {
    Solution solution;

    // Create a sample binary search tree for testing
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new  Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);

    int K = 3; // Find the 3rd smallest element

    int result = solution.KthSmallestElement(root, K);

    if (result != -1) {
        std::cout << "The " << K << "th smallest element in the BST is: " << result << std::endl;
    } else {
        std::cout << "Kth smallest element not found." << std::endl;
    }

    return 0;
}
