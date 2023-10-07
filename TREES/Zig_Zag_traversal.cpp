#include <iostream>  // Include the necessary standard library for input/output
#include <vector>    // Include the necessary standard library for vectors
#include <queue>     // Include the necessary standard library for queues

using namespace std;  // Allow the use of standard library components without prefixing with "std::"

// Define your Node class here (you should include its definition).

class Node {
public:
    int data;        // Data stored in the node
    Node* left;      // Pointer to the left child node
    Node* right;     // Pointer to the right child node

    Node(int val) : data(val), left(nullptr), right(nullptr) {}  // Constructor to initialize the node
};

class Solution {
public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> res;             // Create a vector to store the zigzag traversal result
        if (root == nullptr) return res;  // If the tree is empty, return an empty result
        queue<Node*> q;              // Create a queue for level-order traversal
        q.push(root);                // Enqueue the root node
        bool leftToRight = true;     // Initialize a flag for direction

        while (!q.empty()) {         // Continue until the queue is empty
            int size = q.size();     // Get the number of nodes at the current level
            vector<int> ans(size);  // Create a vector to store nodes at the current level

            for (int i = 0; i < size; i++) {  // Iterate through nodes at the current level
                Node* temp = q.front();      // Dequeue a node from the front of the queue
                q.pop();

                // Determine the index based on the zigzag direction
                int index = leftToRight ? i : (size - 1 - i);

                ans[index] = temp->data;  // Store the node's data in the appropriate index

                if (temp->left) {
                    q.push(temp->left);   // Enqueue the left child if it exists
                }
                if (temp->right) {
                    q.push(temp->right);  // Enqueue the right child if it exists
                }
            }
            leftToRight = !leftToRight;  // Toggle the direction for the next level

            for (auto it : ans) {
                res.push_back(it);       // Append nodes at the current level to the result
            }
        }
        return res;  // Return the zigzag traversal result
    }
};

int main() {
    // Create a sample binary tree for testing
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;           // Create an instance of the Solution class
    vector<int> result = solution.zigZagTraversal(root);  // Perform zigzag traversal

    cout << "ZigZag Traversal: ";
    for (int val : result) {
        cout << val << " ";  // Print each value in the zigzag traversal result
    }
    cout << endl;

    // Clean up memory (don't forget to delete allocated nodes)
    // ...

    return 0;  // Return 0 to indicate successful program execution
}
