/*
Given a sorted array arr[] of size N. 
Find the element that appears only once in the array. All other elements appear exactly twice. 
*/

/*
Input:
N = 11
arr[] = {1, 1, 2, 2, 3, 3, 4, 50, 50, 65, 65}
Output: 4
Explanation: 4 is the only element that 
appears exactly once.
*/

#include <iostream>

class Solution {
public:
    // Function to find the element that appears only once in a sorted array
    int findOnce(int arr[], int n) {
        // If there's only one element, return it
        if (n == 1)
            return arr[0];

        // If the first element is not equal to the second element, return the first element
        if (arr[0] != arr[1])
            return arr[0];

        // If the last element is not equal to the second-to-last element, return the last element
        if (arr[n - 1] != arr[n - 2])
            return arr[n - 1];

        // Binary search to find the element that appears only once
        int low = 1;
        int high = n - 2;
        while (low <= high) {
            int mid = (low + high) / 2;

            // If the element at 'mid' is not equal to the adjacent elements, return it
            if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
                return arr[mid];

            // If 'mid' is an even index and the element is equal to the next one, adjust the range
            if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) ||
                // If 'mid' is an odd index and the element is equal to the previous one, adjust the range
                (mid % 2 == 1 && arr[mid] == arr[mid - 1]))
                low = mid + 1;
            else
                high = mid - 1;
        }

        // If no element appears only once, return -1
        return -1;
    }
};

int main() {
    Solution solution;
    int arr[] = {1, 1, 2, 2, 3, 4, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = solution.findOnce(arr, n);

    if (result != -1) {
        std::cout << "The element that appears only once is: " << result << std::endl;
    } else {
        std::cout << "No element appears only once in the array." << std::endl;
    }

    return 0;
}

