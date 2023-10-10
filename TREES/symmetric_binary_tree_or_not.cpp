#include <iostream>

using namespace std;

// Definition of the Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Helper function to check if two subtrees are symmetric
    bool check(Node* root1, Node* root2) {
        if (root1 == NULL || root2 == NULL) {
            // If one root is null, the other must be null for the condition to be true
            return root1 == root2;
        }

        // If data is not equal, return false
        if (root1->data != root2->data) return false;

        // Recursively check the left subtree of root1 with the right subtree of root2
        // and the right subtree of root1 with the left subtree of root2
        return check(root1->left, root2->right) &&
        // kyuki mirror me aapna left samne vale ka right or aapna right
        // samne vake ka left hota hai
               check(root1->right, root2->left);
    }

    // Function to check if a binary tree is symmetric
    bool isSymmetric(struct Node* root) {
        // If the root is null, we will return true
        if (root == NULL) return true;

        // Call the check function for the left and right subtrees simultaneously
        return check(root->left, root->right);
    }
};

int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    Solution solution;

    // Check if the binary tree is symmetric
    bool isSymmetric = solution.isSymmetric(root);

    // Display the result
    if (isSymmetric) {
        cout << "The binary tree is symmetric." << endl;
    } else {
        cout << "The binary tree is not symmetric." << endl;
    }

    return 0;
}
