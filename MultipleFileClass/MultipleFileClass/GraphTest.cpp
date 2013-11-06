#include <iostream>
#include "Graph.h"
using namespace std;
int main()
{

	Graph G1;
	G1.create_graph(3);

	//Test Add and Delete Edges
	cout << "Test Add and Delete Edges" << endl;
	G1.add_edge(1,2);
	G1.add_edge(2,1);
	G1.add_edge(2,3);
	G1.delete_edge(1,0);

	//Test edges function
	cout << "Test NumEdges" << endl;
	cout << G1.num_edges()<< endl;

	//Test vertices function
	cout << "Test Num Vertices" << endl;
	cout << G1.num_vertices() << endl;

	//Test Set and Get Edge Value
	cout << "Get, Set Edge Value" << endl;
	G1.set_edge_value(1,2,1.2);
	cout << G1.get_edge_value(1,2) << endl;

	//Test Delete Edge and Boolean
	G1.delete_edge(1,2);
	cout << "Test Is_Adjacent" << endl;
	cout << boolalpha << G1.is_adjacent(1,2) << endl;
	cout << "Edge Distance" << endl;
	cout << G1.get_edge_value(1,2) << endl;
	cout << G1.get_edge_value(2,1) << endl;

	//Test Neigbors
	list<edge> neighbors;
	neighbors = G1.neighbors(1);
	list<edge>::iterator it;
	cout << "Test Neighbors" << endl;
	for (it = neighbors.begin(); it != neighbors.end(); it++)
		cout << (*it).destVertexId << ","<< endl;

	//Test Print
	cout << G1 << endl;
	return 0;
}