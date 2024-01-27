// concrete implementation for 'Coordinate' class
#include "../../Common/dataSet2.h"
#include "dataSet2.cpp"
using namespace dataSet2;

vector<int> dataSet2::validNumbers = {1,2,3,6,7,9};

Coordinate::Coordinate()
{
    // operating on the range of 0-200
    this->x = RNG(validNumbers, 200, 0, 10, 90, 100);
    this->y = RNG(validNumbers, 200, 0, 10, 90, 100);
    this->z = RNG(validNumbers, 200, 0, 10, 90, 100);
}

int Coordinate::getXaxis(){return this->x;}

int Coordinate::getYaxis(){return this->y;}

int Coordinate::getZaxis(){return this->z;}

Coordinate& Coordinate::getCoordinate()
{
    return *this;
}

