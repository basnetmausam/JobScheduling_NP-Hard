// Include necessary header files for the unordered_map, list, queue, and the DAG.h header file
#include <unordered_map>
#include <list>
#include <queue>
#include "DAG.h"

// Function to perform topological sort on the given graph
// Parameters:
//   - graph: An unordered map representing the graph with vertices of type Vertex
// Returns:
//   - A list of characters representing the topological order of the graph
std::list<char> topologicalSort(const std::unordered_map<char, Vertex> &graph);
