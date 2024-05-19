# Systems Programming 2 – Assignment 2

## Assignment Description
This assignment includes all the files from the previous assignment with changes made in the `Graph` class within the `ariel` namespace.

## Files
### Graph.hpp
This file includes declarations for all the operators that have been implemented:
1. **Mathematical Operators**:
    - `Operator+(Graph& g1, Graph& g2)`: Returns a new Graph from the addition of g1 and g2 values.
    - `Operator+(Graph& g1)`: Unary plus operator.
    - `Operator-(Graph& g1, Graph& g2)`: Returns a new Graph from the subtraction of g2 values from g1.
    - `Operator-(Graph& g1)`: Unary minus operator.
    - `Operator+=(Graph& g1, Graph& g2)`: Updates the matrix values of g1 to the sum of g1 and g2 values.
    - `Operator-=(Graph& g1, Graph& g2)`: Updates the matrix values of g1 to the difference of g1 and g2 values.

2. **Comparison Operators**:
    - `Operator==(Graph& g1, Graph& g2)`: Returns true if the graphs are equal and false otherwise.
    - `Operator!=(Graph& g1, Graph& g2)`: Returns false if the graphs are equal and true otherwise.
    - `Operator>=(Graph& g1, Graph& g2)`: Returns true if the graphs are equal or g1 > g2 and false otherwise.
    - `Operator>(Graph& g1, Graph& g2)`: Returns true if g1 > g2 and false otherwise.
    - `Operator<=(Graph& g1, Graph& g2)`: Returns true if the graphs are equal or g1 < g2 and false otherwise.
    - `Operator<(Graph& g1, Graph& g2)`: Returns true if g1 < g2 and false otherwise.

3. **Additional Operators**:
    - `Operator++(Graph& g1)`: Increments each cell in the matrix of g1 by 1 using prefix notation (++X).
    - `Operator++(Graph& g1, int n)`: Increments each cell in the matrix of g1 by 1 using postfix notation (X++).
    - `Operator--(Graph& g1)`: Decrements each cell in the matrix of g1 by 1 using prefix notation (--X).
    - `Operator--(Graph& g1, int n)`: Decrements each cell in the matrix of g1 by 1 using postfix notation (X--).
    - `Operator*(Graph& g1, Graph& g2)`: Returns a graph that is the result of g1 * g2.
    - `Operator*=(Graph& g1, int num)`: Updates the matrix values of g1 to their value multiplied by num.
    - `Operator/=(Graph& g1, int num)`: Updates the matrix values of g1 to their value divided by num.
    - `Operator<<(ostream& os, Graph& g1)`: Prints the graph.

### Graph.cpp
This file contains the implementation of the new operators defined in Graph.hpp.

### Additional Files
- **Demo.cpp**: Contains examples of how to use the new operators in Graph.
- **Test.cpp**: Contains new tests for our code.
