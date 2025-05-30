// Practical 5: Write a Program to evaluate a polynomial function.
// Example: f(n) = 4n^2 + 2n + 9

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;
    int result = 4*n*n + 2*n + 9;
    cout << "Value of f(n) = 4n^2 + 2n + 9 is: " << result << endl;
    return 0;
}
