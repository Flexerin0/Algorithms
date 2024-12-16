#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    Edge(int u, int v, int w) : u(u), v(v), weight(w) {}
};

bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

bool isCyclic(const vector<Edge>& mst, const Edge& newEdge) {
    vector<int> visited;
    for (const auto& edge : mst) {
        if (find(visited.begin(), visited.end(), edge.u) == visited.end()) {
            visited.push_back(edge.u);
        }
        if (find(visited.begin(), visited.end(), edge.v) == visited.end()) {
            visited.push_back(edge.v);
        }
    }
    return find(visited.begin(), visited.end(), newEdge.u) != visited.end() &&
        find(visited.begin(), visited.end(), newEdge.v) != visited.end();
}

vector<Edge> algorithmKruskalWithoutUnionFind(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compareEdges);
    vector<Edge> mst;

    for (const auto& edge : edges) {
        if (!isCyclic(mst, edge)) {
            mst.push_back(edge);
        }
    }

    return mst;
}

void testAlgorithmKruskal() {
    int n = 6;
    vector<Edge> edges = {
        {0, 1, 4}, {0, 2, 4}, {1, 2, 2}, {1, 3, 5},
        {2, 3, 8}, {2, 4, 4}, {3, 4, 6}, {3, 5, 7}, {4, 5, 3}
    };

    auto mst = algorithmKruskalWithoutUnionFind(n, edges);
    cout << "Минимальное остовное дерево (без Union-Find):\n";
    for (const auto& edge : mst) {
        cout << edge.u << " - " << edge.v << " (" << edge.weight << ")\n";
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    testAlgorithmKruskal();

    return 0;
}
