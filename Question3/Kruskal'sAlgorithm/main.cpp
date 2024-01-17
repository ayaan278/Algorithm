#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;
// Structure to represent an edge
struct Edge 
{
    char src, dest;
    double weight;
};

// Comparator for sorting edges based on their weight
bool compareEdge(Edge a, Edge b) 
{
    return a.weight < b.weight;
}

// Structure to represent a subset for union-find
struct subset 
{
    int parent;
    int rank;
};

// Structure to represent a graph
struct Graph 
{
    int V; // Number of vertices
    vector<Edge> edges;

    // Function to add an edge to the graph
    void addEdge(char src, char dest, double weight) 
    {
        Edge edge = {src, dest, weight};
        edges.push_back(edge);
    }
};

// A utility function to find set of an element i (uses path compression)
int find(subset subsets[], int i) 
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// A function that does union of two sets of x and y (uses union by rank)
void Union(subset subsets[], int x, int y) 
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to construct MST using Kruskal's algorithm
vector<Edge> KruskalMST(Graph &graph) 
{
    vector<Edge> mst;
    int V = graph.V;
    sort(graph.edges.begin(), graph.edges.end(), compareEdge);

    subset *subsets = new subset[V];
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int e = 0;
    int i = 0;
    while (e < V - 1 && i < graph.edges.size()) {
        Edge next_edge = graph.edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            mst.push_back(next_edge);
            Union(subsets, x, y);
            e++;
        }
    }

    delete[] subsets;
    return mst;
}

// Main function
int main() 
{
    Graph graph;
    unordered_map<char, int> vertexMap;

    ifstream file("../../DatasetsSamples/DataSet2/edges.csv");

    if (!file.is_open()) 
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    string line;
    // Read edges from CSV file and populate the graph and vertexMap
    while (getline(file, line)) 
    {
        stringstream ss(line);
        char src, dest, comma;
        double weight;

        if (ss >> src >> comma && comma == ',' &&
            ss >> dest >> comma && comma == ',' && ss >> weight) 
        {
            cout << "Read edge: " << src << " -- " << dest << " == " << weight << endl;

            if (vertexMap.find(src) == vertexMap.end()) 
            {
                vertexMap[src] = vertexMap.size();
            }
            if (vertexMap.find(dest) == vertexMap.end()) 
            {
                vertexMap[dest] = vertexMap.size();
            }

            int srcIndex = vertexMap[src];
            int destIndex = vertexMap[dest];

            // Add edge to the graph using integer indices
            graph.addEdge(srcIndex, destIndex, weight);
        } else {
            cout << "Failed to parse line: " << line << endl;
        }
    }

    cout << "Vertex Map:" << endl;
    for (const auto &pair : vertexMap) 
    {
        cout << pair.first << " -> " << pair.second << endl;
    }

    // Set the number of vertices in the graph
    graph.V = vertexMap.size();

    // Find the MST using Kruskal's algorithm
    vector<Edge> mst = KruskalMST(graph);

    // Display the edges of the MST
    cout << "Edges in the constructed MST:" << endl;

    ofstream outputFile("../../SortingOutputs/Kruskal's_Output.csv");

    for (const Edge &edge : mst) 
    {
        // Convert indices back to character vertices for display
        char srcChar = ' '; 
        // Initialize with a placeholder
        char destChar = ' ';
        for (const auto &pair : vertexMap) {
            if (pair.second == edge.src) srcChar = pair.first;
            if (pair.second == edge.dest) destChar = pair.first;
        }
        cout << srcChar << " -- " << destChar << " == " << edge.weight << endl;
        outputFile << srcChar << "," << destChar << "," << edge.weight << "\n";

    }
    outputFile.close();

    return 0;
}