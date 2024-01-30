#include "include/DAG.h"
#include "include/Scheduler.h"
int main()
{
    DAG graph;

    // Add vertices and edges
    // Vertices
    graph.addVertex('A', 7);
    graph.addVertex('B', 5);
    graph.addVertex('C', 1);
    graph.addVertex('D', 4);
    graph.addVertex('E', 5);
    graph.addVertex('F', 2);
    graph.addVertex('G', 1);
    graph.addVertex('H', 5);
    graph.addVertex('I', 13);

    // Edges
    graph.addEdge('A', 'D', 2);
    graph.addEdge('B', 'D', 1);
    graph.addEdge('C', 'D', 6);
    graph.addEdge('D', 'E', 5);
    graph.addEdge('E', 'F', 3);
    graph.addEdge('E', 'G', 8);
    graph.addEdge('F', 'H', 4);
    graph.addEdge('G', 'H', 1);
    graph.addEdge('H', 'I', 1);

    int numMachines = 2;
    int weight = schedule(graph, numMachines);

    if (numMachines > 1)
    {
        // Print vertices with completion times
        std::cout << "\nJob Completion Times:\n";
        for (const auto &[id, vertex] : graph.getVertices())
        {
            std::cout << vertex.id << ": " << vertex.completionTime << std::endl;
        }
    }
    std::cout << "\n************************************" << std::endl;

    std::cout << "Minimum execution time for " << numMachines << " machines: " << weight << std::endl;

    return 0;
}
