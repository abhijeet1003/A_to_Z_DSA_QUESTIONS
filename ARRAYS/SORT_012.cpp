//                              QUESTION

/*Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.*/


//                                BETTER APPROACH

void sortArray(vector<int>& arr, int n) {
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    // Count the number of 0s, 1s, and 2s in the array
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) cnt0++; // Increment the count for 0s
        else if (arr[i] == 1) cnt1++; // Increment the count for 1s
        else cnt2++; // Increment the count for 2s
    }

    // Replace the places in the original array:

    // Replace 0s in the array
    for (int i = 0; i < cnt0; i++) {
        arr[i] = 0;
    }

    // Replace 1s in the array
    for (int i = cnt0; i < cnt0 + cnt1; i++) {
        arr[i] = 1;
    }

    // Replace 2s in the array
    for (int i = cnt0 + cnt1; i < n; i++) {
        arr[i] = 2;
    }
}





//                                OPTIMAL APPROACH

//                          DUTCH NATIONAL FLAG ALGORITHM



class solution {
public:
    void sort012(int a[], int n)
    {
        int mid = 0; // Initialize the midpoint index
        int low = 0; // Initialize the low index
        int high = n - 1; // Initialize the high index
        
        while (mid <= high) { // Continue until the midpoint is less than or equal to the high index
            if (a[mid] == 0) { // If the current element is 0
                swap(a[low], a[mid]); // Swap the element at the low index with the element at the midpoint index
                low++; // Increment the low index
                mid++; // Increment the midpoint index
            }
            else if (a[mid] == 1) { // If the current element is 1
                mid++; // Increment the midpoint index
            }
            else { // If the current element is 2
                swap(a[mid], a[high]); // Swap the element at the midpoint index with the element at the high index
                high--; // Decrement the high index
            }
        }
    }
};