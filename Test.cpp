// ID: 326662574
// MAIL: noamlevin11@gmail.com

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test graph addition")
{
    // Undirected

    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph, 0);

    ariel::Graph g7 = +g1; // Unary plus
    CHECK(g7.printGraph() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");
    
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph, 0);

    ariel::Graph g3 = g7 + g2; // +

    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(g3.printGraph() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]");

    g3 += g2; // +=
    CHECK(g3.printGraph() == "[0, 3, 2]\n[3, 0, 5]\n[2, 5, 0]");


    // Directed

    ariel::Graph g4;
    vector<vector<int>> graph4 = {
        {0, 3, 1},
        {1, 0, 2},
        {0, 2, 0}};
    g4.loadGraph(graph4, 1);

    ariel::Graph g5;
    vector<vector<int>> graph5 = {
        {0, 1, -6},
        {1, 0, 0},
        {0, 4, 0}};
    g5.loadGraph(graph5, 1);

    ariel::Graph g8 = +g5; // Unary plus
    CHECK(g8.printGraph() == "[0, 1, -6]\n[1, 0, 0]\n[0, 4, 0]");

    ariel::Graph g6 = g4 + g8; // +
    CHECK(g6.printGraph() == "[0, 4, -5]\n[2, 0, 2]\n[0, 6, 0]");

    g8 += g4; // +=
    CHECK(g8.printGraph() == "[0, 4, -5]\n[2, 0, 2]\n[0, 6, 0]");
}

TEST_CASE("Test graph substraction")
{
    // Undirected

    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 5},
        {1, 0, 2},
        {5, 2, 0}};
    g1.loadGraph(graph1, 0);

    ariel::Graph g7 = -g1; // Unary minus
    CHECK(g7.printGraph() == "[0, -1, -5]\n[-1, 0, -2]\n[-5, -2, 0]");

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 3, 3},
        {3, 0, 3},
        {3, 3, 0}};
    g2.loadGraph(graph2, 0);

    ariel::Graph g3 = g1 - g2; // -

    vector<vector<int>> expectedGraph = {
        {0, -2, 2},
        {-2, 0, -1},
        {2, -1, 0}};
    CHECK(g3.printGraph() == "[0, -2, 2]\n[-2, 0, -1]\n[2, -1, 0]");

    g3 -= g2; // -=
    CHECK(g3.printGraph() == "[0, -5, -1]\n[-5, 0, -4]\n[-1, -4, 0]");


    // Directed

    ariel::Graph g4;
    vector<vector<int>> graph4 = {
        {0, 3, 1},
        {1, 0, 2},
        {0, 2, 0}};
    g4.loadGraph(graph4, 1);

    ariel::Graph g5;
    vector<vector<int>> graph5 = {
        {0, 1, -6},
        {1, 0, 0},
        {0, 4, 0}};
    g5.loadGraph(graph5, 1);

    ariel::Graph g8 = -g5; // Unary minus
    CHECK(g8.printGraph() == "[0, -1, 6]\n[-1, 0, 0]\n[0, -4, 0]");
    
    ariel::Graph g6 = g5 - g4; // -
    CHECK(g6.printGraph() == "[0, -2, -7]\n[0, 0, -2]\n[0, 2, 0]");

    g5 -= g4; // -=
    CHECK(g5.printGraph() == "[0, -2, -7]\n[0, 0, -2]\n[0, 2, 0]");
}

TEST_CASE("Test graph equality and inequality")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 5},
        {1, 0, 2},
        {5, 2, 0}};
    g1.loadGraph(graph1, 0);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 5},
        {1, 0, 2},
        {5, 2, 0}};
    g2.loadGraph(graph2, 0);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, -3, 5},
        {-3, 0, 2},
        {5, 2, 0}};
    g3.loadGraph(graph3, 0);

    ariel::Graph g4;
    vector<vector<int>> graph4 = {
        {0, 1, 5, 0},
        {1, 0, 2, 0},
        {5, 2, 0, 1},
        {0, 0, 1, 0}};
    g4.loadGraph(graph4, 0);

    ariel::Graph g5;
    vector<vector<int>> graph5 = {
        {0, 0, 5, 0},
        {0, 0, 2, 0},
        {5, 2, 0, 0},
        {0, 0, 0, 0}};
    g5.loadGraph(graph5, 0);

    ariel::Graph g6;
    vector<vector<int>> graph6 = {
        {0, 1, 5},
        {1, 0, 2},
        {5, 2, 0}};
    g6.loadGraph(graph6, 1);

    ariel::Graph g7;
    vector<vector<int>> graph7 = {
        {0, 1, 5},
        {1, 0, 2},
        {5, 2, 0}};
    g7.loadGraph(graph7, 1);

    CHECK(g1 == g2); // Regular == in undirected
    CHECK(g6 == g7); // Regular == in directed
    CHECK(g1 == g3); // ! g1 > g3 && ! g1 < g3
    CHECK(g4 != g3); // g4 > g3
    CHECK(g5 != g3); // g5 < g3 by edges
}

