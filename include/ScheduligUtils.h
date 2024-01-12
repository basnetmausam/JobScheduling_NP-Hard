#include "DAG.h"
#include <vector>
#include <iostream>

int findEarliestMachine(const std::vector<int> &machineFinishTime);
std::vector<Vertex> getPredecessors(const std::unordered_map<char, Vertex> &graph, const Vertex &vertex);
Edge getEdge(const std::unordered_map<char, Vertex> &graph, const Vertex &source, const Vertex &destination);
