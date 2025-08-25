#include <bits/stdc++.h>
using namespace std;
class Graph {
public:
    map<int, bool> visited;
    map<int, list<int> > adj;
    void addEdge(int v, int w);
    void DFS(int v);
};
void Graph::addEdge(int v, int w)
{
       adj[v].push_back(w);
}
void Graph::DFS(int v)
{
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}
int main() {
    Graph g;
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;
    cout << "Enter the edges (format: source destination):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int source, destination;
        cin >> source >> destination;
        g.addEdge(source, destination);
    }
    int startVertex;
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;
    cout << "Depth First Traversal starting from vertex " << startVertex << ":\n";
    g.DFS(startVertex);
    return 0;
}
/*Enter the number of vertices: 4
Enter the number of edges: 5
Enter the edges (format: source destination):
0 1
0 2
1 2
2 0
2 3
Enter the starting vertex for DFS: 2*/
