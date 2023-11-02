/*
You are given 2 numbers (n , m); the task is to find n√m (nth root of m).
*/

/*
Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not
integer.
*/

#include <iostream>

using namespace std;

class Solution {
    private:
        // Helper function to check if 'mid' raised to the power 'n' is equal to 'm'.
        int find(int mid, int n, int m) {
            long long ans = 1;
            for (int i = 0; i < n; i++) {
                ans = ans * mid;
                if (ans > m)
                    return 2; // If the value exceeds 'm', no need to continue.
            }
            if (ans == m)
                return 1; // If 'mid' raised to 'n' equals 'm', return 1 to indicate a match.
            return 0; // Otherwise, return 0.
        }
    public:
        int NthRoot(int n, int m) {
            long long low = 1; // Initialize the lower bound.
            long long high = m; // Initialize the upper bound.

            while (low <= high) {
                long long mid = (low + high) / 2; // Calculate the midpoint.
                int val = find(mid, n, m); // Call the 'find' helper function to check the result.

                if (val == 1)
                    return mid; // If 'mid' raised to 'n' equals 'm', return 'mid' as the nth root.
                else if (val == 0)
                    low = mid + 1; // If 'val' is 0, increase the lower bound.
                else
                    high = mid - 1; // If 'val' is 2, decrease the upper bound.
            }
            return -1; // Return -1 to indicate that no nth root was found within the bounds.
        }
};

int main() {
    Solution solution;
    int n = 3; // The root index
    int m = 27; // The number

    int result = solution.NthRoot(n, m);

    cout << "Nth root of " << m << " with index " << n << " is: " << result << endl;

    return 0;
}
