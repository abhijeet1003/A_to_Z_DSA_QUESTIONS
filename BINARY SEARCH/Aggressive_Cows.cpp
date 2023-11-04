/*
You are given an array consisting of n integers which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
The first line of input contains two space-separated integers n and k.
The second line contains n space-separated integers denoting the position of the stalls.
*/

/*
Input:
n=5 
k=3
stalls = [10 1 2 7 5]
Output:
4
Explanation:
The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows, in this case, is 4,
which also is the largest among all possible ways.
*/

#include <iostream>  // Include the input-output stream header.
#include <vector>    // Include the vector container header.
#include <algorithm> // Include the algorithm header for sorting.

using namespace std;  // Use the standard namespace for standard library functions.

class Solution {
public:
    // Function to check if cows can be placed with a minimum distance `mini` between them.
    bool canWePlace(int mini, vector<int> &stalls, int cows, int n) {
        int cnt = 1;            // Initialize the count of placed cows to 1.
        int lastCow = stalls[0]; // Set the position of the last placed cow to the first stall.

        // Iterate through stalls to check if cows can be placed with the minimum distance.
        for (int i = 1; i < n; i++) {
            if (stalls[i] - lastCow >= mini) {
                cnt++;            // Increment the count of placed cows.
                lastCow = stalls[i]; // Update the position of the last placed cow.
            }
        }

        // If the count of placed cows is greater or equal to the required cows, return true.
        if (cnt >= cows)
            return true;
        return false; // Otherwise, return false.
    }

    // Function to find the largest minimum distance for placing cows.
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end()); // Sort the stalls in ascending order.

        int low = 1;                          // Initialize the lower bound for binary search.
        int high = stalls[n - 1] - stalls[0]; // Initialize the upper bound for binary search.

        // Binary search loop to find the largest minimum distance.
        while (low <= high) {
            int mid = (low + high) / 2; // Calculate the middle value for minimum distance.

            // If cows can be placed with a minimum distance of `mid`, update the low pointer.
            if (canWePlace(mid, stalls, k, n) == true)
                low = mid + 1;
            else
                high = mid - 1; // Otherwise, update the high pointer.
        }
        return high; // Return the largest minimum distance.
    }
};

int main() {
    Solution solution;  // Create an instance of the Solution class.

    // Sample stalls and number of cows.
    vector<int> stalls = {1, 2, 8, 4, 9};
    int k = 3;

    int result = solution.solve(stalls.size(), k, stalls); // Call the solve function.

    // Print the result to the console.
    cout << "Largest minimum distance for placing cows: " << result << endl;

    return 0;
}
