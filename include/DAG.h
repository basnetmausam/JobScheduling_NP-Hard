#ifndef DAG_H
#define DAG_H

#include <list>
#include <unordered_map>
#include <iostream>
#include <vector>

class Edge;

class Vertex
{
public:
    char id;
    int executionTime;       // Execution time of the job
    int completionTime;      // Completion time of the job
    std::list<Edge> outputs; // List of outgoing edges from this vertex

    Vertex() = default;

    Vertex(char id, int executionTime) : id(id), executionTime(executionTime){};

    int getCompletionTime() const { return completionTime; };

    std::string toString() const { return std::string(1, id); };
};

class Edge
{
public:
    Vertex source;
    Vertex destination;

    int communicationTime; // Communication time between source and destination

    Edge() = default;

    Edge(Vertex src, Vertex dest, int comTime) : source(src), destination(dest), communicationTime(comTime){};

    std::string toString() const
    {
        return "(" + std::string(1, source.id) + "," + std::string(1, destination.id) + "," + std::to_string(communicationTime) + ")";
    }
};

class DAG
{
public:
    std::unordered_map<char, Vertex> vertices;

    void addVertex(char id, int time);

    void addEdge(char u, char v, int comTime);

    std::unordered_map<char, Vertex> &getVertices();

    void printGraph();
};

std::list<char> topologicalSort(const std::unordered_map<char, Vertex> &graph);

int findEarliestMachine(const std::vector<int> &machineFinishTime);

std::vector<Vertex> getPredecessors(const std::unordered_map<char, Vertex> &graph, const Vertex &vertex);

Edge getEdge(const std::unordered_map<char, Vertex> &graph, const Vertex &source, const Vertex &destination);

int schedule(DAG &graph, int numMachine);

#endif
