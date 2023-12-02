#include <iostream>
#include <vector>

using namespace std;

struct Graph {
    int V;
    vector<vector<int>> adj;
    Graph(int V) {
        this->V = V;
        adj.resize(V, vector<int>(V, 0));
    }
    
    void addEdge(int v, int w) {
        adj[v][w] = 1;
        adj[w][v] = 1;
    }
    
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        for (int neighbor = 0; neighbor < V; ++neighbor) {
            if (adj[v][neighbor] && !visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }
    
    bool isEdgeConnected() {
        for (int i = 0; i < V; ++i) {
            for (int neighbor = 0; neighbor < V; ++neighbor) {
                if (adj[i][neighbor]) {
                    adj[i][neighbor] = 0;
                    adj[neighbor][i] = 0;
                    vector<bool> visited(V, false);
                    DFSUtil(i, visited);
                    adj[i][neighbor] = 1;
                    adj[neighbor][i] = 1;
                    if (!visited[neighbor]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    Graph graph = Graph(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph.addEdge(x,y);
    }
    

    if (graph.isEdgeConnected()) {
        cout << "Do thi lien thong canh." << endl;
    } else {
        cout << "Do thi khong lien thong canh." << endl;
    }

    return 0;
}

