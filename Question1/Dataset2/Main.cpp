#include "../../Common/dataSet2.h"
#include "./coordinate.cpp"
#include "./node.cpp"


using namespace dataSet2;
using dataSet2::Node;
using dataSet2::validNumbers;


/*
@couthelloword
@Ahmad Sobhy
*/
int main(){
    int files = 3; // defines the name of the 'csv' file we want to generate
    dataSet2::dataSet2MainLoop(files);
    return 0;
}

