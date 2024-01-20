#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <list>
#include <stack>
#include <iomanip>

using namespace std;

/*
@author 
@ayaan278
*/
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
        int getV() { return V; }
        list<pair<int, double>>* getAdj() { return adj; }

        void addEdge(char u, char v, double w);
        void readEdgesFile(const string filename, 
                        vector<Edge>& edges);
        void printGraph(const char src, 
                vector<int>& parent,
                vector<double>& dist);
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

void Graph::readEdgesFile(const string filename, 
                        vector<Edge>& edges)
{
    ifstream file(filename);
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
    }

    file.close();
}

void Graph::printGraph(const char src, 
                vector<int>& parent,
                vector<double>& dist)
{
    ofstream outputFile("../../Outputs/Question3/Dijkstra's_Output.csv", ios::out);
    ofstream outputFile2("../../Outputs/Question3/Dijkstra's_Visualization.csv", ios::out);

    outputFile << "Starting station: " << src << endl;


    for (int i = 1; i < V; ++i) 
    {
        cout << "| " << char(i + 'A') << " | ";

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
        int space = 28;
        // SortingOutputs the route to the file
        while (!route.empty()) 
        {
            char currentNode = route.top();
            outputFile2 << prevNode << ',' << currentNode << endl;
            outputFile << currentNode;
            cout << currentNode;

            prevNode = currentNode;

            route.pop();
            if (!route.empty()) 
            {
                cout << " -> ";
                outputFile << " -> ";
                space-=4;
            }
            space--;         
        }

        for(int i=0;i<=space;i++)
        {
            cout<<" ";
        }

        // SortingOutputs the distance to the file
        outputFile << "," << fixed << setprecision(2) << dist[i] << endl;
        cout << "| " << setw(6) << fixed << setprecision(2) << dist[i] << " |" << endl;

    }

    cout<<"|---|------------------------------|--------|"<<endl;
    
    outputFile.close();
    outputFile2.close();
}