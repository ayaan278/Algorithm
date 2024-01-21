#include <vector>
#include <list>
#include <queue>
#include <limits>
#include <iomanip>
#include <stack>
#include "./GraphHelper.cpp"

using namespace std;

#define INF numeric_limits<double>::infinity()

/*
@author
@ayaan278
*/
void Graph::shortestPath(Graph g, char src)
{
    priority_queue<pair<double, int>,
                   vector<pair<double, int>>,
                   greater<pair<double, int>>>pq;

    vector<double> dist(g.getV(), INF);
    // Parent array to store the shortest path
    vector<int> parent(g.getV(), -1);
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

        for (auto &neighbor : g.getAdj()[u])
        {
            int v = neighbor.first;
            double distance = neighbor.second;

            if (dist[v] > dist[u] + distance)
            {
                dist[v] = dist[u] + distance;
                parent[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
   
    g.printDijkstraPath(src, parent, dist);
}

int main()
{
    // Read the file from the Edges Class
    vector<Edge> edges;
    string file = "../../DatasetsSamples/DataSet2/edges.csv";

    // Create the graph and add edges
    int numVertices = 20;
    Graph g(numVertices);
    g.readEdgesFile(file, edges);

    cout << "|-------------------------------------------|" << endl;
    cout << "|       Welcome to Dijkstra's Algorithm     |" << endl;
    cout << "|-------------------------------------------|" << endl;
    cout << "| Starting Station = A                      |" << endl;
    cout << "|-------------------------------------------|" << endl;

    // Get the starting station
    char startStation = 'A';

    for (const auto &edge : edges)
    {
        g.addEdge(edge.name, edge.destination, edge.distance);
    }

    // Find the shortest path from the starting station
    g.shortestPath(g, startStation);

    return 0;
}
