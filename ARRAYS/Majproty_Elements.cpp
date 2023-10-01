//   questions


/*
Given an array A of N elements. Find the majority element in 
the array. A majority element in an array A of size N is an 
element that appears strictly more than N/2 times in the array.
*/


/*  first one is better approach using map data structure*/


class Solution {
public:
    // Function to find the majority element in the array
    // a: input array
    // size: size of the input array
    int majorityElement(int a[], int size) {
        // Create an unordered map to store the count of each element
        unordered_map<int, int> mp;
        
        // Iterate through the input array to count occurrences of each element
        for (int i = 0; i < size; i++) {
            mp[a[i]]++;
        }
        
        // Iterate through the elements and their counts in the map
        for (auto it : mp) {
            // Check if the count of the element is greater than half of the array size
            if (it.second > (size / 2)) {
                // If the above condition is met, return the majority element
                return it.first;
            }
        }
        
        // If there is no majority element, return -1
        return -1;
    }
};


/*second one is best optimal approach using famous algortham*/

//   MOORE'S VOOTING ALGORITHM


class Solution {
public:
    // Function to find the majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int size) {
        int count = 0;        // Initialize a count variable to keep track of the current element's count.
        int element;          // Initialize a variable to store the potential majority element.

        // Iterate through the input array.
        for (int i = 0; i < size; i++) {
            // If the count is zero, set the current element as the potential majority element.
            if (count == 0) {
                count = 1;
                element = arr[i];
            } else if (arr[i] == element) {
                // If the current element matches the potential majority element, increment the count.
                count++;
            } else {
                // If the current element is different, decrement the count.
                count--;
            }
        }

        int count1 = 0;  // Initialize a count variable to count occurrences of the potential majority element.

        // Iterate through the input array again to count occurrences of the potential majority element.
        for (int i = 0; i < size; i++) {
            if (arr[i] == element) {
                count1++;
            }
        }

        // Check if the count of the potential majority element is greater than half of the array size.
        if (count1 > (size / 2)) {
            // If the condition is met, return the potential majority element.
            return element;
        }

        // If there is no majority element, return -1.
        return -1;
    }
};
