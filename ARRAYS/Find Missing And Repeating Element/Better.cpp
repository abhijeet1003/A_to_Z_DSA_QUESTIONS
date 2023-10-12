#include <iostream>
#include <vector>

class Solution {
public:
    // Function to find repeating and missing elements in the array.
    std::vector<int> findTwoElement(std::vector<int> arr, int n) {
        int repeat = -1;   // Variable to store the repeating element.
        int missing = -1;  // Variable to store the missing element.
        int hash[n + 1] = {0};  // Create an array to count occurrences of each element.

        // Count the occurrences of each element in the array.
        for (int i = 0; i < n; i++) {
            hash[arr[i]]++;
        }

        // Find the repeating and missing elements.
        for (int i = 1; i <= n; i++) {
            if (hash[i] == 2) {
                repeat = i;  // If an element occurs twice, it is the repeating element.
            } else if (hash[i] == 0) {
                missing = i; // If an element doesn't occur, it is the missing element.
            }

            // If both the repeat and missing elements are found, exit the loop.
            if (repeat != -1 && missing != -1) break;
        }

        return {repeat, missing};  // Return the result as a vector.
    }
};

int main() {
    Solution solution;

    std::vector<int> input = {4, 3, 2, 7, 8, 2, 1, 5}; // Replace this with your input array
    int n = input.size();  // Get the size of the input array.

    std::vector<int> result = solution.findTwoElement(input, n);  // Call the findTwoElement function.

    // Print the results to the console.
    std::cout << "Repeating element: " << result[0] << " Missing element: " << result[1] << std::endl;

    return 0;
}
