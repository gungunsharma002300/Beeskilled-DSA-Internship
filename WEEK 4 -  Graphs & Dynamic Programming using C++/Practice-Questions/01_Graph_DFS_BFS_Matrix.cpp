#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
 * Practice Question 1: Implement DFS and BFS for a given graph.
 *
 * This version represents the graph using an ADJACENCY MATRIX instead
 * of an adjacency list (a different representation than the one used
 * in Assignments/01_BFS_DFS.cpp), as mentioned in "Graph Representation
 * (Adjacency List/Matrix)" from the topics covered.
 */

class GraphMatrix {
private:
    int numVertices;
    vector<vector<int>> matrix; // matrix[i][j] = 1 if edge exists

public:
    GraphMatrix(int vertices) {
        numVertices = vertices;
        matrix.assign(vertices, vector<int>(vertices, 0));
    }

    void addEdge(int u, int v) {
        matrix[u][v] = 1;
        matrix[v][u] = 1; // undirected graph
    }

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

            for (int neighbor = 0; neighbor < numVertices; neighbor++) {
                if (matrix[current][neighbor] == 1 && !visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    void dfsUtil(int current, vector<bool>& visited) {
        visited[current] = true;
        cout << current << " ";

        for (int neighbor = 0; neighbor < numVertices; neighbor++) {
            if (matrix[current][neighbor] == 1 && !visited[neighbor]) {
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

    cout << "=== Graph Traversal (Adjacency Matrix) - BFS & DFS ===" << endl;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    GraphMatrix g(vertices);

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
