#include "PriorityQueue.h"
#include <limits>

	bool PriorityQueue::Insert(int queue_element, double priority)											// insert queue_element into queue
	{
		//Insert element at the end with Inf Priority
		QElem NewVal(queue_element,std::numeric_limits<int>::max());
		
		queue.push_back(NewVal);
		int NewElemPosition = queue.size()-1;
		Pos[queue_element] = NewElemPosition;
		//Change the element priority to given value
		DecreaseKeyValue(NewElemPosition,priority);
		return true;
	}
	
	bool PriorityQueue::chgPriority(int queue_element, double priority)		// changes the priority (node value) of queue element.
	{
		//Find location of the element in the queue
		int pos = GetElementPosInQueue(queue_element);

		if (pos != -1) //If the element exists in queue
		{
			if (priority< queue[pos].priority)
				DecreaseKeyValue(pos, priority);
			else
				IncreaseKeyValue(pos, priority);
			return true; //success
		}
		else
			return false; //no success
	}

	int  PriorityQueue::top()											    //returns the top element of the queue
	{
		if (queue.size() >0)
		return queue[0].queue_element;
		else
			return -1;
	}
	int  PriorityQueue::minPriority()									    // removes the top element of the queue
	{
		int sizeq = queue.size();
		
		if(queue.size() >0)
		{
			int output = queue[0].queue_element;
			assert(queue.size() >0);
			int n =queue.size()-1;
			if (n >0)
				SwapElementsInQueue(0,n);
			queue.pop_back();
			if ( n >0 )
			{
				//swap first and last element
				IncreaseKeyValue(0,queue[0].priority);
			}
			return output;
		}
		else
			return -1;

	}
	bool PriorityQueue::contains(int queue_element)						  // does the queue contain queue_element
	{
		//Find location of the element in the queue
		int pos = GetElementPosInQueue(queue_element);
		return (pos != -1);

	}

	int  PriorityQueue::size()											   // return the number of queue_elements
	{
		return queue.size();
	}

	//Helper Functions
    bool PriorityQueue::DecreaseKeyValue(int pos, double priority)
	{

		//Set the Value
		queue[pos].priority = priority;

		//Move it up in the queue and update ElementPosInQueue
		int ChildId  = pos;
		int ParentId = (ChildId+1)/2 -1 ;
		while ( ParentId >= 0 && priority < queue[ParentId].priority)
		{
			//Swap Elements
			SwapElementsInQueue(ParentId,ChildId);

			//New Position
			ChildId  = ParentId;
			ParentId = (ChildId+1)/2-1;
		}
		return true;
	}

	    bool PriorityQueue::IncreaseKeyValue(int pos, double priority)
		{
		//Set the Value
		queue[pos].priority = priority;

		//Move it up in the queue and update ElementPosInQueue
		int ParentId  = pos;
		int Child1Id   = (ParentId+1)*2-1; //Changing to Index1 Array
		int Child2Id   = (ParentId+1)*2-1+1;
		int minChildId;
		int ElementsInQueue = size();
		while ( Child1Id < ElementsInQueue)
		{
			//Find Minimum of the Childs
			if (Child2Id <ElementsInQueue)
			{
				if( queue[Child1Id].priority <= queue[Child2Id].priority)
					minChildId = Child1Id;
				else
				    minChildId = Child2Id;
			}
			else
				minChildId = Child1Id;
			if (queue[minChildId].priority < queue[pos].priority)
			{
				//Swap Elements & Update Map
				SwapElementsInQueue(ParentId,minChildId);
			}
			else
				break;

			//New Position
			ParentId   = minChildId;
			Child1Id   = (ParentId+1)*2-1; //Changing to Index1 Array
			Child2Id   = (ParentId+1)*2-1+1;
		}
		return false;
	}


	inline int PriorityQueue::GetElementPosInQueue(const int& queue_element)
	{
		//Check if element exists in queue if so return position, else return -1
		std::map<int,int>::iterator it = Pos.find(queue_element);
		if (it == Pos.end())
			return -1;
		else
			return (*it).second;
	}

	void PriorityQueue::SwapElementsInQueue(int pos1, int pos2)
	{
			QElem temp;
			// Swap Position of elements In Map
			Pos[queue[pos1].queue_element] = pos2;
			Pos[queue[pos2].queue_element] = pos1;

			//Swap Elements in Queued Array
			temp = queue[pos1];
			queue[pos1]= queue[pos2];
			queue[pos2]= temp;


	}

	void PriorityQueue::Print()
	{
		std::cout << "Element ---> Priority" << std::endl;
		for ( std::vector<QElem>::iterator it= queue.begin(); it != queue.end(); it++)
		{
			std::cout << it->queue_element <<"-->" << it->priority << std::endl;
		}
	}
	/*Notes:
	Parent(m) = floor(m/2)
	LeftChild(m) = 2m
	RightChild(m) = 2m+1
	*/