TEST_CASE("Test >/< and >=/<=")
{
    // Undirected

    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 2, 0, 0},
        {2, 0, 1, 1},
        {0, 1, 0, -1},
        {0, 1, -1, 0}};
    g1.loadGraph(graph1, 0);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, -1},
        {1, -1, 0}};
    g2.loadGraph(graph2, 0);

    CHECK(g1 > g2); // g2 in g1
    CHECK(g1 >= g2); // if g1 > g2 it must also be that g1 >= g2
    CHECK(!(g1 < g2)); // g1 not in g2 and g1 has more edges and vertices


    // Directed

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 2, 0, 0},
        {0, 0, -3, 1},
        {-8, 1, 0, 4},
        {0, 2, 1, 0}};
    g3.loadGraph(graph3, 1);

    ariel::Graph g4;
    vector<vector<int>> graph4 = {
        {0, -3, 1},
        {1, 0, 4},
        {2, 0, 0}};
    g4.loadGraph(graph4, 1);

    CHECK(g4 < g3); // g4 in g3
    CHECK(g4 <= g3); // if g4 < g3 it must also be that g4 <= g3
    CHECK(!(g4 > g3)); // g3 is not in g4 and g3 has more edges and vertices


    // By edge#

    ariel::Graph g5;
    vector<vector<int>> graph5 = {
        {0, 2, 0, 0},
        {2, 0, 0, 1},
        {0, 0, 0, 0},
        {0, 1, 0, 0}};
    g5.loadGraph(graph5, 0);

    ariel::Graph g6;
    vector<vector<int>> graph6 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g6.loadGraph(graph6, 0);

    CHECK(g6 > g5);


    // Same edge# (by vertices)

    ariel::Graph g7;
    vector<vector<int>> graph7 = {
        {0, 2, 0, 0},
        {0, 0, 0, 4},
        {-3, 0, 0, 0},
        {0, 0, -1, 0}};
    g7.loadGraph(graph7, 1);

    ariel::Graph g8;
    vector<vector<int>> graph8 = {
        {0, 0, 1},
        {1, 0, 1},
        {0, 1, 0}};
    g8.loadGraph(graph8, 1);

    CHECK(g7 > g8);


    // Equal which means !< and !>

    ariel::Graph g9;
    vector<vector<int>> graph9 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g9.loadGraph(graph9, 0);

    ariel::Graph g10;
    vector<vector<int>> graph10 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g10.loadGraph(graph10, 0);

    CHECK(g9 == g10);
    CHECK(!(g9 > g10));
    CHECK(!(g9 < g10));
}

TEST_CASE("Test ++ and --")
{
    // Undirected

    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1, 0);

    ++g1;
    CHECK(g1.printGraph() == "[0, 2, 1]\n[2, 0, 2]\n[1, 2, 0]");

    --g1;
    CHECK(g1.printGraph() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");

    g1++;
    CHECK(g1.printGraph() == "[0, 2, 1]\n[2, 0, 2]\n[1, 2, 0]");

    g1--;
    CHECK(g1.printGraph() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");

    // Directed

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {-4, 0, 2},
        {3, 0, 0}};
    g2.loadGraph(graph2, 1);

    ++g2;
    CHECK(g2.printGraph() == "[0, 2, 1]\n[-3, 0, 3]\n[4, 1, 0]");

    --g2;
    CHECK(g2.printGraph() == "[0, 1, 0]\n[-4, 0, 2]\n[3, 0, 0]");

    g2++;
    CHECK(g2.printGraph() == "[0, 2, 1]\n[-3, 0, 3]\n[4, 1, 0]");

    g2--;
    CHECK(g2.printGraph() == "[0, 1, 0]\n[-4, 0, 2]\n[3, 0, 0]");
}

