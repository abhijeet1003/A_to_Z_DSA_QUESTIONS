/*
You are given the root of a complete binary tree. Your task is to find the count of nodes.

A complete binary tree is a binary tree whose, all levels except the last one are completely filled, the last level may or may not be completely filled and Nodes in the last level are as left as possible.

Design an algorithm that runs better than O(n).
*/



/*
Input: 
root = [1,2,3,4,5,6]
Output: 
6
Explanation: 
There are a total of 6 nodes in the given tree.
*/


#include <iostream>
#include <cmath>
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
public:
    // Function to find the height of the left subtree
    int findheightleft(Node* root) {
        int h = 0;
        while (root) {
            h++;
            root = root->left;
        }
        return h;
    }

    // Function to find the height of the right subtree
    int findheightright(Node* root) {
        int h = 0;
        while (root) {
            h++;
            root = root->right;
        }
        return h;
    }

    // Function to count the number of nodes in the binary tree
    int countNodes(Node* root) {
        if (root == NULL) return 0; // Base case: If the tree is empty, return 0

        int lh = findheightleft(root->left); // Find the height of the left subtree
        int rh = findheightright(root->right); // Find the height of the right subtree

        // If the heights of the left and right subtrees are equal, the tree is a complete binary tree
        if (lh == rh) return pow(2, lh + 1) - 1;

        // If the tree is not complete, recursively count nodes in the left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main() {
    Solution solution;

    // Create a sample binary tree for testing
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Count the number of nodes in the binary tree
    int nodeCount = solution.countNodes(root);

    cout << "Number of nodes in the tree: " << nodeCount << endl;

    return 0;
}
