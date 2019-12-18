#include "convexHull.h"
#include <time.h>

#define N 10000
#define RMAX 1.0
#define M_PI 3.14159265358979323846  /* pi */

int main()
{
	//CREATING VERTICES AND ASSIGNING RANDOM VALUE
	vector<Vertex>V;
	srand(time(static_cast<time_t>(0)));
	for (auto it = 0; it < N; ++it)
	{
		double radius = RMAX * static_cast<double> (rand()) / static_cast<double>(RAND_MAX);
		double angle = 2.0 * M_PI * static_cast<double> (rand()) / static_cast<double>(RAND_MAX);
		V.emplace_back(radius * cos(angle), radius * sin(angle));
	}

	list<Vertex*> convexHullVertexList; // LIST TO STORE POINTER TO CONVEX HULL VERTEX
	//CALLING THE CONVEX HULL FUNCTION
	convexHull(V, convexHullVertexList);

	//PRINTING THE CONVEXHULL VERTICES
	for (auto it = convexHullVertexList.begin(); it != convexHullVertexList.end(); ++it)
	{
		cout << (*it)->GetXCoord() << " " << (*it)->GetYCoord() << endl;
	}
	cout << (*convexHullVertexList.begin())->GetXCoord() << " " << (*convexHullVertexList.begin())->GetYCoord() << endl;

}