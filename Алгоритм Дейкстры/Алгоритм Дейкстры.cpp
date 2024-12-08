#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <utility>

using namespace std;

const int INF = numeric_limits<int>::max();

void addEdge(vector<vector<pair<int, int>>>& graph, int u, int v, int weight) {
    graph[u].emplace_back(v, weight);
}

vector<int> dijkstra(const vector<vector<pair<int, int>>>& graph, int start) {
    int n = graph.size();
    vector<int> len(n, INF);
    vector<bool> visited(n, false);

    len[start] = 0;

    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && (v == -1 || len[j] < len[v])) {
                v = j;
            }
        }

        if (len[v] == INF) {
            break;
        }

        visited[v] = true;

        for (const auto& edge : graph[v]) {
            int to = edge.first;
            int weight = edge.second;

            if (len[v] + weight < len[to]) {
                len[to] = len[v] + weight;
            }
        }
    }

    return len;
}

void printResult(const vector<int>& distances, int start) {
    cout << "Кратчайшее расстояние от начальной вершины " << start << ":\n";
    for (int i = 0; i < distances.size(); ++i) {
        cout << "Вершина " << i << ": ";
        if (distances[i] == INF) {
            cout << "INF";
        }
        else {
            cout << distances[i];
        }
        cout << endl;
    }
}

void testDijkstra() {
    int numsVertex = 10;
    vector<vector<pair<int, int>>> graph(numsVertex);

    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 1);
    addEdge(graph, 2, 1, 2);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 2, 3, 5);
    addEdge(graph, 3, 4, 3);
    addEdge(graph, 4, 5, 6);
    addEdge(graph, 1, 6, 8);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 7, 8, 7);
    addEdge(graph, 8, 9, 2);
    addEdge(graph, 0, 9, 15);

    int startVertex = 0;
    vector<int> distances = dijkstra(graph, startVertex);

    printResult(distances, startVertex);
}

int main() {
    setlocale(LC_ALL, "ru");

    testDijkstra();

    return 0;
}
