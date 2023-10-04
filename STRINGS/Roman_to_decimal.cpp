/*
Given a string in roman no format (s)  your task is to convert it to an integer . 
Various symbols and their values are given below.
I 1
V 5
X 10
L 50
C 100
D 500
M 1000
*/

// User function template for C++

class Solution {
public:
    int romanToDecimal(string &str) {
        unordered_map <char , int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        int result = 0; // Initialize the result to store the decimal value of the Roman numeral.
        int prevres = 0; // Initialize a variable to keep track of the previous Roman numeral value.

        // Iterate through the characters of the Roman numeral string from right to left.
        for (int i = str.size() - 1; i >= 0; i--) {
            int currentval = roman[str[i]]; // Get the decimal value of the current Roman numeral character.

            // Check if the current value is less than the previous value.
            if (currentval < prevres) {
                result = result - currentval; // Subtract the current value from the result.
            } else {
                result = result + currentval; // Add the current value to the result.
            }

            prevres = currentval; // Update the previous value for the next iteration.
        }

        return result; // Return the final decimal value of the Roman numeral.
    }
};
