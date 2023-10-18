/*
Given a Binary Tree of size N, 
you need to find all the possible paths from root node to all the leaf node's of the binary tree.
*/


/*
Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 10 20 40 #10 20 60 #10 30 #
*/


#include <iostream>
#include <vector>

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to find all root-to-leaf paths in a binary tree
void path(Node* root, std::vector<std::vector<int>>& ans, std::vector<int> temp) {
    if (root == NULL)
        return;

    // Add the current node's data to the path
    temp.push_back(root->data);

    // If it's a leaf node, add the path to the answer
    if (!root->left && !root->right) {
        ans.push_back(temp);
        return;
    }

    // Recur on the left and right subtrees
    path(root->left, ans, temp);
    path(root->right, ans, temp);
}

// Function to find all root-to-leaf paths in a binary tree and return them
std::vector<std::vector<int>> Paths(Node* root) {
    std::vector<std::vector<int>> ans;
    std::vector<int> temp;

    // Call the path function to populate 'ans'
    path(root, ans, temp);

    return ans;
}

int main() {
    // Create a binary tree for testing
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Find all root-to-leaf paths in the binary tree
    std::vector<std::vector<int>> result = Paths(root);

    // Display the found paths
    for (const std::vector<int>& path : result) {
        for (int nodeValue : path) {
            std::cout << nodeValue << " -> ";
        }
        std::cout << "NULL" << std::endl;
    }

    return 0;
}
