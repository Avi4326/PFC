// Practical 6: Write a Program to check if a given graph is a complete graph.
// Represent using Adjacency Matrix.

#include <iostream>
using namespace std;

int main() {
    int n, isComplete = 1;
    cout << "Enter number of vertices: ";
    cin >> n;
    int graph[10][10];

    cout << "Enter adjacency matrix (0 or 1):\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> graph[i][j];

    for (int i = 0; i < n && isComplete; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j && graph[i][j] == 0)
                isComplete = 0;

    cout << (isComplete ? "Graph is complete" : "Graph is not complete") << endl;
    return 0;
}
