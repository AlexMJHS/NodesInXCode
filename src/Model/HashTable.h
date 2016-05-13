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
#include "CTECList.cpp"

template <class Type>
class HashTable
{
private:
    int capacity;
    double efficiencyPercentage;
    int size;
    int tableSize;
    HashNode<Type> * internalStorage;
    CTECList<HashNode <Type>> * tableStorage;
    
    int findPosition(HashNode<Type> * currentNode);
    int findTablePosition(HashNode<Type>);
    
    int handleCollision(HashNode<Type> * currentNode);
    
    void updateSize();
    void updateTableCapacity();
    
    int getNextPrime();
    bool isPrime(int candidateNumber);
public:
    HashTable();
    ~HashTable();
    
    void add(HashNode<Type> * currentNode);
    void addToTable(HashNode<Type> currentNode);
    
    bool remove(HashNode<Type> * currentNode);
    bool contains(HashNode<Type> * currentNode);
    int getSize();
    
};

#endif /* HashTable_h */
