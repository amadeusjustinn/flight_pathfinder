#pragma once

#include "graph.h"
#include <map>
using std::pair;

/**
 * @brief Comparator used for priority queue
 *
 */
struct compareVertexWeight
{
    bool operator()(pair<Vertex, long double> &lhs, pair<Vertex, long double> &rhs)
    {
        return lhs.second > rhs.second;
    }
};

/**
 * @brief Dijkstra's algorithm for a starting node and an end node
 *
 * @param g Graph to be analysed
 * @param start Starting vertex
 * @param end End or destination vertex
 *
 * @return Graph with shortest path from starting vertex to end vertex
 */
Graph Dijkstra(Graph &, Vertex &, Vertex &);

/**
 * @brief Dijkstra's algorithm for a starting node and an end node
 *
 * @param g Graph to be analysed
 * @param start Starting vertex
 * @param end End or destination vertex
 *
 * @return Vector with vertices of shortest path from starting vertex to end vertex
 */
vector<Vertex> DijkstraV(Graph &, Vertex &, Vertex &);
