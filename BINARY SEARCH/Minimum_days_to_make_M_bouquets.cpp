/*
To make one bouquet we need K adjacent flowers from the garden. 
Here the garden consists of N different flowers, the ith flower will bloom in the bloomDay[i]. 
Each flower can be used inside only one bouquets. We have to find the minimum number of days need to wait to make M bouquets from the garden. If we cannot make m bouquets, then return -1.

The first line of input contains two integers M and K.
The second line contains N space-separated integers of bloomDay[i] array.
*/

/*
Input:
M = 2, K = 3
bloomDay = [5, 5, 5, 5, 10, 5, 5]
Output:
10
Explanation:
As we need 2 (M = 2) bouquets and each should have 3 flowers,
After day 5: [x, x, x, x, _, x, x], we can make one bouquet of
the first three flowers that bloomed, but cannot make another bouquet.
After day 10: [x, x, x, x, x, x, x], Now we can make two bouquets,
taking 3 adjacent flowers in one bouquet.
*/

#include <iostream>
#include <vector>
#include <algorithm>  // Required for 'min' and 'max' functions
#include<bits/stdc++.h>



using namespace std;  // Simplify the use of standard C++ libraries

class Solution {
private:
    // Helper function to check if it's possible to achieve 'm' bouquets with 'k' flowers per bouquet within 'day' days
    bool check(vector<int> &bloom, int day, int m, int k) {
        int cnt = 0;
        int ans = 0;

        for (int i = 0; i < bloom.size(); i++) {
            if (bloom[i] <= day)
                cnt++;
            else {
                ans += (cnt / k);
                cnt = 0;
            }
        }

        ans += cnt / k;
        return ans >= m;
    }

public:
    // Function to solve the problem by finding the minimum day required to make 'm' bouquets with 'k' flowers per bouquet
    int solve(int m, int k, vector<int> &bloom) {
        long long val = m * 1ll * k * 1ll;  // Calculate the required total flowers
        if (val > bloom.size())
            return -1;  // If the required flowers exceed the total available, it's impossible

        int mini = INT_MAX;  // Initialize 'mini' with the maximum possible integer value
        int maxi = INT_MIN;  // Initialize 'maxi' with the minimum possible integer value

        // Find the minimum and maximum bloom days in the vector
        for (int i = 0; i < bloom.size(); i++) {
            mini = min(mini, bloom[i]);
            maxi = max(maxi, bloom[i]);
        }

        int low = mini;  // Initialize 'low' with the minimum bloom day
        int high = maxi;  // Initialize 'high' with the maximum bloom day

        while (low <= high) {
            int mid = (low + high) / 2;  // Calculate the midpoint

            if (check(bloom, mid, m, k))
                high = mid - 1;  // Update 'high' if it's possible to achieve 'm' bouquets with 'k' flowers within 'mid' days
            else
                low = mid + 1;  // Update 'low' if it's not possible

        }
        return low;  // Return the minimum day required to achieve the goal
    }
};

int main() {
    Solution solution;

    // Example usage:
    vector<int> bloom = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;

    int result = solution.solve(m, k, bloom);
    cout << "Minimum day required: " << result << endl;

    return 0;
}
