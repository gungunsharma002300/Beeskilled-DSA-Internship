#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

/*
 * Assignment 2: Find shortest path using Dijkstra's Algorithm.
 *
 * Uses an adjacency list of (neighbor, weight) pairs and a min-priority
 * queue to always expand the closest unvisited vertex next.
 */

typedef pair<int, int> pii; // (weight, vertex)

void dijkstra(int numVertices, vector<vector<pii>>& adjList, int source) {
    vector<int> dist(numVertices, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq; // min-heap

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue; // outdated entry, skip

        for (auto& edge : adjList[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nShortest distances from vertex " << source << ":" << endl;
    for (int i = 0; i < numVertices; i++) {
        if (dist[i] == INT_MAX) {
            cout << "Vertex " << i << " -> unreachable" << endl;
        } else {
            cout << "Vertex " << i << " -> " << dist[i] << endl;
        }
    }
}

int main() {
    int vertices, edges;

    cout << "=== Dijkstra's Shortest Path Algorithm ===" << endl;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    vector<vector<pii>> adjList(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter " << edges << " edges (u v weight format, vertices numbered from 0):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w}); // undirected graph
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    dijkstra(vertices, adjList, source);

    return 0;
}
