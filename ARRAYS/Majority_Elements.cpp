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



