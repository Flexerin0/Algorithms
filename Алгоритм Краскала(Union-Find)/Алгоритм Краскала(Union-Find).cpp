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

class UnionFind {
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            }
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

vector<Edge> algorithmKruskalWithUnionFind(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compareEdges);
    UnionFind uf(n);
    vector<Edge> mst;

    for (const auto& edge : edges) {
        if (uf.find(edge.u) != uf.find(edge.v)) {
            mst.push_back(edge);
            uf.unite(edge.u, edge.v);
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

    auto mst = algorithmKruskalWithUnionFind(n, edges);
    cout << "Минимальное остовное дерево (с Union-Find):\n";
    for (const auto& edge : mst) {
        cout << edge.u << " - " << edge.v << " (" << edge.weight << ")\n";
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    testAlgorithmKruskal();

    return 0;
}
