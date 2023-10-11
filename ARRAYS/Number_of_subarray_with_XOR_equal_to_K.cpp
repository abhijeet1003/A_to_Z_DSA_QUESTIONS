#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Function to find the number of subarrays with a sum equal to 'k' in an input array 'a'
int subarraysWithSumK(vector<int> a, int k) {
    int n = a.size(); // Get the size of the input array 'a'
    int xr = 0; // Initialize a variable 'xr' for storing the XOR sum
    int cnt = 0; // Initialize a counter 'cnt' to keep track of subarrays with sum 'k'
    map<int, int> mpp; // Create a map 'mpp' to store XOR sums and their counts
    mpp[xr]++; // Initialize the XOR sum with 0 and set its count to 1

    for (int i = 0; i < n; i++) {
        xr = xr ^ a[i]; // Update the XOR sum by XORing with the current element
        int x = xr ^ k; // Calculate the target XOR sum 'x' by XORing with 'k'

        cnt += mpp[x]; // Update 'cnt' by adding the count of 'x' in the map
        // If 'x' is present, this increases the count; otherwise, it remains unchanged

        mpp[xr] = mpp[xr] + 1; // Update the count of the current XOR sum in the map
        // If the same XOR sum occurs again, increment its count; otherwise, set it to 1
    }

    return cnt; // Return the count of subarrays with sum 'k'
}

int main() {
    // Create a sample input array and specify the value of 'k'
    vector<int> inputArray = {1, 2, 3, 4, 5};
    int k = 3;

    // Call the subarraysWithSumK function to find the number of subarrays with sum 'k'
    int countSubarrays = subarraysWithSumK(inputArray, k);

    // Display the result
    cout << "Number of Subarrays with Sum " << k << ": " << countSubarrays << endl;

    return 0; // Return 0 to indicate successful program execution
}
