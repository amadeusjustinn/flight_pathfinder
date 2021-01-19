#pragma once

#include "dijkstra.h"

/**
 * @brief Performs Landmark Path algorithm on graph given 3 vertices
 *
 * @param g Graph for algorithm to be performed on
 * @param a Starting (or source) vertex
 * @param b Midway vertex
 * @param c End (or destination) vertex
 *
 * @return Graph after algorithm has performed
 */
Graph Landmark(Graph &g, Vertex &a, Vertex &b, Vertex &c);

/**
 * @brief Performs Landmark Path algorithm on graph given 3 vertices
 *
 * @param g Graph for algorithm to be performed on
 * @param a Starting (or source) vertex
 * @param b Midway vertex
 * @param c End (or destination) vertex
 *
 * @return Vector of vertices after algorithm has performed
 */
vector<Vertex> LandmarkV(Graph &g, Vertex &a, Vertex &b, Vertex &c);
