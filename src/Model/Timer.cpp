/*
 * Timer.cpp
 *
 *  Created on: Feb 16, 2016
 *      Author: amag6880
 */

#include "Timer.h"
#include <iostream>
#include <iomanip> //Make output look nicer!
using namespace std;

Timer::Timer()
{
	executionTime = 0;

}

Timer::~Timer()
{
	// TODO Auto-generated destructor stub
}
// Displays the timer info.
void Timer::displayTimerInformation()
{
	cout << fixed;
	cout << setprecision(8);

	cout << executionTime << " us (microseconds) for the code " << endl;
	cout << "Which is " << float(executionTime)/CLOCKS_PER_SEC<< " seconds" << endl;
}
	// Starts the Timer.
void Timer::startTimer()
{
	executionTime = clock();
}
	// Stops the timer.
void Timer::stopTimer()
{
	executionTime = clock() - executionTime;
}

	// This will reset the timer back to zero.
void Timer::resetTimer()
{
	executionTime = 0;
}

long Timer:: getExecutionTimeInMicroseconds()
{
	return executionTime;
}
