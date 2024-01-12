#include <list>
#include <unordered_map>
#include <queue>
#include "../include/DAG.h"

// Function to perform topological sort on the given graph
std::list<char> topologicalSort(const std::unordered_map<char, Vertex> &graph)
{
    std::queue<char> queue;
    std::unordered_map<char, int> inDegrees;
    std::list<char> result; // Vector to store the topological order

    // Initialize in-degrees
    for (const auto &[node, vertex] : graph)
    {
        inDegrees[node] = 0;
    }

    // Calculate in-degrees
    for (const auto &[node, vertex] : graph)
    {
        for (const Edge &edge : vertex.outputs)
        {
            inDegrees[edge.destination.id]++;
        }
    }

    // BFS traversal for topological sorting
    for (const auto &[node, vertex] : graph)
    {
        if (inDegrees[node] == 0)
        {
            queue.push(node);
        }
    }

    while (!queue.empty())
    {
        char v = queue.front();
        queue.pop();

        result.push_back(v); // Add node to the result vector

        for (const Edge &e : graph.at(v).outputs)
        {
            inDegrees[e.destination.id]--;
            if (inDegrees[e.destination.id] == 0)
            {
                queue.push(e.destination.id);
            }
        }
    }

    return result; // Return the topological order vector
}
