// Include the DAG.h header file to access Vertex and Edge classes
#include "DAG.h"

#include <vector>
#include <iostream>

// Function to find the earliest available machine based on machine finish times
// Parameters:
//   - machineFinishTime: A vector containing the finish times of machines
// Returns:
//   - The index of the earliest available machine
int findEarliestMachine(const std::vector<int> &machineFinishTime);

// Function to get the predecessors of a given vertex in a graph
// Parameters:
//   - graph: An unordered map representing the graph
//   - vertex: The vertex for which predecessors are to be found
// Returns:
//   - A vector of vertices representing the predecessors of the given vertex
std::vector<Vertex> getPredecessors(const std::unordered_map<char, Vertex> &graph, const Vertex &vertex);

// Function to get the edge between two vertices in a graph
// Parameters:
//   - graph: An unordered map representing the graph
//   - source: The source vertex of the edge
//   - destination: The destination vertex of the edge
// Returns:
//   - The edge between the source and destination vertices
Edge getEdge(const std::unordered_map<char, Vertex> &graph, const Vertex &source, const Vertex &destination);
