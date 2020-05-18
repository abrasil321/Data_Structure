#include "graph.h"
#include <iostream>

using namespace custom;

Graph::Graph()
{
    matrix = 1;
}

Graph::Graph(bool &n)
{
    matrix = new bool[n * n];
    for (int i = 0; i < (n * n); i++)
    {
        grid[i] = false;
    }
}

Graph & Graph::operator=(Graph & G)
{
    matrix = G.matrix;
}
        
bool Graph::empty()
{
    return !vertex;
}

int Graph::size()
{
    return vertex;
}

int Graph::capacity()
{
    return (vertex * vertex);
}

void Graph::clear()
{
    vertex = 0;
}

void Graph::add(Vertex &v1, Vertex &v2)
{
    grid[v1, v2] = true;
}

bool Graph::isEdge(Vertex &v1, Vertex &v2)
{
    return grid[v1, v2];
}

set Graph::findEdges(Vertex &v)
{
    for (v2 = 0; v2 < size(); i++)
    {
        if (grid[v1, v2] == true)
        {
            matrix.insert(v2);
        }
    }
    return matrix;
}

list Graph::findPath(Vertex &v1, Vertex &v2)
{
    //
}