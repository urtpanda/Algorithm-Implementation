#include <bits/stdc++.h>
using namespace std;

class Graph {

    int V;

    vector<list<int> > adj;

public:

    Graph(int V);

    void addEdge(int v, int w);

    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w)
{

    adj[v].push_back(w);
}

void Graph::BFS(int s)
{

    vector<bool> visited;
    visited.resize(V, false);

    list<int> queue;


    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty()) {

        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (auto adjacent : adj[s]) {
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
}


int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter edges (format: source destination):" << endl;
    for (int i = 0; i < E; i++) {
        int source, destination;
        cin >> source >> destination;
        g.addEdge(source, destination);
    }

    int startVertex;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;

    cout << "Breadth First Traversal starting from vertex " << startVertex << ": \n";
    g.BFS(startVertex);

    return 0;
}
