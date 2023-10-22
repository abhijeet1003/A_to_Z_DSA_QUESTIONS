/*

Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same Node class where the right child pointer points to the next   node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
*/


/*
Input : 
          1
        /   \
       2     5
      / \     \
     3   4     6
Output :
1 2 3 4 5 6 


    Explanation: 
    After flattening, the tree looks 
    like this
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6 

Here, left of each node points 
to NULL and right contains the 
next node in preorder.The inorder 
traversal of this flattened tree 
is 1 2 3 4 5 6.
*/

#include <iostream>
#include <stack>
using namespace std;

// Definition of a binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to flatten a binary tree using an iterative approach
    void flatten(Node* root) {
        stack<Node*> st;
        Node* curr;
        st.push(root);
        while (!st.empty()) {
            curr = st.top();
            st.pop();
            if (curr->right) st.push(curr->right); // Push the right child onto the stack
            if (curr->left) st.push(curr->left); // Push the left child onto the stack
            if (!st.empty()) curr->right = st.top(); // Set the right child to the next node on the stack
            curr->left = NULL; // Set the left child to null
        }
    }
};

int main() {
    Solution solution;

    // Create a sample binary tree for testing
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    // Flatten the binary tree
    solution.flatten(root);

    // Print the flattened tree
    Node* current = root;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->right;
    }
    cout << endl;

    return 0;
}
