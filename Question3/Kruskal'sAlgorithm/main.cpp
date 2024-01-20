#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <iomanip>
#include "./CSVReader.cpp"

using namespace std;

// Structure to represent a subset for union-find
struct subset
{
    int parent;
    int rank;
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
    else
    {
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
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int e = 0;
    int i = 0;
    while (e < V - 1 && i < graph.edges.size())
    {
        Edge next_edge = graph.edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y)
        {
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
    string fileName = "../../DatasetsSamples/DataSet2/edges.csv";
    unordered_map<char, int> vertexMap;
    graph = readEdgesFile(fileName, vertexMap);

    // Find the MST using Kruskal's algorithm
    vector<Edge> mst = KruskalMST(graph);

    cout << "|------------------------------|" << endl;
    cout << "|Welcome to Kruskal's Algorithm|" << endl;
    cout << "|------------------------------|" << endl;
    cout << "| Edges in the constructed MST |" << endl;
    cout << "|------------------------------|" << endl;

    ofstream outputFile("../../SortingOutputs/Kruskal's_Visualization.csv");

    for (const Edge &edge : mst)
    {
        // Convert indices back to character vertices for display
        char srcChar = ' ';
        // Initialize with a placeholder
        char destChar = ' ';
        for (const auto &pair : vertexMap)
        {
            if (pair.second == edge.src)
                srcChar = pair.first;
            if (pair.second == edge.dest)
                destChar = pair.first;
        }
        cout << "| " << srcChar << " --> "
             << destChar << "  |    "
             << setw(6) << fixed << setprecision(2)
             << edge.weight << "         |" << endl;
        outputFile << srcChar << "," << destChar << "," << edge.weight << "\n";
    }
    outputFile.close();
    cout << "|------------------------------|" << endl;

    return 0;
}