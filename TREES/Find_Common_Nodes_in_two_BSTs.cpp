/*
Given two Binary Search Trees. Find the nodes that are common in both of them, ie- find the intersection of the two BSTs.

Note: Return the common nodes in sorted order.
*/

/*
Input:
BST1:
                  5
               /     \
             1        10
           /   \      /
          0     4    7
                      \
                       9
BST2:
                10 
              /    \
             7     20
           /   \ 
          4     9
Output: 4 7 9 10
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Define the structure for a Binary Tree Node.
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    // Function to traverse the first BST and populate a map.
    void f(Node* root, unordered_map<int, int>& mp) {
        if (!root)
            return;
        mp[root->data]++;
        f(root->left, mp);
        f(root->right, mp);
    }
    
    // Function to find common nodes between two BSTs.
    void final(Node* root, unordered_map<int, int>& mp, vector<int>& ans) {
        if (!root)
            return;
        
        final(root->left, mp, ans);
        if (mp.find(root->data) != mp.end())
            ans.push_back(root->data);
        final(root->right, mp, ans);
    }
    
    vector<int> findCommon(Node* root1, Node* root2) {
        vector<int> ans;
        unordered_map<int, int> mp;
        
        // Populate the map with values from the first BST.
        f(root1, mp);
        
        // Find common nodes in the second BST and add them to the answer vector.
        final(root2, mp, ans);
        
        return ans;
    }
};

int main() {
    Solution solution;

    // Example usage:
    // Create your BSTs and call the findCommon function here.
    
    // Node* root1 = new Node(5);
    // root1->left = new Node(2);
    // root1->right = new Node(8);
    // ...
    
    // Node* root2 = new Node(8);
    // root2->left = new Node(2);
    // root2->right = new Node(12);
    // ...

    // Call findCommon to find common nodes between the two trees.
    vector<int> commonNodes = solution.findCommon(root1, root2);

    cout << "Common Nodes: ";
    for (int node : commonNodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
