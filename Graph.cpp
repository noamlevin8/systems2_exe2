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
string Graph::printGraph() {

    size_t i, j, V = vertex_num;
    string result = "";

    for (i = 0; i < V; ++i) 
    { 
        result += "[";

        for(j = 0; j < V; j++)
        {
            result += to_string(graph[i][j]);
            
            if(j < V-1)
                result += ", ";
        }
        if(i < V-1)
            result += "]\n";
    }

    return result + "]";    
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


// Mathematical operators

//
Graph& ariel::operator+(Graph& g1, Graph& g2)
{
    size_t V1 = g1.vertex_num;
    size_t V2 = g2.vertex_num;

    if(V1 != V2)
        throw invalid_argument("Invalid graphs: The graphs are not from the same size.");

    if(g1.if_directed != g2.if_directed)
        throw invalid_argument("Invalid graphs: The graphs are not both directed/undirected.");  

    vector<vector<int>> new_graph(V1, vector<int>(V1, 0));

    size_t i, j;

    for(i = 0; i < V1; i++)
    {
        for(j = 0; j < V1; j++)
        {
            new_graph[i][j] = g1.graph[i][j] + g2.graph[i][j];
        }
    }

    static Graph g3;
    g3.loadGraph(new_graph, g1.if_directed);

    return g3;
}

//
void ariel::operator+(Graph& g1)
{
    return;
}

//
Graph& ariel::operator-(Graph& g1, Graph& g2)
{
    size_t V1 = g1.vertex_num;
    size_t V2 = g2.vertex_num;

    if(V1 != V2)
        throw invalid_argument("Invalid graphs: The graphs are not from the same size.");
    
    if(g1.if_directed != g2.if_directed)
        throw invalid_argument("Invalid graphs: The graphs are not both directed/undirected.");  

    vector<vector<int>> new_graph(V1, vector<int>(V1, 0));

    size_t i, j;

    for(i = 0; i < V1; i++)
    {
        for(j = 0; j < V1; j++)
        {
            new_graph[i][j] = g1.graph[i][j] - g2.graph[i][j];
        }
    }

    static Graph g3;
    g3.loadGraph(new_graph, g1.if_directed);

    return g3;
}

//
void ariel::operator-(Graph& g1)
{
    size_t i, j, V = g1.vertex_num;

    for(i = 0; i < V; i++)
    {
        for(j = 0; j < V; j++)
        {
            g1.graph[i][j] *= -1;
        }
    }
}

//
void ariel::operator+=(Graph& g1, Graph& g2)
{
    size_t V1 = g1.vertex_num;
    size_t V2 = g2.vertex_num;

    if(V1 != V2)
        throw invalid_argument("Invalid graphs: The graphs are not from the same size.");

    if(g1.if_directed != g2.if_directed)
        throw invalid_argument("Invalid graphs: The graphs are not both directed/undirected.");  

    size_t i, j;

    for(i = 0; i < V1; i++)
    {
        for(j = 0; j < V1; j++)
        {
            g1.graph[i][j] += g2.graph[i][j];
        }
    }
}

//
void ariel::operator-=(Graph& g1, Graph& g2)
{
    size_t V1 = g1.vertex_num;
    size_t V2 = g2.vertex_num;

    if(V1 != V2)
        throw invalid_argument("Invalid graphs: The graphs are not from the same size.");

    if(g1.if_directed != g2.if_directed)
        throw invalid_argument("Invalid graphs: The graphs are not both directed/undirected.");  

    size_t i, j;

    for(i = 0; i < V1; i++)
    {
        for(j = 0; j < V1; j++)
        {
            g1.graph[i][j] -= g2.graph[i][j];
        }
    }
}


// Comperation operators

//
bool ariel::operator==(Graph& g1, Graph& g2)
{
    size_t V1 = g1.vertex_num;
    size_t V2 = g2.vertex_num;

    if(g1.if_directed != g2.if_directed)
        throw invalid_argument("Invalid graphs: The graphs are not both directed/undirected.");  

    size_t i, j;

    if(V1 == V2)
    {
        bool flag = true;

        for(i = 0; i < V1; i++)
        {
            for(j = 0; j < V1; j++)
            {
                if(g1.graph[i][j] != g2.graph[i][j])
                {
                    flag = false;
                    break;
                }
            }

            if(!flag)
                break;
        }

        if(flag)
            return true;
    }

    if(!(g1 > g2) && !(g2 > g1))
        return true;

    return false;
}

//
bool ariel::operator!=(Graph& g1, Graph& g2)
{
    if(g1 == g2)
        return false;

    return true;
}

//
bool ariel::operator>=(Graph& g1, Graph& g2)
{
    if(g1 == g2 || g1 > g2)
        return true;
    
    return false;
}

//
bool ariel::operator>(Graph& g1, Graph& g2)
{
    size_t V1 = g1.vertex_num;
    size_t V2 = g2.vertex_num;
    size_t i, j;
    size_t count_i = 0, count_j = 0;

    if(V1 != V2)
    {
        for(i = 0; i < V1; i++)
        {
            if(i + V2 > V1)
                break;

            for(j = 0; j < V1; j++)
            {
                if(j + V2 > V1)
                    break;

                if(g2.graph[count_i][count_j] == g1.graph[i][j])
                {
                    if(count_i == V2 && count_j == V2)
                        return true;
                    
                    count_i++;
                    count_j++;
                }

                else
                {
                    count_i = 0;
                    count_j = 0;
                }
            }
        }
    }

    if(g1.edge_num > g2.edge_num)
        return true;

    if(g1.edge_num < g2.edge_num)
        return false;

    if(g1.vertex_num > g2.vertex_num)
        return true;

    return false;
}

//
bool ariel::operator<=(Graph& g1, Graph& g2)
{
    if(g1 == g2 || g1 < g2)
        return true;

    return false;
}

//
bool ariel::operator<(Graph& g1, Graph& g2)
{
    size_t V1 = g1.vertex_num;
    size_t V2 = g2.vertex_num;
    size_t i, j;
    size_t count_i = 0, count_j = 0;

    if(V1 != V2)
    {
        for(i = 0; i < V2; i++)
        {
            if(i + V1 > V2)
                break;

            for(j = 0; j < V2; j++)
            {
                if(j + V1 > V2)
                    break;

                if(g1.graph[count_i][count_j] == g2.graph[i][j])
                {
                    if(count_i == V1 && count_j == V1)
                        return true;
                    
                    count_i++;
                    count_j++;
                }

                else
                {
                    count_i = 0;
                    count_j = 0;
                }
            }
        }
    }

    if(g1.edge_num < g2.edge_num)
        return true;

    if(g1.edge_num > g2.edge_num)
        return false;

    if(g1.vertex_num < g2.vertex_num)
        return true;

    return false;
}


// Other operators

//
void ariel::operator++(Graph& g1)
{
    size_t i, j, V = g1.vertex_num;

    for(i = 0; i < V; i++)
    {
        for(j = 0; j < V; j++)
        {
            g1.graph[i][j]++;
        }
    }
}

//
void ariel::operator--(Graph& g1)
{
    size_t i, j, V = g1.vertex_num;

    for(i = 0; i < V; i++)
    {
        for(j = 0; j < V; j++)
        {
            g1.graph[i][j]--;
        }
    }
}

//
void ariel::operator*(Graph& g1, int num)
{
    size_t i, j, V = g1.vertex_num;

    for(i = 0; i < V; i++)
    {
        for(j = 0; j < V; j++)
        {
            g1.graph[i][j] *= num;
        }
    }
}

//
Graph& ariel::operator*(Graph& g1, Graph& g2)
{
    size_t V1 = g1.vertex_num;
    size_t V2 = g2.vertex_num;

    if(V1 != V2)
        throw invalid_argument("Invalid graphs: The graphs are not from the same size.");

    if(g1.if_directed != g2.if_directed)
        throw invalid_argument("Invalid graphs: The graphs are not both directed/undirected.");  

    vector<vector<int>> new_graph(V1, vector<int>(V1, 0));

    size_t i, j, k;

    for (i = 0; i < V1; i++) 
    {
        for (j = 0; j < V1; j++) 
        {
            if(i == j)
                continue;

            for (k = 0; k < V1; k++) 
            {
                new_graph[i][j] += g1.graph[i][k] * g2.graph[k][j];
            }
         }
    }

    static Graph g3;
    g3.loadGraph(new_graph, 1); // Directed because multiplication doesn't necessarily maintain the symmetricity

    return g3;
}

//
ostream& ariel::operator<<(ostream& os, Graph& g1)
{
    size_t i, j, V = g1.vertex_num;

    for (i = 0; i < V; ++i) 
    { 
        os << "[";

        for(j = 0; j < V; j++)
        {
            os << g1.graph[i][j];
            
            if(j < V-1)
                os << ", ";
        }
        os << "]\n";
    }

    return os; 
}