#include "csvreader.h"
#include "dfs.h"
#include "landmark.h"
using std::cin;
using std::stringstream;

int main()
{
    Graph g = Graph(true, true);
    //reads data from CSV files, properly puts them into graph
    airportsReader(g);
    routesReader(g);
    DFS(g); //performs Depth-First Search on graph

    Vertex a1, a2, a3;
    while (true)
    {
        //input for Dijkstra's Algorithm and Landmark Path Algorithm
        string s1, s2, s3;
        cout << endl
             << "----INPUTS----" << endl
             << "Please enter OpenFlights ID of source airport for Dijkstra's algorithm and Landmark Path algorithm: ";
        cin >> s1;
        cout << "Please enter OpenFlights ID of destination airport for Dijkstra's algorithm and Landmark Path algorithm (DO NOT REPEAT YOUR INPUTS): ";
        cin >> s2;
        cout << "Please enter OpenFlights ID of midpoint airport for Landmark Path algorithm (DO NOT REPEAT YOUR INPUTS): ";
        cin >> s3;
        if (s1 != s2 && s1 != s3 && s2 != s3) //make sure none of the input IDs are repeated
        {
            int found = 0;
            for (Vertex &v : g.getVertices())
            {

                stringstream ss(v);
                string token;
                vector<string> Vect; //1. Airport ID, 2. Name, 3. City, 4. Country, 5. IATA code,
                                     //6. ICAO code, 7. Latitude, 8. Longitude, 9. Altitude, 10. Timezone,
                                     //11. DST, 12. tz Timezone, 13. Type, 14. Source
                while (ss.good())
                {
                    getline(ss, token, ',');
                    Vect.push_back(token);
                }
                if (found == 3) //if all airports have been found in database,
                {
                    break;
                }
                if (Vect[0] == s1) //find source airport
                {
                    a1 = v;
                    ++found;
                }
                if (Vect[0] == s2) //find destination airport
                {
                    a2 = v;
                    ++found;
                }
                if (Vect[0] == s3) //find midpoint airport
                {
                    a3 = v;
                    ++found;
                }
            }
            if (found == 3) //in case of invalid inputs
            {
                break;
            }
        }
        cout << endl
             << "AT LEAST 1 OF THE INPUTS WERE INVALID. PLEASE TRY AGAIN." << endl;
    }

    //prints results of Dijkstra's Algorithm
    cout << endl
         << "----RESULTS OF ALGORITHMS----" << endl
         << "Dijkstra's Algorithm: ";
    vector<Vertex> h = DijkstraV(g, a1, a2);
    for (Vertex &u : h)
    {
        vector<string> printV;
        stringstream x1(u);
        string t;
        while (x1.good())
        {
            getline(x1, t, ',');
            printV.push_back(t);
        }
        cout << printV[1] << " --> ";
    }
    cout << "nullptr" << endl
         << "Landmark Path Algorithm: ";

    //prints results of Landmark Path Algorithm
    vector<Vertex> y = LandmarkV(g, a1, a3, a2);
    for (Vertex &u : y)
    {
        vector<string> printV;
        stringstream x2(u);
        string t;
        while (x2.good())
        {
            getline(x2, t, ',');
            printV.push_back(t);
        }
        cout << printV[1] << " --> ";
    }
    cout << "nullptr" << endl;
    return 0;
}
