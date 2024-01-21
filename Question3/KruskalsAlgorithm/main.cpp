#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <iomanip>
#include "./Kruskal.cpp"

using namespace std;
/*
@author 
@SalahAlHaismawi
*/

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

    ofstream outputFile("../../Outputs/Question3/Kruskal's_Visualization.csv");

    double sum = 0;
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
        sum += edge.weight;
    }
    outputFile.close();
    cout << "|------------------------------|" << endl;
    cout << "|Total weight of MST is: " << setw(6) << fixed << setprecision(2) << sum << "|" << endl;
    cout << "|------------------------------|" << endl;

    return 0;
}