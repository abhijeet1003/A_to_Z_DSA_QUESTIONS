
/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/

class Solution {
public:
    // Function to perform postorder traversal of a binary tree
    vector<int> postOrder(Node* node) {
        vector<int> ans;          // Create a vector to store the postorder traversal result
        stack<Node*> st1, st2;    // Create two stacks for traversal
        st1.push(node);           // Push the root node onto the first stack
        
        // Continue until the first stack is empty
        while (!st1.empty()) {
            Node* curr = st1.top();
            st1.pop();
            
            st2.push(curr);        // Push the current node onto the second stack
            
            if (curr->left != NULL)
                st1.push(curr->left);   // Push the left child to the first stack if it exists
            
            if (curr->right != NULL)
                st1.push(curr->right);  // Push the right child to the first stack if it exists
        }
        
        // Pop nodes from the second stack to get the postorder traversal result
        while (!st2.empty()) {
            Node* res = st2.top();
            st2.pop();
            ans.push_back(res->data);  // Add the data of the popped node to the result vector
        }
        
        return ans;  // Return the postorder traversal result
    }
};
