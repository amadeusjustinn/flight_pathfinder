#include "csvreader.h"
using std::getline;
using std::stold;

void airportsReader(Graph &g)
{
    std::ifstream file("./datasets/airports.csv");
    if (file.is_open())
    {
        string line, token;
        while (getline(file, line))
        {
            //removes quotation marks from each line
            line.erase(std::remove(line.begin(), line.end(), '\"'), line.end());
            g.insertVertex(line);
        }
    }
    file.close();
}

void routesReader(Graph &g)
{
    std::ifstream file("./datasets/routes.csv");
    if (file.is_open())
    {
        string line, token1, token2;
        while (getline(file, line))
        {
            std::stringstream ss1(line);
            vector<string> Vect1; /* 1. Airline, 2.Airline ID (see Airlines CSV file), 3. Source airport,
                                     4. Source airport ID, 5. Destination airport, 6. Destination airport ID,
                                     7. Codeshare, 8. Stops, 9. Equipment */
            while (getline(ss1, token1, ','))
            {
                Vect1.push_back(token1);
            }
            Vertex source, dest;
            int found = 0;
            long double slat, slong, dlat, dlong; //source and destination coordinates
            for (Vertex &a : g.getVertices())
            {
                if (found == 2)
                {
                    //if both source and destination airports have been found,
                    break;
                }
                std::stringstream ss2(a);
                vector<string> Vect2; /* 1. Airport ID, 2. Name, 3. City, 4. Country, 5. IATA code,
                                         6. ICAO code, 7. Latitude, 8. Longitude, 9. Altitude, 10. Timezone,
                                         11. DST, 12. tz Timezone, 13. Type, 14. Source */
                while (ss2.good())
                {
                    getline(ss2, token2, ',');
                    Vect2.push_back(token2);
                }
                if (Vect1[3] == Vect2[0]) //searches for Airport with the same ID as source
                {
                    source = a;
                    slat = stold(Vect2[6]);
                    slong = stold(Vect2[7]);
                    ++found;
                }
                if (Vect1[5] == Vect2[0]) //searches for Airport with the same ID as destination
                {
                    dest = a;
                    dlat = stold(Vect2[6]);
                    dlong = stold(Vect2[7]);
                    ++found;
                }
            }
            g.insertEdge(source, dest); //connects source and destination Airports with edge
            //sets weight to distance between Airports (calculated using function from "coorddist.h")
            g.setEdgeWeight(source, dest, std::fabs(distance(slat, slong, dlat, dlong)));
        }
        file.close();
    }
}
