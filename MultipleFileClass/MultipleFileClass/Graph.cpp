#include "Graph.h"
	//Graph Building Functions
	Graph::Graph()
	{
		numEdges = 0;
	}
	Graph::Graph(std::ifstream& infile)
	{
		//std::ifstream infile;
		//Create vector of vertices
		std::list<edge> temp;
		G.push_back(temp); //Dummy Node at Index 0
		numEdges =0;

		std::string line;
		while(getline(infile,line))
			UpdateGraph(line);
		numEdges/=2; //Since it is an undirected graph
		infile.close();
	}
	void Graph::UpdateGraph(std::string line)
	{
		std::stringstream linestream(line);
		int Vertex1, Vertex2,cost;
		int iter=0;
		std::string sub;
			while(!linestream.eof())
			{
				linestream >> sub;
				if (iter++ ==0)
				{
					Vertex1 = std::stoi(sub);
					std::list<edge> temp;
					G.push_back(temp);
					//std::cout << Vertex1 << "--";
				}
				else
				{
					std::stringstream edgeinfo(sub);
					edgeinfo  >> Vertex2;
					//std::cout << Vertex2 << ",";
					edgeinfo.ignore(); //Ignore ","
					edgeinfo >> cost;
					//std::cout << cost<<"\t";
					add_edge(Vertex1,Vertex2);
					set_edge_value(Vertex1,Vertex2,cost);
				}
			};
			//std::cout << std::endl;
	}

	Graph::~Graph()
	{

	}
	//Create a Graph with N vertice and no edges
	void Graph::create_graph(int numVertices)
	{
		//Node Vertex Numbering Starts from 1, so leave the first vertex and don't do anything on it.
		std::list<edge> temp;
		//Revserve space for vertices+1 to increase performance
		G.reserve(numVertices+1);
		
		//Create vector of vertices
		G.push_back(temp); //Dummy Node at Index 0
		for(int i=1; i< numVertices+1; i++)
			G.push_back(temp);

	}
	void Graph::create_random_graph(int numVertices, double density)	// Create a random graph with N vertices
	{
	//srand(time(NULL));
	double cost;
	//Create a graph with vertices and no edges
	create_graph(numVertices);
	numEdges =0;

	//Create Edges in the Graph
	for (int i = 1; i < numVertices+1; i++)
		for (int j=i+1; j < numVertices+1; j++)
		{
			if( getRandomNumber(0.0,1.0)<= density)
			{
				add_edge(i,j);
				add_edge(j,i);
				cost = getRandomNumber(1.0,10.0);//Get a number between 1 and 10;
				set_edge_value(i,j,cost);
				set_edge_value(j,i,cost);
				numEdges++; //Update NumEdges
			}
		}
	}
	// Adds to G the edge from x to y, if it is not there.
	void Graph::add_edge (int source, int dest)
	{
		//Check if the source, dest exist

		//Check if the edge exists
		if (FindEdgeInList(G[source], dest) == G[source].end())
		{
		//If edge doesn't exist, add it to the list
			edge E1(dest);
			edge E2(source);
			G[source].push_back(E1);
			//G[dest].push_back(E2);
			numEdges++;
		}

	}

	// removes the edge from x to y, if it is there
	void Graph::delete_edge (int source, int dest){
		//Check if edge exist (check source, vertex exist
		
		//Check if the edge  exists
		if (FindEdgeInList(G[source], dest) != G[source].end())
		{
			edge E1(dest);
			edge E2(source);
			G[source].remove(E1);
			G[dest].remove(E2);
			numEdges --;
		}
	}

	//Property Nodes
	// sets the value associated with the node N to value.
	void Graph::set_node_value(int node, int value)
	{


	}

	// get_node_value: returns the value associated with the node x.
	int Graph::get_node_value (int node)					
	{
		return 0;
	}
	//get_edge_value: returns the value associated to the edge (x,y).
	double	 Graph::get_edge_value(int source, int dest)				
	{
		//Check if edge exists

		//If exists, get the value
		std::list<edge>::iterator it;

		//Find iterator the destination vertex and replace cost of the edge
		it = FindEdgeInList(G[source], dest);
		if (it != G[source].end())
			return (*it).edgeCost;
		else
			return std::numeric_limits<double>::infinity();
	}

	// set_edge_value: sets the value associated to the edge (x,y) to v.
	void Graph::set_edge_value (int source, int dest, double value)		
	{
		//Check if edge exists

		//If exists, get the value
		std::list<edge>::iterator it;

		//Find iterator the destination vertex, if you don't find it add it to the list
		it = FindEdgeInList(G[source], dest);
		if (it == G[source].end())
		{
			add_edge (source,dest);
			//iterator is at the end of the list, decrement it by 1 to point to the
			// newly add value
			it--;
		}
		//Replace cost of the edge
		(*it).edgeCost = value;
	
	}
	//Vertices: returns the number of vertices in the graph
	int Graph::num_vertices()											
	{

		return G.size()-1; //Remove 1 as vertex indexing starts from 1
	}
	//Edges: returns the number of edges in the graph
	int Graph::num_edges()											
	{

		return numEdges;
	}
	// IsAdjacent: tests whether there is an edge from node source to node dest.
	bool Graph::is_adjacent (int source, int dest)					
	{
		std::list<edge>::iterator it = FindEdgeInList(G[source],dest);
		if (it == G[source].end())
			return false;
		else
			return true;
	}
	// Neighbors:lists all nodes y such that there is an edge from source to dest
	std::list<edge> Graph::neighbors (int source)					
	{
		return G[source];
	}

	//Find the iterator to destination vertex in the edge list
	std::list<edge>::iterator Graph::FindEdgeInList(std::list<edge>& edges, int destVertex)
	{
		std::list<edge>::iterator it = edges.begin();
		std::list<edge>::iterator end = edges.end();
		edge temp;
		while (it != end)
		{
			temp = *it;
			
			if ( temp.destVertexId == destVertex)
				return it;
			it++;
		}

		return end; //End will equivalent to null pointer
	}



	void Graph::printGraph(std::ostream& out)
	{


	}
	std::ostream& operator << (std::ostream& out, Graph& Gr) 
	{
			out << "Printing Graph" << std::endl;
			std::list<edge> Edges;
			std::list<edge>::iterator it;
			std::list<edge>::iterator begin;
			std::list<edge>::iterator end;
			size_t numRows= Gr.num_vertices()+1;
			for (size_t row=1; row < numRows ; row++ )
			{
				out << row;
				Edges = Gr.neighbors(row);
				begin	= Edges.begin();
				end		= Edges.end();	
				if(begin !=end)
				{
					for (it = begin; it != end; it++)
						out << "->" << it->destVertexId;
				}
				out << std::endl;
			}

		return out;
	}

	inline double Graph::getRandomNumber(double low, double high)
	{
		return ((double)rand()) / RAND_MAX * (high-low) + low;
	}

