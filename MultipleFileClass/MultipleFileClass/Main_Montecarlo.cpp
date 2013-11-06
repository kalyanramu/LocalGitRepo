#include <iostream>
#include "Graph.h"
#include "ShortestPathAlgo.h"
#include <time.h>
using namespace std;

void PrintVector(ostream& out, const vector<int> & vec);
int main()
{

	const int numVertices = 50;
	const double densities[] = {0.2,0.4};
	int numIterations = sizeof(densities)/sizeof(double);

	for (int iter =0; iter < numIterations ; iter++)
	{
	//Create Algo Object
	//Create Random Graph
		double MonteCarloSum =0;
		int monteCarloSimulations = 10000;
		srand(time(NULL));
		double density = densities[iter];
		for (int i=0; i < monteCarloSimulations ; i++)
		{
			Graph G1;
			G1.create_random_graph(numVertices,density);
			//cout << "Vertices is" << G1.num_vertices() << endl;
			ShortestPathAlgo Algo1(G1);
			//vector<int> vertices = Algo1.vertex_list();
			double acc=0; int numValidPaths =0;
			double dist=0, avgPath=0;
			for (int j = 1; j< G1.num_vertices() + 1; j++)
			{
				dist = Algo1.Shortest_Path_Size(1,j);
				if (dist != std::numeric_limits<int>::max())
				{
					acc+= dist;
					numValidPaths++;
				}
			}
			avgPath = (acc/numValidPaths);
			MonteCarloSum += avgPath;
			if (i% 1000 == 0)
				std::cout << "Finished " << i << " Iterations" << std::endl;
		}
		cout << "Average Path from MonteCarlo for density of " << density << " is \t" << MonteCarloSum/(double)monteCarloSimulations << endl;
	}
	return 0;

}
void PrintVector(ostream& out, const vector<int> & vec)
{
	std::vector<int>::const_iterator vit= vec.begin();
	out << (*vit); vit++;
	for (; vit != vec.end(); vit++)
		out << "--" << (*vit);
	out << std::endl;
}