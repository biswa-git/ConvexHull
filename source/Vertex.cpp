#include "Vertex.h"

size_t Vertex::count = 0;

Vertex::Vertex(double x, double y):id(count++),xCoord(x),yCoord(y),angle(0.0)
{
}

Vertex::~Vertex()
{
}

void Vertex::Reassign(double x, double y)
{
	xCoord = x;
	yCoord = y;
}

size_t Vertex::GetId()
{
	return id;
}

double Vertex::GetXCoord()
{
	return xCoord;
}

double Vertex::GetYCoord()
{
	return yCoord;
}

void Vertex::SetAngle(const double& angle)
{
	this->angle = angle;
}

double Vertex::GetAngle()
{
	return angle;
}

void Vertex::Print()
{
	cout << "id:" << id << " [" << xCoord << "," << yCoord << "]" << " has angle -> " << angle << endl;
}

