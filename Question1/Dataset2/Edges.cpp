// concrete implementation for 'Coordinate' class
#include "../../Common/dataSet2.h"
#include "dataSet2.cpp"
using namespace dataSet2;
using dataSet2::Edge;


/*
@couthelloword
@Ahmad Sobhy
...
@ayaan278
@Ahmad Ayaan
*/
Edge::Edge()
{

}

// Calculate distance between two nodes
double calculate_distance(const Node& station1, const Node& station2) 
{
    return std::sqrt(std::pow(station1.x - station2.x, 2) +
                     std::pow(station1.y - station2.y, 2) +
                     std::pow(station1.z - station2.z, 2));
}

// Generate routes function
vector<Edge> generate_routes(const vector<Node>& nodes) 
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
        vector<Node> connected_stations = nodes;
        connected_stations.erase
        (
            remove_if(connected_stations.begin(), 
                        connected_stations.end(),
                        [&node](const Node& s) 
                        { 
                            return s.id == node.id; 
                        }),
                        connected_stations.end()
        );

        sort(connected_stations.begin(), connected_stations.end(),
                  [&node](const Node& s1, const Node& s2) 
                  {
                    return calculate_distance(node, s1) < calculate_distance(node, s2);
                  }
        );

        for (const Node& connected_station : connected_stations) {
            Edge route(node.id, connected_station.id);
            // Avoid redundancy
            if (find(routes.begin(), routes.end(), route) == routes.end() &&
                find(routes.begin(), routes.end(), Edge(connected_station.id, node.id)) == routes.end()) 
                {
                routes.push_back(route);
            }

            // Break if the desired number of connections is reached
            if (static_cast<int>(routes.size()) == desired_routes) 
            {
                break;
            }
        }
    }

    return routes;
}
