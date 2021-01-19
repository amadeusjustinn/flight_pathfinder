#include "dfs.h"

void DFS(Graph &g)
{
    vector<Vertex> vertices = g.getVertices();
    std::map<Vertex, bool> visited; //keep track of vertices that have been visited
    for (Vertex &w : vertices)
    {
        //all vertices have not been visited
        visited[w] = false;
    }
    for (Vertex &i : vertices)
    {
        if (!visited[i])
        {
            //perform DFS on every unvisited vertex
            DFS(g, i, visited);
        }
    }
}

void DFS(Graph &g, Vertex v, std::map<Vertex, bool> &visited)
{
    std::stack<string> St; //initialise stack for DFS
    St.push(v);            //push current source node
    while (!St.empty())
    {
        //pop vertex from stack so it is ready to be printed
        v = St.top();
        St.pop();
        if (!visited[v]) //in case stack contains multiple copies of a vertex
        {
            printDetails(v);
            visited[v] = true;
        }
        // Get all adjacent vertices of the popped vertex.
        // If an adjacent vertex has not been visited,
        // then push it to the stack.
        for (Vertex &adj : g.getAdjacent(v))
        {
            if (!visited[adj])
            {
                St.push(adj);
            }
        }
    }
}

void printDetails(Vertex &v)
{
    std::stringstream ss(v);
    string token;
    vector<string> Vect; /* 1. Airport ID, 2. Name, 3. City, 4. Country, 5. IATA code,
                            6. ICAO code, 7. Latitude, 8. Longitude, 9. Altitude, 10. Timezone,
                            11. DST, 12. tz Timezone, 13. Type, 14. Source */
    while (ss.good())
    {
        getline(ss, token, ',');
        Vect.push_back(token);
    }
    if (Vect.size() > 7)
    {
        //print ID, name, city, country and coordinates of airport
        cout << Vect[0] << ": " << Vect[1] << " is in " << Vect[2] << ", " << Vect[3]
             << ". Its coordinates are " << Vect[6] << ", " << Vect[7] << "." << endl;
    }
}
