/*
We can binary search on the array for the index of the minimum element.
 Let ‘low’ and ‘high’ represent the current range and ‘mid’ be the middle
  index of this range. If ‘arr[mid]’ > ‘arr[high]’ then the minimum value 
  lies in the range ‘mid+1’ to ‘high’. Otherwise it lies in the range ‘low’ to ‘mid’. 
*/


/*
INPUT
int arr[] = {4 3 2 1}

OUTPUT

4 times rotated

*/

#include <iostream>
#include <vector>
#include <climits>

// Function to find the rotation index in a rotated sorted array
int findKRotation(std::vector<int> &arr) {
    int n = arr.size();
    int low = 0;         // Initialize the low index
    int high = n - 1;    // Initialize the high index
    int index = -1;      // Initialize the rotation index to -1 (not found)
    int ans = INT_MAX;   // Initialize a variable to store the minimum value

    while (low <= high) {
        int mid = (low + high) / 2;  // Calculate the middle index

        if (arr[low] <= arr[mid]) {
            if (arr[low] < ans) {     // Check if the left subarray is sorted and contains a minimum value
                ans = arr[low];       // Update the minimum value
                index = low;          // Update the rotation index
            }
            low = mid + 1;           // Move to the right subarray
        } else {
            if (arr[mid] < ans) {     // Check if the right subarray contains a minimum value
                ans = arr[mid];       // Update the minimum value
                index = mid;          // Update the rotation index
            }
            high = mid - 1;          // Move to the left subarray
        }
    }

    return index;  // Return the rotation index
}

int main() {
    std::vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int rotationIndex = findKRotation(arr);
    std::cout << "Array is rotated at index: " << rotationIndex << std::endl;

    return 0;
}
