//
//  HashTable.h
//  NodesInXCe
//
//  Created by Magallanes, Alejandro on 5/5/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

template <class Type>
class HashTable
{
private:
    int capacity;
    double efficiencyPercentage;
    int size;
    Type * internalStorage;
    
    int findPosition(const Type& value);
    int handleCollision(const Type& value);
    void updateSize();
public:
    HashTable();
    ~HashTable();
    void add(const Type& value);
    bool remove(const Type& value);
    bool contains(const Type& value);
    
    
    
};

#endif /* HashTable_h */
