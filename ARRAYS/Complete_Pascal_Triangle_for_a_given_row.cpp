#include <iostream>
#include <vector>

// Function to generate a single row of Pascal's Triangle
std::vector<int> generateRow(int row) {
    std::vector<int> ansRow;  // Create a vector to store the current row
    int res = 1;  // Initialize the first element of the row to 1
    ansRow.push_back(res);  // Add the first element to the row

    for (int column = 1; column < row; column++) {
        res = res * (row - column);  // Calculate the next value in the row using the formula (previous_value * (row - column))
        res = res / column;  // Divide the result by 'column' to get the final value for the current position
        ansRow.push_back(res);  // Add the calculated value to the row
    }

    return ansRow;  // Return the generated row
}

// Function to generate Pascal's Triangle with N rows
std::vector<std::vector<int>> pascalTriangle(int N) {
    std::vector<std::vector<int>> ans;  // Create a vector of vectors to represent Pascal's Triangle

    for (int i = 1; i <= N; i++) {
        std::vector<int> temp;  // Create a temporary vector to store the current row
        temp = generateRow(i);  // Generate a row for the current iteration and store it in 'temp'
        ans.push_back(temp);    // Add the current row to Pascal's Triangle
    }

    return ans;  // Return Pascal's Triangle with N rows
}

int main() {
    int N;

    std::cout << "Enter the number of rows for Pascal's Triangle: ";
    std::cin >> N;  // Read the number of rows from the user

    std::vector<std::vector<int>> triangle = pascalTriangle(N);  // Generate Pascal's Triangle with N rows

    std::cout << "Pascal's Triangle with " << N << " rows:" << std::endl;
    for (const auto& row : triangle) {
        for (int val : row) {
            std::cout << val << " ";  // Print each value in the current row
        }
        std::cout << std::endl;  // Move to the next row
    }

    return 0;  // Return 0 to indicate successful program execution
}
