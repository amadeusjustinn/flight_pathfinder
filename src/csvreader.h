#pragma once

#include "coorddist.h"
#include "graph.h"

/**
 * @brief Reads ./datasets/airports.csv and inserts airports using CSV data as vertices into graph
 *
 * @param g Graph to be inserted vertices (airports) into
 */
void airportsReader(Graph &);

/**
 * @brief Reads ./datasets/routes.csv and inserts routes as edges into graph,
 * connecting vertices (airports) using CSV data
 *
 * @param g Graph to be inserted edges (routes) into
 */
void routesReader(Graph &);
