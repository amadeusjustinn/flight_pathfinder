#pragma once

#include "graph.h"
#include <map>
#include <stack>

/**
 * @brief Main DFS function; performs a depth-first traversal on the graph
 * and outputs something at every vertex visited
 *
 * @param g Graph for DFS to be performed on
 */
void DFS(Graph &);

/**
 * @brief Helper function for main DFS function
 *
 * @param g Graph for DFS to be performed on
 * @param v Vertex to be explored
 */
void DFS(Graph &, Vertex, std::map<Vertex, bool> &);

/**
 * @brief Helper function for printing details about an airport
 *
 * @param v Airport whose details are to be printed
 */
void printDetails(Vertex &);
