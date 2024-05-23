// ID: 326662574
// MAIL: noamlevin11@gmail.com

#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace ariel {

        class Graph {

        // Private fields
        vector<vector<int>> graph; // The adjacency matrix
        size_t vertex_num; // Number of vertecis in the graph
        size_t edge_num; // Number of edges in the graph
        int if_directed; // 1 - if directed, 0 - if not

        public:
                void loadGraph(vector<vector<int>> graph, int directed); // Loading the graph to our object
                string printGraph(); // Returns a string representing the adjacency matrix (Change from exe1)

                vector<vector<int>> getGraph(); // Returns the adjacency matrix
                size_t getVertexNum(); // Returns the number of vertecis in the graph
                size_t getEdgeNum(); // Returns the number of edges in the graph
                int getIfDirected(); // Returns if the graph is directed or not 



                // Mathematical operators
                friend Graph& operator+(Graph& g1, Graph& g2); // Returns a graph that represents the addition between g1 and g2
                friend Graph& operator+(Graph& g1); // Unary plus (does nothing)
                friend Graph& operator-(Graph& g1, Graph& g2); // Returns a graph that represents the substraction between g1 and g2
                friend Graph& operator-(Graph& g1); // Unary minus
                friend void operator+=(Graph& g1, Graph& g2); // Adds the values in g2 to g1
                friend void operator-=(Graph& g1, Graph& g2); // Substract the values of g2 from g1

                // Comperation operators
                friend bool operator==(Graph& g1, Graph& g2); // Return true if g1 equals to g2 or, g1 !> g2 and g1 !< g2
                friend bool operator!=(Graph& g1, Graph& g2); // Returns the opposite from the == function
                friend bool operator>=(Graph& g1, Graph& g2); // Returns true if g1 == g2 or g1 > g2
                friend bool operator>(Graph& g1, Graph& g2); // Returns true if g1 contains g2, or g1 has more edges, or (if edge num is equal) g1 has more vertices
                friend bool operator<=(Graph& g1, Graph& g2); // Returns true if g1 == g2 or g1 < g2
                friend bool operator<(Graph& g1, Graph& g2); // Returns true if g2 contains g1, or g2 has more edges, or (if edge num is equal) g2 has more vertices

                // Other operators
                friend void operator++(Graph& g1); // Adds 1 to every cell that is not in the primery diagonal (++x)
                friend void operator++(Graph& g1, int n); // Adds 1 to every cell that is not in the primery diagonal (x++)
                friend void operator--(Graph& g1); // Substract 1 from every cell that is not in the primery diagonal (--x)
                friend void operator--(Graph& g1, int n); // Substract 1 from every cell that is not in the primery diagonal (x--)
                friend Graph& operator*(Graph& g1, Graph& g2); // Returns a graph that represents the multiplication between g1 and g2
                friend void operator*=(Graph& g1, int num); // Multiply every cell by num
                friend void operator/=(Graph& g1, int num); // Divide every cell by num
                friend ostream& operator<<(ostream& os, Graph& g1); // Prints g1 with cout << g1
        };
}