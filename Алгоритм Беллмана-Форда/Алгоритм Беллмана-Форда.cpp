#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const double INF = numeric_limits<double>::infinity();

struct Edge {
    int from, to;
    double weight;
};

vector<double> algorithmBellmanFord(int n, int s, const vector<Edge>& edges) {
    vector<double> dist(n, INF);
    dist[s] = 0;

    for (int i = 1; i <= n; ++i) {
        bool stop = true;

        for (const auto& el : edges) {
            if (dist[el.from] != INF &&
                dist[el.to] > dist[el.from] + el.weight) {
                dist[el.to] = dist[el.from] + el.weight;
                stop = false;
            }
        }

        if (stop) {
            return dist;
        }
    }

    for (const auto& el : edges) {
        if (dist[el.from] != INF &&
            dist[el.to] > dist[el.from] + el.weight) {
            throw runtime_error("Граф содержит отрицательный цикл!");
        }
    }

    return dist;
}

void testAlgorithmBellmanFord() {
    int n = 5;
    int s = 0;

    vector<Edge> edges = {
        {0, 1, 6},
        {0, 2, 7},
        {1, 2, 8},
        {1, 3, 5},
        {1, 4, -4},
        {2, 3, -3},
        {2, 4, 9},
        {3, 1, -2},
        {4, 3, 7}
    };

    try {
        vector<double> distances = algorithmBellmanFord(n, s, edges);

        cout << "Кратчайшее расстояние из вершины " << s << ":\n";
        for (int i = 0; i < n; ++i) {
            cout << "Вершина " << i << ": ";
            if (distances[i] == INF) {
                cout << "INF\n";
            }
            else {
                cout << distances[i] << "\n";
            }
        }
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    testAlgorithmBellmanFord();

    return 0;
}
