/*
Given N piles of bananas, the ith pile has piles[i] bananas and H hours 
time until guards return (N <= H). Find the minimum (S) bananas to eat per
hour such that Koko can eat all the bananas within H hours. Each hour, Koko
chooses some pile of bananas and eats S bananas from that pile. If the pile
has less than S bananas, then she consumes all of them, and wont eat any more bananas during that hour. 
*/

/*
Example 2:
Input:
n = 5
piles = [30, 11, 23, 4, 20]
H = 5
Output:
30
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include<bits/stdc++.h>

using namespace std; // Namespace declaration to avoid explicit use of std::

class Solution {
private:
    int maxfind(vector<int> piles) {
        int ans = INT_MIN;
        for (int i = 0; i < piles.size(); i++) {
            ans = max(ans, piles[i]);
        }
        return ans;
    }

    int calculate(vector<int> piles, int hourly) {
        int total = 0;
        for (int i = 0; i < piles.size(); i++) {
            // Calculate the total hours required for each pile
            total += ceil(static_cast<double>(piles[i]) / static_cast<double>(hourly));
        }
        return total;
    }

public:
    int Solve(int N, vector<int>& piles, int H) {
        int low = 1;
        int high = maxfind(piles);

        while (low <= high) {
            int mid = (low + high) / 2;
            int hour = calculate(piles, mid);
            if (hour <= H) high = mid - 1;
            else low = mid + 1;
        }

        return low; // Return the minimum hourly rate
    }
};

int main() {
    Solution solution;
    int N = 5;
    vector<int> piles = {30, 11, 23, 4, 20};
    int H = 6;

    int result = solution.Solve(N, piles, H);

    cout << "Minimum hourly rate: " << result << endl;

    return 0;
}
