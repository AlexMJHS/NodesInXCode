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

#include "../Model/Node.cpp"
#include "../Model/ArrayNode.cpp"
#include "../Model/CTECArray.cpp"
#include "../Model/Timer.h"
#include "../Model/CTECList.cpp"
#include "../Model/CTECBinaryTree.cpp"
#include "../Model/Graph.cpp"
#include "../Model/HashTable.cpp"

using namespace std;

class NodeController
{
private:
    CTECArray<int> * notHipsterInts;
    CTECList<int> * numbers;
    Timer arrayTimer;
    void sortData();
    void testLists();
    void searchTest();
    void checkSorts();
    
    void swap(int first, int second);
    void quicksort(int first, int size);
    int partition(int first, int last);
    void doQuick();
    
    int  * mergeData;
    void doMergesort();
    void mergesort(int data [], int size);
    void merge(int data [], int sizeOne, int sizeTwo);
    
    void tryTree();
    void tryGraphs();
    void tryHash();
public:
    NodeController();
    virtual ~NodeController();
    void start();
};

#endif /* CONTROLLER_NODECONTROLLER_H_ */
