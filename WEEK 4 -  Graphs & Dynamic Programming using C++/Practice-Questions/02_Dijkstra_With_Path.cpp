#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

/*
 * Practice Question 2: Find the shortest path using Dijkstra's algorithm.
 *
 * This version goes one step further than Assignments/02_Dijkstra_Shortest_Path.cpp
 * by also reconstructing and printing the actual shortest PATH (sequence of
 * vertices), not just the shortest distance.
 */

typedef pair<int, int> pii; // (weight, vertex)

void dijkstraWithPath(int numVertices, vector<vector<pii>>& adjList, int source, int destination) {
    vector<int> dist(numVertices, INT_MAX);
    vector<int> parent(numVertices, -1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adjList[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[destination] == INT_MAX) {
        cout << "No path exists between " << source << " and " << destination << endl;
        return;
    }

    // Reconstruct path from destination back to source
    vector<int> path;
    for (int at = destination; at != -1; at = parent[at]) {
        path.push_back(at);
    }

    cout << "Shortest distance from " << source << " to " << destination << " = " << dist[destination] << endl;
    cout << "Path: ";
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i];
        if (i != 0) cout << " -> ";
    }
    cout << endl;
}

int main() {
    int vertices, edges;

    cout << "=== Dijkstra's Algorithm with Path Reconstruction ===" << endl;
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
        adjList[v].push_back({u, w});
    }

    int source, destination;
    cout << "Enter source vertex: ";
    cin >> source;
    cout << "Enter destination vertex: ";
    cin >> destination;

    dijkstraWithPath(vertices, adjList, source, destination);

    return 0;
}
