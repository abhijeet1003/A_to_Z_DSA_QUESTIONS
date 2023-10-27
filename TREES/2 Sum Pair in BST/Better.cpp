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
#include <vector>
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
    // Function to perform an inorder traversal of the BST and store values in a vector.
    void inorder(Node* root, vector<int>& arr) {
        if (root == NULL) return;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }

    // Function to check if there is a pair of elements in the BST that sum up to the target.
    int isPairPresent(struct Node *root, int target) {
        vector<int> arr;
        inorder(root, arr);
        int n = arr.size();
        int i = 0;
        int j = n - 1;

        while (i < j) {
            if (arr[i] + arr[j] == target) return 1;
            else if (arr[i] + arr[j] < target) i++;
            else j--;
        }
        return 0;
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
