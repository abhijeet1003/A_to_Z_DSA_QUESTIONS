/*
Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.
*/

/*
Input
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output
[null, 3, 7, true, 9, true, 15, true, 20, false]

Explanation
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False
*/


#include <iostream>
#include <stack>

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class BSTIterator {
private:
    std::stack<TreeNode*> st;

    // Helper function to push all left nodes to the stack.
    void pushAll(TreeNode* root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        // Initialize the iterator by pushing all left nodes to the stack.
        pushAll(root);
    }

    int next() {
        // Get the top node from the stack.
        TreeNode* node = st.top();
        st.pop();

        // Push all left nodes of the right subtree to the stack.
        pushAll(node->right);

        // Return the value of the current node.
        return node->val;
    }

    bool hasNext() {
        // Check if the stack is empty.
        return !st.empty();
    }
};

int main() {
    // Create a binary search tree.
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    // Initialize the BSTIterator with the root node.
    BSTIterator iterator(root);

    std::cout << "BST Iterator Output:" << std::endl;
    while (iterator.hasNext()) {
        // Print the next element using the iterator.
        std::cout << iterator.next() << " ";
    }
    std::cout << std::endl;

    // Don't forget to free the allocated memory (implement your own logic for memory deallocation).
    return 0;
}
