//                       QUESTIONS

/*
Given two binary trees, the task is to find if both of them are identical or not. 
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

class Solution
{
public:
    // Function to check if two trees are identical.
    bool isIdentical(Node *p, Node *q)
    {
        // Base case: If both trees are NULL, they are identical.
        if (p == NULL && q == NULL) {
            return true;
        }
        
        // Base case: If one of the trees is NULL and the other is not, they are not identical.
        if (p == NULL || q == NULL) {
            return false;
        }
        
        // Check if the current nodes' data are equal, and recursively check the left and right subtrees.
        // The logical AND operator (&&) ensures that both the data and subtrees must be identical.
        // If any of these conditions fail, the trees are not identical.
        return (p->data == q->data) && 
               isIdentical(p->left, q->left) &&    // Recursively check left subtrees
               isIdentical(p->right, q->right);    // Recursively check right subtrees
    }
};



/*

EXPLAINATION of line 39

return (p->data == q->data) && isIdentical(p->left, q->left) && isIdentical(p->right, q->right); = 

1. This line checks if the current nodes' data (p->data and q->data) are equal.

2.It also recursively checks if the left subtrees of both trees (p->left and q->left) are identical.

3.Additionally, it recursively checks if the right subtrees of both trees (p->right and q->right) are identical.

4.If any of these conditions fail, the function returns false.


*/