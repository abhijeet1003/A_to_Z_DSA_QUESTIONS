#include <iostream>
#include <vector>

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
    // Recursive helper function to obtain the left view elements of the binary tree
    void recursion(Node* root, int level, vector<int>& res) {
        if (root == NULL) return;

        if (res.size() == level) res.push_back(root->data); // Add the leftmost element at each level
        recursion(root->left, level + 1, res); // Recursively process the left subtree
        recursion(root->right, level + 1, res); // Recursively process the right subtree
    }

    // Function to return a list containing elements of the left view of a binary tree.
    vector<int> leftView(Node* root) {
        vector<int> res; // Initialize the result vector
        recursion(root, 0, res); // Call the recursive helper function to obtain the left view
        return res; // Return the left view elements
    }
};

int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;

    // Call the leftView function to obtain the left view of the binary tree
    vector<int> leftViewResult = solution.leftView(root);

    // Display the left view of the binary tree
    cout << "Left View of the Binary Tree: ";
    for (int val : leftViewResult) {
        cout << val << " "; // Print each element of the left view
    }
    cout << endl;

    return 0; // Return 0 to indicate successful program execution
}
