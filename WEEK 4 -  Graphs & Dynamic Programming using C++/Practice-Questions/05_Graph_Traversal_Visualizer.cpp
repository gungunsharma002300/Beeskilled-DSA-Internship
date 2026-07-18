#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
 * Practice Question 5: Build a mini project to visualize graph traversal output.
 *
 * Instead of just printing the final visited order, this program shows
 * the traversal STEP BY STEP:
 *  - For BFS, it prints the graph level by level (like a tree drawn outward
 *    from the source).
 *  - For DFS, it prints the path depth using indentation, so you can see
 *    how deep the recursion goes at each step.
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
        adjList[v].push_back(u);
    }

    // BFS visualized level by level
    void visualizeBFS(int start) {
        vector<bool> visited(numVertices, false);
        vector<int> level(numVertices, -1);
        queue<int> q;

        visited[start] = true;
        level[start] = 0;
        q.push(start);

        cout << "\n----- BFS Visualization (level by level) -----" << endl;

        int currentLevel = 0;
        while (!q.empty()) {
            int size = q.size();
            cout << "Level " << currentLevel << ": ";

            for (int i = 0; i < size; i++) {
                int current = q.front();
                q.pop();
                cout << current << " ";

                for (int neighbor : adjList[current]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        level[neighbor] = currentLevel + 1;
                        q.push(neighbor);
                    }
                }
            }
            cout << endl;
            currentLevel++;
        }
    }

    // DFS visualized with indentation showing recursion depth
    void visualizeDFSUtil(int current, vector<bool>& visited, int depth) {
        visited[current] = true;

        // print indentation proportional to depth, like a tree branch
        for (int i = 0; i < depth; i++) {
            cout << "  ";
        }
        cout << "-> Visiting " << current << " (depth " << depth << ")" << endl;

        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                visualizeDFSUtil(neighbor, visited, depth + 1);
            }
        }
    }

    void visualizeDFS(int start) {
        vector<bool> visited(numVertices, false);
        cout << "\n----- DFS Visualization (depth shown by indentation) -----" << endl;
        visualizeDFSUtil(start, visited, 0);
    }
};

int main() {
    int vertices, edges;

    cout << "=== Graph Traversal Visualizer (BFS & DFS) ===" << endl;
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

    g.visualizeBFS(startVertex);
    g.visualizeDFS(startVertex);

    return 0;
}
