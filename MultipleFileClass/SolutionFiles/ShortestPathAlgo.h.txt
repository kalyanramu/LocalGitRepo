#ifndef SHORTALGO_H
#define SHORTALGO_H
#include "Graph.h"
#include "PriorityQueue.h"

class ShortestPathAlgo
{
private:
	Graph G;
public:
	ShortestPathAlgo(const Graph& Gr);
	std::vector<int> vertex_list();									// List of vertices in G(V,E).
	std::vector<int> ShortestPath(int source, int dest);			// Find shortest path between u-w and returns the sequence of vertices representing shorest path u-v1-v2-…-vn-w.
	double Shortest_Path_Size(int source, int dest);					// returns the path cost associated with the shortest path.
private:
	void ShortestPathAlgo::Dijkstra(int source, int dest, std::vector<double>& dist, std::vector<int>& previous, bool AllVertices);
};
#endif