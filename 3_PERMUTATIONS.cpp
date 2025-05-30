// Practical 3: Write a Program that generates all the permutations of a given set of digits,
// with or without repetition.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of digits: ";
    cin >> n;
    vector<int> digits(n);
    cout << "Enter the digits: ";
    for (int i = 0; i < n; ++i)
        cin >> digits[i];

    sort(digits.begin(), digits.end());
    cout << "Permutations without repetition:\n";
    do {
        for (int x : digits) cout << x << " ";
        cout << endl;
    } while (next_permutation(digits.begin(), digits.end()));

    return 0;
}
