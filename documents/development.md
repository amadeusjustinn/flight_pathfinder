# Development

## Week 1
We downloaded the relevant data sets from OpenFlights, turned them into CSV files for accessing data. We also added a guide for the columns for each data set. From here we started to think about how to start doing this project. We decided that the best way would be to think and research the algorithms and write some pseudocode first. After doing so, we tried to create structs and attempted at doing the traversals portion of our project.

## Week 2
We downloaded some of the previous code from previous MPs. We also researched the details of the landmark path algorithm. Some of the object class files for the airport, airline, route, country and plane classes are written, though it has not been checked whether it is correct. We are trying to implement the traversal for this graph. The shortest path algorithm by using Djikstra's algorithm is also trying to be developed. The DFS traversal source code is almost complete; it is still missing around 10% of the final project.

## Week 3
We have written the DFS code but we still have no checked whether it worked or not. We believe that it should work but there should still be some testing. We are currently trying to do Dijkstra's algorithm and we found that we needed to use an operator overload to compare the weights. If this is solved, we believe that the rest of the algorithm should work smoothly. We have also started to think about what to do for the last part. For the last part, we think that to draw it unto the map, we can scale the coordinates with a corresponding world map image and then mark the vertices on the map. When this is done, connected paths can be made by connecting coordinates using slopes.

## Week 3 (continued)
We have essentially written all of the algorithms that we needed. Now, we are trying to create the executable and the make file for the program that we have written. We are also trying to write test cases for our program. However, we are struggling in both of these areas. We are unsure of whether the executable we create will work properly. In addition to this, we have started making our presentation. We also removed unnecessary datasets ( those of airlines, countries, planes) and their respective object CPP and header files; we realised only the datasets of airports and routes are needed for this project. As of right now, we are planning to record the presentation through Zoom, but we are unsure of whether it would work.

## Final Works
We have essentially finished up everything. In this case, we have completed compiling and making the makefile, as well as running the program. We first found some problems when trying to run the program but after thorough testing and debugging, we were able to make it work. We essentially started by debugging it one by one using manual test cases in the main file. In the end, we completed the presentation as well.