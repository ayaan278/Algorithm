// concrete implementation for 'Coordinate' class
#include "../../Common/dataSet2.h"
#include "dataSet2.cpp"
using namespace dataSet2;
//TODO
//Add the summation of id and explain the validNumbers
vector<int> dataSet2::validNumbers = {0,1,3,6,7,8,9};

/*
@couthelloword
@Ahmad Sobhy
*/
Coordinate::Coordinate()
{
    // operating on the range of 0-200
    this->x = RNG(validNumbers, 100, 0, 10, 90, 100);
    this->y = RNG(validNumbers, 100, 0, 10, 90, 100);
    this->z = RNG(validNumbers, 100, 0, 10, 90, 100);
}

int Coordinate::getXaxis(){return this->x;}

int Coordinate::getYaxis(){return this->y;}

int Coordinate::getZaxis(){return this->z;}

Coordinate& Coordinate::getCoordinate()
{
    return *this;
}

// Deletable
void Coordinate::getData()
{
    cout << "x-axis = " << this->x << endl;
    cout << "y-axis = " << this->y << endl;
    cout << "z-axis = " << this->z << endl;
}