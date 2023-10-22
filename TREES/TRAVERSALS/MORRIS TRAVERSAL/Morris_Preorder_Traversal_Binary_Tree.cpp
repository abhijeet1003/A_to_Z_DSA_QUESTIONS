#include <iostream>
#include <vector>
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
    // Function to perform a pre-order traversal of a binary tree using Morris Traversal
    vector<int> preOrder(Node* root) {
        vector<int> ans;
        Node* curr = root;
        while (curr != NULL) {
            if (curr->left == NULL) {
                ans.push_back(curr->data); // Visit and add the data of the current node
                curr = curr->right; // Move to the right child
            } else {
                Node* prev = curr->left;
                while (prev->right != NULL && prev->right != curr) {
                    prev = prev->right;
                }
                if (prev->right == NULL) {
                    prev->right = curr; // Create a temporary link from the rightmost node of the left subtree
                    ans.push_back(curr->data); // Visit and add the data of the current node
                    curr = curr->left; // Move to the left child
                } else {
                    prev->right = NULL; // Remove the temporary link
                    curr = curr->right; // Move to the right child
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Create a sample binary tree for testing
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = a Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Perform a pre-order traversal of the binary tree using Morris Traversal
    vector<int> preOrderTraversal = solution.preOrder(root);

    cout << "Pre-order traversal of the tree: ";
    for (int val : preOrderTraversal) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
