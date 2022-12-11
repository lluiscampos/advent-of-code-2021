
CXXFLAGS := -Wall --std=c++11

advent: main.cpp day1.o day2.o
	g++ $(CXXFLAGS) -o $@ $^ && ./advent

day%.o: day%.cpp
	g++ $(CXXFLAGS) -c -o $@ $^
