#ifndef GRAPH_H
#define GRAPH_H

#include "set.h"
#include "list.h"
namespace custom
{
    class Graph
    {
        private:
        bool matrix;
        int *grid;
        set set;
        list list;

        public:
        class Vertex;

        Graph();
        Graph(bool &n);
        Graph & operator=(Graph & G);
        
        bool empty();
        int size();
        int capacity();
        void clear();

        void add(Vertex &v1, Vertex &v2);
        bool isEdge(Vertex &v1, Vertex &v2);
        set findEdges(Vertex &v);
        list findPath(Vertex &v1, Vertex &v2);

    };
}

#endif