// Practical 2: Create a class RELATION using Matrix notation to represent a relation.
// Include member functions to check if the relation is Reflexive, Symmetric, Anti-symmetric, Transitive.
// Also determine if the relation is an Equivalence or Partial Order or None.

#include <iostream>
using namespace std;

class RELATION {
    int matrix[10][10];
    int n;

public:
    void input() {
        cout << "Enter number of elements: ";
        cin >> n;
        cout << "Enter relation matrix (0 or 1):\n";
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> matrix[i][j];
    }

    bool isReflexive() {
        for (int i = 0; i < n; ++i)
            if (matrix[i][i] != 1) return false;
        return true;
    }

    bool isSymmetric() {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (matrix[i][j] != matrix[j][i]) return false;
        return true;
    }

    bool isAntisymmetric() {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (i != j && matrix[i][j] == 1 && matrix[j][i] == 1)
                    return false;
        return true;
    }

    bool isTransitive() {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    if (matrix[i][j] && matrix[j][k] && !matrix[i][k])
                        return false;
        return true;
    }

    void checkRelationType() {
        bool ref = isReflexive();
        bool sym = isSymmetric();
        bool anti = isAntisymmetric();
        bool trans = isTransitive();

        cout << "Reflexive: " << (ref ? "Yes" : "No") << endl;
        cout << "Symmetric: " << (sym ? "Yes" : "No") << endl;
        cout << "Anti-symmetric: " << (anti ? "Yes" : "No") << endl;
        cout << "Transitive: " << (trans ? "Yes" : "No") << endl;

        if (ref && sym && trans)
            cout << "Relation is Equivalence Relation\n";
        else if (ref && anti && trans)
            cout << "Relation is Partial Order\n";
        else
            cout << "Relation is neither Equivalence nor Partial Order\n";
    }
};

int main() {
    RELATION r;
    r.input();
    r.checkRelationType();
    return 0;
}
