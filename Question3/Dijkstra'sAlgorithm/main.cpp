#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <limits>
#include <iomanip>
#include <stack> 

using namespace std;

#define INF numeric_limits<double>::infinity()

struct Edge 
{
    char name;
    char destination;
    double distance;
};

class Graph 
{
    // No. of vertices
    int V;
    list<pair<int, double>>* adj;

    public:
        Graph();
        Graph(int V);
        void addEdge(char u, char v, double w);
        void shortestPath(char src);
};

Graph::Graph(){}

Graph::Graph(int V) 
{
    this->V = V;
    adj = new list<pair<int, double>>[V];
}

void Graph::addEdge(char u, char v, double w) 
{
    adj[u - 'A'].push_back(make_pair(v - 'A', w));
    adj[v - 'A'].push_back(make_pair(u - 'A', w));
}

void Graph::shortestPath(char src) 
{
    priority_queue<pair<double, int>, 
        vector<pair<double, int>>, 
        greater<pair<double, int>>> pq;

    vector<double> dist(V, INF);
    // Parent array to store the shortest path
    vector<int> parent(V, -1); 
    pq.push(make_pair(0.0, src - 'A'));
    dist[src - 'A'] = 0.0;

    while (!pq.empty()) 
    {
        int u = pq.top().second;
        double currentDist = pq.top().first;
        pq.pop();

        // If the popped vertex has already been processed, skip
        if (currentDist > dist[u]) 
        {
            continue;
        }

        for (auto& neighbor : adj[u]) 
        {
            int v = neighbor.first;
            double distance = neighbor.second;

            if (dist[v] > dist[u] + distance) 
            {
                dist[v] = dist[u] + distance;
                parent[v] = u; // Update the parent for the shortest path
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    ofstream outputFile("../../Outputs/Question3/Dijkstra's_Output.csv", ios::out);
    ofstream outputFile2("../../Outputs/Question3/Dijkstra's_Visualization.csv", ios::out);

    outputFile << "Starting station: " << "A" << endl;
    cout << "Starting station: " << src << endl;


    for (int i = 1; i < V; ++i) 
    {
        cout << char(i + 'A') << ",";
        outputFile << char(i + 'A') << ",";

        stack<char> route;
        int currentVertex = i;

        // Build the route stack
        while (currentVertex != -1) 
        {
            route.push(char(currentVertex + 'A'));
            currentVertex = parent[currentVertex];
        }

        // SortingOutputs the route to the file
        char prevNode = route.top();
        route.pop();

        // SortingOutputs the route to the file
        while (!route.empty()) 
        {
            char currentNode = route.top();
            outputFile2 << prevNode << ',' << currentNode << endl;
            outputFile << currentNode;
            cout << currentNode;

        }

        // SortingOutputs the distance to the file
        outputFile << "," << fixed << setprecision(2) << dist[i] << endl;
        cout << "," << fixed << setprecision(2) << dist[i] << endl;
    }


    outputFile.close();
    outputFile2.close();
}

int main() {
    // Read the file from the Edges Class
    vector<Edge> edges;
    ifstream file("../../DatasetsSamples/DataSet2/edges.csv");
    if (file.is_open()) 
    {
        string line;
        while (getline(file, line)) 
        {
            stringstream ss(line);
            char name, destination, comma;
            double distance;

            if (ss >> name >> comma && comma == ',' &&
                ss >> destination >> comma && comma == ',' && 
                ss >> distance) 
            {
                edges.push_back({name, destination, distance});
            } 
            else 
            {
                cout << "Failed to parse line: " << line << endl;
            }
        }
    } 
    else 
    {
        cout << "Failed to open file" << endl;
        return 1;
    }

    file.close();

    // Get the starting station
    char startStation = 'A';

    // Create the graph and add edges
    int numVertices = 20;
    Graph g(numVertices);

    for (const auto& edge : edges) 
    {
        g.addEdge(edge.name, edge.destination, edge.distance);
    }

    // Find the shortest path from the starting station
    g.shortestPath(startStation);

    return 0;
}
