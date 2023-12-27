// concrete implementation for 'Edge' class
#include "../../Common/dataSet2.h"
using namespace dataSet2;
using dataSet2::Edge;
using dataSet2::Node;
using dataSet2::Coordinate;
#include <algorithm>


/*
@couthelloword
@Ahmad Sobhy
...
@ayaan278
@Ahmad Ayaan
*/

Edge::Edge(){}

Edge::Edge(char name, double distance, pair<Node, Node> endVertices){
    this->name = name;
    this->distance = distance;
    this->endVertices = endVertices;
}

// end Vertices getter
pair<Node, Node> Edge::getEndVertices() const {
    return this->endVertices;
}

// id getter
char Edge::getName() const {return this->name;}

// distance getter
double Edge::getDistance() const {return this->distance;}


// getter for member '_TOTAL_NUM_OF_EDGES_'
int dataSet2::Edge::getTotalEdges(){
    return _TOTAL_NUM_OF_EDGES_;
}

//Calculate distance between two nodes
double calculateDistance(const Node& node1, const Node& node2)
{
    double distance = sqrt(
        pow((node1.getCoordinate().getXaxis() - node2.getCoordinate().getXaxis()), 2) + 
        pow((node1.getCoordinate().getYaxis() - node2.getCoordinate().getYaxis()), 2) + 
        pow((node1.getCoordinate().getZaxis() - node2.getCoordinate().getZaxis()), 2));
    return distance;
}
// Generate a function to filter the duplicate values

// Generate routes function
vector<Edge> Edge::generateRoutes(const vector<Node>& nodes) const
{
   // Create a vector of edges
    vector<Edge> routes;

    // Define the desired number of routes
    int desired_routes = 54;

    // Ensure each node connects to at least 3 other nodes
    for (const Node& node : nodes) 
    {
        // Calculate how many connections are needed to reach a total of 54 routes
        int remaining_connections = max(3, desired_routes - static_cast<int>(routes.size()));

        // Limit the maximum number of connections from each node to 5
        int num_connections = min(remaining_connections, 5);

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

    return routes;
}
