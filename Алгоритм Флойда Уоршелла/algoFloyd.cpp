#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const double INF = numeric_limits<double>::infinity();

void algorithmFloyd(const vector<vector<double>>& graph, int n) {
    vector<vector<vector<double>>> A(n + 1, vector<vector<double>>(n, vector<double>(n, INF)));

    for (int v = 0; v < n; v++) {
        for (int w = 0; w < n; w++) {
            if (v == w) {
                A[0][v][w] = 0;
            }
            else if (graph[v][w] != INF) {
                A[0][v][w] = graph[v][w];
            }
            else {
                A[0][v][w] = INF;
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int v = 0; v < n; v++) {
            for (int w = 0; w < n; w++) {
                A[k][v][w] = min(A[k - 1][v][w], A[k - 1][v][k - 1] + A[k - 1][k - 1][w]);
            }
        }
    }

    for (int v = 0; v < n; v++) {
        if (A[n][v][v] < 0) {
            cout << "Граф содержит отрицательный цикл." << endl;
            return;
        }
    }

    cout << "Матрица кратчайших расстояний:" << endl;
    for (int v = 0; v < n; v++) {
        for (int w = 0; w < n; w++) {
            if (A[n][v][w] == INF) {
                cout << "INF ";
            }
            else {
                cout << A[n][v][w] << " ";
            }
        }
        cout << endl;
    }
}

void testAlgorithmFloyd() {
    int n = 4;
    vector<vector<double>> graph = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    cout << "Тестовый граф (размер " << n << "):" << endl;
    for (const auto& row : graph) {
        for (double value : row) {
            if (value == INF) {
                cout << "INF ";
            }
            else {
                cout << value << " ";
            }
        }
        cout << endl;
    }
    cout << endl;

    algorithmFloyd(graph, n);
}

int main() {
    setlocale(LC_ALL, "ru");

    testAlgorithmFloyd();

    return 0;
}
