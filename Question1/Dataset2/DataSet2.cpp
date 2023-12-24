// concrete implementation for 'dataSet2' namespace
#include "../../Common/dataSet2.h"
using namespace dataSet2;

/*
@couthelloword
@Ahmad Sobhy
*/
int dataSet2::RNG(vector<int> validNumbers, int upperPound, int lowerPound, int a, int b, int c)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> valueDistribution(0, 6); 
    int sum = a+b+c;
    discrete_distribution<int> distribution{
        (static_cast<double>(a))/sum, 
        (static_cast<double>(b))/sum,  
        (static_cast<double>(c))/sum};

    bool valid = false;
    int solution[3];
    int result=0, index=0, j=1;
    int digitDistribution = distribution(gen);

    while(valid != true){

        result=0, index=0, j=1;
        for(int i=0; i<=digitDistribution; i++, j*=10){
            index = valueDistribution(gen);
            solution[i] = validNumbers[index];
            result += j*(solution[i]);
        }
        if(result >= lowerPound && result <= upperPound)
            valid = true;

    }

    return result;
}

void dataSet2::setMap(map<int, char>& instance)
{
    for (int i = 1, letter = 'A'; i <= 20; ++i, ++letter) 
    {
        instance[i] = letter;
    }
}

char dataSet2::mapping(map<int, char>& instance, int n)
{
    auto it = instance.find(n);
    return it->second; 
}

void dataSet2::initialization(string fileName)
{
    fstream file;
    file.open(fileName, ios_base::app);
    for(int i=0; i<Node::getTotalNum(); i++){
        Node newNode;
        file << newNode.getName() << "," << to_string(newNode.position.getXaxis()) 
            << "," << to_string(newNode.position.getYaxis()) << "," << to_string(newNode.position.getZaxis())
            << "," << to_string(newNode.getProfit()) << "," << to_string(newNode.getDegree()) << endl;
    }
    file.close();
} 

void dataSet2::dataSet2MainLoop(int n)
{
    dataSet2::alphabeticOrder;
    dataSet2::setMap(alphabeticOrder);
    string fileName = "coordinates" + to_string(n) + ".csv";
    dataSet2::initialization(fileName);
}


