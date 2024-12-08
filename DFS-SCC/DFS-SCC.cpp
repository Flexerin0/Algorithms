#include <iostream>
#include <vector>

using namespace std;

struct Graph {
    int numVertices;
    vector<vector<int>> adjList;
    bool* visited;
    vector<int> scc;
    int numberSCC;

    Graph(int vertices) {
        numVertices = vertices;
        adjList.resize(vertices);
        visited = new bool[vertices];
        fill(visited, visited + vertices, false);
        scc.resize(vertices, -1);
        numberSCC = 0;
    }

    ~Graph() {
        delete[] visited;
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void dfsSCC(int v) {
        visited[v] = true;

        scc[v] = numberSCC;

        for (int neighbor : adjList[v]) {
            if (!visited[neighbor]) {
                dfsSCC(neighbor);
            }
        }
    }

    void findSCC() {
        for (int i = 0; i < numVertices; ++i) {
            if (!visited[i]) {
                ++numberSCC;
                dfsSCC(i);
            }
        }
    }

    void printSCC() {
        for (int i = 0; i < numVertices; ++i) {
            cout << "Вершина " << i << " находится в SCC: " << scc[i] << endl;
        }
    }
};

void testDFS() {
    Graph g(20);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 3);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
    g.addEdge(8, 6);
    g.addEdge(0, 3);
    g.addEdge(3, 6);
    g.addEdge(6, 9);
    g.addEdge(9, 10);
    g.addEdge(10, 11);
    g.addEdge(11, 9);
    g.addEdge(12, 13);
    g.addEdge(13, 14);
    g.addEdge(14, 12);
    g.addEdge(15, 16);
    g.addEdge(16, 17);
    g.addEdge(17, 15);
    g.addEdge(18, 19);
    g.addEdge(19, 18);

    g.findSCC();
    g.printSCC();
}

int main() {
    setlocale(LC_ALL, "ru");

    testDFS();

    return 0;
}
