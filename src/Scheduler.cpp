#include "../include/DAG.h"
#include "../include/ScheduligUtils.h"
#include "../include/TopologicalSort.h"
#include <algorithm>

// Scheduler function to assign jobs to machines and calculate makespan
int schedule(DAG &graph, int numMachine)
{
    // No machines for the job
    if (numMachine <= 0)
    {
        return 0;
    }

    // Schedule jobs on a single machine
    if (numMachine == 1)
    {
        int totalDuration = 0;

        // Calculate sum of all vertices' durations
        for (const auto &[id, vertex] : graph.getVertices())
        {
            totalDuration += vertex.executionTime; // Assuming you meant "duration" instead of "executationTime"
        }

        // Calculate sum of all edges' weights (assuming "weight" is the correct attribute)
        int totalEdgeWeights = 0;
        for (const auto &[id, vertex] : graph.getVertices())
        {
            for (const Edge &edge : vertex.outputs)
            {
                totalEdgeWeights += edge.communicationTime;
            }
        }

        int totalWeight = totalDuration + totalEdgeWeights;

        // Return the total weight
        return totalWeight;
    }

    // Get topological order of jobs
    std::list<char> order = topologicalSort(graph.getVertices());

    // Print the Topological order
    std::cout << "\nOrder of job execution: ";
    for (char node : order)
    {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    // Track scheduled vertices for each machine
    std::vector<std::vector<char>> scheduledVertices; // Use std::vector for consistency
    for (int i = 0; i < numMachine; i++)
    {
        scheduledVertices.push_back({}); // Initialize empty lists for each machine
    }

    // Initialize machine finish times
    std::vector<int> machineFinishTime(numMachine, 0); // Use std::vector for consistency

    // Schedule jobs one by one
    for (char jobId : order)
    {
        // Get job vertex
        Vertex job = graph.getVertices().at(jobId); // Use at for potential exception

        // Find the predecessors of job vertex
        std::vector<Vertex> inputs = getPredecessors(graph.getVertices(), job);
        std::cout << "\nPredecessors of job '" << jobId << "' are: [ ";
        for (const Vertex &in : inputs)
        {
            std::cout << in.id << " ";
        }
        std::cout << "]" << std::endl;

        // Find the machine with earliest finish time
        int earliestMachine = findEarliestMachine(machineFinishTime);
        int maxDependencyFinishTime = 0;

        // Update finish time based on dependencies
        for (const Vertex &in : inputs)
        {
            Edge edge = getEdge(graph.getVertices(), in, job);

            // Edge found, use it
            int dependencyFinishTime = std::max(in.getCompletionTime(), machineFinishTime[earliestMachine]) + edge.communicationTime;
            std::cout << "Completion time of dependency '" << in.id << "' is: " << dependencyFinishTime << std::endl;
            maxDependencyFinishTime = std::max(maxDependencyFinishTime, dependencyFinishTime);
        }

        if (maxDependencyFinishTime != 0)
        {
            std::cout << "\nMaximum dependency completion time: " << maxDependencyFinishTime << std::endl;
        }

        std::cout << "Execution time of '" << jobId << "' is: " << job.executionTime << std::endl;

        // No predecessors
        if (inputs.size() == 0)
        {
            // Update finish time with job duration
            machineFinishTime[earliestMachine] += job.executionTime;

            // Set job completion time
            job.completionTime = machineFinishTime[earliestMachine];

            // Update completion time in the graph
            graph.getVertices().at(jobId).completionTime = job.completionTime;
        }
        else
        {
            // Update finish time with job duration
            machineFinishTime[earliestMachine] = std::max(maxDependencyFinishTime, machineFinishTime[earliestMachine]) + job.executionTime;

            // Set job completion time
            job.completionTime = maxDependencyFinishTime + job.executionTime;

            // Update completion time in the graph
            graph.getVertices().at(jobId).completionTime = job.completionTime;
        }

        // Track scheduled vertices for the machine
        scheduledVertices[earliestMachine].push_back(jobId);
        std::cout << "\nSo, Finish time for each machine: [ ";
        for (int m = 0; m < numMachine; m++)
        {
            std::cout << machineFinishTime[m] << " ";
        }
        std::cout << "]" << std::endl;
        std::cout << "************************************" << std::endl;
    }

    // Print vertices scheduled on each machine
    for (int i = 0; i < numMachine; i++)
    {
        std::cout << "Jobs scheduled in machine " << (i + 1) << " : ";
        for (const char &vertexId : scheduledVertices[i])
        {
            std::cout << vertexId << " ";
        }
        std::cout << std::endl;
    }

    // Get overall makespan
    int makespan = *std::max_element(machineFinishTime.begin(), machineFinishTime.end());

    return makespan;
};
