#include <iostream>
#include <vector>
#include<bits/stdc++.h>

// Function declaration for majorityElement
std::vector<int> majorityElement(std::vector<int> v);

// Function to find majority elements in a vector
std::vector<int> majorityElement(std::vector<int> v) {
    int cnt1 = 0;            // Initialize count for the first candidate
    int cnt2 = 0;            // Initialize count for the second candidate
    std::vector<int> ans;    // Create a vector to store the majority elements
    int ele1 = INT_MIN;      // Initialize the first candidate to a very small value
    int ele2 = INT_MIN;      // Initialize the second candidate to a very small value
    int n = v.size();        // Get the size of the input vector

    // First loop to find potential majority candidates
    for (int i = 0; i < n; i++) {
        // Check if the count for the first candidate is 0 and the current element is not the second candidate
        if (cnt1 == 0 && ele2 != v[i]) {
            cnt1 = 1;         // Reset the count for the first candidate
            ele1 = v[i];      // Update the first candidate
        } 
        // Check if the count for the second candidate is 0 and the current element is not the first candidate
        else if (cnt2 == 0 && ele1 != v[i]) {
            cnt2 = 1;         // Reset the count for the second candidate
            ele2 = v[i];      // Update the second candidate
        } 
        // Check if the current element is the first candidate
        else if (v[i] == ele1)
            cnt1++;            // Increment the count for the first candidate
        // Check if the current element is the second candidate
        else if (v[i] == ele2)
            cnt2++;            // Increment the count for the second candidate
        else {
            cnt1--;            // Decrement the count for the first candidate
            cnt2--;            // Decrement the count for the second candidate
        }
    }

    cnt1 = 0;                  // Reset the count for the first candidate
    cnt2 = 0;                  // Reset the count for the second candidate

    // Second loop to count occurrences of potential majority candidates
    for (int i = 0; i < n; i++) {
        if (ele1 == v[i])
            cnt1++;            // Count occurrences of the first candidate
        if (ele2 == v[i])
            cnt2++;            // Count occurrences of the second candidate
    }

    int mini = int(n / 3) + 1;  // Calculate the minimum threshold for majority

    // Check if potential candidates meet the majority criteria and add them to 'ans'
    if (cnt1 >= mini)
        ans.push_back(ele1);
    if (cnt2 >= mini)
        ans.push_back(ele2);

    sort(ans.begin(), ans.end());  // Sort the 'ans' vector

    if (ans.size() == 0)
        return {-1};  // Return -1 if 'ans' is empty

    return ans;  // Return the majority elements
}

// Main function to take input, call majorityElement, and display results
int main() {
    int n;

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::vector<int> input(n);  // Create a vector to store the input elements

    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> input[i];  // Read input elements from the user
    }

    std::vector<int> result = majorityElement(input);  // Call the majorityElement function

    std::cout << "Majority Elements: ";
    for (int val : result) {
        std::cout << val << " ";  // Print the majority elements
    }
    std::cout << std::endl;

    return 0;  // Return 0 to indicate successful program execution
}
