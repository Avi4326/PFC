#include <iostream>
using namespace std;

int main() {
    int sizeA, sizeB;

    // Input size of array A
    cout << "Enter the number of elements in first array: ";
    cin >> sizeA;

    // Dynamically allocate array A
    int* A = new int[sizeA];

    // Input elements of array A (assumed to be sorted)
    cout << "Enter elements of first array (sorted): ";
    for (int i = 0; i < sizeA; i++) {
        cin >> A[i];
    }

    // Input size of array B
    cout << "Enter the number of elements in second array: ";
    cin >> sizeB;

    // Dynamically allocate array B
    int* B = new int[sizeB];

    // Input elements of array B (assumed to be sorted)
    cout << "Enter elements of second array (sorted): ";
    for (int i = 0; i < sizeB; i++) {
        cin >> B[i];
    }

    // Dynamically allocate merged array C
    int* C = new int[sizeA + sizeB];

    // Copy elements of A to C
    for (int i = 0; i < sizeA; i++) {
        C[i] = A[i];
    }

    // Copy elements of B to C after elements of A
    for (int i = 0; i < sizeB; i++) {
        C[sizeA + i] = B[i];
    }

    // Sort the merged array using bubble sort
    for (int i = 0; i < sizeA + sizeB - 1; i++) {
        for (int j = 0; j < sizeA + sizeB - i - 1; j++) {
            if (C[j] > C[j + 1]) {
                // Swap C[j] and C[j + 1]
                int temp = C[j];
                C[j] = C[j + 1];
                C[j + 1] = temp;
            }
        }
    }

    // Output the sorted merged array
    cout << "Merged and Sorted Array: ";
    for (int i = 0; i < sizeA + sizeB; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    return 0;
}
// EXPLANATION:
// - This program merges two sorted arrays into a single sorted array.
// - It first takes the sizes and elements of both arrays from the user.
// - It then merges the two arrays into a new array and sorts it using bubble sort.
// - Finally, it outputs the sorted merged array.