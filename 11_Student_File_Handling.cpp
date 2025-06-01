#include <iostream>
#include <fstream>  // For file handling
using namespace std;

class Student {
    int rollNo;
    char name[50];
    char studentClass[20];
    int year;
    float totalMarks;

public:
    void getData() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cin.ignore(); // Clear newline character from buffer

        cout << "Enter Name: ";
        cin.getline(name, 50);

        cout << "Enter Class: ";
        cin.getline(studentClass, 20);

        cout << "Enter Year: ";
        cin >> year;

        cout << "Enter Total Marks: ";
        cin >> totalMarks;
    }

    void showData() const {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Class: " << studentClass << endl;
        cout << "Year: " << year << endl;
        cout << "Total Marks: " << totalMarks << endl;
        cout << "------------------------" << endl;
    }
};

int main() {
    Student s;
    fstream file;

    // Write 5 students to file
    file.open("students.dat", ios::out | ios::binary);
    if (!file) {
        cerr << "Error creating file!" << endl;
        return 1;
    }

    cout << "Enter details for 5 students:\n";
    for (int i = 0; i < 5; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        s.getData();
        file.write(reinterpret_cast<char*>(&s), sizeof(s));
    }
    file.close();

    // Read and display students from file
    file.open("students.dat", ios::in | ios::binary);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    cout << "\nStored Student Records:\n";
    while (file.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        s.showData();
    }
    file.close();

    return 0;
}
