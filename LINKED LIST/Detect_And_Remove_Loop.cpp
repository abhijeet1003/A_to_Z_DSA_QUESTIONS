// QUESTIONS


/*
Given a linked list of N nodes such that it may contain a loop.

A loop here means that the last node of the link list is connected to the node at 
position X(1-based index). If the link list does not have any loop, X=0.

Remove the loop from the linked list, if it is present, i.e. unlink the last node 
which is forming the loop.

*/
struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};


class Solution
{
public:
    // Function to detect if there is a loop in the linked list.
    Node* detect(Node* head) {
        Node* slow = head;
        Node* fast = head;

        // Use a slow and a fast pointer to traverse the linked list.
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                fast = fast->next;
            }

            slow = slow->next;

            // If the slow and fast pointers meet, there is a loop in the linked list.
            if (slow == fast) {
                return slow; // Return the node where they meet.
            }
        }
        return NULL; // No loop found, return NULL.
    }

    // Function to find the start node of the loop in the linked list.
    Node* startOfLoop(Node* head) {
        Node* meeting = detect(head);
        if (meeting == NULL) {
            return NULL; // No loop found, return NULL.
        }

        Node* slow = head;

        // Move one pointer from the head and another from the meeting point until they meet again.
        while (slow != meeting) {
            slow = slow->next;
            meeting = meeting->next;
        }
        return slow; // Return the start node of the loop.
    }

    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        if (head == NULL) {
            return; // Empty list, nothing to remove.
        }

        Node* intersection = startOfLoop(head);
        if (intersection == NULL) {
            return; // No loop found, nothing to remove.
        }

        Node* temp = intersection;

        // Traverse until the last node of the loop.
        while (temp->next != intersection) {
            temp = temp->next;
        }

        temp->next = NULL; // Remove the loop by breaking the connection.
    }
};
