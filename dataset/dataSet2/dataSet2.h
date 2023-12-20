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
#include <string>
#include <vector>
#include <map>
using namespace std;

namespace dataSet2{
    // Section 1 : Entities
    void initialization(string fileName);

    // Coordinate-related declrations
    class Coordinate{
    private:
        int x, y, z;
    public:
        Coordinate();
        // Attributes getters
        int getXaxis();
        int getYaxis();
        int getZaxis();
        Coordinate& getCoordinate();
        void getData(); // no meaningful use, for testing purposes only
    };

    // Node-related declrations
    class Node{
    private:
        static const int  _TOTAL_NUM_OF_NODES_=20;
        inline static int _NUM_OF_NODES_;
        char name;
        Coordinate position;
        int degree, profit;

    public:
        Node();
        static int getTotalNum();
        char getName(void);
        int getDegree(void);
        int getProfit(void);
        Coordinate getCoordinate(void);
        void calulateDegree(void);

        void getData(void); // no meaningful use, for testing purposes only
        friend void dataSet2::initialization(string fileName); // friendship for facilitating accessbility
    };

    // Edge-related declrations. This class is unimplemented for now
    class Edge{
    private:
        char name;
        int cost;
        pair<Node, Node> endVertices;

    public:
        Edge();

        char getName(void);
        pair<Node, Node> getEndVertices(); 
        int calculateCost(void);
    };


    // Section 2 : namespace dataSet2 related functions(implemented in 'dataSet2.cpp' file)

    // set of vaild number for dataSet2's RNG() to use:
    extern vector<int> validNumbers;

    // mapping alphabit with numbers based on their order
    map<int, char> alphabeticOrder;

    // constructor for 'alphabeticOrder' map
    void setMap(map<int, char>& instance);

    // searcing within 'alphabeticOrder' map
    char mapping(map<int, char>& instance, int n);

    // general purpose random number generator. operating on validNumbers
    int RNG(vector<int> validNumbers, int upperPound, int lowerPound, int a, int b, int c);

    // initializor
    void initialization(string fileName);

    // executer
    void dataSet2MainLoop(int n);
}
# endif