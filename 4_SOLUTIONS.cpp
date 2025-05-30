// Practical 4: For any number n, write a program to list all the solutions of the equation
// x1 + x2 + ... + xn = C where C <= 10, and x1...xn are nonnegative integers (brute force).

#include <iostream>
using namespace std;

int count = 0;
void solve(int n, int C, int arr[], int index = 0, int sum = 0) {
    if (index == n) {
        if (sum == C) {
            for (int i = 0; i < n; ++i)
                cout << arr[i] << " ";
            cout << endl;
            count++;
        }
        return;
    }
    for (int i = 0; i <= C - sum; ++i) {
        arr[index] = i;
        solve(n, C, arr, index + 1, sum + i);
    }
}

int main() {
    int n, C;
    cout << "Enter number of variables (n): ";
    cin >> n;
    cout << "Enter value of constant (C <= 10): ";
    cin >> C;

    int arr[10];
    cout << "Solutions:\n";
    solve(n, C, arr);
    cout << "Total solutions: " << count << endl;
    return 0;
}
