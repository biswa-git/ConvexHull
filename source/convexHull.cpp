#include "convexHull.h"

void convexHull(vector<Vertex>& V, list<Vertex*>& convexHullVertexList)
{
	Vertex* firstVertex = nullptr;
	{
		//FINDING THE LEFTMOST POINTS ID  O(n)
		double leftPos = V.begin()._Ptr->GetXCoord();
		for (auto it = V.begin(); it != V.end(); ++it)
		{
			if (it->GetXCoord() < leftPos)
			{
				leftPos = it->GetXCoord();
				firstVertex = it._Ptr;
			}
		}
	}

	//SORTING THE POINTS IN COUNTERCLOCKWISE DIR

	for (auto it = V.begin(); it != V.end(); ++it)
	{
			Vector vec1(*firstVertex, *(it._Ptr));
			it->SetAngle(asin((vec1.GetDy()) / vec1.abs()));
	}
	firstVertex->SetAngle(-2.0);

	// SORTING THE ANGLE
	sort(V.begin(), V.end(), compareAngle);

	/*-----------------------------------------------------
		WE NEED TO ADD FEW ADDITIONAL CHECKS FOR CORNER 
		CASES. WHICH I WILL ADD LATER :)
	-----------------------------------------------------*/

	//PUSHING THE VERTEX
	//vector<Vertex*> convexHullVertexList;
	convexHullVertexList.push_back((V.begin()  )._Ptr);
	convexHullVertexList.push_back((V.begin()+1)._Ptr);

	for (auto it = V.begin()+2; it != V.end(); ++it)
	{
		bool contd{ true };
		while(contd)
		{
			//GETTINT THE POINTER OF PAST, PRES, NEXT VERTEX
			Vertex* present = convexHullVertexList.back();
			convexHullVertexList.pop_back();
			Vertex* prev = convexHullVertexList.back();
			convexHullVertexList.pop_back();
			Vertex* next = it._Ptr;

			//FORMING EDGE IN THE FORM OF VECTOR
			Vector firstEdge(*prev, *present);
			Vector secondEdge(*present, *next);
			
			convexHullVertexList.push_back(prev);
			if ((firstEdge ^ secondEdge) > 0.0) // ^ IS OVERLOADED TO PERFORM CROSS PRODUCT
			{
				convexHullVertexList.push_back(present);
				contd = false;
			}
		}
		convexHullVertexList.push_back(it._Ptr);
	}
}

bool compareAngle(Vertex& V1, Vertex& V2)
{
	return (V1.GetAngle()<V2.GetAngle());
}
