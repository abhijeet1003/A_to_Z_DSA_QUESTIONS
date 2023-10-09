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
#include <set>
#include <algorithm>

using namespace std;

// Function declaration for triplet
vector<vector<int>> triplet(int n, vector<int> &arr);

// Function to find triplets with a sum of zero
vector<vector<int>> triplet(int n, vector<int> &arr) {
    set<vector<int>> st;  // Create a set to store unique triplets

    for (int i = 0; i < n; i++) {
        set<int> hash;  // Create a set to store unique values

        for (int j = i + 1; j < n; j++) {
            int third = -(arr[i] + arr[j]);  // Calculate the third element needed for the sum to be zero

            if (hash.find(third) != hash.end()) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());  // Sort the triplet to ensure uniqueness
                st.insert(temp);  // Add the sorted triplet to the set
            }
            hash.insert(arr[j]);  // Add the current element to the set
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());  // Convert the set to a vector
    return ans;
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

