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

// Comparator for sorting edges based on their weight
bool compareEdge(Edge a, Edge b) 
{
    return a.weight < b.weight;
}

//Read Edges File
Graph readEdgesFile(const string& fileName, 
                    unordered_map<char, int>& vertexMap) 
{
    Graph graph;
    ifstream file(fileName);


    if (!file.is_open()) 
    {
        cerr << "Error opening file: " << fileName << endl;
        return graph;
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
            //cout << "Read edge: " << src << " -- " << dest << " == " << weight << endl;

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

    file.close();

    // Set the number of vertices in the graph
    graph.V = vertexMap.size();

    return graph;
}