/*
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.
*/

/*
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
*/


#include <iostream>
#include <queue>
#include <utility> // Include this for std::pair

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to find the width of a binary tree
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0; // If the tree is empty, the width is 0
        int ans = 0; // Initialize the width to 0
        std::queue<std::pair<TreeNode*, int>> q; // Use a queue to perform level-order traversal

        // Push the root node with a position index of 0 into the queue
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size(); // Get the number of nodes at the current level
            int curMin = q.front().second; // Get the position index of the leftmost node at the current level
            int leftMost, rightMost; // Initialize variables to track the leftmost and rightmost positions

            for (int i = 0; i < size; i++) {
                int cur_id = q.front().second - curMin; // Calculate the position index relative to the leftmost node to prevent integer overflow
                TreeNode* temp = q.front().first; // Get the current node
                q.pop();

                if (i == 0) leftMost = cur_id; // Update leftMost for the first node in the level
                if (i == size - 1) rightMost = cur_id; // Update rightMost for the last node in the level

                if (temp->left)
                    q.push({temp->left, cur_id * 2 + 1}); // Push the left child with an adjusted position index
                if (temp->right)
                    q.push({temp->right, cur_id * 2 + 2}); // Push the right child with an adjusted position index
            }

            ans = std::max(ans, rightMost - leftMost + 1); // Update the width by comparing with the current level's width
        }

        return ans; // Return the maximum width
    }
};

int main() {
    // Create a sample binary tree for testing
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    int result = solution.widthOfBinaryTree(root);

    std::cout << "Width of the binary tree is: " << result << std::endl;

    // Clean up the allocated memory (this part is not shown in the code)
    // You should delete the tree nodes to avoid memory leaks
    // DeleteTree(root);

    return 0;
}
