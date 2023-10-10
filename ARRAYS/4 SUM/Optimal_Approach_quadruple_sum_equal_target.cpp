// QUESTIONS
/*

An ARRAY arr given with n elements . Return all the unique elements quadruple (arr[i],arr[j],arr[k],arr[l]) where
i != j != k  != l and the sum of them is equal to target

*/

/*
INPUT
 N=5 K=3 
 A[]={0 0 1 2 1} 

OUTPUT
0 0 1 2


*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    // arr[] : int input array of integers
// k : the quadruple sum required
vector<vector<int>> fourSum(vector<int> &arr, int target) {
    vector<vector<int>> ans;  // Create a vector to store the resulting quadruples
    int n = arr.size();  // Get the size of the input array
    sort(arr.begin(), arr.end());  // Sort the input array in ascending order to simplify the search

    for (int i = 0; i < n; i++) {
        // Skip duplicate elements (if any) by comparing with the previous element
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        for (int j = i + 1; j < n; j++) {
            // Skip duplicate elements (if any) by comparing with the previous element
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;

            int k = j + 1;  // Initialize the left pointer for the remaining elements
            int l = n - 1;  // Initialize the right pointer for the remaining elements

            while (k < l) {
                long long sum = arr[i] + arr[j] + arr[k] + arr[l];  // Calculate the sum of elements at indices i, j, k, and l

                if (sum == target) {
                    // Found a quadruple with the target sum
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);  // Add the quadruple to the result vector

                    k++;  // Move the left pointer to the right
                    l--;  // Move the right pointer to the left

                    // Skip duplicate elements (if any) by comparing with the previous elements
                    while (k < l && arr[k] == arr[k - 1]) k++;
                    while (k < l && arr[l] == arr[l + 1]) l--;
                } else if (sum < target) {
                    k++;  // If the sum is less than the target, move the left pointer to the right
                } else {
                    l--;  // If the sum is greater than the target, move the right pointer to the left
                }
            }
        }
    }
    return ans;  // Return the vector containing all quadruples with the target sum
}

};

int main() {
    int n;
    int target;

    // Prompt the user to enter the number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    // Create a vector to store the input elements
    vector<int> input(n);

    // Prompt the user to enter the elements
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> input[i];  // Read input elements from the user
    }

    // Prompt the user to enter the target sum
    cout << "Enter the target sum: ";
    cin >> target;

    Solution solution;

    // Call the fourSum function to find quadruples with the target sum
    vector<vector<int>> result = solution.fourSum(input, target);

    // Display the quadruples with the target sum
    cout << "Quadruples with the target sum: " << endl;
    for (vector<int> quadruple : result) {
        for (int val : quadruple) {
            cout << val << " ";  // Print each element of the quadruple
        }
        cout << endl;  // Print a newline to separate quadruples
    }

    return 0;  // Return 0 to indicate successful program execution
}

