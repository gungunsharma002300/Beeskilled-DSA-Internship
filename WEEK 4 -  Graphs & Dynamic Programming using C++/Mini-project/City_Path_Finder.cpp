#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <climits>
using namespace std;

/*
 * Mini Project: City Path Finder
 *
 * - Represent cities as nodes.
 * - Find shortest route between two points.
 *
 * Cities are entered by name (e.g. "Delhi", "Mumbai") and connected by
 * roads with a distance/weight. Dijkstra's algorithm is used to find
 * the shortest route between any two cities, and the actual path is
 * reconstructed and printed (not just the distance).
 */

typedef pair<int, int> pii; // (distance, node index)

class CityPathFinder {
private:
    map<string, int> cityToIndex;   // city name -> index
    vector<string> indexToCity;     // index -> city name
    vector<vector<pii>> adjList;    // adjacency list (neighborIndex, weight)

    int getOrCreateIndex(const string& city) {
        if (cityToIndex.find(city) == cityToIndex.end()) {
            cityToIndex[city] = indexToCity.size();
            indexToCity.push_back(city);
            adjList.push_back(vector<pii>());
        }
        return cityToIndex[city];
    }

public:
    void addRoad(const string& cityA, const string& cityB, int distance) {
        int a = getOrCreateIndex(cityA);
        int b = getOrCreateIndex(cityB);
        adjList[a].push_back({b, distance});
        adjList[b].push_back({a, distance}); // roads work both ways
    }

    void findShortestRoute(const string& source, const string& destination) {
        if (cityToIndex.find(source) == cityToIndex.end() ||
            cityToIndex.find(destination) == cityToIndex.end()) {
            cout << "One or both cities are not in the map!" << endl;
            return;
        }

        int n = indexToCity.size();
        int src = cityToIndex[source];
        int dest = cityToIndex[destination];

        vector<int> dist(n, INT_MAX);
        vector<int> parent(n, -1);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;

            for (auto& edge : adjList[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        if (dist[dest] == INT_MAX) {
            cout << "No route found between " << source << " and " << destination << "." << endl;
            return;
        }

        // Reconstruct the path by following parent pointers backwards
        vector<int> path;
        for (int at = dest; at != -1; at = parent[at]) {
            path.push_back(at);
        }

        cout << "\nShortest route from " << source << " to " << destination << ":" << endl;
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << indexToCity[path[i]];
            if (i != 0) cout << " -> ";
        }
        cout << "\nTotal distance: " << dist[dest] << " km" << endl;
    }
};

void printMenu() {
    cout << "\n===== City Path Finder =====" << endl;
    cout << "1. Add a road between two cities" << endl;
    cout << "2. Find shortest route between two cities" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    CityPathFinder finder;
    int choice;

    do {
        printMenu();
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string cityA, cityB;
            int distance;

            cout << "Enter first city name: ";
            getline(cin, cityA);
            cout << "Enter second city name: ";
            getline(cin, cityB);
            cout << "Enter distance between them (km): ";
            cin >> distance;
            cin.ignore();

            finder.addRoad(cityA, cityB, distance);
            cout << "Road added: " << cityA << " <-> " << cityB << " (" << distance << " km)" << endl;

        } else if (choice == 2) {
            string source, destination;

            cout << "Enter source city: ";
            getline(cin, source);
            cout << "Enter destination city: ";
            getline(cin, destination);

            finder.findShortestRoute(source, destination);

        } else if (choice == 3) {
            cout << "Exiting City Path Finder. Goodbye!" << endl;

        } else {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 3);

    return 0;
}
