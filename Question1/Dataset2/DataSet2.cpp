// concrete implementation for 'dataSet2' namespace
#include "../../Common/dataSet2.h"
using namespace dataSet2;
using dataSet2::Node;
using dataSet2::Edge;
using dataSet2::Coordinate;
#include "Edges.cpp"

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
    file.open(fileName, ios_base::out);
    for(int i=0; i<Node::getTotalNum(); i++){
        Node newNode;
        file << newNode.getName() << "," << to_string(newNode.position.getXaxis()) 
            << "," << to_string(newNode.position.getYaxis()) << "," << to_string(newNode.position.getZaxis())
            << "," << to_string(newNode.getProfit()) << "," << to_string(newNode.getDegree()) << endl;
    }
    file.close();
} 


void dataSet2::generateCoordinates()
{
    dataSet2::alphabeticOrder;
    dataSet2::setMap(alphabeticOrder);
    string fileName = "../../Dataset/Dataset2/coordinates.csv";
    dataSet2::initialization(fileName);

}


void dataSet2::generateEdges(string coordinatesFile)
{
    string edgeFileName = "../../Dataset/Dataset2/edges.csv";
    fstream file;
    ifstream file2;
    file.open(edgeFileName, ios_base::out);
    file2.open(coordinatesFile, ios_base::in);

    vector<Node> nodes;
    string line, word; 
    while (getline(file2, line)) {
        stringstream ss(line);

        char name;
        int x, y, z, profit, degree, columnCount = 0;
        while (getline(ss, word, ',')) {
            switch (columnCount) {
                case 0:
                    name = word[0];
                    break;
                case 1:
                    x = stoi(word);
                    break;
                case 2:
                    y = stoi(word);
                    break;
                case 3:
                    z = stoi(word);
                    break;
                case 4:
                    profit = stoi(word);
                    break;
                case 5:
                    degree = stoi(word);
                    break;
                default:
                    // Handle the case where there are more values than expected
                    break;
            }
            
            columnCount++;
        }

        // Create a new Node and store it in the vector
        Node newNode(name, x, y, z, profit, degree);
        nodes.push_back(newNode);
    }

    // Close the file
    file2.close();
    
    // Create a vector of edges
    vector<Edge> edges;

    Edge obj;

    edges = obj.generateRoutes(nodes);

    // Write the edges to the file
    for (const Edge& edge : edges) {
        file << edge.getEndVertices().first.getName()
        << "," << edge.getEndVertices().second.getName()
        << "," << edge.getDistance() << "," <<  endl;
    }

    // Close the file
    file.close();

    cout<<"|------------------------------------------------------------------|"<<endl;
    cout<<"|            The edges have been generated successfully            |"<<endl;
    cout<<"|------------------------------------------------------------------|"<<endl;

}