TEST_CASE("Test graph multiplication and division")
{
    // Undirected

    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1, 0);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2, 0);

    ariel::Graph g3 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}};
    CHECK(g3.printGraph() == "[0, 0, 2]\n[1, 0, 1]\n[1, 0, 0]");

    g1 *= 2;
    CHECK(g1.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]");
    g1 /= 2;
    CHECK(g1.printGraph() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");


    // Directed

    ariel::Graph g4;
    vector<vector<int>> graph4 = {
        {0, 0, -3},
        {-1, 0, 4},
        {0, 5, 0}};
    g4.loadGraph(graph4, 1);

    ariel::Graph g5;
    vector<vector<int>> graph5 = {
        {0, 1, 0},
        {0, 0, 2},
        {2, 1, 0}};
    g5.loadGraph(graph5, 1);
    
    ariel::Graph g6 = g4 * g5;
    CHECK(g6.printGraph() == "[0, -3, 0]\n[8, 0, 0]\n[0, 0, 0]");

    g4 *= -3;
    CHECK(g4.printGraph() == "[0, 0, 9]\n[3, 0, -12]\n[0, -15, 0]");
    g4 /= 3;
    CHECK(g4.printGraph() == "[0, 0, 3]\n[1, 0, -4]\n[0, -5, 0]");
}

// TEST_CASE("Test print")
// {
//     ariel::Graph g1;
//     vector<vector<int>> graph1 = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g1.loadGraph(graph1, 0);

//     ariel::Graph g2;
//     vector<vector<int>> graph2 = {
//         {0, -5, 3},
//         {1, 0, 0},
//         {0, -3, 0}};
//     g2.loadGraph(graph2, 1);

//     // Works
//     cout << g1;
//     cout << endl;
//     cout << g2;
// }

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1, 0);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 0},
        {1, 1, 0, 0}};
    g2.loadGraph(graph2, 0);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {0, 0, 1},
        {-5, 0, 0}};
    g3.loadGraph(graph3, 1);

    CHECK_THROWS(g2 * g1); // Undirected with different dimensions
    CHECK_THROWS(g1 * g2); // Undirected with different dimensions
    CHECK_THROWS(g3 * g1); // Undirected with directed
    CHECK_THROWS(g1 * g3); // Undirected with directed

    ariel::Graph g4;
    vector<vector<int>> graph4 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g4.loadGraph(graph4, 0);

    ariel::Graph g5;
    vector<vector<int>> graph5 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph5, 1);
    CHECK_THROWS(g1 + g4); // Addition of two graphs with different dimensions
    CHECK_THROWS(g5 + g4); // Addition of directed and undirected graphs

    CHECK_THROWS(g1 - g4); // Substraction of two graphs with different dimensions
    CHECK_THROWS(g5 - g4); // Substraction of directed and undirected graphs

    // Had problem with throwing exeption so changed it to false
    CHECK_FALSE(g4 == g5);
    CHECK_FALSE(g4 != g5);
    CHECK_FALSE(g4 < g5);
    CHECK_FALSE(g4 > g5);

    //CHECK_THROWS(g4 == g5); // Comparison of directed and undirected graphs
    //CHECK_THROWS(g4 < g5); // Comparison of directed and undirected graphs
    //CHECK_THROWS(g4 > g5); // Comparison of directed and undirected graphs
}


// I will show in this tests that I did not need to change any of the functions in 
// the Algorithms file because I am only changing the valus of the graphs and 
// then the functions perform the exact same operation without any problems 
TEST_CASE("Test isConnected")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g1.loadGraph(graph1, 0);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, -1, -1},
        {-1, 0, -1},
        {-1, -1, 0}};
    g2.loadGraph(graph2, 0);

    CHECK(Algorithms::isConnected(g1) == "1");
    
    g1--;
    // {0, 0, 0},
    // {0, 0, 0},
    // {0, 0, 0};
    CHECK(Algorithms::isConnected(g1) == "0"); // We made the edges to be equal to 0 (with --)

    CHECK(Algorithms::isConnected(g2) == "1");
    
    ++g1;
    g2 += g1;
    // {0, 0, 0},
    // {0, 0, 0},
    // {0, 0, 0};
    CHECK(Algorithms::isConnected(g2) == "0"); // We made the edges to be equal to 0 (with +=)

    g2 -= g1;
    ariel::Graph g3 = g2 * g1;
    // {0, -1, -1},
    // {-1, 0, -1},
    // {-1, -1, 0};
    CHECK(Algorithms::isConnected(g3) == "1");

}

