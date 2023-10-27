/*
Given a Binary Search Tree and a target sum.
 Check whether there's a pair of Nodes in the BST with value summing up to the target sum. 
*/


/*
Input:
           6
          /    
         5     
        /
       3 
     /  \
    1    4
sum = 2
Output: 0 
Explanation: 
There's no pair that sums up to 2.
*/





#include <iostream>
#include <stack>
using namespace std;

// Definition of a Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    stack<Node*> stnext;  // Stack for traversing nodes in increasing order
    stack<Node*> stprev;  // Stack for traversing nodes in decreasing order
    
    // Helper function to push all left nodes to the stnext stack
    void pushAllnext(Node* root) {
        while (root) {
            stnext.push(root);
            root = root->left;
        }
    }
    
    // Helper function to push all right nodes to the stprev stack
    void pushAllprev(Node* root) {
        while (root) {
            stprev.push(root);
            root = root->right;
        }
    }
    
    // Function to get the next element in increasing order
    int next() {
        Node* node = stnext.top();
        stnext.pop();
        pushAllnext(node->right);
        return node->data;
    }
    
    // Function to get the previous element in decreasing order
    int before() {
        Node* node = stprev.top();
        stprev.pop();
        pushAllprev(node->left);
        return node->data;
    }
    
    bool hasNext() {
        return !stnext.empty();
    }
    
    bool hasprev() {
        return !stprev.empty();
    }


    // Function to check if there is a pair of elements in the BST that sum up to the target
    bool isPairPresent(struct Node *root, int target) {
        pushAllnext(root);
        pushAllprev(root);
        
        int i = next();
        int j = before();
        
        while (hasNext() && hasprev()) {
            if (i + j == target) return true;
            else if (i + j < target) i = next();
            else j = before();
        }
        
        return false;
    }
};

int main() {
    // Create a binary search tree.
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    // Initialize the Solution class with the root node.
    Solution solution;

    // Define the target sum to find a pair.
    int target = 10;

    // Check if there is a pair of elements in the BST that sums up to the target.
    if (solution.isPairPresent(root, target)) {
        cout << "A pair with sum " << target << " is present in the BST." << endl;
    } else {
        cout << "No pair with sum " << target << " is found in the BST." << endl;
    }

    return 0;
}
