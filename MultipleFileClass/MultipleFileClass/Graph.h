
#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <list>
#include <time.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

struct edge
{
	int    destVertexId;
	double edgeCost;

	edge(int dest =0, double cost = 0):destVertexId(dest),edgeCost(cost){};
	bool operator ==(const edge& E2)
	{
		return ( destVertexId == E2.destVertexId && edgeCost == E2.edgeCost);
	}
};
class Graph
{
	//Data Stored inside the class
private: 
	std::vector< std::list<edge> > G;
	int numEdges;

	//Accessor Function
public: 
	//Constructor and Destructor
	Graph();
	Graph::Graph(std::ifstream& in);// Read Graph from file
	~Graph();
	//Graph Building Functions
	void create_graph		(int numVertices);					//Create Graph of N vertices and no edges
	void add_edge			(int source, int dest);				// adds to G the edge from x to y, if it is not there.
	void delete_edge		(int source, int dest);				// removes the edge from x to y, if it is there.
	void create_random_graph(int numVertices, double density);	// Create a random graph with N vertices
	void UpdateGraph		(std::string line);
	//Property Nodes
	//Node Values
	void set_node_value		(int source, int a);			// sets the value associated with the node x to a.
	int  get_node_value		(int source);					// returns the value associated with the node x.
	
	//EdgeValues
	double	 get_edge_value		(int source, int dest);			  // returns the value associated to the edge (x,y).
	void	 set_edge_value		(int source, int dest, double value);		// sets the value associated to the edge (x,y) to v.
	
	//Get Vertices, Edges
	int num_vertices();									// returns the number of vertices in the graph
	int num_edges();										// returns the number of edges in the graph
	
	//Node Adjacency
	bool is_adjacent			(int source, int dest);					// tests whether there is an edge from node x to node y.
	std::list<edge> neighbors	(int source);					// lists all nodes y such that there is an edge from x to y.

	//Print
	void printGraph(std::ostream& out);

private:
	friend std::ostream& Graph::operator << (std::ostream& out, Graph& Gr);
	std::list<edge>::iterator FindEdgeInList(std::list<edge>& edges, int destVertex); //Find the iterator to destionation vertex in the edge list
	inline double getRandomNumber(double low, double high); // Get a random number
};

#endif