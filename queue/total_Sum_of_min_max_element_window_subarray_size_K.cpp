#include <iostream>
#include <deque>
using namespace std;

//                                            QUESTION


/* Explain the implementation of the solve function in your code, which calculates the total sum of 
minimum and maximum elements in all windows of size k for a given array. Provide a step-by-step 
breakdownof how the algorithm works, and discuss the purpose of using deque data
 structures to optimize this calculation.*/


//                                             ANSWER


int solve(int *arr, int n, int k) {
    deque<int> maxi(k); // Create a deque to store indices of maximum elements within the window
    deque<int> mini(k); // Create a deque to store indices of minimum elements within the window

    int ans = 0; // Initialize the answer variable to 0

    // First traverse the array for the first k-sized window and update mini and maxi queues with the indices of elements.
    for (int i = 0; i < k; i++) {
        // Remove elements from the back of maxi if they are less than or equal to the current element arr[i].
        while (!maxi.empty() && arr[maxi.back()] <= arr[i]) {
            maxi.pop_back();
        }

        // Remove elements from the back of mini if they are greater than or equal to the current element arr[i].
        while (!mini.empty() && arr[mini.back()] >= arr[i]) {
            mini.pop_back();
        }

        // Add the current index i to maxi and mini queues.
        maxi.push_back(i);
        mini.push_back(i);
    }

    // Move ahead in the array, adding one new element and removing one. Remove indices outside the current window if necessary.
    for (int i = k; i < n; i++) {

        // Calculate the answer for all windows from the start, except for the last window which will be handled separately.
        ans = ans + arr[maxi.front()] + arr[mini.front()];

        // Remove indices outside of the current window from the queues. from the front
        while (!maxi.empty() && i - maxi.front() >= k) {
            maxi.pop_front();
        }

        // Remove indices outside of the current window from the queues. from the front

        while (!mini.empty() && i - mini.front() >= k) {
            mini.pop_front();
        }

        // Add the current index i to maxi and mini queues based on the conditions.
        while (!maxi.empty() && arr[maxi.back()] <= arr[i]) {
            maxi.pop_back();
        }
        while (!mini.empty() && arr[mini.back()] >= arr[i]) {
            mini.pop_back();
        }

        // Add the current index i to maxi and mini queues.
        maxi.push_back(i);
        mini.push_back(i);
    }

    // Perform addition for one last time to handle the last window.
    ans = ans + arr[maxi.front()] + arr[mini.front()];

    return ans;
}

int main() {
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    // Output the result of the solve function.
    cout << "Maximum Sum of Minimum and Maximum Elements in All Windows: " << solve(arr, 7, k) << endl;

    return 0;
}
