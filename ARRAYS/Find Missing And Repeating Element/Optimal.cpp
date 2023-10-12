#include <iostream>
#include <vector>

// Function to find missing and repeating numbers in the input array.
std::vector<int> findMissingRepeatingNumbers(std::vector<int> a) {
    long long n = a.size();
    long long s = (long long)(n * (n + 1)) / 2; // Sum of first 'n' natural numbers
    long long s2 = (long long)(n * (n + 1) * ((2 * n) + 1)) / 6; // Sum of squares of first 'n' natural numbers
    long long sa = 0; // Sum of elements in the input array
    long long s2a = 0; // Sum of squares of elements in the input array

    for (int i = 0; i < n; i++) {
        sa += (a[i]); // Calculate the sum of elements
        s2a += (long long)(a[i] * a[i]); // Calculate the sum of squares of elements
    }

    long long val1 = sa - s; // Calculate X - Y
    long long val2 = s2a - s2; // Calculate X^2 - Y^2

    val2 = val2 / val1; // Calculate X + Y

    long long x = (val2 + val1) / 2; // Calculate X
    long long y = x - val1; // Calculate Y

    return {(int)x, (int)y}; // Return the result as a vector
}

int main() {
    std::vector<int> input = {3, 1, 3, 4, 2}; // Replace this with your input array

    std::vector<int> result = findMissingRepeatingNumbers(input);

    std::cout << "Missing: " << result[0] << " Repeating: " << result[1] << std::endl;

    return 0;
}
