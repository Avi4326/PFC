#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Enter a text string: ";
    getline(cin, input); // Read the full line, including spaces

    // Array to hold the count of each letter (26 letters for a-z)
    int count[26] = {0};

    // Loop through each character in the input string
    for (char ch : input) {
        // Convert uppercase to lowercase
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + 32;
        }

        // Count only alphabet characters
        if (ch >= 'a' && ch <= 'z') {
            count[ch - 'a']++;
        }
    }

    // Display the results
    cout << "Character frequencies:\n";
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            cout << char(i + 'a') << ": " << count[i] << endl;
        }
    }

    return 0;
}

/*
EXPLANATION:
- This version asks the user to type a string during program execution.
- It handles spaces and both uppercase and lowercase letters.
- Example:
    Input: Hello World
    Output: d:1 e:1 h:1 l:3 o:2 r:1 w:1
*/