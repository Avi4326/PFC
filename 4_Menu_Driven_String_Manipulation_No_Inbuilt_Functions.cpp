#include <iostream>
using namespace std;

#define MAX 100

// a. Show address of each character
void showAddress(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        cout << str[i] << "= " << (void*)&str[i] << endl;
    }
}

// b. Concatenate two strings
void concatenate(char str1[], char str2[], char result[]) {
    int i = 0, j = 0;
    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }
    while (str2[j] != '\0') {
        result[i] = str2[j];
        i++;
        j++;
    }
    result[i] = '\0';
}

// c. Compare two strings
bool compare(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i])
            return false;
        i++;
    }
    return true;
}

// d. Calculate length of string (using pointers)
int stringLength(char* ptr) {
    int len = 0;
    while (*ptr != '\0') {
        len++;
        ptr++;
    }
    return len;
}

// e. Convert lowercase to uppercase
void toUpperCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
}

// f. Reverse string
void reverseString(char str[]) {
    int len = 0;
    while (str[len] != '\0') len++;

    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

// g. Insert string at position
void insertString(char base[], char insert[], int pos) {
    char result[MAX];
    int i = 0, j = 0, k = 0;

    // Copy characters before position
    while (i < pos && base[i] != '\0') {
        result[k++] = base[i++];
    }

    // Insert new string
    while (insert[j] != '\0') {
        result[k++] = insert[j++];
    }

    // Append remaining original string
    while (base[i] != '\0') {
        result[k++] = base[i++];
    }
    result[k] = '\0';

    cout << "Resulting String: " << result << endl;
}

// Main function with menu
int main() {
    char str1[MAX], str2[MAX], result[MAX];
    int choice, pos;

    cout << "Enter first string: ";
    cin.getline(str1, MAX);

    do {
        cout << "\nMenu:\n";
        cout << "1. Show address of each character\n";
        cout << "2. Concatenate two strings\n";
        cout << "3. Compare two strings\n";
        cout << "4. Calculate length of string\n";
        cout << "5. Convert to uppercase\n";
        cout << "6. Reverse the string\n";
        cout << "7. Insert string at a position\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                showAddress(str1);
                break;
            case 2:
                cout << "Enter second string: ";
                cin.getline(str2, MAX);
                concatenate(str1, str2, result);
                cout << "Concatenated String: " << result << endl;
                break;
            case 3:
                cout << "Enter second string: ";
                cin.getline(str2, MAX);
                if (compare(str1, str2))
                    cout << "Strings are equal\n";
                else
                    cout << "Strings are not equal\n";
                break;
            case 4:
                cout << "Length of string: " << stringLength(str1) << endl;
                break;
            case 5:
                toUpperCase(str1);
                cout << "Uppercase: " << str1 << endl;
                break;
            case 6:
                reverseString(str1);
                cout << "Reversed String: " << str1 << endl;
                break;
            case 7:
                cout << "Enter string to insert: ";
                cin.getline(str2, MAX);
                cout << "Enter position to insert at (0-based): ";
                cin >> pos;
                cin.ignore();
                insertString(str1, str2, pos);
                break;
            case 8:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 8);

    return 0;
}

/*
EXPLANATION:
This is a full menu-driven program that handles string operations manually:
- It does NOT use string libraries.
- All logic like comparing, concatenating, reversing, length, etc., is done using loops and arrays.
- User can keep performing operations until they choose to exit.
- Very beginner friendly, step-by-step explanation and basic operations shown clearly.
*/
