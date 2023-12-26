// concrete implementation for 'Edge' class
#include "../../Common/dataSet2.h"
#include "dataSet2.cpp"
using namespace dataSet2;
using dataSet2::Edge;
using dataSet2::Node;
#include <algorithm>


/*
@couthelloword
@Ahmad Sobhy
...
@ayaan278
@Ahmad Ayaan
*/

Edge::Edge(){}

Edge::Edge(char name, int distance, pair<Node, Node> endVertices)
{
    this->name = name;
    this->distance = distance;
    this->endVertices.first = endVertices.first;
    this->endVertices.second = endVertices.second;
}

// end Vertices getter
pair<Node, Node> Edge::getEndVertices(){
    return this->endVertices;
}

// id getter
char Edge::getName(){return this->name;}

// distance getter
double Edge::getDistance(){return this->distance;}

// getter for member '_TOTAL_NUM_OF_EDGES_'
int dataSet2::Edge::getTotalEdges(){
    return _TOTAL_NUM_OF_EDGES_;
}

/// Generate routes function
vector<Edge> dataSet2::generate_routes(const vector<Node> nodes) 
{
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
        // connected_Nodes.erase
        // (
        //     remove_if(connected_Nodes.begin(), 
        //                 connected_Nodes.end(),
        //                 [&node]
        //                 (const Node& connected_Node) 
        //                 { 
        //                     return connected_Node == node; 
        //                 }
        //                 ),connected_Nodes.end()
        // );

        // Sort the nodes based on distance
        sort(connected_Nodes.begin(), connected_Nodes.end(), 
            [node](const Node& a, const Node& b) 
            { 
                return calculateDistance(node, a) < calculateDistance(node, b);
            }
        );

        for(int i = 0; i < num_connections; i++)
        {
            //print the connected nodes
            cout << connected_Nodes[i].getName() << " ";
            
        }


        // for (const Node& connected_Node : connected_Nodes) {
        //     Edge route(node.getName(), connected_Node.getName());
        //     // Avoid redundancy
        //     if (find(routes.begin(), routes.end(), route) == routes.end() &&
        //         find(routes.begin(), routes.end(), Edge(connected_Node.id, node.id)) == routes.end()) 
        //         {
        //         routes.push_back(route);
        //     }

        //     // Break if the desired number of connections is reached
        //     if (static_cast<int>(routes.size()) == desired_routes) 
        //     {
        //         break;
        //     }
        // }
    }

    return routes;
}
