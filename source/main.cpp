#include "convexHull.h"
#include <time.h>

#define N 100
#define RMAX 1.0
#define M_PI 3.14159265358979323846  /* pi */

int main()
{
	//CREATING VERTICES AND ASSIGNING RANDOM VALUE
	vector<Vertex>V(N);
	list<Vertex*> convexHullVertexList;
	srand(time(static_cast<time_t>(0)));
	for (auto it = V.begin(); it != V.end(); ++it)
	{
		double radius = RMAX * static_cast<double> (rand()) / static_cast<double>(RAND_MAX);
		double angle = 2.0 * M_PI * static_cast<double> (rand()) / static_cast<double>(RAND_MAX);
		it->Reassign(radius * cos(angle), radius * sin(angle));
	}

	vector<Vertex*> list;
	//CALLING THE CONVEX HULL FUNCTION
	convexHull(V, list);

	//PRINTING THE CONVEXHULL VERTICES
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		cout << (*it)->GetXCoord() << " " << (*it)->GetYCoord() << endl;
	}
	cout << (*list.begin())->GetXCoord() << " " << (*list.begin())->GetYCoord() << endl;
}