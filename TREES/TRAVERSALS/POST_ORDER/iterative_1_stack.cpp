//  This 1 stack can be perfomed using two ways .


// carry out like the 2 stack process but instead of storing in 2nd stack store in ans and at last reverse your answer vector


/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/

class Solution {
public:
    // Function to perform postorder traversal of a binary tree
    vector<int> postOrder(Node* root) {
        vector<int> ans;
        stack<Node*> st1;

        // Start with the root node and push it onto the stack
        st1.push(root);

        while (!st1.empty()) {
            Node* node = st1.top();
            st1.pop();

            // Add the current node's data to the result vector
            ans.push_back(node->data);

            // Push the left and right children onto the stack (if they exist)
            if (node->left != NULL) st1.push(node->left);
            if (node->right != NULL) st1.push(node->right);
        }

        // Reverse the result vector to get postorder traversal
        reverse(ans.begin(), ans.end());

        return ans;
    }
};



//  By using single Stack and no Reversing done

// User function Template for C++

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
        vector<int> ans;      // Create a vector to store the postorder traversal result
        stack<Node*> st;      // Create a stack to help with the traversal
        Node* curr = node;    // Initialize a pointer to the current node

        // Continue the loop until the stack is empty or the current node is not NULL
        while (!st.empty() || curr != NULL) {
            if (curr != NULL) {
                st.push(curr);        // Push the current node onto the stack
                curr = curr->left;    // Move to the left child of the current node
            } else {
                // Get the right child of the top node in the stack
                Node* temp = st.top()->right;

                if (temp == NULL) {
                    // If the right child is NULL, pop the node, add its data to the result,
                    // and keep popping nodes whose right child is the same as the popped node
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);

                    // Continue popping until a node with a different right child is encountered
                    while (!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->data);
                    }
                } else {
                    // If the right child exists, set it as the current node
                    curr = temp;
                }
            }
        }

        return ans;  // Return the postorder traversal result
    }
};

