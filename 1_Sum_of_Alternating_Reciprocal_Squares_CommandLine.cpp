#include <iostream>
#include <cmath>      // For pow() function
#include <cstdlib>    // For atoi() function to convert command-line argument to int
using namespace std;

// Main function starts here
int main(int argc, char* argv[]) {
    int n;

    // Check if user has entered command-line argument
    if (argc < 2) {
        cout << "Please enter the number of terms (n): ";
        cin >> n;
    } else {
        // Convert command-line argument (which is a string) to an integer
        n = atoi(argv[1]);
    }

    double sum = 0.0; // To store the result of the series

    // Loop to calculate the sum of the series
    for (int i = 1; i <= n; i++) {
        // pow(i, 2) calculates i raised to the power 2 (i.e., i^2)
        // We alternate signs: subtract if i is even, add if i is odd
        if (i % 2 == 0)
            sum -= 1.0 / pow(i, 2);
        else
            sum += 1.0 / pow(i, 2);
    }

    // Output the result
    cout << "The sum of the series is: " << sum << endl;

    return 0;
}

/*
EXPLANATION:
- This program computes: S = 1 - 1/2^2 + 1/3^2 - 1/4^2 + ... upto n terms
- User can provide n via command line, or the program asks for it
- It uses a loop from 1 to n and adjusts the sign of each term
- We use pow(i, 2) to square i
- Example:
    For n = 3 → S = 1 - 1/4 + 1/9 = 1 - 0.25 + 0.111... ≈ 0.8611
*/
