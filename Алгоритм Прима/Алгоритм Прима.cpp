#include <iostream>
#include <vector>

using namespace std;

const int INF = numeric_limits<int>::max();

void algorithmPrimaWithoutHeap(const vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    vector<int> minEdge(n, INF);
    vector<bool> inMST(n, false);
    vector<int> parent(n, -1);

    minEdge[0] = 0;

    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!inMST[j] && (v == -1 || minEdge[j] < minEdge[v])) {
                v = j;
            }
        }

        inMST[v] = true;

        if (parent[v] != -1) {
            cout << "Ребро: " << parent[v] << " - " << v << " с весом " << minEdge[v] << endl;
        }

        for (const auto& edge : graph[v]) {
            int to = edge.first;
            int weight = edge.second;

            if (!inMST[to] && weight < minEdge[to]) {
                minEdge[to] = weight;
                parent[to] = v;
            }
        }
    }
}

void testAlgorithmPrima() {
    int n = 6;
    vector<vector<pair<int, int>>> graph(n);

    graph[0].push_back({ 1, 4 });
    graph[0].push_back({ 2, 4 });
    graph[1].push_back({ 0, 4 });
    graph[1].push_back({ 2, 2 });
    graph[1].push_back({ 3, 5 });
    graph[2].push_back({ 0, 4 });
    graph[2].push_back({ 1, 2 });
    graph[2].push_back({ 3, 5 });
    graph[2].push_back({ 4, 9 });
    graph[3].push_back({ 1, 5 });
    graph[3].push_back({ 2, 5 });
    graph[3].push_back({ 4, 7 });
    graph[3].push_back({ 5, 6 });
    graph[4].push_back({ 2, 9 });
    graph[4].push_back({ 3, 7 });
    graph[4].push_back({ 5, 8 });
    graph[5].push_back({ 3, 6 });
    graph[5].push_back({ 4, 8 });

    cout << "Алгоритм Прима без использования кучи:\n";
    algorithmPrimaWithoutHeap(graph);
}

int main() {
    setlocale(LC_ALL, "ru");

    testAlgorithmPrima();

    return 0;
}