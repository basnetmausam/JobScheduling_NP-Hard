#include <list>
#include <unordered_map>
#include <queue>
#include "../include/DAG.h"

// Function to perform topological sort on the given graph
std::list<char> topologicalSort(const std::unordered_map<char, Vertex> &graph)
{
    std::queue<char> queue;                  // Queue for BFS traversal
    std::unordered_map<char, int> inDegrees; // Map to store in-degrees of each vertex
    std::list<char> result;                  // List to store the topological order

    // Initialize in-degrees
    for (const auto &[node, vertex] : graph)
    {
        inDegrees[node] = 0;
    }

    // Calculate in-degrees
    for (const auto &[node, vertex] : graph)
    {
        // Traverse each output edge of the current vertex
        for (const Edge &edge : vertex.outputs)
        {
            // Increment in-degree for the destination vertex of the edge
            inDegrees[edge.destination.id]++;
        }
    }

    // BFS traversal for topological sorting
    for (const auto &[node, vertex] : graph)
    {
        // Enqueue vertices with in-degree 0
        if (inDegrees[node] == 0)
        {
            queue.push(node);
        }
    }

    while (!queue.empty())
    {
        char v = queue.front();
        queue.pop();

        result.push_back(v); // Add node to the result list

        // Update in-degrees and enqueue adjacent vertices with in-degree 0
        for (const Edge &e : graph.at(v).outputs)
        {
            inDegrees[e.destination.id]--;

            // Enqueue vertices with in-degree 0 after the update
            if (inDegrees[e.destination.id] == 0)
            {
                queue.push(e.destination.id);
            }
        }
    }

    return result; // Return the topological order list
}
