#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

//	This implementation of priority queue allows the user to modify the priority of a queue element
//	Although, this class implements the priority queue according to specifications, a bette implementation
//  of Dijkstra can be implemented without changing the priority of the queue_element but rather inserting
//  a new qelement with new priority value and when the qelement is popped, it can be checked whether it has
//  been visited or not in the algorithm

#include <vector>
#include <map>
#include <iostream>
#include <cassert>

//QElement
struct QElem
{
	int queue_element;
	double priority;
	QElem(int elem=0, double priority=0): queue_element(elem),priority(priority){};
	
	bool operator <(const QElem& lhs)
	{
		return priority < lhs.priority;
	}
};

class PriorityQueue
{
//Internal Data
private:
	std::vector<QElem> queue;								// Actual Queue DataStructure with Qelem
	std::map <int, int> Pos;								//Keep track of element position in Queue

//Accessor Functions
public:
	bool chgPriority(int queue_element, double priority);		// changes the priority (node value) of queue element.
	int  minPriority();									    // removes the top element of the queue.
	bool contains(int queue_element);						// does the queue contain queue_element.
	bool Insert(int queue_element, double priority);			// insert queue_element into queue
	int  top();											    //returns the top element of the queue
	int  size();											// return the number of queue_elements
	void Print();

//Helper Functions
private:													
   bool Heapify();
   bool DecreaseKeyValue(int queue_element, double priority);
   bool IncreaseKeyValue(int queue_element, double priority);
   int  GetElementPosInQueue(const int& queue_element);
   void SwapElementsInQueue(int Pos1, int Pos2);
   
};

#endif