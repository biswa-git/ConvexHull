// convex_hull.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "convexHull.h"

void convexHull(vector<Vertex>& V, vector<Vertex*>& convexHullVertexList)
{
	size_t firstVertexId = 0;
	{
		//FINDING THE LEFTMOST POINTS ID  O(n)
		double leftPos = V[0].GetXCoord();
		for (auto it = V.begin(); it != V.end(); ++it)
		{
			if (it->GetXCoord() < leftPos)
			{
				leftPos = it->GetXCoord();
				firstVertexId = it->GetId();
			}
		}
	}

	//SORTING THE POINTS IN COUNTERCLOCKWISE DIR

	for (auto it = V.begin(); it != V.end(); ++it)
	{
			Vector vec1(V[firstVertexId], *it);
			it->SetAngle(asin((vec1.GetDy()) / vec1.abs()));
	}
	V[firstVertexId].SetAngle(-2.0);

	// SORTING THE ANGLE
	sort(V.begin(), V.end(), compareAngle);

	//PUSHING THE VERTEX
	//vector<Vertex*> convexHullVertexList;
	convexHullVertexList.push_back(&V[0]);
	convexHullVertexList.push_back(&V[1]);

	for (auto it = 2; it < V.size(); ++it)
	{
		bool contd{ true };
		while(contd)
		{
			//GETTINT THE POINTER OF PAST, PRES, NEXT VERTEX
			Vertex* present = convexHullVertexList.back();
			convexHullVertexList.pop_back();
			Vertex* prev = convexHullVertexList.back();
			convexHullVertexList.pop_back();
			Vertex* next = &V[it];

			//FORMING EDGE IN THE FORM OF VECTOR
			Vector firstEdge(*prev, *present);
			Vector secondEdge(*present, *next);
			
			convexHullVertexList.push_back(prev);
			if ((firstEdge ^ secondEdge) > 0.0)
			{
				convexHullVertexList.push_back(present);
				contd = false;
			}
		}
		convexHullVertexList.push_back(&V[it]);
	}
}

bool compareAngle(Vertex& V1, Vertex& V2)
{
	return (V1.GetAngle()<V2.GetAngle());
}