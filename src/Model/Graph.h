//
//  Graph.h
//  NodesInXCe
//
//  Created by Magallanes, Alejandro on 4/25/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include <stdio.h>

template <class Type>
class Graph
{

private:
    static const int MAXIMUM = 20;
    
public:
    Graph();
    virtual ~Graph();
    
    void addVertex(const Type& label);
    void addEdge(int source, int target);
    void removeEdge(int source, int target);
    Type& operator [] (int vertex);

};

#endif /* Graph_h */
