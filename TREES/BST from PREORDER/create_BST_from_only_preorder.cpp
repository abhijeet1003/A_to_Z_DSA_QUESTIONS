#include <vector>
#include <climits>

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Recursive function to build a Binary Search Tree (BST) from a preorder traversal array.
    TreeNode* build(std::vector<int>& A, int& i, int bound) {
        // If the current index is at the end of the array or the value is greater than the bound, return NULL.
        if (i == A.size() || A[i] > bound) {
            return nullptr;
        }
        
        // Create a new TreeNode with the current value.
        TreeNode* root = new TreeNode(A[i]);
        i++; // Move to the next element in the array.

        // Recursively build the left and right subtrees, ensuring they follow the BST property.
        root->left = build(A, i, root->val);
        root->right = build(A, i, bound);

        return root;
    }

    // Function to construct a BST from a preorder traversal array.
    TreeNode* bstFromPreorder(std::vector<int>& A) {
        int i = 0; // Initialize the index to 0.
        return build(A, i, INT_MAX); // Start building the BST with an initial "bound" of INT_MAX.
    }
};

int main() {
    // Example usage and testing can be done here.
    return 0;
}
