// QUESTIONS

// Write a function for Inorder , Preorder and Post order traversal 

#include <vector>
#include <stack>


    // Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    

    // Function to perform tree traversal (in-order, pre-order, post-order) using an iterative approach.
    vector<vector<int>> getTreeTraversal(TreeNode *root) {
    // Create a stack to perform iterative traversal.
    stack<pair<TreeNode*, int>> st;
    // The second element of the pair represents the number:
    // - 1 for pre-order
    // - 2 for in-order
    // - 3 for post-order

    // Create vectors to store the traversal results.
    vector<int> pre, ino, post;

    // Push the root node onto the stack with the number 1 (pre-order).
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        // When num = 1, push the node's data in PRE, increment the number by 1,
        // and push the node back onto the stack. If the left child exists, push it as well.
        if (it.second == 1) {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }

        // When num = 2, push the node's data in INO, increment the number by 1,
        // and push the node back onto the stack. If the right child exists, push it as well.
        else if (it.second == 2) {
            ino.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }

        // When num = 3, push the node's data in POST and do nothing else.
        else {
            post.push_back(it.first->data);
        }
    }

    // Create a vector of vectors to store the traversal results.
    vector<vector<int>> ans;
    ans.push_back(ino);  // In-order
    ans.push_back(pre);  // Pre-order
    ans.push_back(post); // Post-order

    return ans;
}
};
