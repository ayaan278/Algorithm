// concrete implementation for 'Edge' class
#include "../../Common/dataSet2.h"
using namespace dataSet2;
using dataSet2::Edge;
using dataSet2::Node;
using dataSet2::Coordinate;


/*
@couthelloword
@Ahmad Sobhy
...
@ayaan278
@Ahmad Ayaan
*/

Edge::Edge(){}

Edge::Edge(char name, double distance, pair<Node, Node> endVertices){
    this->name = name;
    this->distance = distance;
    this->endVertices = endVertices;
}

// end Vertices getter
pair<Node, Node> Edge::getEndVertices() const {
    return this->endVertices;
}

// id getter
char Edge::getName() const {return this->name;}

// distance getter
double Edge::getDistance() const {return this->distance;}


// getter for member '_TOTAL_NUM_OF_EDGES_'
int dataSet2::Edge::getTotalEdges(){
    return _TOTAL_NUM_OF_EDGES_;
}

