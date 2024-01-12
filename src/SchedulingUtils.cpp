#include <vector>
#include <unordered_map>

#include "../include/DAG.h"

// Function to find the machine with the earliest finish time
int findEarliestMachine(const std::vector<int> &machineFinishTime)
{
    int earliestMachine = 0;
    for (auto i = 1U; i < machineFinishTime.size(); i++)
    {
        if (machineFinishTime[i] < machineFinishTime[earliestMachine])
        {
            earliestMachine = i;
        }
    }
    return earliestMachine;
}

// Function to get all the input vertices of a particular vertex
std::vector<Vertex> getPredecessors(const std::unordered_map<char, Vertex> &graph, const Vertex &vertex)
{
    std::vector<Vertex> predecessors;
    for (const auto &[id, v] : graph)
    {
        for (const Edge &edge : v.outputs)
        {
            if (edge.destination.id == vertex.id)
            {
                predecessors.push_back(v);
            }
        }
    }
    return predecessors;
}

// Function to get edge between two vertices
Edge getEdge(const std::unordered_map<char, Vertex> &graph, const Vertex &source, const Vertex &destination)
{
    for (const Edge &edge : source.outputs)
    {
        if (edge.destination.id == destination.id)
        {
            return edge; // Return a copy of the edge
        }
    }
    return Edge(); // Return an empty Edge if not found
}