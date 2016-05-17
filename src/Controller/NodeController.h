/*
 * NodeController.h
 *
 *  Created on: Jan 27, 2016
 *      Author: amag6880
 */

#ifndef CONTROLLER_NODECONTROLLER_H_
#define CONTROLLER_NODECONTROLLER_H_

#include <iostream>
#include <string>

#include "../Model/Node.h"
#include "../Model/ArrayNode.h"
#include "../Model/CTECArray.h"
#include "../Model/CTECList.cpp"
#include "../Model/Timer.h"
#include "../Model/CTECBinaryTree.cpp"
#include "../Model/CTECBinaryTree.h"


class NodeController
{
private:
	CTECArray<int> * notHipsterInts;
	CTECList<int> * numbers;
	Timer arrayTimer;
	void testLists();
    void checkSorts();
    void searchTest();
    void doBogo();
    void bogosort();
    
    void swap(int first, int second);
    void quicksort(int data[], int size);
    int partition(int first, int last);
    void doQuick();
    
    int * mergeData;
    void doMergesort();
    void mergesort(int dataArray [], int size);
    void merge(int data [], int sizeOne, int sizeTwo);
    
    void tryGraphs();
    void tryTree();
    
    void testHashTable();
public:
	NodeController();
	virtual ~NodeController();
	void start();
};

#endif /* CONTROLLER_NODECONTROLLER_H_ */
