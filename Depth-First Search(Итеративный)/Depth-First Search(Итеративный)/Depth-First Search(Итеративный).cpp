#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Graph {
    int numVertices;
    vector<vector<int>> adjList;
    bool* visited;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjList.resize(vertices);
        visited = new bool[vertices];
    };

    void addEdge(int v, int w) {
        adjList[v].push_back(w);
        adjList[w].push_back(v);
    };

    void depthFirstSearch(int v) {
        vector<bool> visited(numVertices, false);
        stack<int> stack;

        stack.push(v);

        while (!stack.empty()) {
            int v = stack.top();
            stack.pop();

            if (!visited[v]) {  
                cout << v << " ";
                visited[v] = true;
            }

            for (int neighbor : adjList[v]) {
                if (!visited[neighbor]) {
                    stack.push(neighbor);
                }
            }
        }
    };
};

void testDFS() {
    Graph g(20);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 7);
    g.addEdge(4, 8);
    g.addEdge(5, 9);
    g.addEdge(6, 10);
    g.addEdge(7, 11);
    g.addEdge(8, 12);
    g.addEdge(9, 13);
    g.addEdge(10, 14);
    g.addEdge(11, 15);
    g.addEdge(12, 16);
    g.addEdge(13, 17);
    g.addEdge(14, 18);
    g.addEdge(15, 19);

    g.depthFirstSearch(0);
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru");

    testDFS();

    return 0;
}
