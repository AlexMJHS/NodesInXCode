/*
 * NodeController.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: amag6880
 */

#include "NodeController.h"
#include <stdlib.h>

NodeController::NodeController()
{
    notHipsterInts = new CTECArray<int>(5);
    numbers = new CTECList<int>();
}

NodeController::~NodeController()
{
    
}

void NodeController :: testLists()
{
    numbers -> addToFront(3);
    numbers -> addToEnd(8);
    cout << "Front should be 3 and is:  " << numbers->getFront() << endl;
    cout << "End should be 8 and is:  " << numbers->getEnd() << endl;
}

void NodeController :: sortData()
{
    /*
     Create an array and list
     Fill each with random data
     sort and time
     repeat with ordered data
     print results
     */
    
    CTECArray<int> numbersInArray(5000);
    CTECList<int> numbersInList;
    int cPlusPlusArray[5000];
    for(int spot = 0; spot < 5000; spot++)
    {
        int randomValue = rand();
        numbersInArray.set(spot, randomValue);
        numbersInList.addToEnd(randomValue);
        cPlusPlusArray[spot] = randomValue;
    }
    
    Timer sortTimer;
    sortTimer.startTimer();
    numbersInList.selectionSort();
    sortTimer.stopTimer();
    sortTimer.displayTimerInformation();
    
    sortTimer.resetTimer();
    sortTimer.startTimer();
    
}

void NodeController::start()
{
    tryHash();
    
}


void NodeController::doMergesort()
{
    mergeData = new int[5000];
    
    for(int spot = 0; spot < 5000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
    }
    for(int spot = 0; spot < 50; spot++)
    {
        cout << mergeData[spot] << ", ";
    }
    Timer mergeTimer;
    mergeTimer.startTimer();
    mergesort(mergeData, 5000);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInformation();
    for(int spot = 0; spot < 50; spot++)
    {
        cout << mergeData[spot] << "; ";
    }
    
    delete [] mergeData;
    
}

void NodeController::mergesort(int data [], int size)
{
    int sizeOne;
    int sizeTwo;
    
    if(size > 1)
    {
        sizeOne = size/2;
        sizeTwo = size - sizeOne;
        
        mergesort(data, sizeOne);
        mergesort(data + sizeOne, sizeTwo);
        
        merge(data, sizeOne, sizeTwo);
    }
}

void NodeController::merge(int data [], int sizeOne, int sizeTwo)
{
    int * temp; //Link for a temporary array.
    int copied = 0;
    int copied1 = 0;
    int copied2 = 0;
    int index;
    
    temp = new int[sizeOne + sizeTwo];
    while((copied1 < sizeOne) && (copied2 < sizeTwo))
    {
        if(data[copied1] < (data + sizeOne) [copied2])  //smaller goes in small half
        {
            temp[copied++] = data[copied1++];
        }
        else    //larger goes in large half
        {
            temp[copied++] = (data + sizeOne) [copied2++];
        }
    }
    
    while(copied1 < sizeOne)
    {
        temp[copied++] = data[copied1++];
    }
    while(copied2 < sizeTwo)
    {
        temp[copied++] = (data + sizeOne) [copied2++];
    }
    
    for(index = 0; index < sizeOne + sizeTwo; index++)
    {
        data[index] = temp[index];
    }
    delete [] temp;
}



void NodeController :: quicksort(int first, int last)
{
    int pivotIndex;
    
    
    if(first < last)
    {
        pivotIndex = partition(first, last);
        quicksort(first, pivotIndex - 1);
        quicksort(pivotIndex + 1, last);
    }
}

int NodeController :: partition(int first, int last)
{
    int pivot;
    
    int index, smallIndex;
    swap(first, (first + last)/2);
    
    pivot = mergeData[first];
    smallIndex = first;
    
    for(index = first + 1; index <= last; index++)
    {
        if(mergeData[index] < pivot)
        {
            smallIndex++;
            swap(smallIndex, index);
        }
    }
    swap(first, smallIndex);
    
    return smallIndex;
}


void NodeController :: swap(int first, int last)
{
    int temp = mergeData[first];
    mergeData[first] = mergeData[last];
    mergeData[last] = temp;
}

void NodeController :: doQuick()
{
    mergeData = new int[5000];
    
    for(int spot = 0; spot < 5000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
    }
    
    Timer mergeTimer;
    mergeTimer.startTimer();
    quicksort(0, 5000);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInformation();
    
    delete [] mergeData;
}

void NodeController::tryGraphs()
{
    Graph<int> testerGraph;
    testerGraph.addVertex(7);
    testerGraph.addVertex(18);
    testerGraph.addVertex(9);
    testerGraph.addVertex(17);
    testerGraph.addVertex(6);
    testerGraph.addVertex(3);
    testerGraph.addVertex(52);
    testerGraph.addVertex(68);
    testerGraph.addVertex(23);
    testerGraph.addVertex(35);
    //Add at least 7 vertices.
    //Connct the vertices
    testerGraph.addEdge(0,1);
    testerGraph.addEdge(1,2);
    testerGraph.addEdge(2,3);
    testerGraph.addEdge(6,7);
    testerGraph.addEdge(7,8);
    testerGraph.addEdge(8,9);
    
    
    testerGraph.breadthFirstTraversal(testerGraph, 0);
    
    
    
}

void NodeController :: tryTree()
{
    CTECBinaryTree<int> testTree;
    testTree.insert(7);
    testTree.insert(10);
    testTree.insert(-5);
    
    cout << testTree.contains(4) << endl;
    cout << " Inorder Traveral " << endl;
    testTree.inorderTraversal(testTree.getRoot());
    cout << " \nPreoder Traversal " << endl;
    testTree.preorderTraversal(testTree.getRoot());
    cout << " \nPostorder Traversal " << endl;
    testTree.postorderTraversal(testTree.getRoot());
    cout<< " Tree " << endl;
    
    
}

void NodeController :: tryHash()
{
    HashTable<int> tempTable;
    HashNode<int> tempArray[10];
    for(int spot = 0; spot < 10; spot++)
    {
        int randomValue = rand();
        int randomKey = rand();
        HashNode<int> temp = HashNode<int>(randomKey, randomValue);
        tempTable.add(temp);
        tempArray[spot] = temp;
    }
    bool test = tempTable.contains(tempArray[3]);
    string result;
    if(test)
    {
        result = "It's there";
    }
    else
    {
        result = "Not anywhere";
    }
    cout << result << endl;
    
}