// QUESTIONS

/*
Given a collection of Intervals, the task is to merge all of the overlapping Intervals.
*/

/*
Input:
Intervals = {{1,3},{2,4},{6,8},{9,10}}
Output: {{1, 4}, {6, 8}, {9, 10}}
Explanation: Given intervals: [1,3],[2,4]
[6,8],[9,10], we have only two overlapping
intervals here,[1,3] and [2,4]. Therefore
we will merge these two and return [1,4],
[6,8], [9,10].
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to merge overlapping intervals.
    vector<vector<int>> overlappedInterval(vector<vector<int>>& arr) {
        vector<vector<int>> ans;  // Create a vector to store merged intervals.
        int n = arr.size();  // Get the number of input intervals.
        sort(arr.begin(), arr.end());  // Sort the intervals based on their start values.

        for (int i = 0; i < n; i++) {
            int start = arr[i][0];  // Get the start of the current interval.
            int end = arr[i][1];    // Get the end of the current interval.

            // If the result vector is not empty and the current interval's end
            // is less than or equal to the end of the last merged interval,
            // continue to the next interval (they overlap).
            if (!ans.empty() && end <= ans.back()[1]) {
                continue;
            }

            // Iterate through the remaining intervals to merge overlapping ones.
            for (int j = i + 1; j < n; j++) {
                if (arr[j][0] <= end) {
                    end = max(end, arr[j][1]);  // Merge overlapping intervals.
                } else {
                    break;  // Stop merging when no more overlaps are found.
                }
            }

            ans.push_back({ start, end });  // Add the merged interval to the result vector.
        }

        return ans;  // Return the merged intervals.
    }
};

int main() {
    Solution solution;

    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n);
    cout << "Enter the intervals (format: start end):" << endl;

    // Input the intervals as pairs of start and end values.
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        intervals[i] = { start, end };
    }

    vector<vector<int>> overlapped = solution.overlappedInterval(intervals);

    cout << "Merged intervals:" << endl;

    // Output the merged intervals.
    for (vector<int> interval : overlapped) {
        cout << interval[0] << " " << interval[1] << endl;
    }

    return 0;
}
