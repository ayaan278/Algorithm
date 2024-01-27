#include "../../Common/dataSet2.h"
#include "./Coordinate.cpp"
#include "./Node.cpp"


using namespace dataSet2;
using dataSet2::Node;
using dataSet2::Edge;
using dataSet2::validNumbers;


/*
@author 
@couthelloword
@Ahmad Sobhy
*/
int main(){
    cout<<"|------------------------------------------------------------------|"<<endl;
    cout<<"|            This is the output of the second dataset              |"<<endl;
    cout<<"|------------------------------------------------------------------|"<<endl;
    cout<<"| Enter 1 to generate random coordinates                           |"<<endl;
    cout<<"| Enter 2 to generate edges from those co-ordinates                |"<<endl;
    cout<<"|------------------------------------------------------------------|"<<endl;

    int choice;
    cin>>choice;
    switch(choice){
        case 1:
            dataSet2::generateCoordinates();
            break;
        case 2:
            dataSet2::generateEdges("../../DatasetsSamples/Dataset2/coordinates.csv");
            break;
    }
 
    return 0;
}

