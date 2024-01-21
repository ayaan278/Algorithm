#include "./CoordinatesHelper.cpp"


/*
@author 
@SalahAlHaismawi
@ayaan278
*/
vector<string> knapsack(const vector<Coordinates>& coordinates, int maxWeight) 
{
    int n = coordinates.size();
    vector<vector<int> > dp(n + 1, vector<int>(maxWeight + 1, 0));

    for (int i = 1; i <= n; i++) 
    {
        for (int w = 1; w <= maxWeight; w++) {
            // If this item can be included
            if (coordinates[i - 1].weight <= w) 
            {
                dp[i][w] = max(coordinates[i - 1].profit + 
                    dp[i - 1][w - coordinates[i - 1].weight], dp[i - 1][w]);
            } 
            // Else, item cannot be included
            else 
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    vector<string> itemsSelected;
    int w = maxWeight;

    for (int i = n; i > 0; i--) 
    {
        if (dp[i][w] == dp[i-1][w]) 
        {
            continue; // Coordinates was not included
        } 
        else 
        {
            itemsSelected.push_back(coordinates[i - 1].name);
            w -= coordinates[i - 1].weight;
            if (w <= 0) break; // Capacity exhausted
        }
    }

    reverse(itemsSelected.begin(), itemsSelected.end());
    return itemsSelected;
}

int main() 
{
    string fileName = "../DatasetsSamples/DataSet2/coordinates.csv";
    vector<Coordinates> coordinates = readCSV(fileName);

    cout << "|--------------------------------------|" << endl;
    cout << "|   Welcome to Knapsack's Algorithm    |" << endl;
    cout << "|--------------------------------------|" << endl;

    // Max weight set
    int maxWeight = 800; 
    // Calculate the coordinates to visit
    vector<string> stationsToVisit = knapsack(coordinates, maxWeight);
    
    // Print the coordinates to visit
    printItems(stationsToVisit, coordinates);

    Graph graph;
    string edges = "../DatasetsSamples/DataSet2/edges.csv";
    unordered_map<char, int> vertexMap;
    graph = filterEdgesFile(edges, vertexMap, graph, stationsToVisit);

    // Find the MST using Kruskal's algorithm
    vector<Edge> mst = KruskalMST(graph);
    cout << "| Path Visualized with Kruskal         |" << endl;
    cout << "| Starting Station "<< stationsToVisit[0] << "                   |" << endl;
    cout << "|--------------------------------------|" << endl;



    ofstream outputFile("../Outputs/Question4/Knapsack's_Visualization.csv");

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
        cout << "|    " << srcChar << " --> "
             << destChar << "    |       "
             << setw(6) << fixed << setprecision(2)
             << edge.weight << "         |" << endl;
        outputFile << srcChar << "," << destChar << "," << edge.weight << "\n";
        sum += edge.weight;
    }
    outputFile.close();
    cout << "|--------------------------------------|" << endl;
    cout << "|Total Distance is           " << setw(6) 
         << fixed << setprecision(2) << sum << "   |" << endl;
    cout << "|--------------------------------------|" << endl;


    return 0;
}

