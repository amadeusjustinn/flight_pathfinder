EXENAME = main
OBJS = main.o coorddist.o csvreader.o dfs.o dijkstra.o graph.o landmark.o random.o

CL = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

# Custom Clang version enforcement logic:
ccred=$(shell echo -e "\033[0;31m")
ccyellow=$(shell echo -e "\033[0;33m")
ccend=$(shell echo -e "\033[0m")

IS_EWS=$(shell hostname | grep "ews.illinois.edu")
IS_CORRECT_CLANG=$(shell clang -v 2>&1 | grep "version 6")
ifneq ($(strip $(IS_EWS)),)
ifeq ($(strip $(IS_CORRECT_CLANG)),)
CLANG_VERSION_MSG = $(error $(ccred) On EWS, please run 'module load llvm/6.0.1' first when running CS225 assignments. $(ccend))
endif
else
ifneq ($(strip $(SKIP_EWS_CHECK)),True)
CLANG_VERSION_MSG = $(warning $(ccyellow) Looks like you are not on EWS. Be sure to test on EWS before the deadline. $(ccend))
endif
endif

.PHONY: all output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME) : output_msg $(OBJS)
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

#test : output_msg tests.o dfs.o landmark.o
#		$(CL) tests.o dfs.o landmark.o $(LDFLAGS) -o test
#tests.o: tests/tests.cpp tests/catch.hpp dfs.h landmark.h
#		$(CL) $(CXXFLAGS) tests/tests.cpp
clean :
	-rm -f *.o $(EXENAME)
