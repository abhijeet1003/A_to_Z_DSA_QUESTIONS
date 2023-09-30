vector<vector<int>> levelOrder(Node* node)
{
    vector<vector<int>> ans;        // Create a 2D vector to store the level order traversal result
    if(node == NULL) return ans;     // If the tree is empty, return an empty result
    
    queue<Node*> q;                 // Create a queue for level order traversal
    q.push(node);                   // Push the root node onto the queue
    
    while(!q.empty()){
        int size = q.size();         // Get the number of nodes at the current level
        vector<int> level;           // Create a vector to store nodes at the current level
        
        for(int i = 0; i < size; i++){
            Node* val = q.front();   // Get the front node from the queue
            q.pop();                 // Remove the front node from the queue
            
            if(val->left != NULL)    // If the left child exists, push it to the queue
                q.push(val->left);
            
            if(val->right != NULL)   // If the right child exists, push it to the queue
                q.push(val->right);
            
            level.push_back(val->data); // Add the data of the current node to the level vector
        }
        
        ans.push_back(level);       // Add the level vector to the result
    }
    
    return ans;                    // Return the level order traversal result
}
