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

void NodeController::checkSorts()
{
    /*
     Create an array and list
     Fill each with random data
     sort and time
     repeat with ordered dta
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

void NodeController :: testLists()
{
	numbers->addToFront(3);
	numbers->addToEnd(8);
	cout << "End should be 8 and is: " << numbers->getEnd() << endl;
}

void NodeController :: start()
{
    doMergesort();

}

void NodeController::doMergesort()
{
    mergeData = new int[5000];
    
    for(int spot = 0; spot < 5000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
    }
    for (int spot = 0; spot < 50; spot++)
    {
        cout << mergeData[spot] << ", " ;
    }
    Timer mergeTimer;
    mergeTimer.startTimer();
    mergesort(mergeData, 5000);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInformation();
    
    delete [] mergeData;
    
}

void NodeController::mergesort(int data[], int size)
{
    int sizeOne;
    int sizeTwo;
    
    if(size > 1)
    {
        sizeOne = size/2;
        sizeTwo = size-sizeOne;
        mergesort(data, sizeOne);
        mergesort(data+sizeOne, sizeTwo);
        
        merge(data, sizeOne, sizeTwo);
    }
    
}

void NodeController::merge(int data[], int sizeOne, int sizeTwo)
{
    int * temp;   //Link for a temporary array.
    int copied = 0;
    int copied1 = 0;
    int copied2 = 0;
    int index;
    
    temp = new int[sizeOne + sizeTwo];
    
    while((copied1 < sizeOne) && (copied2 < sizeTwo))
    {
        if(data[copied1] < (data + sizeOne) [copied2]) //smaller goes in small half
        {
            temp[copied++] = data[copied1++];
        }
        else //larger es in large half
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
    
    for(index = 0; index< sizeOne + sizeTwo; index++)
    {
        data[index] = temp[index];
        delete [] temp;
    }
    
}

void NodeController::doQuick()
{
    
}

void NodeController::doBogo()
{
    int temp [10];
    int check [10];
    
    for(int index = 0; index < 10; index++)
    {
        check[index] = index;
    }
    
    
    
}

void NodeController::quicksort(int data[], int size)
{
    int pivotIndex;
    
    
    
    if(size < last)
    {
        pivotIndex = partition(first, last);
        quicksort(first, pivotIndex-1);
        quicksort(pivotIndex+1, last);
        
    }
}

void NodeController:: partition(int data[], int size, int pivotIndex)
{
    int pivot;
    
    int index, smallIndex;
    swap(first, (first + last)/2);
    
    pivot = mergeata [ first];
    smallIndex = first;
    
    for(index = first + 1; index <= last, index++);
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

void NodeController::swap(int first, int last)
{
    int temp = first;
    mergeData[first] = mergeData[last];
    mergeData[last] = temp;
}

void NodeController::doQuick()
{
    
}