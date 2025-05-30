// Practical 7: Write a Program to accept a directed graph and compute in-degree and out-degree of each vertex.

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    int graph[10][10], indeg[10] = {0}, outdeg[10] = {0};

    cout << "Enter adjacency matrix (0 or 1):\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
            outdeg[i] += graph[i][j];
            indeg[j] += graph[i][j];
        }

    for (int i = 0; i < n; ++i)
        cout << "Vertex " << i << ": In-degree = " << indeg[i] << ", Out-degree = " << outdeg[i] << endl;

    return 0;
}