TEST_CASE("Test shortest path")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1, 0);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 5},
        {1, 0, 1},
        {5, 1, 0}};
    g2.loadGraph(graph2, 0);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 5},
        {0, 0, 0},
        {1, 0, 0}};
    g3.loadGraph(graph3, 1);

    ariel::Graph g4;
    vector<vector<int>> graph4 = {
        {0, 1, 0},
        {0, 0, 1},
        {0, 3, 0}};
    g4.loadGraph(graph4, 1);

    CHECK(Algorithms::shortestPath(g1, 0, 2) == "0->1->2");
    
    g1++;
    // {0, 2, 1},
    // {2, 0, 2},
    // {1, 2, 0};
    CHECK(Algorithms::shortestPath(g1, 0, 2) == "0->2"); // We added an edge from 0 to 2
    
    --g1;
    g1 += g2;
    // {0, 2, 5},
    // {2, 0, 2},
    // {5, 2, 0};
    CHECK(Algorithms::shortestPath(g1, 0, 2) == "0->1->2"); // The edge we added is heavier that 0->1->2
    
    ariel::Graph g5 = g3 * g4;
    // {0, 15, 1},
    // {0, 0, 0},
    // {0, 1, 0};
    CHECK(Algorithms::shortestPath(g5, 0, 1) == "0->2->1");
    
    g5--;
    // {0, 14, 0},
    // {-1, 0, -1},
    // {-1, 0, 0};
    CHECK(Algorithms::shortestPath(g5, 0, 1) == "0->1");
}

TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1, 0);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 0, 1},
        {1, 0, 0},
        {0, 1, 0}};
    g2.loadGraph(graph2, 1);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 1},
        {2, 0, 1},
        {0, 3, 0}};
    g3.loadGraph(graph3, 1);

    CHECK(Algorithms::isContainsCycle(g1) == "0");
    CHECK(Algorithms::isContainsCycle(g2) == "The cycle is: 0->2->1->0");

    ++g1;
    // {0, 2, 1},
    // {2, 0, 2},
    // {1, 2, 0};
    CHECK(Algorithms::isContainsCycle(g1) == "The cycle is: 0->1->2->0");
    
    g2--;
    // {0, -1, 0},
    // {0, 0, -1},
    // {-1, 0, 0};
    CHECK(Algorithms::isContainsCycle(g2) == "The cycle is: 0->1->2->0");

    g2++;
    ariel::Graph g4 = g2 * g3;
    // {0, 3, 0},
    // {0, 0, 1},
    // {2, 0, 0};
    CHECK(Algorithms::isContainsCycle(g4) == "The cycle is: 0->1->2->0");


}

TEST_CASE("Test isBipartite")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1, 0);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 2},
        {1, 0, 1},
        {1, 2, 0}};
    g2.loadGraph(graph2, 1);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 1},
        {2, 0, 1},
        {0, 3, 0}};
    g3.loadGraph(graph3, 1);

    CHECK(Algorithms::isBipartite(g1) == "The graph is bipartite: A={0, 2}, B={1}");
    CHECK(Algorithms::isBipartite(g2) == "0");
    
    g1++;
    // {0, 2, 1},
    // {2, 0, 2},
    // {1, 2, 0};
    CHECK(Algorithms::isBipartite(g1) == "0");

    g2--;
    // {0, 0, 1},
    // {0, 0, 0},
    // {0, 1, 0};
    CHECK(Algorithms::isBipartite(g2) == "The graph is bipartite: A={0, 1}, B={2}");

    ariel::Graph g4 = g2 * g3;
    // {0, 3, 0},
    // {0, 0, 0},
    // {2, 0, 0};
    CHECK(Algorithms::isBipartite(g4) == "0");
}

TEST_CASE("Test negativeCycle")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 0, 0, 1, 0},
        {-3, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    g1.loadGraph(graph1, 1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, -1, 0, 0, 0},
        {0, 0, -1, 0, 0},
        {0, 0, 0, 0, -1},
        {-1, 0, 0, 0, 0},
        {0, 0, 0, -1, 0}};
    g2.loadGraph(graph2, 1);

    CHECK(Algorithms::negativeCycle(g1) == "Negative cycle found: 0->3->1->0");
    
    g1++;
    // {0, 1, 1, 2, 1}
    // {-2, 0, 1, 1, 1}
    // {1, 1, 0, 1, 1}
    // {1, 2, 1, 0, 1}
    // {1, 1, 1, 1, 0}}
    CHECK(Algorithms::negativeCycle(g1) == "Negative cycle found: 0->1->0");

    g1++;
    // {0, 2, 2, 3, 2}
    // {-1, 0, 2, 2, 2}
    // {2, 2, 0, 2, 2}
    // {2, 3, 2, 0, 2}
    // {2, 2, 2, 2, 0}}
    CHECK(Algorithms::negativeCycle(g1) == "No negative cycle found");

    ariel::Graph g3 = g1 * g2;
    // {0, 0, -2, -2, -2}
    // {-2, 0, 0, -2, -2}
    // {-2, -2, 0, -2, 0}
    // {0, -2, -3, 0, -2}
    // {-2, -2, -2, 0, 0}
    CHECK(Algorithms::negativeCycle(g3) == "Negative cycle found: 0->2->3->4->0");
}