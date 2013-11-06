	#include "ShortestPathAlgo.h"
	ShortestPathAlgo::ShortestPathAlgo(const Graph& Gr):G(Gr)					//Reads a graph
	{}
	std::vector<int> ShortestPathAlgo::vertex_list()				// List of vertices in G(V,E)
	{
		int numVertices =G.num_vertices();
		std::vector<int> vertices;
		vertices.reserve(numVertices+1);
		for (int i =1; i < numVertices+1; i++)
			vertices.push_back(i);
		return vertices;
	}
	
	// Returns the sequence of vertices representing shorest path u-v1-v2-…-vn-w
	void ShortestPathAlgo::Dijkstra(int source, int dest, std::vector<double>& dist, std::vector<int>& previous, bool AllVertices)	
	{
		int numVertices = G.num_vertices();
		int num_vertices_1 = numVertices+1;
		std::vector<bool> visited(num_vertices_1);
		for (int v=0; v<num_vertices_1;v++)
		{
		   dist[v]      = std::numeric_limits<int>::max();        // Unknown distance from src to v 
           visited[v]   = false;                                 // Nodes have not been visited
           previous[v]  = -1;									// -1 => undefined
		}

	    dist[source]  = 0;                                        // Distance from source to source

		//Priority Queue
		PriorityQueue PQ;
		PQ.Insert(source,0);// Start off with just the source node                             
	    int u; 
		std::list<edge> neighbors;
		std::list<edge>::iterator neighbor_it;
		double alt; int v;
		//std::cout << "Start of Iterations, PQSize is  " << PQ.size() <<std::endl;
	    while (PQ.size() !=0)                                     // The main loop
		 {
			 //u := vertex in Q with smallest distance in dist[] and has not been visited;  // Source node in first case
			//remove u from Q;
			//std::cout << "Get New Element, PQ.top() is   "<< PQ.top() << std::endl;
			while(PQ.size() !=0)
			{
				 assert(PQ.size() >0);
				 //std::cout << "PQ.top() is " << PQ.top() << " Visited is " << visited[PQ.top()] << "PQ.size is " << PQ.size() << std::endl;
				 if (visited[PQ.top()] == true)
				 {
					 u = PQ.minPriority();
				 }
				 else
					 break;
			 }
			 //std::cout << "New Element Arrived for Processing" << PQ.top() << std::endl;
			 if (PQ.size() == 0) 
				 break;
			 else
				u = PQ.minPriority();
			// std::cout << "Start of Processing New Element: " << u << std::boolalpha << " visited: " << visited[u] << " source: " << source << std::endl;
			 if( AllVertices == false)
			 {
				if (u == dest)	break;
			 }
	         visited[u] = true;                                   // mark this node as visited
	         //std::cout << "Search all neighbors " << std::endl;
			 neighbors = G.neighbors(u);
			 for (neighbor_it = neighbors.begin(); neighbor_it!= neighbors.end(); neighbor_it++)
			 {
				 v = neighbor_it ->destVertexId;
				 alt = dist[u] + neighbor_it->edgeCost;              // accumulate shortest dist from source
	             if (alt < dist[v] && !visited[v]) 
				 {
	                 dist[v]	= alt;                              // keep the shortest dist from src to v
	                 previous[v]= u;		 
					 PQ.Insert(v,alt);								// Add unvisited v into the Q to be process
				 }
			 }
			//std::cout << "End of Processing New Element" << std::endl;
		 }
		//std::cout << "End of Dijkstra" << std::endl;
	}

	std::vector<int> ShortestPathAlgo::ShortestPath(int source, int dest)
	{
		int numVertices = G.num_vertices();
		int num_vertices_1 = numVertices+1;
		
		std::vector<double> dist(num_vertices_1);
		std::vector<int>	previous(num_vertices_1);

		Dijkstra(source,dest, dist,previous,false);
		//What happens if previous[dest] = -1 => No Path
		 int currentVertex = dest;
		 std::vector<int> path;
		 
		 while ( currentVertex != source && currentVertex != -1)
		 {
			 path.push_back(currentVertex);
			 currentVertex= previous[currentVertex];
		 }
		 if(currentVertex !=-1)
			 path.push_back(currentVertex);
	     return path;
	}

	double ShortestPathAlgo::Shortest_Path_Size(int source, int dest) // returns the path cost associated with the shortest path
	{
		int numVertices = G.num_vertices();
		int num_vertices_1 = numVertices+1;
		
		std::vector<double> dist(num_vertices_1);
		std::vector<int>	previous(num_vertices_1);

		//std::cout << "Start of Dijkstra Calc" << std::endl;
		Dijkstra(source,dest, dist,previous,false);
		//std::cout << "End of Dijkstra Calc" << std::endl;
		//std::cout << "Dest is" << dest << std::endl;
		if (dest == 51)
			int a =12;
		return dist[dest];
	}