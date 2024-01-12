#include "../include/DAG.h"
#include <queue>
#include <algorithm>

// Implementation of DAG member functions
void DAG::addVertex(char id, int time)
{
    vertices.emplace(id, Vertex(id, time));
}

void DAG::addEdge(char u, char v, int comTime)
{
    vertices[u].outputs.emplace_back(Edge(vertices[u], vertices[v], comTime));
}

std::unordered_map<char, Vertex> &DAG::getVertices()
{
    return vertices;
}
