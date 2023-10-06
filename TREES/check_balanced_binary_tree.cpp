//                                        QUESTIONS

/*
Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right 
subtrees is not more than one for all nodes of tree. 
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

class Solution{
public:
    // Function to check the height difference between the left and right subtrees.
    int checkHeight(Node* root){
        // Base case: If the root is NULL, return a height of 0.
        if(root == NULL) return 0;
        
        // Recursively calculate the height of the left subtree.
        int lh = checkHeight(root->left);
        
        // Recursively calculate the height of the right subtree.
        int rh = checkHeight(root->right);
        
        // If either subtree is unbalanced (-1), return -1 immediately.
        if(lh == -1 || rh == -1) return -1;
        
        // If the absolute difference between the left and right subtree heights
        // is greater than 1, return -1 to indicate an unbalanced tree.
        if(abs(lh - rh) > 1) return -1;
        
        // Return 1 plus the maximum of the left and right subtree heights,
        // representing the height of the current subtree.
        return 1 + max(lh , rh);
    }
    
    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        // If the height check function returns -1, the tree is unbalanced, so return false.
        if(checkHeight(root) == -1) return false;
        
        // Otherwise, return true, indicating that the tree is balanced.
        return true;
    }
};
