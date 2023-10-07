#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}*head;

class Solution {
public:
    // Recursive function to swap two adjacent nodes in a linked list.
    Node* pairWiseSwap(struct Node* head) {
        // Base case: If the list is empty or contains only one node, no swapping needed.
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        // Store the next node and recursively swap the remaining nodes.
        Node* nextNode = head->next;
        head->next = pairWiseSwap(nextNode->next);
        
        // Swap the current node and the next node.
        nextNode->next = head;
        
        // Return the new head of the swapped list (which is the next node).
        return nextNode;
    }
};


// 1. pairWiseSwap is a recursive function that swaps two adjacent nodes in a linked list.

// 2.The base case checks if the list is empty or contains only one node. If so, no swapping is needed, and the current head is returned as is.

// 3.For lists with more than one node, the function recursively calls itself on the remaining part of the list (i.e., pairWiseSwap(nextNode->next)).

// 4.After the recursive call, we swap the current node (head) and the next node (nextNode) by updating their next pointers.

// 5.Finally, the function returns the new head of the swapped list, which is nextNode.