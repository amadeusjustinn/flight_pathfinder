#pragma once

#include "coorddist.h"
#include "graph.h"

/**
 * @brief Reads airports.csv and inserts Airport objects using CSV data as vertices into graph
 *
 * @param g Graph to be inserted Airport objects into
 */
void airportsReader(Graph &);

/**
 * @brief Reads routes.csv and inserts "routes" (edges)
 * by connecting Airport objects using CSV data as vertices into graph
 *
 * @param g Graph to be inserted edges into
 */
void routesReader(Graph &);
