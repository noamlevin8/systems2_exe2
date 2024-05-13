// ID: 326662574
// MAIL: noamlevin11@gmail.com

#include "Graph.hpp"

using namespace std;
using namespace ariel;

// Loading the graph to our object
void Graph::loadGraph(vector<vector<int>> new_graph, int directed = 0) { // If we don't get the directed value we consider the graph undirected

    // Checking that the matrix is square
    if(new_graph.size() != new_graph[0].size())
        throw invalid_argument("Invalid graph: The graph is not a square matrix.");
    
    // Checking the value of directed
    if(directed != 1 && directed != 0)
        throw invalid_argument("Invalid graph: Directed value is not 0 or 1.");

    graph = new_graph;
    vertex_num = new_graph.size();
    if_directed = directed;

    size_t i, j;
    size_t count = 0;

    for(i = 0; i < new_graph.size(); i++)
    {
        for(j = 0; j < new_graph[0].size(); j++)
        {
            // Checking for self edges
            if(i == j && new_graph[i][j] != 0)
                throw invalid_argument("Invalid graph: The graph has a self edge.");

            // Checking if the graph is really undirected
            if(!directed && i != j && new_graph[i][j] != new_graph[j][i])
                throw invalid_argument("Invalid graph: The graph is not undirected.");

            // Counting the edges
            if(new_graph[i][j] != 0)
                count++;
        }
    }

    if(!directed) // Not counting an edge twice if the graph is undirected
        edge_num = count/2;
    else
        edge_num = count;
}

// Prints the number of vertices and the number of edges
void Graph::printGraph() {
        cout << "Graph with " << vertex_num << " vertices and " << edge_num << " edges." << endl;
}

// Returns the adjacency matrix
vector<vector<int>> Graph::getGraph()
{
    return graph;
}

// Returns number of vertecis in the graph
size_t Graph::getVertexNum()
{
    return vertex_num;
}

// Returns the number of edges in the graph
size_t Graph::getEdgeNum()
{
    return edge_num;
}

// Returns if the graph is directed or not
int Graph::getIfDirected()
{
    return if_directed;
}