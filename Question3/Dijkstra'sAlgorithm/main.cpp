#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    char source, destination;
    double weight;

    Edge(char src, char dest, double w) : source(src), destination(dest), weight(w) {}
};

// Function to read edges from a CSV file
vector<Edge> readEdges(const string& filename) {
    vector<Edge> edges;
    ifstream file(filename);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            char src, dest;
            double weight;
            char comma;

            ss >> src >> comma >> dest >> comma >> weight;
            edges.emplace_back(src, dest, weight);
        }
        file.close();
    }

    return edges;
}

// Dijkstra's Algorithm to find the shortest paths
void dijkstra(const vector<Edge>& edges, char start, unordered_map<char, double>& distance) {
    priority_queue<pair<double, char>, vector<pair<double, char>>, greater<pair<double, char>>> pq;
    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        char current = pq.top().second;
        double currentDist = pq.top().first;
        pq.pop();

        for (const Edge& edge : edges) {
            if (edge.source == current) {
                char neighbor = edge.destination;
                double newDist = currentDist + edge.weight;

                if (newDist < distance[neighbor]) {
                    distance[neighbor] = newDist;
                    pq.push({newDist, neighbor});
                }
            }
        }
    }
}

int main() {
    // Replace "your_sample_edges.csv" with the actual filename
    string filename = "../../Dataset/Dataset2/edges.csv";
    char startStation = 'A';

    // Read edges from the CSV file
    vector<Edge> edges = readEdges(filename);

    // Find the unique stations in the graph
    unordered_map<char, bool> stations;
    for (const Edge& edge : edges) {
        stations[edge.source] = true;
        stations[edge.destination] = true;
    }

    // Initialize distances to infinity for all stations
    unordered_map<char, double> distance;
    for (const auto& station : stations) {
        distance[station.first] = numeric_limits<double>::infinity();
    }

    // Apply Dijkstra's Algorithm
    dijkstra(edges, startStation, distance);

    // Display the shortest distance to each station
    cout << "Shortest distances from Station " << startStation << ":\n";
    for (const auto& station : distance) {
        cout << "To Station " << station.first << ": " << station.second << "\n";
    }

    return 0;
}
