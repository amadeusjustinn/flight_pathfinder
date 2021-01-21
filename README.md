# flight_pathfinder

A project that uses airport and route data compiled by [OpenFlights](https://openflights.org/data.html) and runs Dijkstra's algorithm and the Landmark Path algorithm using airports selected by the user.

## Usage and Build Documentation
This program traverses through the initialised graph, finds the shortest path between 2 vertices through Dijkstra's Algorithm, then the shortest path between 2 vertices through another vertex using Landmark Path.

To compile the code, run `make` in the terminal. After that, execute it by running `./main` in the terminal. With this, it would essentially run all of the algorithms. As `src/main.cpp` is executed, it would first traverse through the airports' data and print its information through DFS. This would print their information in DFS order. After this, the system would ask for 3 Airports IDs. For testing purposes, the IDs that we used were 1, 2 and 3. After entering the IDs, the code would run both Dijkstra's and Landmark Path algorithm through the graph.
