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
#include <queue>
#include <limits>
#include <memory>
#include <unordered_map> 
using namespace std;

namespace dataSet2
{
    // Section 1 : Entities
    void initialization(string fileName);

    // Coordinate-related declarations
    class Coordinate
    {
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
    };

    // Node-related decorations
    class Node
    {
    private:
        static const int  _TOTAL_NUM_OF_NODES_=20;
        inline static int _NUM_OF_NODES_;
        char name;
        Coordinate position;
        int weight, profit;

    public:
        Node();
        Node(char name, int x, int y, int z, int profit, int weight);
        static int getTotalNum();
        char getName() const;
        int getDegree();
        int getProfit();
        Coordinate getCoordinate() const;

        friend void dataSet2::initialization(string fileName); // friendship for facilitating accessability
    };

    // Edge-related declarations
    class Edge
    {
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
    
    // initializer
    void initialization(string fileName);

    // executer
    void generateCoordinates();

    // Edges developer
    void generateEdges(string coordinatesFile);
}
# endif