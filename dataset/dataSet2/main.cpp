// ambiguous file idk what is that thing
#include "dataSet2.h"
// #include "implementations/dataSet2.cpp"
#include "implementations/Coordinate.cpp"
#include "implementations/Node.cpp"
using namespace dataSet2;
using dataSet2::Node;
using dataSet2::validNumbers;


int main(){
    int files = 3; // defines the name of the 'csv' file we want to generate
    dataSet2::dataSet2MainLoop(files);
    return 0;
}

