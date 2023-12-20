// conctere implementation for 'Coordinate' class
#include "../dataSet2.h"
#include "dataSet2.cpp"
using namespace dataSet2;
vector<int> dataSet2::validNumbers = {0,1,3,6,7,8,9};

Coordinate::Coordinate(){
    // operating on the range of 0-200
    this->x = RNG(validNumbers, 200, 0, 10, 90, 100);
    this->y = RNG(validNumbers, 200, 0, 10, 90, 100);
    this->z = RNG(validNumbers, 200, 0, 10, 90, 100);
}

int Coordinate::getXaxis(){return this->x;}

int Coordinate::getYaxis(){return this->y;}

int Coordinate::getZaxis(){return this->z;}

Coordinate& Coordinate::getCoordinate(){
    return *this;
}

// Deletable
void Coordinate::getData(){
    cout << "x-axis = " << this->x << endl;
    cout << "y-axis = " << this->y << endl;
    cout << "z-axis = " << this->z << endl;
}

