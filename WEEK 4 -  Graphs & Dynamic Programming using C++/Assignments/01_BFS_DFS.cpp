#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
 * Assignment 1: Implement BFS and DFS in C++.
 *
 * The graph is represented using an Adjacency List and is treated
 * as undirected (an edge between u and v is added both ways).
 */

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjList;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjList.resize(vertices);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // undirected graph
    }

    // Breadth First Search starting from a given source vertex
    void bfs(int start) {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS starting from vertex " << start << ": ";
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // Depth First Search (recursive) starting from a given source vertex
    void dfsUtil(int current, vector<bool>& visited) {
        visited[current] = true;
        cout << current << " ";

        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited);
            }
        }
    }

    void dfs(int start) {
        vector<bool> visited(numVertices, false);
        cout << "DFS starting from vertex " << start << ": ";
        dfsUtil(start, visited);
        cout << endl;
    }
};

int main() {
    int vertices, edges;

    cout << "=== Graph Traversal - BFS & DFS ===" << endl;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter " << edges << " edges (u v format, vertices numbered from 0):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int startVertex;
    cout << "Enter the starting vertex for traversal: ";
    cin >> startVertex;

    g.bfs(startVertex);
    g.dfs(startVertex);

    return 0;
}
