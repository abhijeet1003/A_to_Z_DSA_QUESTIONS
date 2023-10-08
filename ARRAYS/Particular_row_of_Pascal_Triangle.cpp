#include <iostream>  // Include the necessary standard library for input/output
#include <vector>    // Include the necessary standard library for vectors

typedef long long ll;  // Define an alias for "long long" as "ll" for convenience

class Solution {
public:
    // Function to calculate the nth row of Pascal's Triangle
    std::vector<ll> nthRowOfPascalTriangle(int n) {
        long long mod = 1000000007;  // Define a constant for modulo operation
        if (n == 1)
            return {1};  // If n is 1, return a vector with the first row, which is {1}

        std::vector<std::vector<ll>> result;  // Create a vector of vector to store Pascal's triangle
        result.push_back({1});  // Initialize the first row with {1}
        result.push_back({1, 1});  // Initialize the second row with {1, 1}

        for (int i = 2; i < n; i++) {  // Build Pascal's Triangle up to the nth row, starting with the 3rd row
            std::vector<ll> curr_row;  // Create a vector to represent the current row
            curr_row.push_back(1);  // The first element of each row is always 1

            for (int j = 1; j < i; j++) {
                ll next_value = (result[i - 1][j - 1] + result[i - 1][j]) % mod;  // Calculate the next value in the current row
                curr_row.push_back(next_value);  // Add the calculated value to the current row
            }

            curr_row.push_back(1);  // The last element of the current row is always 1
            result.push_back(curr_row);  // Add the current row to the triangle
        }
        return result[n - 1];  // Return the nth row of Pascal's Triangle
    }
};

int main() {
    Solution solution;  // Create an instance of the Solution class
    int n;

    std::cout << "Enter the value of n: ";
    std::cin >> n;  // Read the value of n from the user

    std::vector<ll> nthRow = solution.nthRowOfPascalTriangle(n);  // Calculate the nth row using the Solution class

    std::cout << "The " << n << "th row of Pascal's triangle: ";
    for (ll val : nthRow) {
        std::cout << val << " ";  // Print the elements of the nth row
    }
    std::cout << std::endl;  // Print a newline

    return 0;  // Return 0 to indicate successful program execution
}
