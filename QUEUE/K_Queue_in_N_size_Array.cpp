#include<iostream>
using namespace std;

// Define a class for implementing K queues in an N-sized array
class Kqueue {
public:
    int n;        // Total size of the array
    int k;        // Number of queues (K)
    int *arr;     // Array to store queue elements
    int *next;    // Array to store the next available index
    int *front;   // Array to store the front index of each queue
    int *rear;    // Array to store the rear index of each queue
    int freespot; // Index of the next available spot in the array

    // Constructor to initialize the Kqueue
    Kqueue(int n, int k) {
        this->n = n;
        this->k = k;
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];
        freespot = 0;

        // Initialize front and rear for each queue
        for (int i = 0; i < k; i++) {
            front[i] = -1; // Initialize front for each queue as -1 (empty)
            rear[i] = -1;  // Initialize rear for each queue as -1 (empty)
        }

        // Initialize the next array to link available spots
        for (int i = 0; i < n; i++) {
            next[i] = i + 1; // Each index points to the next available spot
        }
        next[n - 1] = -1; // Set the last element as -1 to indicate the end of the array
    }

    // Function to enqueue an element into a specified queue (qn)
    void enqueue(int data, int qn) {
        if (freespot == -1) {
            cout << "Array full --- overflow " << endl;
            return;
        }

        int index = freespot; // Get the next available spot in the array
        freespot = next[index]; // Update the next available spot

        if (front[qn - 1] == -1) {
            front[qn - 1] = index; // If the queue is empty, set front to the new index
        } else {
            next[rear[qn - 1]] = index; // Link the previous rear to the new index
        }

        next[index] = -1; // Mark the new index as the end of the queue
        rear[qn - 1] = index; // Update the rear index of the queue
        arr[index] = data; // Store the data in the array
    }

    // Function to dequeue an element from a specified queue (qn)
    int dequeue(int qn) {
        if (front[qn - 1] == -1) {
            cout << "UNDERFLOW---" << endl;
            return -1;
        }

        int index = front[qn - 1]; // Get the index of the front element in the queue
        front[qn - 1] = next[index]; // Update the front to the next element in the queue
        next[index] = freespot; // Mark the index as the next available spot
        freespot = index; // Update the next available spot
        return arr[index]; // Return the dequeued data
    }
};

int main() {
    // Create a Kqueue with a total size of 10 and 3 queues
    Kqueue q(10, 3);

    // Enqueue elements into different queues
    q.enqueue(10, 1); // Enqueue 10 into queue 1
    q.enqueue(15, 1); // Enqueue 15 into queue 1
    q.enqueue(20, 2); // Enqueue 20 into queue 2
    q.enqueue(30, 1); // Enqueue 30 into queue 1

    // Dequeue elements from different queues
    cout << q.dequeue(1) << endl; // Dequeue from queue 1 (10 is expected)
    cout << q.dequeue(1) << endl; // Dequeue from queue 1 (15 is expected)
    cout << q.dequeue(2) << endl; // Dequeue from queue 2 (20 is expected)
    cout << q.dequeue(1) << endl; // Dequeue from queue 1 (30 is expected)
    cout << q.dequeue(1) << endl; // Dequeue from queue 1 (UNDERFLOW message as queue 1 is now empty)

    return 0;
}

