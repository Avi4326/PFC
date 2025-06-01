#include <iostream>
#include <cmath> // for sqrt
using namespace std;

class Triangle {
    float a, b, c;

public:
    void getSides() {
        cout << "Enter three sides of triangle: ";
        cin >> a >> b >> c;
        if (a <= 0 || b <= 0 || c <= 0)
            throw "Sides must be greater than zero!";
        if ((a + b <= c) || (a + c <= b) || (b + c <= a))
            throw "Sum of any two sides must be greater than the third side!";
    }

    // Function to calculate area of a right-angled triangle
    float area(float base, float height) {
        return 0.5 * base * height;
    }

    // Function to calculate area using Heron's formula
    float area() {
        float s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

int main() {
    Triangle t;
    int choice;
    float base, height;

    try {
        cout << "1. Area of Right-Angled Triangle\n";
        cout << "2. Area using Heron's Formula\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter base and height: ";
            cin >> base >> height;
            if (base <= 0 || height <= 0)
                throw "Base and height must be positive.";
            cout << "Area of Right-Angled Triangle = " << t.area(base, height) << endl;
        } else if (choice == 2) {
            t.getSides();
            cout << "Area using Heron's formula = " << t.area() << endl;
        } else {
            cout << "Invalid choice.\n";
        }
    } catch (const char* msg) {
        cout << "Exception: " << msg << endl;
    }

    return 0;
}
