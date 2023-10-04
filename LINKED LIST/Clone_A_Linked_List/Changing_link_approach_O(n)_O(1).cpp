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
private:
    // Function to insert a new node with the given data at the tail of a linked list.
    void insertAtTail(Node* &head, Node* &tail, int data) {
        Node* newNode = new Node(data); // Create a new node with the given data.
        if (head == NULL) { // If the original list is empty,
            head = newNode; // Set both the head and tail of the original list to the new node.
            tail = newNode;
            return;
        } else { // If the original list is not empty,
            tail->next = newNode; // Append the new node to the tail of the list.
            tail = newNode; // Update the tail to be the newly added node.
        }
    }

public:
    Node* copyList(Node* head) {
        Node* clonehead = NULL; // Initialize the head of the cloned list to NULL.
        Node* clonetail = NULL; // Initialize the tail of the cloned list to NULL.
        Node* temp = head; // Create a temporary pointer to traverse the original list.

        // Step 1: Create a basic clone of the linked list using the next pointers.
        while (temp != NULL) {
            insertAtTail(clonehead, clonetail, temp->data); // Insert a new node with the same data into the cloned list.
            temp = temp->next; // Move to the next node in the original list.
        }

        Node* originalnode = head; // Initialize a pointer to traverse the original list.
        Node* clonenode = clonehead; // Initialize a pointer to traverse the cloned list.
        Node* next = NULL; // Temporary pointer to store the next node.

        // Step 2: Intermix the cloned nodes in between the original nodes using next pointers.
        while (originalnode != NULL && clonenode != NULL) {
            next = originalnode->next; // Store the next node in the original list.
            originalnode->next = clonenode; // Update the next pointer of the original node to point to the corresponding cloned node.
            originalnode = next; // Move to the next node in the original list.
            next = clonenode->next; // Store the next node in the cloned list.
            clonenode->next = originalnode; // Update the next pointer of the cloned node to point to the corresponding original node.
            clonenode = next; // Move to the next node in the cloned list.
        }

        temp = head; // Reset the temporary pointer to the head of the original list.

        // Step 3: Apply the main condition to set the arbitrary pointers.
        while (temp != NULL) {
            if (temp->next != NULL) { // If there is a node next to the current node in the original list,
                if (temp->arb != NULL) { // If the arbitrary pointer of the current node is not NULL,
                    temp->next->arb = temp->arb->next; // Set the arbitrary pointer of the corresponding cloned node.
                } else { // If the arbitrary pointer of the current node is NULL,
                    temp->next->arb = NULL; // Set the arbitrary pointer of the cloned node to NULL.
                }
                temp = temp->next->next; // Move two steps ahead in the original list (skipping cloned nodes).
            }
        }

        originalnode = head; // Reset the pointer to traverse the original list.
        clonenode = clonehead; // Reset the pointer to traverse the cloned list.

        // Step 4: Remove the cloned nodes from between the original nodes.
        while (originalnode != NULL && clonenode != NULL) {
            originalnode->next = clonenode->next; // Remove the cloned node from the original list.
            originalnode = originalnode->next; // Move to the next node in the original list.

            if (originalnode != NULL) { // If there is a node next to the current node in the original list,
                clonenode->next = originalnode->next; // Remove the original node from the cloned list.
                clonenode = clonenode->next; // Move to the next node in the cloned list.
            }
        }

        // Step 5: Return the cloned head as the final result.
        return clonehead;
    }
};
