/*
Stuck on a problem? Level up with 35% Off on premium GfG Courses and master coding! 

banner
Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.
*/



/*
Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 
8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.
*/



#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

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
    // Function to calculate the minimum time to reach a target node
    int minTime(Node* root, int target) {
        std::unordered_map<Node*, Node*> parent; // Mapping of parent nodes
        mparent(root, parent); // Build the mapping

        Node* tar; // The target node
        findTarget(root, tar, target); // Find the target node

        std::unordered_map<Node*, bool> vis;
        int time = 0;
        std::queue<Node*> q;
        q.push(tar);
        vis[tar] = true; // Mark the target node as visited
        while (!q.empty()) {
            int size = q.size();
            time++;
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
        // When we were at the target node, we also increased the time, so at last just 
        // don't forget to remove that 1 extra time
        return time - 1;
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

    int min_time = solution.minTime(root, target);

    std::cout << "Minimum time to reach the target node " << target << ": " << min_time << std::endl;

    // Clean up the allocated memory (this part is not shown in the code)
    // You should delete the tree nodes to avoid memory leaks
    // DeleteTree(root);

    return 0;
}
