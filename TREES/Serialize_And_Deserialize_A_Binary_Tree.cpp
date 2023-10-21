/*
Serialization is to store a tree in an array so that it can be later restored
and Deserialization is reading tree back from the array. Now your task is to 
complete the function serialize which stores the tree into an array A[ ] and 
deSerialize which deserializes the array to the tree and returns it.
Note: The structure of the tree must be maintained. Multiple nodes can have the same data.
Note : NULL is denoted by -1.
*/

/*
Input:
         10
       /    \
      20    30
    /   \
   40  60
Output: 40 20 60 10 30
*/

#include <iostream>
#include <vector>
#include <queue>
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
    // Function to serialize a tree and return a list containing nodes of the tree.
    vector<int> serialize(Node* root) {
        vector<int> A;

        if (root == NULL) return A; // If the tree is empty, return an empty list

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr == NULL) A.push_back(-1); // Use -1 to represent null nodes
            else {
                A.push_back(curr->data); // Add the data of the current node to the list
            }

            if (curr != NULL) {
                q.push(curr->left); // Add the left child to the queue
                q.push(curr->right); // Add the right child to the queue
            }
        }
        return A;
    }

    // Function to deserialize a list and construct the tree.
    Node* deSerialize(vector<int>& A) {
        if (A.size() == 0) return NULL; // If the input list is empty, return NULL
        int n = A.size();
        int i = 0;
        Node* node = new Node(A[i]); // Create the root node using the first value in the list
        i++;
        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            int valleft = A[i];
            if (i <= n) i++;

            if (valleft == -1) curr->left = NULL; // If the value is -1, set the left child to NULL
            else {
                Node* leftnode = new Node(valleft); // Create a new node for the left child
                curr->left = leftnode; // Set the left child of the current node
                q.push(leftnode); // Add the left child to the queue
            }

            int valright = A[i];
            if (i <= n) i++;

            if (valright == -1) curr->right = NULL; // If the value is -1, set the right child to NULL
            else {
                Node* rightnode = new Node(valright); // Create a new node for the right child
                curr->right = rightnode; // Set the right child of the current node
                q.push(rightnode); // Add the right child to the queue
            }
        }

        return node; // Return the root node of the constructed tree
    }
};

// Function to perform inorder traversal of the tree and print the elements
void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left); // Recursively traverse the left subtree
        cout << root->data << " "; // Print the data of the current node
        inorderTraversal(root->right); // Recursively traverse the right subtree
    }
}

int main() {
    Solution solution;

    // Create a sample binary tree for testing
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Serialize the tree
    vector<int> serialized = solution.serialize(root);

    cout << "Serialized Tree: ";
    for (int val : serialized) {
        cout << val << " ";
    }
    cout << endl;

    // Deserialize the tree
    Node* deserialized = solution.deSerialize(serialized);

    cout << "Deserialized Tree: ";
    solution.inorderTraversal(deserialized); // Perform an inorder traversal to verify the tree
    cout << endl;

    return 0;
}
