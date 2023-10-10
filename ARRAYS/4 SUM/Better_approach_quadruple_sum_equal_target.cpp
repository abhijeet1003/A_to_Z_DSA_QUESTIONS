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
#include <set>
#include <algorithm>

using namespace std;

// Function declaration for fourSum
vector<vector<int>> fourSum(vector<int>& nums, int target);

// Function to find quadruples with the target sum
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();  // Get the size of the input vector
    set<vector<int>> res;  // Create a set to store unique quadruples

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            set<long long> hash;  // Create a set to store unique values

            for(int k = j + 1; k < n; k++) {
                long long sum = nums[i] + nums[j] + nums[k];
                long long fourth = target - sum;

                if(hash.find(fourth) != hash.end()) {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                    sort(temp.begin(), temp.end());  // Sort the quadruple to ensure uniqueness
                    res.insert(temp);  // Add the sorted quadruple to the set
                }
                hash.insert(nums[k]);  // Add the current element to the set
            }
        }
    }

    vector<vector<int>> ans(res.begin(), res.end());  // Convert the set to a vector
    return ans;
}

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

    // Call the fourSum function to find quadruples with the target sum
    vector<vector<int>> result = fourSum(input, target);

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
