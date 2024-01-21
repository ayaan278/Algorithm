#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
#include "../Question3/KruskalsAlgorithm/Kruskal.cpp"



/*
@author 
@SalahAlHaismawi
@ayaan278
*/

struct Coordinates {
    string name;
    int x, y, z; 
    int profit;
    int weight;
};

vector<Coordinates> readCSV(const string& fileName) 
{
    vector<Coordinates> coordinates;
    ifstream file(fileName);
    string line;

    if (!file.is_open()) 
    {
        cerr << "Error opening file: " << fileName << endl;
        return coordinates;
    }

    while (getline(file, line)) 
    {
        if (line.empty()) continue; 

        stringstream ss(line);
        Coordinates coordinate;
        string temp;

        try {
            if (!getline(ss, coordinate.name, ',')) throw invalid_argument("Missing name");
            if (!getline(ss, temp, ',')) throw invalid_argument("Invalid x coordinate");
            coordinate.x = stoi(temp);
            if (!getline(ss, temp, ',')) throw invalid_argument("Invalid y coordinate");
            coordinate.y = stoi(temp);
            if (!getline(ss, temp, ',')) throw invalid_argument("Invalid z coordinate");
            coordinate.z = stoi(temp);
            if (!getline(ss, temp, ',')) throw invalid_argument("Invalid profit");
            coordinate.profit = stoi(temp);
            if (!getline(ss, temp, ',')) throw invalid_argument("Invalid weight");
            coordinate.weight = stoi(temp);

            coordinates.push_back(coordinate);
        } catch (const invalid_argument& e) {
            cerr << "Invalid argument: " << e.what() << " in line: " << line << endl;
        }
    }

    file.close();
    return coordinates;
}

void printItems(const vector<string>& stationsToVisit, 
                const vector<Coordinates>& coordinates) 
{
    ofstream outputFile("../../Outputs/Question4/Knapsack's_Output.csv", ios::out);
    ofstream outputFile2("../../Outputs/Question4/Knapsack's_Visualization.csv", ios::out);

    
    cout << "|Stations to visit                     |" << endl 
    << "|   ";
    for (const string& station : stationsToVisit) 
    {
        cout << station << " ";
    }
    cout << "    |\n|--------------------------------------|\n";
    cout << "|  Station  |" << "   Weight   " << "|   Profit    |" << endl;
    cout << "|--------------------------------------|" << endl;
    int totalWeight = 0, totalProfit = 0;
    for (const string& stationName : stationsToVisit) {
        for (const Coordinates& coordinate : coordinates) {
            if (coordinate.name == stationName) {
                totalWeight += coordinate.weight;
                totalProfit += coordinate.profit;
                cout << "|     " << coordinate.name 
                     << "     |     " << coordinate.weight 
                     << "     |     " << coordinate.profit << "      |" << endl;
                outputFile << coordinate.name << "," << coordinate.weight << "," << coordinate.profit << endl;
                break;
            }
        }
    }
    cout << "|--------------------------------------|" << endl;
    cout << "|Total Weight: " << totalWeight << " | Total Profit: " << totalProfit << " |" << endl;
    cout << "|--------------------------------------|" << endl;

    outputFile.close();
    outputFile2.close();
}

//Read Edges File
Graph filterEdgesFile(const string& fileName, 
                    unordered_map<char, int>& vertexMap, 
                    Graph &graph, 
                    vector<string> stationsToVisit) 
{
    ifstream file(fileName);

    //Assume first station as the starting point
    char firstStation = stationsToVisit[0][0];
    bool firstStationFound = false;

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
            // Filter edges that are not connected to the stations to visit
            if(find(stationsToVisit.begin(), stationsToVisit.end(), string(1, src)) != stationsToVisit.end() 
            || find(stationsToVisit.begin(), stationsToVisit.end(), string(1, dest)) != stationsToVisit.end())
            {   
                // Filter edges that are not connected to the first station
                if (vertexMap.find(src) == vertexMap.end()) 
                {   if(firstStation == src && !firstStationFound)
                    {
                        firstStationFound = true;
                        continue;
                    }
                    vertexMap[src] = vertexMap.size();
                }
                if (vertexMap.find(dest) == vertexMap.end()) 
                {   
                    if(firstStation == dest && !firstStationFound)
                    {
                        firstStationFound = true;
                        continue;
                    }
                    vertexMap[dest] = vertexMap.size();
                }

                int srcIndex = vertexMap[src];
                int destIndex = vertexMap[dest];

                // Add edge to the graph using integer indices
                graph.addEdge(srcIndex, destIndex, weight);
            }
            
        } else {
            cout << "Failed to parse line: " << line << endl;
        }
    }

    file.close();

    // Set the number of vertices in the graph
    graph.V = vertexMap.size();

    return graph;
}