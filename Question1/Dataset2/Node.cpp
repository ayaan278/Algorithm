// concrete implementation for 'Node' class
#include "../../Common/dataSet2.h"
using namespace dataSet2;
using dataSet2::Node;

/*
@couthelloword
@Ahmad Sobhy
*/
Node::Node(char name, int x, int y, int z, int profit, int weight){
    this->name = name;
    this->position.setX(x);    
    this->position.setY(y);
    this->position.setZ(z);
    this->profit = profit;
    this->weight = weight;
}

Node::Node()
{
    Node::_NUM_OF_NODES_++;
    this->name = dataSet2::mapping(dataSet2::alphabeticOrder, Node::_NUM_OF_NODES_);

    dataSet2::Coordinate newPosition;
    this->position = newPosition.getCoordinate();

    this->profit = RNG(validNumbers, 100, 0, 9, 90, 1);

    this->weight = RNG(validNumbers, 100, 10, 0, 89, 1);

}

char Node::getName() const {
    return this->name;
}

int Node::getDegree(){return this->weight;}

int Node::getProfit(){return this->profit;}

int Node::getTotalNum(){return _TOTAL_NUM_OF_NODES_;}

Coordinate Node::getCoordinate() const { return this->position; }



