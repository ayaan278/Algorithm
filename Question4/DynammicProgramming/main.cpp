#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Item {
    string name;
    int x, y, z; // Coordinates
    int profit;
    int weight;
};

vector<Item> readCSV(const string& fileName) 
{
    vector<Item> items;
    ifstream file(fileName);
    string line;

    if (!file.is_open()) 
    {
        cerr << "Error opening file: " << fileName << endl;
        return items;
    }

    while (getline(file, line)) 
    {
        if (line.empty()) continue; // Skip empty lines

        stringstream ss(line);
        Item item;
        string temp;

        try {
            if (!getline(ss, item.name, ',')) throw invalid_argument("Missing name");
            if (!getline(ss, temp, ',')) throw invalid_argument("Invalid x coordinate");
            item.x = stoi(temp);
            if (!getline(ss, temp, ',')) throw invalid_argument("Invalid y coordinate");
            item.y = stoi(temp);
            if (!getline(ss, temp, ',')) throw invalid_argument("Invalid z coordinate");
            item.z = stoi(temp);
            if (!getline(ss, temp, ',')) throw invalid_argument("Invalid profit");
            item.profit = stoi(temp);
            if (!getline(ss, temp, ',')) throw invalid_argument("Invalid weight");
            item.weight = stoi(temp);

            items.push_back(item);
        } catch (const invalid_argument& e) {
            cerr << "Invalid argument: " << e.what() << " in line: " << line << endl;
        }
    }

    file.close();
    return items;
}

vector<string> knapsack(const vector<Item>& items, int maxWeight) 
{
    int n = items.size();
    vector<vector<int> > dp(n + 1, vector<int>(maxWeight + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= maxWeight; w++) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = max(items[i - 1].profit + dp[i - 1][w - items[i - 1].weight], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    vector<string> itemsSelected;
    int w = maxWeight;

    for (int i = n; i > 0; i--) {
        if (dp[i][w] == dp[i-1][w]) {
            continue; // Item was not included
        } else {
            itemsSelected.push_back(items[i - 1].name);
            w -= items[i - 1].weight;
            if (w <= 0) break; // Capacity exhausted
        }
    }

    reverse(itemsSelected.begin(), itemsSelected.end());
    return itemsSelected;
}

int main() 
{
    string fileName = "../../DatasetsSamples/DataSet2/coordinates.csv";; // Set the correct path to your CSV file
    vector<Item> items = readCSV(fileName);

    int maxWeight = 800; // Maximum weight capacity of the truck
    vector<string> stationsToVisit = knapsack(items, maxWeight);

    cout << "Stations to visit: ";
    for (const string& station : stationsToVisit) {
        cout << station << " ";
    }
    cout << endl;
    int totalWeight = 0, totalProfit = 0;
    for (const string& stationName : stationsToVisit) {
        for (const Item& item : items) {
            if (item.name == stationName) {
                totalWeight += item.weight;
                totalProfit += item.profit;
                cout << "Station: " << item.name << ", Weight: " << item.weight << ", Profit: " << item.profit << endl;
                break;
            }
        }
    }

    cout << "Total Weight: " << totalWeight << ", Total Profit: " << totalProfit << endl;

    return 0;
}

