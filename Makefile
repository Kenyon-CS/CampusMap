# Makefile for map_demo

CXX = g++
CXXFLAGS = -Wall -std=c++11

# Target to compile and link the program
map_demo: map_demo.o
	$(CXX) $(CXXFLAGS) -o map_demo map_demo.o

# Compile the object file for map_demo.cpp
map_demo.o: map_demo.cpp
	$(CXX) $(CXXFLAGS) -c map_demo.cpp

# Clean up the compiled files
clean:
	rm -f *.o map_demo
