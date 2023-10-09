#include <iostream>
#include <vector>
#include <queue>
#include <map>

// Define the structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to find the vertical order traversal of Binary Tree.
    std::vector<int> verticalOrder(Node* root) {
        // Create a queue for level-order traversal, and a map to store vertical and level-wise nodes
        std::queue<std::pair<Node*, std::pair<int, int>>> q;
        std::map<int, std::map<int, std::vector<int>>> nodes;

        std::vector<int> ans;  // Vector to store the final result
        if (root == nullptr)
            return ans;  // Return an empty result if the tree is empty

        q.push({root, {0, 0}});  // Push the root node into the queue with vertical and level coordinates

        while (!q.empty()) {
            auto it = q.front();  // Get the front element of the queue
            q.pop();  // Pop the front element
            Node* curr = it.first;  // Current node
            int vertical = it.second.first;  // Vertical coordinate
            int level = it.second.second;  // Level coordinate

            // Add the current node's data to the map of nodes with vertical and level coordinates
            nodes[vertical][level].push_back(curr->data);

            if (curr->left)
                q.push({curr->left, {vertical - 1, level + 1}});  // Push left child with adjusted coordinates
            if (curr->right)
                q.push({curr->right, {vertical + 1, level + 1}});  // Push right child with adjusted coordinates
        }

        // Extract nodes from the map and add them to the final result vector
        for (auto it : nodes) {
            for (auto p : it.second) {
                for (auto val : p.second) {
                    ans.push_back(val);
                }
            }
        }
        return ans;  // Return the vertical order traversal
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

    // Create a Solution object
    Solution solution;

    // Get the vertical order traversal
    std::vector<int> result = solution.verticalOrder(root);

    // Print the result
    std::cout << "Vertical Order Traversal: ";
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Clean up memory (free allocated nodes)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
