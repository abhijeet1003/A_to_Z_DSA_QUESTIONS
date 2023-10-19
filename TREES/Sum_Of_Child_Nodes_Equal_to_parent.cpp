#include <iostream>

// Definition of a binary tree node
class Node {
public:
    int data;
    Node* left, * right;
    Node() {
        this->data = 0;
        left = NULL;
        right = NULL;
    }
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

// Function to check if a binary tree follows the Parent Sum Property
bool isParentSum(Node* root) {
    // Check if the current node is a leaf node
    if (root->left == NULL && root->right == NULL)
        return true; // It follows the property by definition.

    int total = 0; // Initialize a variable to store the sum of child node values
    if (root->left)
        total += root->left->data; // Add the left child's value to the total
    if (root->right)
        total += root->right->data; // Add the right child's value to the total

    if (total == root->data) {
        bool a = true;
        bool b = true;
        if (root->left)
            a = isParentSum(root->left); // Recursively check the left subtree
        if (root->right)
            b = isParentSum(root->right); // Recursively check the right subtree
        return (a && b); // If both subtrees follow the property, the entire tree does.
    } else {
        return false; // If the property doesn't hold for the current node, return false.
    }
}

int main() {
    // Create a sample binary tree for testing
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);

    bool result = isParentSum(root);

    if (result) {
        std::cout << "The binary tree follows the Parent Sum Property." << std::endl;
    } else {
        std::cout << "The binary tree does not follow the Parent Sum Property." << std::endl;
    }

    // Clean up the allocated memory (this part is not shown in the code)
    // You should delete the tree nodes to avoid memory leaks
    // DeleteTree(root);

    return 0;
}
