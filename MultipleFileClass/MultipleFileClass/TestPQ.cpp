// accessing mapped values
#include <iostream>
#include "PriorityQueue.h"

int main()
{

	PriorityQueue PQ;

	//Test Insert
	PQ.Insert(1,1);
	PQ.Insert(2,2);
	PQ.Insert(3,1);
	PQ.Insert(4,0);
	PQ.Insert(5,3);

	std::cout << "Does the Queue Contain 5? " << std::boolalpha << PQ.contains(5) << std::endl;
	std::cout << "Does the Queue Contain 10? " << std::boolalpha << PQ.contains(10) << std::endl;
	//Test Change Priority
	PQ.Print();
	std::cout << "Top Element is" << PQ.top() << std::endl;
	PQ.chgPriority(10,1);
	PQ.chgPriority(4,10);
	std::cout << "Does the Queue Contain 10? " << std::boolalpha << PQ.contains(10) << std::endl;
	std::cout << "After Modification \n";
	PQ.Print();

	//Test Remove Element
	std::cout << "Popping Elements" << std::endl;
	while (PQ.size() != 0)
		std::cout<< PQ.minPriority()<< std::endl;;
	
}