// ID: 326662574 
// MAIL: noamlevin11@gmail.com

#include "Algorithms.hpp"

using namespace std;

namespace Algorithms {

    // Regular DFS function but we only care if we visited a vertex
    void dfs(Graph g, size_t v, vector<bool>& visited)
    {
        visited[v] = true;

        size_t i;

        for(i = 0; i < g.getVertexNum(); i++)
        {
            if(g.getGraph()[v][i] != 0 && !visited[i])
            {
                dfs(g, i, visited); // Recursive call for our child/neighbor
            }
        }
    }

    // Checks if a graph is strongly connected (with the help of the "DFS" function)
    string isConnected(Graph g) {
        
        size_t i;

        for(i = 0; i < g.getVertexNum(); i++)
        {
            // Doing DFS from the vertex i
            vector<bool> visited(g.getVertexNum(),false);
            dfs(g, i, visited);

            // Checking if all the vertices are visited
            for(bool v : visited)
            {
                if(!v)
                    return "0"; // If there is a vertex that wasn't reachable from vertex i
            }
        }

        return "1"; // We were able to reach every vertex from every vertex
    }

    // Returns the shortest path from "start" to "end"
    string shortestPath(Graph g, size_t start, size_t end) {

        // Checking if the index of "start" and "end" are valid
        if(start >= g.getVertexNum() || end >= g.getVertexNum())
            throw invalid_argument("Invalid vertex: start/end out of range.");

        size_t V = g.getVertexNum();
        vector<int> dist(V, numeric_limits<int>::max());
        vector<int> parent(V, -1);
        dist[start] = 0;

        size_t i, j, k;

        // Bellman Ford

        // Relax |V| - 1 times
        for(k = 0; k < V - 1; k++)
        {
            for(i = 0; i < V; i++)
            {
                for(j = 0; j < V; j++)
                {
                    // If our graph is undirected we don't want to make a loop between two vertices
                    if(!g.getIfDirected() && parent[i] == j) 
                        continue;

                    if(dist[i] != numeric_limits<int>::max() && g.getGraph()[i][j] != 0 && dist[i] + g.getGraph()[i][j] < dist[j])
                    {
                        dist[j] = dist[i] + g.getGraph()[i][j];
                        parent[j] = i;
                    }
                }
            }
        }

        // If we coundn't reach "end" we don't have a path
        if(dist[end] == numeric_limits<int>::max())
            return "-1";
        
        // Check for a negative cycle in between "start" and "end"
        for(i = 0; i < V; i++)
        {
            for(j = 0; j < V; j++)
            {
                // If our graph is undirected we don't want to make a loop between two vertices
                if(!g.getIfDirected() && parent[i] == j)
                    continue;

                // If we could do another relax there is a negative cycle
                if(dist[i] != numeric_limits<int>::max() && g.getGraph()[i][j] != 0 && dist[i] + g.getGraph()[i][j] < dist[j]) // Found a negative cycle
                {
                    // Checking if the negative cycle is part of our path
                    size_t cur = static_cast<size_t>(parent[end]);
                    int count = 1;

                    while(cur != start && count < V)
                    {
                        if(j == cur)
                           return "-1";

                        cur = static_cast<size_t>(parent[cur]); 
                        count++;
                    }
                }
            }
        }

        // Reconstructing the path
        string path;

        path = to_string(end);

        i = static_cast<size_t>(parent[end]);

        // Looping backwards from "end" until we get to the "start" vertex
        while(i != start)
        {
            path = to_string(i) + "->" + path;
            i = static_cast<size_t>(parent[i]);
        }
        
        path = to_string(start) + "->" + path;

        return path;
    }

    // Part of the DFS we use in order to check if we have a cycle
    int DFSVisit(Graph g, size_t u, vector<string> color, vector<int>& parent)
    {
        color[u] = "gray";

        size_t i;
        int result = -1;

        for(i = 0; i < g.getVertexNum(); i++)
        {
            if(u != i && g.getGraph()[u][i] != 0)
            {
                // If our graph is undirected we don't want to make a loop between two vertices
                if(!g.getIfDirected() && parent[u] == i)
                    continue;

                if(color[i] == "white")
                {
                    parent[i] = u;
                    result = DFSVisit(g, i, color, parent); // Recursive call

                    if(result != -1) // We got a cycle
                        break;
                }
                else if(color[i] == "gray") // There is a backedge which means we have a cycle
                {
                    parent[i] = u;
                    return i; // Return the vertex that closed the cycle
                }
            }
        }
        color[u] = "black";
        
        return result;
    }

