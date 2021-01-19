#include "dijkstra.h"
#include <queue>

Graph Dijkstra(Graph &g, Vertex &start, Vertex &end)
{
    std::map<Vertex, long double> dist; //map for keeping track of current distance
    std::map<Vertex, Vertex> prev;      //map for keeping track of vertex "before" every vertex
    Graph t = Graph(true, true);
    std::priority_queue<pair<Vertex, long double>, vector<pair<Vertex, long double>>, compareVertexWeight> pq;
    for (Vertex &v : g.getVertices())
    {
        dist[v] = (v != start) ? INT_MAX : 0; //set all distances from start to infinity (except start itself, which is set to 0)
        prev[v] = "";
    }
    pq.push(make_pair(start, 0)); //put dist[start] = 0 into priority queue
    while (!pq.empty())
    {
        Vertex current = pq.top().first;
        pq.pop();
        t.insertVertex(current); //insert current vertex to return graph
        vector<Vertex> adjacent = g.getAdjacent(current);
        for (Vertex &u : adjacent) //each airport adjacent to current airport is analysed
        {
            //if shorter path is found and neighbour is not already in graph,
            if (dist[current] + g.getEdgeWeight(current, u) < dist[u] && !t.vertexExists(u))
            {
                //update relevant information with shorter path
                dist[u] = dist[current] + g.getEdgeWeight(current, u);
                prev[u] = current;
                pq.push(make_pair(u, dist[u]));
            }
        }
    }
    //FOR GRAPH-RETURNING VERSION OF ALGORITHM
    Vertex a = end;
    while (prev[a] != "") //traverse through path, stop when start is reached (start already in return graph)
    {
        //add all edges and their weights (distances between airports) of processed graph into return graph
        t.insertEdge(prev[a], a);
        t.setEdgeWeight(prev[a], a, g.getEdgeWeight(prev[a], a));
        a = prev[a];
    }
    return t;
}

vector<Vertex> DijkstraV(Graph &g, Vertex &start, Vertex &end)
{
    //SAME ALGORITHM AS GRAPH-RETURNING VERSION UP TO LINE 74
    std::map<Vertex, long double> dist;
    Graph t = Graph(true, true);
    std::map<Vertex, Vertex> prev;
    std::priority_queue<pair<Vertex, long double>, vector<pair<Vertex, long double>>, compareVertexWeight> pq;
    for (Vertex &v : g.getVertices())
    {
        dist[v] = (v != start) ? INT_MAX : 0;
        prev[v] = "";
    }
    pq.push(make_pair(start, 0));
    while (!pq.empty())
    {
        Vertex current = pq.top().first;
        pq.pop();
        t.insertVertex(current);
        vector<Vertex> adjacent = g.getAdjacent(current);
        for (Vertex &u : adjacent)
        {
            if (dist[current] + g.getEdgeWeight(current, u) < dist[u] && !t.vertexExists(u))
            {
                dist[u] = dist[current] + g.getEdgeWeight(current, u);
                prev[u] = current;
                pq.push(make_pair(u, dist[u]));
            }
        }
    }
    //FOR PATH VECTOR-RETURNING VERSION OF ALGORITHM
    vector<Vertex> path;
    Vertex a = end;
    while (a != "") //traverse through path up to and including start is reached
    {
        //put all vertices in prev into path in reverse order, traverse
        path.push_back(a);
        a = prev[a];
    }
    //correct order before returning
    std::reverse(path.begin(), path.end());
    return path;
}
