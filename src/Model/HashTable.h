//
//  HashTable.h
//  NodesInXCe
//
//  Created by Magallanes, Alejandro on 5/5/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h
#include "CTECArray.cpp"
#include "HashNode.cpp"

template <class Type>
class HashTable
{
private:
    int capacity;
    double efficiencyPercentage;
    int size;
    HashNode<Type> * internalStorage;
    
    int findPosition(HashNode<Type> * currentNode);
    int handleCollision(HashNode<Type> * currentNode);
    void updateSize();
public:
    HashTable();
    ~HashTable();
    
    void add(HashNode<Type> * currentNode);
    bool remove(HashNode<Type> * currentNode);
    bool contains(HashNode<Type> * currentNode);
    int getSize();
    
};

#endif /* HashTable_h */
