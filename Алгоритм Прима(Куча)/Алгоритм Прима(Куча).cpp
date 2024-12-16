#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = numeric_limits<int>::max();

void algorithmPrimaHeap(const vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    vector<bool> inMST(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> parent(n, -1);

    pq.push({ 0, 0 });

    while (!pq.empty()) {
        pair<int, int> current = pq.top();
        pq.pop();
        int weight = current.first;
        int v = current.second;

        if (inMST[v]) continue;

        inMST[v] = true;
        if (parent[v] != -1) {
            cout << "Ребро: " << parent[v] << " - " << v << " с весом " << weight << endl;
        }

        for (const auto& edge : graph[v]) {
            int to = edge.first;
            int edgeWeight = edge.second;

            if (!inMST[to]) {
                pq.push({ edgeWeight, to });
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

    cout << "Алгоритм Прима с использованием кучи:\n";
    algorithmPrimaHeap(graph);
}

int main() {
    setlocale(LC_ALL, "ru");

    testAlgorithmPrima();

    return 0;
}
