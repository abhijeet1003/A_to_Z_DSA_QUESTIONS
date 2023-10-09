// QUESTIONS
/*

An ARRAY arr given with n elements . Return all the unique elements triplet (arr[i],arr[j],arr[k]) where
i != j != k and the sum of them is 0

*/

/*
INPUT
 12                                                                              
 1 2 3 4 5 6 -6 -5 -4 -3 -2 -1  

OUTPUT 
-6 1 5 
-6 2 4 
-5 -1 6 
-5 1 4
-5 2 3
-4 -2 6
-4 -1 5
-4 1 3
-3 -2 5
-3 -1 4
-3 1 2
-2 -1 3


*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;  // Using the standard namespace to simplify the code

// Function declaration for triplet
vector<vector<int>> triplet(int n, vector<int> &arr);

// Function to find triplets with a sum of zero
vector<vector<int>> triplet(int n, vector<int> &arr) {
    // Sort the input vector in ascending order
    sort(arr.begin(), arr.end());

    // Create a vector to store triplets
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        // Skip duplicate elements (if any) by comparing with the previous element
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        int j = i + 1;       // Initialize the left pointer
        int k = n - 1;       // Initialize the right pointer

        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];  // Calculate the sum of elements at indices i, j, and k

            if (sum < 0) {
                j++;  // If the sum is negative, move the left pointer (j) to the right
            } else if (sum > 0) {
                k--;  // If the sum is positive, move the right pointer (k) to the left
            } else {
                // Found a triplet with a sum of zero
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);  // Add the triplet to the answer vector
                j++;  // Move the left pointer to the right
                k--;  // Move the right pointer to the left

                // Skip duplicate elements (if any) by comparing with the previous elements
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;  // Return the vector containing all triplets with a sum of zero
}

int main() {
    int n;

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

    // Call the triplet function to find triplets with a sum of zero
    vector<vector<int>> result = triplet(n, input);

    // Display the triplets with a sum of zero
    cout << "Triplets with a sum of zero: " << endl;
    for (vector<int> triplet : result) {
        for (int val : triplet) {
            cout << val << " ";  // Print each element of the triplet
        }
        cout << endl;  // Print a newline to separate triplets
    }

    return 0;  // Return 0 to indicate successful program execution
}
