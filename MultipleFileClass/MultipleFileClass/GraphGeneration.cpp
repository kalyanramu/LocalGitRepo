#include <iostream>
#include "Graph.h"
#include <time.h>
using namespace std;
//To do:
//cout << Graph << endl;

int main()
{
	
	const int numVertices = 50;
	const double density = 0.1;

	//Create Random Graph
	Graph G1;
	G1.create_random_graph(numVertices,density);
	
	//Print Graph
	cout << G1 << endl;

	//Inform NumEdges and Density
	cout << "Num of Edges :\t" << G1.num_edges() << endl;
	cout << "Density of Graph:\t" << G1.num_edges()/ (G1.num_vertices()*0.5*(G1.num_vertices()-1))<< endl;
	return 0;

}
