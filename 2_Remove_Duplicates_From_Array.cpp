#include <iostream>
using namespace std;

// Function to remove duplicates from an array
int removeDuplicates(int arr[], int n, int newArr[]) {
    int newSize = 0;

    // Loop through each element
    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;

        // Check if the current element already exists in newArr
        for (int j = 0; j < newSize; j++) {
            if (arr[i] == newArr[j]) {
                isDuplicate = true;
                break;
            }
        }

        // If not duplicate, add to newArr
        if (!isDuplicate) {
            newArr[newSize] = arr[i];
            newSize++;
        }
    }

    return newSize; // Return the size of new array
}

int main() {
    int arr[100], n;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int uniqueArr[100]; // This will store the array without duplicates
    int uniqueSize = removeDuplicates(arr, n, uniqueArr);

    cout << "Array after removing duplicates:";
    for (int i = 0; i < uniqueSize; i++) {
        cout << uniqueArr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
EXPLANATION:
- We take an array of integers from the user.
- We compare each element with the ones already added to a new array.
- If it's not found in the new array, we add it (i.e., it's unique).
- This way we eliminate any duplicates.
- Example:
    Input: 5 elements → 1 2 2 3 1
    Output: 1 2 3
*/
