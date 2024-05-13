# ID: 326662574
# MAIL: noamlevin11@gmail.com

#!make -f

CXX=clang++
CXXFLAGS=-std=c++11 -Werror -Wsign-conversion

SOURCES=Graph.cpp Algorithms.cpp TestCounter.cpp Test.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

run: test
	./$^

demo: Demo.o $(filter-out TestCounter.o Test.o, $(OBJECTS))
	$(CXX) $(CXXFLAGS) $^ -o demo

test: TestCounter.o Test.o $(filter-out Demo.o, $(OBJECTS))
	$(CXX) $(CXXFLAGS) $^ -o test

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o demo test