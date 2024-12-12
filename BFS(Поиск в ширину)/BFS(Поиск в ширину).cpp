#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

vector<int> bfs(const vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> reachable;
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        reachable.push_back(v);

        for (int neighbor : graph[v]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return reachable;
}

void printResult(const vector<int>& reachable, int start) {
    cout << "Вершины, достижимые из вершины " << start << ":\n";
    for (int vertex : reachable) {
        cout << vertex << " ";
    }
    cout << endl;
}

void testBFS() {
    int numVertices = 8;
    vector<vector<int>> graph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 7);

    int startVertex = 0;
    vector<int> reachable = bfs(graph, startVertex);

    printResult(reachable, startVertex);
}

int main() {
    setlocale(LC_ALL, "ru");

    testBFS();

    return 0;
}
