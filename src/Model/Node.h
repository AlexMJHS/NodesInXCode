/*
 * Node.h
 *
 *  Created on: Jan 27, 2016
 *      Author: amag6880
 */

#ifndef MODEL_NODE_H_
#define MODEL_NODE_H_

#include <iostream>

template <class Type>
class Node
{
private:
	Type value;			//Container for the value stored in the node.
	Node * pointers;	//Pointer to the array of Nodes that are linked to this node.
public:
	Node();
	Node(const Type& value);
	virtual ~Node();
	Type getValue();
	void setValue(const Type& value);
	Node * getPointers();
};

#endif /* MODEL_NODE_H_ */
