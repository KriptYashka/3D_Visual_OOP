#ifndef EDGE_H
#define EDGE_H
#include "vertex.h"
#include <iostream>

class Edge{
private:
    //Vertex &_begin;
    //Vertex &_end;
public:
    Edge();
    Vertex &getBegin();
    Vertex &getEnd();
};

#endif // EDGE_H
