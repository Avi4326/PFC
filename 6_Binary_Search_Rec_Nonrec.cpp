// 6_binary_search_rec_nonrec.cpp
// Program to search a given element using binary search:
// (a) with recursion
// (b) without recursion
// Concepts used: arrays, functions, recursion, loops — Unit 2 topics

#include <iostream>
using namespace std;

// Recursive binary search function
int binarySearchRecursive(int arr[], int left, int right, int key) {
    // Base condition: when search range is valid
    if (left <= right) {
        int mid = (left + right) / 2; // Calculate middle index

        if (arr[mid] == key)
            return mid; // Key found at mid
        else if (key < arr[mid])
            return binarySearchRecursive(arr, left, mid - 1, key); // Search in left half
        else
            return binarySearchRecursive(arr, mid + 1, right, key); // Search in right half
    }
    return -1; // Key not found
}

// Non-recursive (iterative) binary search function
int binarySearchIterative(int arr[], int size, int key) {
    int left = 0, right = size - 1;

    // Keep searching while the range is valid
    while (left <= right) {
        int mid = (left + right) / 2; // Calculate middle index

        if (arr[mid] == key)
            return mid; // Key found
        else if (key < arr[mid])
            right = mid - 1; // Eliminate right half
        else
            left = mid + 1; // Eliminate left half
    }
    return -1; // Key not found
}

int main() {
    int n, key;

    // Step 1: Take input for array size
    cout << "Enter number of elements in the sorted array: ";
    cin >> n;
    int* arr = new int[n]; // Dynamically allocate array of size 'n'

    // Step 2: Input sorted elements
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 3: Input the element to be searched
    cout << "Enter the element to search for: ";
    cin >> key;

    // Step 4: Perform recursive binary search
    int resultRec = binarySearchRecursive(arr, 0, n - 1, key);
    if (resultRec != -1)
        cout << "Recursive: Element found at index " << resultRec << endl;
    else
        cout << "Recursive: Element not found." << endl;

    // Step 5: Perform iterative binary search
    int resultIter = binarySearchIterative(arr, n, key);
    if (resultIter != -1)
        cout << "Non-Recursive: Element found at index " << resultIter << endl;
    else
        cout << "Non-Recursive: Element not found." << endl;

    delete[] arr; // Free dynamically allocated memory
    return 0;
}

/*
------------------------- EXPLANATION -------------------------

This program demonstrates binary search using two approaches:
1. Recursive method
2. Iterative (loop-based) method

How Binary Search works:
- It works only on sorted arrays.
- It divides the search space in half each time by comparing the key with the middle element.

Steps:
1. User inputs a sorted array and the target key to search.
2. The recursive function calls itself by narrowing the search range.
3. The iterative function does the same using a while loop.
4. Both return the index if found or -1 if not found.

---------------------------------------------------------------
*/
