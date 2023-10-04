// QUESTIONS


/*
You are given a special linked list with N nodes where each node has
 a next pointer pointing to its next node. You are also given M random
  pointers, where you will be given M number of pairs denoting 
two nodes a and b  i.e. a->arb = b (arb is pointer to random node).


Construct a copy of the given list. The copy should consist of exactly N 
new nodes, where each new node has its value set to the value of its 
corresponding original node. Both the next and random pointer of the new 
nodes should point to new nodes in the copied list such that the pointers in
 the original list and copied list represent the same list state. None of the
 pointers in the new list should point to nodes in the original list.


For example, if there are two nodes X and Y in the original list, where X.arb --> Y,
 then for the corresponding two nodes x and y in the copied list, x.arb --> y.
*/

#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<map>
using namespace std;



class Solution {
public:
    // Function to insert a new node with the given digit at the end of the linked list.
    void insert(Node* &clonehead, Node* &clonetail, int digit) {
        Node* temp = new Node(digit);
        if (clonehead == NULL) {
            clonehead = temp;
            clonetail = temp;
            return;
        }
        clonetail->next = temp;
        clonetail = temp;
    }
    
    // Function to copy a linked list with both next and arbitrary pointers.
    Node* copyList(Node* head) {
        Node* clonehead = NULL; // Initialize the cloned list's head to NULL.
        Node* clonetail = NULL; // Initialize the cloned list's tail to NULL.
        
        Node* temp = head; // Create a temporary pointer to traverse the original list.
        
        // Traverse the original list and insert each node into the cloned list.
        while (temp != NULL) {
            insert(clonehead, clonetail, temp->data); // Insert the node in the cloned list.
            temp = temp->next; // Move to the next node in the original list.
        }
        
        unordered_map<Node*, Node*> oldtonew; // Create a map to store the mapping between old and new nodes.
        
        temp = head; // Reset the temporary pointer to the head of the original list.
        Node* temp2 = clonehead; // Create a new temporary pointer to traverse the cloned list.
        
        // Build a mapping from the old nodes to their corresponding new nodes.
        while (temp != NULL && temp2 != NULL) {
            oldtonew[temp] = temp2; // Map the old node to the new node.
            temp = temp->next; // Move to the next node in the original list.
            temp2 = temp2->next; // Move to the next node in the cloned list.
        }
        
        temp = head; // Reset the temporary pointer to the head of the original list.
        temp2 = clonehead; // Reset the temporary pointer to the head of the cloned list.
        
        // Update the arbitrary pointers in the cloned list using the mapping.
        while (temp != NULL && temp2 != NULL) {
            temp2->arb = oldtonew[temp->arb]; // Update the arbitrary pointer of the cloned node.
            temp = temp->next; // Move to the next node in the original list.
            temp2 = temp2->next; // Move to the next node in the cloned list.
        }
        
        return clonehead; // Return the head of the cloned list.
    }
};
