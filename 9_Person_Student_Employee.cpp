#include <iostream>
using namespace std;

// Base class
class Person {
protected:
    string name;
public:
    void getData() {
        cout << "Enter name: ";
        cin >> name;
    }

    virtual void display() {
        cout << "Name: " << name << endl;
    }
};

// Derived class Student
class Student : public Person {
    string course;
    int marks;
    int year;
public:
    void getData() {
        Person::getData();
        cout << "Enter course: ";
        cin >> course;
        cout << "Enter marks: ";
        cin >> marks;
        cout << "Enter year: ";
        cin >> year;
    }

    void display() override {
        cout << "\nStudent Details:\n";
        cout << "Name: " << name << endl;
        cout << "Course: " << course << endl;
        cout << "Marks: " << marks << endl;
        cout << "Year: " << year << endl;
    }
};

// Derived class Employee
class Employee : public Person {
    string department;
    float salary;
public:
    void getData() {
        Person::getData();
        cout << "Enter department: ";
        cin >> department;
        cout << "Enter salary: ";
        cin >> salary;
    }

    void display() override {
        cout << "\nEmployee Details:\n";
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Person* ptr; // base class pointer

    Student s;
    Employee e;

    cout << "Enter student details:\n";
    s.getData();

    cout << "\nEnter employee details:\n";
    e.getData();

    // Runtime polymorphism
    ptr = &s;
    ptr->display(); // calls Student display

    ptr = &e;
    ptr->display(); // calls Employee display

    return 0;
}
