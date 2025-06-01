// 7_gcd_rec_nonrec.cpp
// Program to calculate GCD of two numbers:
// (a) with recursion
// (b) without recursion
// Concepts used: functions, recursion, loops — from Unit 2

#include <iostream>
using namespace std;

// Recursive GCD function using Euclidean algorithm
int gcdRecursive(int a, int b) {
    if (b == 0)
        return a;
    return gcdRecursive(b, a % b);
}

// Non-recursive GCD function
int gcdIterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;

    cout << "Enter two positive integers: ";
    cin >> num1 >> num2;

    // Recursive method
    int resultRec = gcdRecursive(num1, num2);
    cout << "GCD (Recursive): " << resultRec << endl;

    // Iterative method
    int resultIter = gcdIterative(num1, num2);
    cout << "GCD (Non-Recursive): " << resultIter << endl;

    return 0;
}

/*
------------------------- EXPLANATION -------------------------

This program calculates the GCD (Greatest Common Divisor) of two numbers.

Two methods are used:
1. Recursive method using the Euclidean algorithm
2. Iterative method (loop-based)

How Euclidean Algorithm Works:
- GCD(a, b) = GCD(b, a % b)
- Base case is when b becomes 0; then GCD is a

Steps:
1. Take two numbers as input.
2. Use both recursive and iterative functions to find the GCD.
3. Print the results.

---------------------------------------------------------------
*/