    // Checks if there is a cycle in the graph and if there is, it returns it (with the help of the "DFSVisit" function)
    string isContainsCycle(Graph g) {

        vector<string> color(g.getVertexNum(), "white");
        vector<int> parent(g.getVertexNum(), -1);
    
        size_t i;
        int j;
        int result;

        for(i = 0; i < g.getVertexNum(); i++)
        {
            if(color[i] == "white")
                result = DFSVisit(g, i, color, parent); // Using the "DFSVisit" function

            if(result != -1) // We found a cycle
            {
                // Reconstructing the path
                string path;

                path = to_string(result);

                j = parent[static_cast<size_t>(result)];

                int count = 1;

                // Looping backwards from "result" until we get to the "result" vertex again
                while(j != result && count < g.getVertexNum())
                {
                    path = to_string(j) + "->" + path;
                    j = parent[static_cast<size_t>(j)];
                    count++;
                }
                
                path = to_string(result) + "->" + path;

                return "The cycle is: " + path;
            }
        }

        return "0"; // We didn't find any cycle
    }

    // Checks if the graph is bipartite and if so, returns the partition
    string isBipartite(Graph g) {

        vector<int> parent (g.getVertexNum(), -1);
        vector<string> color (g.getVertexNum(), "white");
        queue<size_t> q;
        size_t u, v;

        bool flag = false; // If we don't have any edge from the current vertex we want to continue to next vertex
        size_t index = 0; // Current index

        color[0] = "blue"; // Starting the coloring from vertex 0
        q.push(0);

        while(!q.empty())
        {
            u = q.front();
            q.pop();

            for(v = 0; v < g.getVertexNum(); v++)
            {
                // Checking if we have an edge
                if(g.getGraph()[u][v] != 0)
                {
                    flag = true; // We change the flag because we have an edge

                    if(parent[u] == v) // We don't care if we already colored our parent
                        continue;

                    if(color[v] == color[u]) // Non-bipartite
                        return "0";
                    
                    if(color[v] == "white")
                    {
                        parent[v] = u;

                        // Coloring our child in different color
                        if(color[u] == "blue")
                            color[v] = "red";

                        else
                            color[v] = "blue";
                        
                       q.push(v); // Inserting our child to the queue 
                    }
                }
            }

            index++;

            // Checking the flag
            if(!flag)
            {
                if(index < g.getVertexNum())
                {
                    color[index] = "blue"; // Don't really matter what color because the last vertex don't have any edges 
                    q.push(index);
                }
            }

            flag = false;
        }

        // Showing the partitions
        string a, b;

        a = "A={";
        b = "B={";

        for(v = 0; v < g.getVertexNum(); v++)
        {
            if(color[v] == "blue")
            {
                if(a == "A={")
                    a += to_string(v);

                else
                    a += ", " + to_string(v);
            }

            else
            {
                if(b == "B={")
                    b += to_string(v);

                else
                    b += ", " + to_string(v);
            }
        }

        a += "}";
        b += "}";

        return "The graph is bipartite: " + a + ", " + b;
    }

    // Bellman Ford in order to detact negative cycles
    string bellmanFord(Graph g, size_t V, size_t src)
    {
        vector<int> dist(V, numeric_limits<int>::max());
        vector<int> parent(V, -1);
        dist[src] = 0; // Src is 0
        bool flag = false; // If we don't have any edge from a vertex we want to move to the next one

        size_t i, j, k;

        // Relax |V| - 1 times
        for(k = 0; k < V - 1; k++)
        {
            for(i = 0; i < V; i++)
            {
                for(j = 0; j < V; j++)
                {
                    // If our graph is undirected we don't want to make a loop between two vertices
                    if(!g.getIfDirected() && parent[i] == j)
                        continue;

                    if(g.getGraph()[i][j] != 0)
                    {
                        flag = true; // Updating flag

                        if(dist[i] != numeric_limits<int>::max() && dist[i] + g.getGraph()[i][j] < dist[j])
                        {
                            dist[j] = dist[i] + g.getGraph()[i][j];
                            parent[j] = i;
                        }
                    }
                }

                if(!flag && i+1 < V)
                    dist[i+1] = 0; // We didn't find an edge
                
                flag = false;
            }
        }

        // Checking if we can do another relax
        for(i = 0; i < V; i++)
        {
            for(j = 0; j < V; j++)
            {
                // If our graph is undirected we don't want to make a loop between two vertices
                if(!g.getIfDirected() && parent[i] == j)
                    continue;

                if(dist[i] != numeric_limits<int>::max() && g.getGraph()[i][j] != 0 && dist[i] + g.getGraph()[i][j] < dist[j]) // Found a negative cycle
                {
                    // Reconstructing the cycle

                    parent[j] = i;

                    string cycle;

                    cycle = to_string(i);

                    size_t node = static_cast<size_t>(parent[i]);

                    int count = 1;

                    // Looping backwards from i until we get to the i vertex again
                    while(node != i && count < V)
                    {
                        cycle = to_string(node) + "->" + cycle;
                        node = static_cast<size_t>(parent[node]);
                        count++;
                    }
                    
                    cycle = to_string(i) + "->" + cycle;

                    return "Negative cycle found: " + cycle;
                }
            }
        }
        return "No negative cycle found";
    }

    // Checks if there is a negative cycle in the graph and if so, it returns it (with the help of the "bellmanFord" function)
    string negativeCycle(Graph g) {

        size_t V = static_cast<size_t>(g.getVertexNum());

        return bellmanFord(g, V, 0); // Returning the result of running Bellman Ford
    }
}