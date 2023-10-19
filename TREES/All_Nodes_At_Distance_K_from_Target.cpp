/*
Given a binary tree, a target node in the binary tree, and an integer value k, find all the nodes that are at distance k from the given target node. No parent pointers are available.
Note:

You have to return the list in sorted order.
The tree will not contain duplicate values.
*/


/*
Input:      
          20
        /    \
      8       22 
    /   \
   4    12 
       /   \
      10    14
    Target Node = 8
    K = 2
    Output: 10 14 22
    Explanation: The three nodes at distance 2
    from node 8 are 10, 14, 22.

Example 2:

Input:      
         20
       /    \
      7      24
    /   \
   4     3
        /  
       1    
    Target Node = 7
    K = 2
    Output: 1 24
*/


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    // Helper function to build a mapping of parent nodes
    void mparent(Node* root, std::unordered_map<Node*, Node*>& parent) {
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            if (curr->left) {
                parent[curr->left] = curr; // Store the parent of the left child
                q.push(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr; // Store the parent of the right child
                q.push(curr->right);
            }
        }
    }

    // Helper function to find the target node in the tree
    void findTarget(Node* root, Node*& tar, int target) {
        std::queue<Node*> find;
        find.push(root);
        while (!find.empty()) {
            Node* curr = find.front();
            find.pop();
            if (curr->data == target) {
                tar = curr; // Found the target node
                break;
            }
            if (curr->left) {
                find.push(curr->left);
            }
            if (curr->right) {
                find.push(curr->right);
            }
        }
    }

public:
    // Function to find nodes at a given distance k from a target node
    std::vector<int> KDistanceNodes(Node* root, int target, int k) {
        std::unordered_map<Node*, Node*> parent; // Mapping of parent nodes
        mparent(root, parent); // Build the mapping

        Node* tar; // The target node
        findTarget(root, tar, target); // Find the target node

        std::unordered_map<Node*, bool> vis; // Keep track of visited nodes
        int level = 0;
        std::queue<Node*> q;
        q.push(tar);
        vis[tar] = true; // Mark the target node as visited
        while (!q.empty()) {
            int size = q.size();
            if (level++ == k) break; // If we've reached the desired level, stop
            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

                if (curr->left && !vis[curr->left]) {
                    q.push(curr->left); // Add the left child to the queue
                    vis[curr->left] = true; // Mark it as visited
                }

                if (curr->right && !vis[curr->right]) {
                    q.push(curr->right); // Add the right child to the queue
                    vis[curr->right] = true; // Mark it as visited
                }
                if (parent[curr] && !vis[parent[curr]]) {
                    q.push(parent[curr]); // Add the parent to the queue
                    vis[parent[curr]] = true; // Mark it as visited
                }
            }
        }
        std::vector<int> res;
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            res.push_back(curr->data); // Collect nodes at the k-distance level
        }
        std::sort(res.begin(), res.end()); // Sort the result vector
        return res; // Return the nodes at distance k
    }
};

int main() {
    // Create a sample binary tree for testing
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    Solution solution;
    int target = 5;
    int k = 2;
    std::vector<int> result = solution.KDistanceNodes(root, target, k);

    std::cout << "Nodes at distance " << k << " from target " << target << ": ";
    for (int value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Clean up the allocated memory (this part is not shown in the code)
    // You should delete the tree nodes to avoid memory leaks
    // DeleteTree(root);

    return 0;
}
