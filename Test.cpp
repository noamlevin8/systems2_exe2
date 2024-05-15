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

    +g1; // Onary plus
    CHECK(g1.printGraph() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");
    
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph, 0);

    ariel::Graph g3 = g1 + g2; // +

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

    +g5; // Onary plus
    CHECK(g5.printGraph() == "[0, 1, -6]\n[1, 0, 0]\n[0, 4, 0]");

    ariel::Graph g6 = g4 + g5; // +
    CHECK(g6.printGraph() == "[0, 4, -5]\n[2, 0, 2]\n[0, 6, 0]");

    g5 += g4; // +=
    CHECK(g5.printGraph() == "[0, 4, -5]\n[2, 0, 2]\n[0, 6, 0]");
}

TEST_CASE("Test graph substruction")
{
    // Undirected

    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 5},
        {1, 0, 2},
        {5, 2, 0}};
    g1.loadGraph(graph1, 0);

    -g1; // Onary minus
    CHECK(g1.printGraph() == "[0, -1, -5]\n[-1, 0, -2]\n[-5, -2, 0]");
    -g1; // Return to the before state

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

    -g5; // Onary minus
    CHECK(g5.printGraph() == "[0, -1, 6]\n[-1, 0, 0]\n[0, -4, 0]");
    -g5; // Return to the before state
    
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
    CHECK(g3 != g4); // Different dimensions
    //CHECK(g5 != g3);
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
}

TEST_CASE("Test graph multiplication")
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

    g1 * 2;
    CHECK(g1.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]");


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

    g4 * -3;
    CHECK(g4.printGraph() == "[0, 0, 9]\n[3, 0, -12]\n[0, -15, 0]");
}

TEST_CASE("Test print")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1, 0);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, -5, 3},
        {1, 0, 0},
        {0, -3, 0}};
    g2.loadGraph(graph2, 1);

    // Works
    cout << g1;
    cout << endl;
    cout << g2;
}

// TEST_CASE("Invalid operations")
// {
//     ariel::Graph g1;
//     vector<vector<int>> graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g1.loadGraph(graph, 0);

//     ariel::Graph g2;
//     vector<vector<int>> weightedGraph = {
//         {0, 1, 1, 1},
//         {1, 0, 2, 1},
//         {1, 2, 0, 1}};
//     g2.loadGraph(weightedGraph, 0);

//     ariel::Graph g5;
//     vector<vector<int>> graph2 = {
//         {0, 1, 0, 0, 1},
//         {1, 0, 1, 0, 0},
//         {0, 1, 0, 1, 0},
//         {0, 0, 1, 0, 1},
//         {1, 0, 0, 1, 0}};
//     g5.loadGraph(graph2, 0);
//     CHECK_THROWS(g5 * g1);
//     CHECK_THROWS(g1 * g2);

//     // Addition of two graphs with different dimensions
//     ariel::Graph g6;
//     vector<vector<int>> graph3 = {
//         {0, 1, 0, 0, 1},
//         {1, 0, 1, 0, 0},
//         {0, 1, 0, 1, 0},
//         {0, 0, 1, 0, 1},
//         {1, 0, 0, 1, 0}};
//     g6.loadGraph(graph3, 0);
//     CHECK_THROWS(g1 + g6);
// }