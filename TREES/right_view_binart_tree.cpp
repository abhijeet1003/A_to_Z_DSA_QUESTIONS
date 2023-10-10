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
    // Recursive helper function to obtain the right view elements of the binary tree
    void recursion(Node *root, int level, vector<int> &res) {
        if (root == NULL) return;

        if (res.size() == level) res.push_back(root->data); // Add the rightmost element at each level
        recursion(root->right, level + 1, res); // Recursively process the right subtree
        recursion(root->left, level + 1, res); // Recursively process the left subtree
    }

    // Function to return a list containing elements of the right view of a binary tree.
    vector<int> rightView(Node *root) {
        vector<int> res; // Initialize the result vector
        recursion(root, 0, res); // Call the recursive helper function to obtain the right view
        return res; // Return the right view elements
    }
};

int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    Solution solution;

    // Call the rightView function to obtain the right view of the binary tree
    vector<int> rightViewResult = solution.rightView(root);

    // Display the right view of the binary tree
    cout << "Right View of the Binary Tree: ";
    for (int val : rightViewResult) {
        cout << val << " "; // Print each element of the right view
    }
    cout << endl;

    return 0; // Return 0 to indicate successful program execution
}
