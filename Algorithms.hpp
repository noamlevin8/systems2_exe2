// ID: 326662574
// MAIL: noamlevin11@gmail.com

#pragma once

#include "Graph.hpp"
#include <unordered_map>
#include <queue>
#include <limits>
#include <algorithm>

using namespace ariel;
using namespace std;// Returns the shortest path from "start" to "end"

namespace Algorithms {
        string isConnected(Graph g); // Checks if a graph is strongly connected
        string shortestPath(Graph g, size_t start, size_t end); 
        string isContainsCycle(Graph g); // Checks if there is a cycle in the graph and if there is, it returns it 
        string isBipartite(Graph g); // Checks if the graph is bipartite and if so, returns the partition
        string negativeCycle(Graph g); // Checks if there is a negative cycle in the graph and if so, it returns it

        // Helping functions
        void dfs(Graph g, size_t v, vector<bool>& visited); // For the "isConnected" function
        int DFSVisit(Graph g, size_t u, vector<string> color, vector<int>& parent); //For the "isContainsCycle" function
        string bellmanFord(Graph g, size_t V, size_t src); // For the "negativeCycle" function
}