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
                friend Graph& operator+(Graph& g1, Graph& g2);
                friend void operator+(Graph& g1);
                friend Graph& operator-(Graph& g1, Graph& g2);
                friend void operator-(Graph& g1);
                friend void operator+=(Graph& g1, Graph& g2);
                friend void operator-=(Graph& g1, Graph& g2);

                // Comperation operators
                friend bool operator==(Graph& g1, Graph& g2);
                friend bool operator!=(Graph& g1, Graph& g2);
                friend bool operator>=(Graph& g1, Graph& g2);
                friend bool operator>(Graph& g1, Graph& g2);
                friend bool operator<=(Graph& g1, Graph& g2);
                friend bool operator<(Graph& g1, Graph& g2);

                // Other operators
                friend void operator++(Graph& g1);
                friend void operator++(Graph& g1, int n);
                friend void operator--(Graph& g1);
                friend void operator--(Graph& g1, int n);
                friend void operator*(Graph& g1, int num);
                friend Graph& operator*(Graph& g1, Graph& g2);
                friend ostream& operator<<(ostream& os, Graph& g1);
        };
}