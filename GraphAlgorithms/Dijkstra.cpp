#include <climits>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int src, dest, weight;
};

int minDistance(int dist[], bool sptSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[], int n) {
    cout << "Vertex   Distance from Source\n";
    for (int i = 0; i < n; i++)
        cout << "\t" << i << "\t\t" << dist[i] << "\n";
}

void dijkstra(vector<vector<pair<int, int>>>& graph, int src, int V) {
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);

        sptSet[u] = true;

        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!sptSet[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    printSolution(dist, V);
}

void performDijkstra() {
    int V, E;

    cout << "Enter the number of vertices: ";
    cin >> V;

    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<pair<int, int>>> graph(V);

    cout << "Enter the edges (source destination weight):\n";
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[src].push_back({dest, weight});
        // If the graph is undirected, you may want to add the reverse edge as well
        // graph[dest].push_back({src, weight});
    }

    int sourceVertex;
    cout << "Enter the source vertex (0 to " << V - 1 << "): ";
    cin >> sourceVertex;

    dijkstra(graph, sourceVertex, V);
}

int main() {
    performDijkstra();

    return 0;
}

