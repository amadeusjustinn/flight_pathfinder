#include "landmark.h"

Graph Landmark(Graph &g, Vertex &a, Vertex &b, Vertex &c)
{
    //perform Dijkstra's algorithm between a and b and between b and c
    Graph graphAB = Dijkstra(g, a, b), graphBC = Dijkstra(g, b, c), ret = Graph(true, true);
    for (Vertex &v : graphAB.getVertices())
    {
        //insert all vertices in AB graph to return graph
        ret.insertVertex(v);
    }
    for (Edge &e : graphAB.getEdges())
    {
        //insert all edges and their weights in AB graph to return graph
        ret.insertEdge(e.source, e.dest);
        ret.setEdgeWeight(e.source, e.dest, e.getWeight());
    }
    for (Vertex &v : graphBC.getVertices())
    {
        //insert all vertices in BC graph to return graph that are not already present in return graph
        if (!ret.vertexExists(v))
        {
            ret.insertVertex(v);
        }
    }
    for (Edge &e : graphBC.getEdges())
    {
        //insert all edges and their weights in BC graph to return graph that are not already present in return graph
        if (!ret.edgeExists(e.source, e.dest))
        {
            ret.insertEdge(e.source, e.dest);
            ret.setEdgeWeight(e.source, e.dest, e.getWeight());
        }
    }
    return ret;
}

vector<Vertex> LandmarkV(Graph &g, Vertex &a, Vertex &b, Vertex &c)
{
    //perform Dijkstra's algorithm between a and b and between b and c
    vector<Vertex> graphAB = DijkstraV(g, a, b), graphBC = DijkstraV(g, b, c), path;

    for (auto it = graphAB.begin(); it != graphAB.end(); it++)
    {
        //insert all vertices in AB graph to path vector
        path.push_back(*it);
    }

    for (auto it = graphBC.begin(); it != graphBC.end(); it++)
    {
        //insert all vertices in BC graph to path vector except for B (already present from previous for loop)
        if (it != graphBC.begin())
        {
            path.push_back(*it);
        }
    }
    return path;
}
