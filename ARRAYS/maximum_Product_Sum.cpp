//                                              QUESTIONS

/*
Given an array Arr[] that contains
 N integers (may be positive, negative or zero). Find the product of the maximum product subarray.
*/

/*
Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180
Explanation: Subarray with maximum product
is [6, -3, -10] which gives product as 180.
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    // Function to find the maximum product subarray
    long long maxProduct(vector<int> arr, int n) {
        long long pre = 1, suff = 1; // Initialize prefix and suffix product variables.
        long long maxi = INT_MIN; // Initialize a variable to store the maximum product found.

        for (int i = 0; i < n; i++) {
            if (pre == 0) pre = 1; // Reset prefix product to 1 if it becomes 0.
            if (suff == 0) suff = 1; // Reset suffix product to 1 if it becomes 0.

            pre = pre * arr[i]; // Update prefix product by multiplying it with the current element.
            suff = suff * arr[n - i - 1]; // Update suffix product by multiplying it with the current element (in reverse order).

            maxi = max(maxi, max(pre, suff)); // Update the maximum product found by comparing it with both prefix and suffix products.
        }
        return maxi; // Return the maximum product of a subarray.
    }
};

int main() {
    Solution solution;

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long result = solution.maxProduct(arr, n); // Call the maxProduct function and store the result.

    cout << "Maximum Product of Subarray: " << result << endl; // Display the maximum product.

    return 0;
}
