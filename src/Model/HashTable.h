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

template <class Type>
class HashTable
{
private:
    int capacity;
    double efficiencyPercentage;
    int size;
    Type * internalStorage;
    CTECArray<Type> internalArray;
    
    int findPosition(const Type& value);
    int handleCollision(const Type& value);
    void updateSize();
public:
    HashTable();
    ~HashTable();
    
    void add(const Type& value);
    bool remove(const Type& value);
    bool contains(const Type& value);
    int getSize();
    
};

#endif /* HashTable_h */
