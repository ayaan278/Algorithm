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
    file.open(fileName, ios_base::app);
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
    string fileName = "coordinates.csv";
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


//Calculate distance between two nodes
double dataSet2::calculateDistance(const Node& node1, const Node& node2)
{
    double distance = sqrt(
            pow((node1.getCoordinate().getXaxis() - node2.getCoordinate().getXaxis()), 2) +
            pow((node1.getCoordinate().getYaxis() - node2.getCoordinate().getYaxis()), 2) +
            pow((node1.getCoordinate().getZaxis() - node2.getCoordinate().getZaxis()), 2));
    return distance;
}

void dataSet2::filterRoutes(vector<Edge>& routes, int desired_routes,
                            int min_degree, int max_degree)
{
    // remove the duplicates routes that have vertices in reverse order
    routes.erase(remove_if(routes.begin(), routes.end(),
                           [](const Edge& route) {
                               return route.getEndVertices().first.getName() > route.getEndVertices().second.getName();
                           }), routes.end());

    // Sort the routes based on distance
    sort(routes.begin(), routes.end(),
         [](const Edge& a, const Edge& b) {
             return a.getDistance() < b.getDistance();
         });

    // Remove the routes that have a degree less than the minimum degree and filter only the desired number of routes
    routes.erase(remove_if(routes.begin(), routes.end(),
                           [&min_degree, &max_degree](const Edge& route) {
                               return route.getEndVertices().first.getDegree() < min_degree ||
                                      route.getEndVertices().second.getDegree() < min_degree &&
                                      route.getEndVertices().first.getDegree() > max_degree ||
                                      route.getEndVertices().second.getDegree() > max_degree;
                           }), routes.end());


    // Make only the desired number of routes
    routes.erase(routes.begin() + desired_routes, routes.end());

}

// Generate routes function
vector<Edge> Edge::generateRoutes(const vector<Node>& nodes) const
{
    // Create a vector of edges
    vector<Edge> routes;

    // Define the desired number of routes
    int desired_routes = 54;

    // Define minimum number of nodes connected to each node
    int min_degree = 3;

    // Define maximum number of nodes connected to each node
    int max_degree = 5;

    //Generate all possible routes
    for (const Node& node : nodes)
    {
        // Connect the node to the closest nodes based on distance
        vector<Node> connected_Nodes = nodes;

        // Remove the current node from the vector
        connected_Nodes.erase(remove_if(connected_Nodes.begin(),
                                        connected_Nodes.end(),
                                        [&node](const Node& connected_Node) {
                                            return connected_Node.getName() == node.getName();
                                        }), connected_Nodes.end());

        // Sort the nodes based on distance
        sort(connected_Nodes.begin(), connected_Nodes.end(),
             [&node](const Node& a, const Node& b) {
                 return calculateDistance(node, a) < calculateDistance(node, b);
             });

        for (Node& connected_Node : connected_Nodes) {
            Edge route(node.getName(),
                       calculateDistance(node, connected_Node),
                       make_pair(node, connected_Node));

            // Check if the route already exists
            routes.push_back(route);
        }
    }

    // Filter the duplicate routes
    filterRoutes(routes, desired_routes, min_degree, max_degree);

    return routes;
}




void dataSet2::interface(){
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
}


