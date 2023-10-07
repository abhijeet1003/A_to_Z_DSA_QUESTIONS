//                      QUESTIONS



/*

Given a Binary Tree, find its Boundary Traversal. The traversal should 
be in the following order: 


Left boundary nodes: defined as the path from the root to the left-most 
node ie- the leaf node you could reach when you always travel preferring
 the left subtree over the right subtree. 


Leaf nodes: All the leaf nodes except for the ones that are part of left
 or right boundary.


Reverse right boundary nodes: defined as the path from the right-most node
 to the root. The right-most node is the leaf node you could reach when you 
 always travel preferring the right subtree over the left subtree. Exclude the
 root from this as it was already included in the traversal of left boundary nodes.


Note: If the root doesn't have a left subtree or right subtree, then the root
 itself is the left or right boundary. 

*/


#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    // Function to check if a given node is a leaf node (has no children).
    bool isLeaf(Node *root) {
        // Check if both left and right child pointers are NULL.
        if (root->left != NULL || root->right != NULL) {
            return false; // Node has at least one child.
        } else {
            return true; // Node is a leaf (no children).
        }
    }

    // Function to add the left boundary nodes to the result vector.
    void addLeftBoundary(Node* root, vector<int> &res) {
        Node* curr = root->left;
        while (curr) {
            // Add non-leaf nodes to the result.
            if (isLeaf(curr) == false) {
                res.push_back(curr->data);
            }
            if (curr->left != NULL) {
                curr = curr->left; // Move to the left child.
            } else {
                curr = curr->right; // Move to the right child.
            }
        }
    }

    // Function to add the right boundary nodes to the result vector.
    void addRightBoundary(Node* root, vector<int> &res) {
        Node* curr = root->right;
        vector<int> temp;

        while (curr) {
            // Add non-leaf nodes to the temporary vector.
            if (isLeaf(curr) == false) {
                temp.push_back(curr->data);
            }
            if (curr->right != NULL) {
                curr = curr->right; // Move to the right child.
            } else {
                curr = curr->left; // Move to the left child.
            }
        }

        // Add the temporary vector in reverse order to the result.
        for (int i = temp.size() - 1; i >= 0; i--) {
            res.push_back(temp[i]);
        }
    }

    // Function to add the leaf nodes to the result vector.
    void addLeaves(Node* root, vector<int> &res) {
        if (isLeaf(root) == true) {
            res.push_back(root->data); // Node is a leaf, add to the result.
            return;
        }
        if (root->left) {
            addLeaves(root->left, res); // Recursively process left subtree.
        }
        if (root->right) {
            addLeaves(root->right, res); // Recursively process right subtree.
        }
    }

public:
    // Function to return the boundary nodes of a binary tree in anticlockwise order.
    vector<int> boundary(Node *root) {
        vector<int> res; // Initialize the result vector.
        if (root == NULL) {
            return res; // If the tree is empty, return an empty result.
        }

        // If the root is not a leaf, add it to the result.
        if (isLeaf(root) == false) {
            res.push_back(root->data);
        }

        // Add left boundary, leaves, and right boundary to the result.
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res; // Return the final result vector.
    }
};

int main() {
    // Create the binary tree for testing
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;
    vector<int> result = solution.boundary(root);

    cout << "Boundary nodes in anticlockwise order: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory (don't forget to delete allocated nodes)
    // ...

    return 0;
}
