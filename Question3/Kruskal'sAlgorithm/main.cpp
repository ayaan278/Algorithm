#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>

using namespace std;

struct Edge {
    int src, dest;
    double weight;
    Edge(int s, int d, double w) : src(s), dest(d), weight(w) {}
};

bool compareByWeight(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

struct subset {
    int parent;
    int rank;
};

int find(vector<subset>& subsets, int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(vector<subset>& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void loadEdgesFromFile(vector<Edge>& edges, const string& filePath, map<char, int>& vertexIndexMap) {
    ifstream file(filePath);
    if (!file) {
        cerr << "I can't open the file: " << filePath << endl;
        return;
    }
    string line;
    int index = 0; // I'll use this index for the vertices
    while (getline(file, line)) {
        istringstream iss(line);
        char srcChar, destChar;
        double weight;
        char comma;

        iss >> srcChar >> comma >> destChar >> comma >> weight;
        if (iss.fail()) {
            cerr << "I encountered an error parsing the line: " << line << endl;
            iss.clear();
            continue;
        }

        // I'm mapping the vertices to indices here
        if (vertexIndexMap.find(srcChar) == vertexIndexMap.end()) {
            vertexIndexMap[srcChar] = index++;
        }
        if (vertexIndexMap.find(destChar) == vertexIndexMap.end()) {
            vertexIndexMap[destChar] = index++;
        }

        edges.push_back(Edge(vertexIndexMap[srcChar], vertexIndexMap[destChar], weight));
    }
    file.close();
}

vector<Edge> KruskalMST(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end(), compareByWeight);
    vector<subset> subsets(V);
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    vector<Edge> result;
    for (Edge& e : edges) {
        int x = find(subsets, e.src);
        int y = find(subsets, e.dest);

        if (x != y) {
            result.push_back(e);
            Union(subsets, x, y);
        }
    }
    return result;
}

int main() {
    vector<Edge> edges;
    map<char, int> vertexIndexMap;
    string filePath = "../../Dataset/DataSet2/edges.csv";
    loadEdgesFromFile(edges, filePath, vertexIndexMap);

    int V = vertexIndexMap.size(); // I'm determining the number of vertices here

    vector<Edge> mst = KruskalMST(edges, V);

    cout << "Minimum Spanning Tree:" << endl;
    for (const Edge& e : mst) {
        char srcChar = 'A' + e.src; // I'm assuming vertices start from 'A'
        char destChar = 'A' + e.dest; // I'll adjust this if the vertices have different labels
        cout << srcChar << " -- " << destChar << " == " << e.weight << endl;
    }

    return 0;
}
