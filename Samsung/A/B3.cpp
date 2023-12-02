#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct Graph {
    int vertices;
    vector<vector<int>> adjacency_list;
    Graph(int vertices) : vertices(vertices), adjacency_list(vertices) {}

    void addEdge(int u, int v) {
        adjacency_list[u].push_back(v);
        adjacency_list[v].push_back(u);
    }

    int countParallelEdges() {
        int parallel_edges = 0;

        for (int vertex = 0; vertex < vertices; ++vertex) {
            unordered_set<int> visited;

            for (int neighbor : adjacency_list[vertex]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                } else {
                    parallel_edges++;
                }
            }
        }
        return parallel_edges / 2;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph graph = Graph(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph.addEdge(x, y);
    }
    cout << graph.countParallelEdges();

    return 0;
}