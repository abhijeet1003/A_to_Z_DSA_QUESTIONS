//                                 QUESTIONS
/*
The diameter of a tree (sometimes called the width) is the number of nodes on 
the longest path between two end nodes. The diagram below shows two trees each
 with diameter nine, the leaves that form the ends of the longest path are shaded 
 (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).
*/

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    // Constructor to initialize a Node with data and set left and right pointers to NULL.
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    // Variable to store the diameter of the binary tree.
    int ans = 0;
    
    // Function to calculate the height of the binary tree.
    int height(Node * root){
        // Base case: If the root is NULL, return a height of 0.
        if(root == NULL) return 0;
        
        // Recursively calculate the height of the left subtree.
        int l = height(root->left);
        
        // Recursively calculate the height of the right subtree.
        int r = height(root->right);
        
        // Update the diameter (ans) if the sum of left and right subtree heights + 1 is greater.
        ans = max(ans, l + r + 1);
        
        // Return 1 plus the maximum of left and right subtree heights,
        // representing the height of the current subtree.
        return 1 + max(l, r);
    }
    
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Calculate the height of the binary tree, which also updates the diameter.
        height(root);
        
        // Return the computed diameter of the binary tree.
        return ans;
    }
};
