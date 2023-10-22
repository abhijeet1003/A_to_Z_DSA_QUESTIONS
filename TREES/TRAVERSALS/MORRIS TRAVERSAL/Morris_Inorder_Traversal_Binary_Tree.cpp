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
    // Function to perform an in-order traversal of a binary tree using Morris Traversal
    vector<int> inOrder(Node* root) {
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
                    curr = curr->left; // Move to the left child
                } else {
                    prev->right = NULL; // Remove the temporary link
                    ans.push_back(curr->data); // Visit and add the data of the current node
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
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Perform an in-order traversal of the binary tree using Morris Traversal
    vector<int> inOrderTraversal = solution.inOrder(root);

    cout << "In-order traversal of the tree: ";
    for (int val : inOrderTraversal) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
