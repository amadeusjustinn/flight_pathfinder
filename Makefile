EXENAME = main
OBJS = main.o coorddist.o csvreader.o dfs.o dijkstra.o graph.o landmark.o random.o

CL = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

all : $(EXENAME)

.PHONY: all

$(EXENAME) : $(OBJS)
	$(CL) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : src/main.cpp src/coorddist.h src/csvreader.h src/dfs.h src/dijkstra.h src/edge.h src/graph.h src/landmark.h src/random.h
		$(CL) $(CXXFLAGS) src/main.cpp
coorddist.o : src/coorddist.cpp src/coorddist.h
		$(CL) $(CXXFLAGS) src/coorddist.cpp
csvreader.o : src/csvreader.cpp src/csvreader.h src/coorddist.h src/graph.h src/edge.h src/random.h
		$(CL) $(CXXFLAGS) src/csvreader.cpp
dfs.o : src/dfs.cpp src/dfs.h src/graph.h src/edge.h src/random.h
		$(CL) $(CXXFLAGS) src/dfs.cpp
dijkstra.o : src/dijkstra.cpp src/dijkstra.h src/graph.h src/edge.h src/random.h
		$(CL) $(CXXFLAGS) src/dijkstra.cpp
graph.o : src/graph.cpp src/graph.h src/edge.h src/random.h
		$(CL) $(CXXFLAGS) src/graph.cpp
landmark.o : src/landmark.cpp src/landmark.h src/dijkstra.h src/graph.h src/edge.h src/random.h
		$(CL) $(CXXFLAGS) src/landmark.cpp
random.o : src/random.cpp src/random.h
		$(CL) $(CXXFLAGS) src/random.cpp

clean :
	-rm -f *.o $(EXENAME)
