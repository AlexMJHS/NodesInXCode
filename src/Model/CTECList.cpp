/*
 * CTECList.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: amag6880
 */

#include "CTECList.h"
#include <assert.h>

template <class Type>
CTECList<Type>:: CTECList()
{
	this->size = 0;
	this->head = nullptr;
	this->end = nullptr;

}

template <class Type>
CTECList<Type>::~CTECList()
{
    ArrayNode<Type> * current = head;
    
    for (int deleteCount = 0; deleteCount < size; deleteCount++)
	{
	ArrayNode<Type> * temp = current;

	current = current->getNext();
	head = current;
	delete temp;
	}
}

template<class Type>
int CTECList<Type>:: getSize()
{
	return size;
}

/**
 * 1. Creates a new ArrayNode with value and head
 * 2. Updates head
 * 3. Updates size.
 */
template<class Type>
void CTECList<Type>:: addToFront(const Type& value)
{
	ArrayNode<Type> * newNode;
	ArrayNode<Type> * newStuff = new ArrayNode<Type>(value);
	head = newStuff;

	calculateSize();

	newNode = new ArrayNode<Type>;
	newNode -> value = value; //store the new value in the node
	newNode -> next = head; //insert newNode before first
	head = newNode; //make first point to the actual first node
	size++; // increment count
	if(end == NULL) //If the list was empty, newNode is also the last node in the list
	{
		end = newNode;
	}
}

/**
 * 1. Create new ArrayNode<Type> with the supplied value.
 * 2. Adds the node to the end.
 * 3.Updates end.
 * 4. Updates size.
 */
template<class Type>
void CTECList<Type>:: addToEnd(const Type& value)
{
	ArrayNode<Type> * newStuff = new ArrayNode<Type>(value);
	end->setNext(newStuff);
	end = newStuff;

    calculateSize();
}

template<class Type>
void CTECList<Type>:: addAtIndex(int index, const Type& value)
{

}

template<class Type>
Type CTECList<Type>:: getFront()
{
	assert(head != NULL);

	return head -> value; //return the info of the first node
}

template<class Type>
Type CTECList<Type>:: getEnd()
{
	assert(end != NULL);

	return end -> value; //return the info of the last node
}

template<class Type>
Type CTECList<Type>:: getFromIndex(int index)
{
    //Check that not removing from an empty list
    assert(this->size > 0);
    //Check that index is in bounds.
    assert(index >= 0 && index < size);
    
    ArrayNode<Type> * current = head;
    Type returnValue;
    
    for(int spot = 0; spot <= index; spot++)
    {
        if(spot == index)
        {
            returnValue = current->getValue;
        }
        current = current->getNext();
    }
    return current-> getValue();
}

template <class Type>
Type CTECList<Type>:: removeFromFront()
{
	Type thingToRemove; //In case we need to use the value we are removing
	assert(size > 0);
	//Create a pointer to what is after head.
	//Find the next spot
	ArrayNode<Type> * newHead = new ArrayNode<Type>();
	newHead= head->getNext();
	//Get what was in the head node
	thingToRemove = head -> getValue();
	//Delete what head is pointing to
	//Remove head
	delete head;
	//Set head to the new head
	//Move head to the next spot
	head = newHead;

	size--;

	this -> calculateSize();
	return thingToRemove;
}

template <class Type>
Type CTECList<Type>:: removeFromEnd()
{
	assert(size > 0);
	Type thingToRemove;

	ArrayNode<Type> * newHead = new ArrayNode<Type>();
	newHead = head->getNext();

	//Check for size == 1 it is a special case
	//Loop over size
	//or
	//Loop until getNext()->getNext() == nullptr
	//grab the value from the last node
	//set the next to last node to point to nullptr
	//set the next to last node as end
	//delete the old last node
	//Before return the variable call calculatedSize()
	//return value
	while(head -> getNext() -> getNext() != nullptr)
	{

	}

	this -> calculateSize();
	return thingToRemove;
}

template<class Type>
Type CTECList<Type>:: removeFromIndex(int index)
{
	Type thingToRemove;

	assert(size > 0);
	assert(index >= 0);
	assert(index < size);
	assert(size > 0 && index >= 0 && index < size); //Same as the three above

	ArrayNode<Type> * previous, deleteMe, newNext;
	if(index == 0)
	{
		thingToRemove = removeFromFront();
	}
	else if(index == size - 1)
	{
		thingToRemove = removeFromEnd();
	}
	else
	{
		for(int spot = 0; spot < index + 1; spot++)
		{

		}
	}

	this -> calculateSize();
	return thingToRemove;
}

/**
 * Calculates the size of the list by iterating over all of the nodes in the list
 */
template<class Type>
void CTECList<Type>:: calculateSize()
{
	assert(size >= 0);

	ArrayNode<Type> * counterPointer = head;
	int count = 0;
	if(counterPointer == nullptr)
	{
		this -> size = 0;
		return;
	}
	else
	{
		count ++;
		while(counterPointer -> getNext() != nullptr)
			{
				counterPointer = counterPointer -> getNext();
				count ++;
			}
		this -> size = count;
	}

}

template<class Type>
Type CTECList<Type>:: set(int index, const Type& value)
{

}

template <class Type>
int CTECList<Type> :: indexOf(Type searchValue)
{
    assert(this->size > 0);
    int index = -1;
    ArrayNode<Type> * searchPointer = head;
    if (searchPointer->getValue() == searchValue)
    {
        return 0;
    }
    for(searchPointer = head; searchPointer->getNext() != nullptr; searchPointer = searchPointer->getNext())
    {
        if(searchValue == searchPointer->getValue())
        {
            return index;
        }
        index++;
    }
    index = -1;
    
    return index;
}

template<class Type>
void CTECList<Type> :: swap(int indexOne, int indexTwo)
{
    assert(indexOne < size && indexTwo < size);
    ArrayNode<Type> * first = getFromIndex(indexOne);
    ArrayNode<Type> * second = getFromIndex(indexTwo);
    ArrayNode<Type> * temp = new ArrayNode<Type>();
    
    temp->setValue(first->getValue());
    first->setValue(second->getValue());
    second->setValue(temp->getValue());
    
    delete temp;
}

template<class Type>
void CTECList<Type>::selectionSort()
{
    int innerLoop, outerLoop;
    for(int outerLoop = 0; outerLoop < this->size()-1; outerLoop++)
    {
        int selectedMinimum = outerLoop;
        for(innerLoop = outerLoop+1; innerLoop < size; innerLoop++)
        {
            if(getFromIndex(innerLoop) < getFromIndex(selectedMinimum))
            {
                selectedMinimum = innerLoop;
            }
        }
        if(selectedMinimum != outerLoop)
        {
            swap(selectedMinimum, outerLoop);
        }
    }
}
