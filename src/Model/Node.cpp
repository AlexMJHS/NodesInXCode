/*
 * Node.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: amag6880
 */

#include "Node.h"
#include <iostream>

//Sets the pointers to nullAllison road
template <class Type>
Node<Type>::Node()
{
	pointers = nullptr;

}

template <class Type>
Node<Type> :: Node(const Type& value)
{
	this -> value = value;
	pointers = nullptr;
}

template <class Type>
Node<Type>::~Node()
{
	// TODO Auto-generated destructor stub
}

//Gets the values for the class
template <class Type>
Type Node<Type> :: getValue()
{
	return this->value;
}

//Gets the pointers for the class
template <class Type>
Node<Type> * Node<Type> :: getPointers()
{
	return this ->pointers;
}

template <class Type>
void Node<Type>:: setValue(const Type& value)
{
	this->value = value;
}
