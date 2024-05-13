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
                void printGraph(); // Prints the number of vertices and the number of edges

                vector<vector<int>> getGraph(); // Returns the adjacency matrix
                size_t getVertexNum(); // Returns the number of vertecis in the graph
                size_t getEdgeNum(); // Returns the number of edges in the graph
                int getIfDirected(); // Returns if the graph is directed or not               
        };
}