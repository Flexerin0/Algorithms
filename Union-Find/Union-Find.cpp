#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            }
            else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            }
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }

    void printParents() {
        cout << "Родители: ";
        for (int i = 0; i < parent.size(); ++i) {
            cout << parent[i] << " ";
        }
        cout << endl;
    }
};

void testUnionFind() {
    UnionFind uf(10);

    uf.unionSets(1, 2);
    uf.unionSets(2, 3);
    uf.unionSets(4, 5);
    uf.unionSets(5, 6);

    cout << "1 и 3 в одном множестве?" << endl;
    cout << "Результат: ";
    if (uf.isConnected(1, 3)) {
        cout << "Да\n\n";
    }
    else {
        cout << "Нет\n\n";
    }

    cout << "1 и 4 в одном множестве?" << endl;
    cout << "Результат: ";
    if (uf.isConnected(1, 4)) {
        cout << "Да\n\n";
    }
    else {
        cout << "Нет\n\n";
    }

    uf.unionSets(3, 4);

    cout << "1 и 4 в одном множестве?" << endl;
    cout << "Результат: ";
    if (uf.isConnected(1, 4)) {
        cout << "Да\n\n";
    }
    else {
        cout << "Нет\n\n";
    }

    uf.printParents();
}

int main() {
    setlocale(LC_ALL, "ru");

    testUnionFind();

    return 0;
}
