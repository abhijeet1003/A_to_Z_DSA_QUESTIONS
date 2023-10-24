/*
Given a Binary Search Tree. 
Your task is to complete the function which will return the Kth largest 
element without doing any modification in Binary Search Tree.
*/

/*
Input:
       9
        \ 
          10
K = 1
Output: 10
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
    // Function to count the number of nodes in the BST using an in-order traversal.
    void count(Node* root, int& nodecnt) {
        if (root == NULL) return;
        count(root->left, nodecnt);
        nodecnt++;
        count(root->right, nodecnt);
    }

    // Function to find the Kth largest element in the BST.
    int kthLargest(Node* root, int K) {
        int nodecnt = 0;
        count(root, nodecnt); // Count the total number of nodes in the BST.

        int largest = nodecnt - K + 1; // Calculate the position of the Kth largest element.
        nodecnt = 0; // Reset the node count.
        Node* curr = root;

        while (curr) {
            if (curr->left == NULL) {
                nodecnt++;
                if (nodecnt == largest) return curr->data; // If we reach the Kth largest element, return its data.
                curr = curr->right; // Move to the right subtree.
            } else {
                Node* last = curr->left;

                while (last->right != NULL && last->right != curr) last = last->right;

                if (last->right == NULL) {
                    last->right = curr;
                    curr = curr->left; // Move to the left subtree.
                } else {
                    last->right = NULL;
                    nodecnt++;
                    if (nodecnt == largest) return curr->data; // If we reach the Kth largest element, return its data.
                    curr = curr->right; // Move to the right subtree.
                }
            }
        }
        return -1; // Return -1 if the Kth largest element is not found.
    }
};

int main() {
    Solution solution;

    // Create a sample binary search tree for testing
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);

    int K = 3; // Find the 3rd largest element

    int result = solution.kthLargest(root, K);

    if (result != -1) {
        std::cout << "The " << K << "th largest element in the BST is: " << result << std::endl;
    } else {
        std::cout << "Kth largest element not found." << std::endl;
    }

    return 0;
}
