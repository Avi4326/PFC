#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

class SET
{
    set<int> s;

public:
    void input(int n)
    {
        s.clear();
        int temp;
        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            s.insert(temp);
        }
    }

    void display()
    {
        cout << "{ ";
        for (int x : s)
            cout << x << " ";
        cout << "}" << endl;
    }

    bool isMember(int x)
    {
        return s.count(x) > 0;
    }

    void powerSet()
    {
        vector<int> v(s.begin(), s.end());
        int powSize = pow(2, v.size());
        for (int i = 0; i < powSize; i++)
        {
            cout << "{ ";
            for (int j = 0; j < v.size(); j++)
            {
                if (i & (1 << j))
                    cout << v[j] << " ";
            }
            cout << "}" << endl;
        }
    }

    bool isSubset(SET &other)
    {
        // Correct logic: check if *this is a subset of other
        return includes(other.s.begin(), other.s.end(), s.begin(), s.end());
    }

    SET setUnion(SET &other)
    {
        SET result;
        set_union(s.begin(), s.end(), other.s.begin(), other.s.end(),
                  inserter(result.s, result.s.begin()));
        return result;
    }

    SET setIntersection(SET &other)
    {
        SET result;
        set_intersection(s.begin(), s.end(), other.s.begin(), other.s.end(),
                         inserter(result.s, result.s.begin()));
        return result;
    }

    SET setDifference(SET &other)
    {
        SET result;
        set_difference(s.begin(), s.end(), other.s.begin(), other.s.end(),
                       inserter(result.s, result.s.begin()));
        return result;
    }

    SET symmetricDifference(SET &other)
    {
        SET result;
        set_symmetric_difference(s.begin(), s.end(), other.s.begin(), other.s.end(),
                                 inserter(result.s, result.s.begin()));
        return result;
    }

    SET complement(SET &universal)
    {
        return universal.setDifference(*this);
    }

    void cartesianProduct(SET &other)
    {
        for (int a : s)
        {
            for (int b : other.s)
            {
                cout << "(" << a << ", " << b << ") ";
            }
        }
        cout << endl;
    }
};

int main()
{
    SET A, B, U;
    int choice, x, n;

    cout << "Enter number of elements for Set A: ";
    cin >> n;
    A.input(n);

    cout << "Enter number of elements for Set B: ";
    cin >> n;
    B.input(n);

    cout << "Enter number of elements for Universal Set: ";
    cin >> n;
    U.input(n);

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Is Member\n";
        cout << "2. Power Set\n";
        cout << "3. Subset\n";
        cout << "4. Union\n";
        cout << "5. Intersection\n";
        cout << "6. Complement\n";
        cout << "7. Set Difference\n";
        cout << "8. Symmetric Difference\n";
        cout << "9. Cartesian Product\n";
        cout << "10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element to check: ";
            cin >> x;
            cout << (A.isMember(x) ? "True" : "False") << endl;
            break;

        case 2:
            A.powerSet();
            break;

        case 3:
            cout << (A.isSubset(B) ? "A is subset of B" : "A is not subset of B") << endl;
            break;

        case 4:
            cout << "A ∪ B = ";
            A.setUnion(B).display();
            break;

        case 5:
            cout << "A ∩ B = ";
            A.setIntersection(B).display();
            break;

        case 6:
            cout << "A' (complement of A) = ";
            A.complement(U).display();
            break;

        case 7:
            cout << "A - B = ";
            A.setDifference(B).display();
            break;

        case 8:
            cout << "A △ B (Symmetric Difference) = ";
            A.symmetricDifference(B).display();
            break;

        case 9:
            cout << "A × B = ";
            A.cartesianProduct(B);
            break;

        case 10:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 10);

    return 0;
}
