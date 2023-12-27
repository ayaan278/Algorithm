// concrete implementation for 'Node' class
#include "../../Common/dataSet2.h"
using namespace dataSet2;
using dataSet2::Node;

/*
@couthelloword
@Ahmad Sobhy
*/
Node::Node(char name, int x, int y, int z, int profit, int degree){
    this->name = name;
    this->position.setX(x);    
    this->position.setY(y);
    this->position.setZ(z);
    this->profit = profit;
    this->degree = degree;
}

Node::Node()
{
    Node::_NUM_OF_NODES_++;
    this->name = dataSet2::mapping(dataSet2::alphabeticOrder, Node::_NUM_OF_NODES_);

    dataSet2::Coordinate newPosition;
    this->position = newPosition.getCoordinate();

    this->profit = RNG(validNumbers, 600, 0, 10, 90, 500);

    // for now and until the concrete implementation of the class 'Edge' the 'degree' are set to 0
    this->degree=0;
}

char Node::getName() const {
    return this->name;
}

int Node::getDegree(){return this->degree;}

int Node::getProfit(){return this->profit;}

int Node::getTotalNum(){return _TOTAL_NUM_OF_NODES_;}

Coordinate Node::getCoordinate() const { return this->position; }

// // Deletable
void Node::getData()
{
    cout << "Node summary " << endl;
    cout << "\t name:\t" << this->name << endl;

    cout << "\tNode positioning:" << endl;
    this->position.getData();

    cout << "\tNode profit:\t" << this->profit << endl;
}