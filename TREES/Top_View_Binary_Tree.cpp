#include <iostream>  // Standard input/output library
#include <vector>    // Vector container library
#include <queue>     // Queue container library
#include <map>       // Map container library

// Define the structure of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    std::vector<int> topView(Node* root) {
        std::vector<int> ans;  // Initialize an empty vector to store top view nodes
        std::queue<std::pair<Node*, int>> q;  // Initialize a queue for level order traversal
        if (root == nullptr) return ans;  // Return an empty vector if the tree is empty

        std::map<int, int> mpp;  // Initialize a map to store nodes at each horizontal distance

        q.push({root, 0});  // Push the root node and its horizontal distance (0) into the queue
        while (!q.empty()) {  // Loop until the queue is empty
            auto it = q.front();  // Get the front element of the queue
            q.pop();  // Remove the front element from the queue

            Node* node = it.first;  // Extract the node
            int line = it.second;  // Extract the horizontal distance

            if (mpp.find(line) == mpp.end()) mpp[line] = node->data;  // Store the first node encountered at this horizontal distance

            if (node->left) q.push({node->left, line - 1});  // Push the left child with a decremented horizontal distance
            if (node->right) q.push({node->right, line + 1});  // Push the right child with an incremented horizontal distance
        }

        for (auto it : mpp) {
            ans.push_back(it.second);  // Store the top view nodes in the answer vector
        }
        return ans;  // Return the vector containing top view nodes
    }
};

int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);

    Solution solution;

    std::vector<int> topViewNodes = solution.topView(root);

    std::cout << "Nodes visible from top view (left to right): ";
    for (int val : topViewNodes) {
        std::cout << val << " ";  // Print the top view nodes
    }
    std::cout << std::endl;

    // Clean up memory (free the allocated nodes)
    delete root->left->right->right;
    delete root->left->right;
    delete root->left;
    delete root;

    return 0;  // Return 0 to indicate successful program execution
}
