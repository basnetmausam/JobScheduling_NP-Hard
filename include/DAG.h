#ifndef DAG_H
#define DAG_H

#include <list>
#include <unordered_map>
#include <iostream>
#include <vector>

// Forward declaration of Edge class to resolve circular dependency
class Edge;

class Vertex
{
public:
    char id;                 // Unique identifier for the vertex
    int executionTime;       // Execution time of the job
    int completionTime;      // Completion time of the job
    std::list<Edge> outputs; // List of outgoing edges from this vertex

    Vertex() = default; // Default constructor

    // Parameterized constructor to initialize vertex with id and execution time
    Vertex(char id, int executionTime) : id(id), executionTime(executionTime){};

    int getCompletionTime() const { return completionTime; }; // Getter for completion time

    std::string toString() const { return std::string(1, id); }; // Convert vertex to string representation
};

class Edge
{
public:
    Vertex source;      // Source vertex of the edge
    Vertex destination; // Destination vertex of the edge

    int communicationTime; // Communication time between source and destination

    Edge() = default; // Default constructor

    // Parameterized constructor to initialize edge with source, destination, and communication time
    Edge(Vertex src, Vertex dest, int comTime) : source(src), destination(dest), communicationTime(comTime){};

    // Convert edge to string representation
    std::string toString() const
    {
        return "(" + std::string(1, source.id) + "," + std::string(1, destination.id) + "," + std::to_string(communicationTime) + ")";
    }
};

class DAG
{
public:
    std::unordered_map<char, Vertex> vertices; // Map to store vertices in the DAG

    // Function to add a new vertex to the DAG
    void addVertex(char id, int time);

    // Function to add a new directed edge between two vertices in the DAG
    void addEdge(char u, char v, int comTime);

    // Getter for the vertices of the DAG
    std::unordered_map<char, Vertex> &getVertices();
};

#endif
