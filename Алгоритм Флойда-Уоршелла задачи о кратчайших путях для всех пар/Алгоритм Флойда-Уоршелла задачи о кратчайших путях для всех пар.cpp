#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

const double INF = numeric_limits<double>::infinity();

vector<vector<vector<double>>> algorithmFloydThreeArray(const vector<vector<double>>& graph) {
    int n = graph.size();
    vector<vector<vector<double>>> A(n + 1, vector<vector<double>>(n, vector<double>(n, INF)));

    for (int v = 0; v < n; ++v) {
        for (int w = 0; w < n; ++w) {
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

    for (int k = 1; k <= n; ++k) {
        for (int v = 0; v < n; ++v) {
            for (int w = 0; w < n; ++w) {
                A[k][v][w] = min(A[k - 1][v][w], A[k - 1][v][k - 1] + A[k - 1][k - 1][w]);
            }
        }
    }

    for (int v = 0; v < n; ++v) {
        if (A[n][v][v] < 0) {
            throw runtime_error("Граф содержит отрицательный цикл");
        }
    }

    return A;
}

void testAlgorithmFloydThreeArray() {
    vector<vector<double>> graph = {
        {0, 3, INF, INF},
        {INF, 0, 1, INF},
        {INF, INF, 0, 7},
        {2, INF, INF, 0}
    };

    auto result = algorithmFloydThreeArray(graph);

    cout << "Кратчайшие пути между всеми парами вершин:\n";
    for (int v = 0; v < graph.size(); ++v) {
        for (int w = 0; w < graph.size(); ++w) {
            if (result[graph.size()][v][w] == INF) {
                cout << "INF ";
            }
            else {
                cout << setw(4) << result[graph.size()][v][w] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    testAlgorithmFloydThreeArray();

    return 0;
}
