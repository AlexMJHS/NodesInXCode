//
//  HashTable.cpp
//  NodesInXCe
//
//  Created by Magallanes, Alejandro on 5/5/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "HashTable.h"

template <class Type>
HashTable<Type> :: HashTable()
{
    this->capacity = 101;
    this->efficiencyPercentage = .667;
    this->size = 0;
    this->internalStorage = new HashNode<Type>[capacity];
}

template <class Type>
HashTable<Type> :: ~HashTable<Type>()
{
    delete [] internalStorage;
}

template <class Type>
int HashTable<Type> :: getSize()
{
    return this->size;
}

template <class Type>
void HashTable<Type> :: add(HashNode<Type> * currentNode)
{
    if(!contains(currentNode))
    {
        //update size if needed.
        if(this->size/this->capacity >= this->efficiencyPercentage)
        {
            updateSize();
        }
        //Find where to put the value.d
        int positionToInsert = findPosition(currentNode);
        
        if(internalStorage[positionToInsert] != nullptr)
        {
            //Loop over the internalStorage to find the next empty slot.
            //Wrap if needed
            //Insert the value there.
            while(internalStorage[positionToInsert] != nullptr)
            {
                positionToInsert = (positionToInsert + 1) % capacity;
                
            }
            internalStorage[positionToInsert] = currentNode;
        }
        else
        {
            internalStorage[positionToInsert] = currentNode;
        }
    }
}
/*
 * Very basic hashing algorithm.
 * Simply assigns a position based on modulo math.
 */
template <class Type>
int HashTable<Type> :: findPosition(HashNode<Type> * currentNode)
{
    //We are going to "hash" the key of the HashNode to find its storage spot.
    int position = 0;
    
    position = currentNode.getKey() % capacity;
    
    return position;
}