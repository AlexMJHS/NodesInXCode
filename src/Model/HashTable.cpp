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
    this->internalStorage = new Type[capacity];
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
void HashTable<Type> :: add(const Type& value)
{
    if(!contains(value))
    {
        //update size if needed.
        if(this->size/this->capacity >= this->efficiencyPercentage)
        {
            updateSize();
        }
        //Find where to put the value.d
        int positionToInsert = findPosition(value);
        
        if(internalStorage[positionToInsert] != nullptr)
        {
            //Loop over the internalStorage to find the next empty slot.
            //Wrap if needed
            //Insert the value there.
            while(internalStorage[positionToInsert] != nullptr)
            {
                positionToInsert = (positionToInsert + 1) % capacity;
                
            }
            internalStorage[positionToInsert] = value;
        }
        else
        {
            internalStorage[positionToInsert] = value;
        }
    }
}