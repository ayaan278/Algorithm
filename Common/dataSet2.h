/*
dataSet2.h:
    1. refer to this file for abstracted form of the dataSet2 components.
    2. for entities-related implementations refer for implementations directory then 'entity'.cpp for the concrete implementations.
    3. this header file ALONE is enough to be directly included within any scopes that implements Graph processing algorithms. MOSTLY NO OTHER FILES REQUIRED
*/
#pragma once
# ifndef _DATASET2_
# define _DATASET2_
#include <iostream>
#include <random> // to operate 'RNG()'
#include <fstream> // for writing into 'csv'
#include <cmath>
#include <string>
#include <algorithm>
#include <utility>
#include <sstream>
#include <vector>
#include <map>
#include <memory>
#include <unordered_map> 
using namespace std;

namespace dataSet2{
    // Section 1 : Entities
    void initialization(string fileName);

    // Coordinate-related declarations
    class Coordinate{
    private:
        int x, y, z;
    public:
        Coordinate();       
        // setters
        void setX(int x){this->x = x;}
        void setY(int y){this->y = y;}
        void setZ(int z){this->z = z;}

        // Attributes getters
        int getXaxis();
        int getYaxis();
        int getZaxis();
        Coordinate& getCoordinate();
        void getData(); // no meaningful use, for testing purposes only
    };

    // Node-related declarations
    class Node{
    private:
        static const int  _TOTAL_NUM_OF_NODES_=20;
        inline static int _NUM_OF_NODES_;
        char name;
        Coordinate position;
        int weight, degree, profit;

    public:
        Node();
        Node(char name, int x, int y, int z, int profit, int degree);


        // Attributes getters
        char getName() const;
        Coordinate getCoordinate() const;
        int getProfit();
        int getWeight();
        int getDegree();

        static int getTotalNum();
        void calculateDegree();

        void getData(); // no meaningful use, for testing purposes only
        friend void dataSet2::initialization(string fileName); // friendship for facilitating accessability
    };

    // Edge-related declarations
    class Edge{
    private:
        static const int _TOTAL_NUM_OF_EDGES_ = 54;
        char name;
        double distance;
        pair<Node, Node> endVertices;

    public:
        Edge();
        Edge(char name, double distance, pair<Node, Node> endVertices);

        // get distance
        int getTotalEdges();
        double getDistance() const;
        char getName() const;
        pair<Node, Node> getEndVertices() const;
        
        // routes generator
        vector<Edge> generateRoutes(const vector<Node>& nodes) const;
    };

    // Adjacency List-related declarations. Implementation will occur in 'AdjacencyList.cpp'
    class AdjacencyList{};



    // Section 2 : namespace dataSet2 related functions(implemented in 'dataSet2.cpp' file)

    // set of valid number for dataSet2's RNG() to use:
    extern vector<int> validNumbers;

    // mapping alphabet with numbers based on their order
    map<int, char> alphabeticOrder;

    // constructor for 'alphabeticOrder' map
    void setMap(map<int, char>& instance);

    // searching within 'alphabeticOrder' map
    char mapping(map<int, char>& instance, int n);

    // general purpose random number generator. operating on validNumbers
    int RNG(vector<int> validNumbers, int upperPound, int lowerPound, int a, int b, int c);
    
    // Nodes developer
    void initialization(string fileName);

    // Nodes printer
    void generateCoordinates();

    // distance calculator
    double calculateDistance(const Node& node1, const Node& node2);

    // Edges configurator
    void filterRoutes(vector<Edge>& routes, int desired_routes,int min_degree, int max_degree);

    // Edges developer
    void generateEdges(string coordinatesFile);

    // Entry point for dataSet2
    void interface();
}
# endif