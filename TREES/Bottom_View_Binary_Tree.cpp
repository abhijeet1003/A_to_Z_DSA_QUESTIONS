#include <iostream>
#include <vector>
#include <queue>
#include <map>

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to find the bottom view of a binary tree.
    std::vector<int> bottomView(Node *root) {
        std::vector<int> ans;                    // Create a vector to store the bottom view
        std::queue<std::pair<Node*, int>> q;    // Create a queue to perform level-order traversal
        std::map<int, int> mpp;                 // Create a map to store the last node at each horizontal line

        if (root == NULL) return ans;            // If the tree is empty, return an empty result
        q.push({root, 0});                      // Push the root node and its horizontal line position (initially 0)

        while (!q.empty()) {
            auto it = q.front();                 // Get the front element of the queue
            q.pop();
            Node *node = it.first;               // Extract the node
            int line = it.second;               // Extract the horizontal line position
            
            mpp[line] = node->data;             // Update the map with the data of the current node
            
            if (node->left) q.push({node->left, line - 1});   // Push the left child with line - 1
            if (node->right) q.push({node->right, line + 1}); // Push the right child with line + 1
        }

        for (auto it : mpp) {
            ans.push_back(it.second);           // Populate the result vector with the bottom view nodes
        }
        return ans;                             // Return the bottom view
    }
};

int main() {
    // Create a binary tree for testing (you can replace this with your tree)
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    Solution solution;

    std::vector<int> result = solution.bottomView(root);

    std::cout << "Bottom View of the Binary Tree: ";
    for (int val : result) {
        std::cout << val << " ";               // Print the bottom view nodes
    }
    std::cout << std::endl;

    return 0;
}
