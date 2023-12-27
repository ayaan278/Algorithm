#include "../../Common/dataSet2.h"
#include "./coordinate.cpp"
#include "./node.cpp"


using namespace dataSet2;
using dataSet2::Node;
using dataSet2::Edge;
using dataSet2::validNumbers;


/*
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
            // cout << "Enter the file name of the coordinates: ";
            // string coordinatesFile;
            // cin >> coordinatesFile;
            dataSet2::generateEdges("../../Dataset/Dataset2/coordinates.csv");
            break;
    }
 
    return 0;
}

