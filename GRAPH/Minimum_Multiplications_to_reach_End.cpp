/*
Given start, end and an array arr of n numbers. At each step, start
 is multiplied with any number in the array and then mod operation with 
 100000 is done to get the new start.

Your task is to find the minimum steps in which end can be achieved 
starting from start. If it is not possible to reach end, then return -1.
*/

/*
Input:
arr[] = {2, 5, 7}
start = 3, end = 30
Output:
2
Explanation:
Step 1: 3*2 = 6 % 100000 = 6 
Step 2: 6*5 = 30 % 100000 = 30
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to find the minimum number of multiplications to reach the 'end' value
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // If 'start' and 'end' are the same, no multiplications are needed (0 operations).
        if (start == end)
            return 0;

        // Initialize an array to store minimum steps to reach each value (up to 100,000).
        vector<int> dis(100000, 1e9);

        // Create a queue to perform breadth-first search.
        queue<pair<int, int>> q;

        // Push the 'start' value with 0 steps into the queue.
        q.push({start, 0});

        // Set the modulus value for calculations.
        int mod = 100000;

        // Initialize the distance to reach 'start' as 0.
        dis[start] = 0;

        // Perform breadth-first search
        while (!q.empty()) {
            // Get the front element from the queue.
            auto it = q.front();
            int time = it.second;
            int ans = it.first;
            q.pop();

            // Iterate through the elements in the 'arr' vector.
            for (auto it : arr) {
                // Calculate the result of multiplication and take it modulo 'mod'.
                int res = (ans * it) % mod;

                // If the new path is shorter, update the distance and enqueue the result.
                if (time + 1 < dis[res]) {
                    dis[res] = time + 1;

                    // If 'end' is reached, return the number of multiplications needed.
                    if (res == end)
                        return time + 1;

                    // Enqueue the result with the updated steps.
                    q.push({res, time + 1});
                }
            }
        }
        // If 'end' is not reachable, return -1.
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {2, 3};
    int start = 2;
    int end = 7;

    // Call the minimumMultiplications function to find the minimum number of multiplications
    int result = solution.minimumMultiplications(arr, start, end);

    cout << "Minimum multiplications to reach " << end << ": " << result << endl;

    return 0;
}
