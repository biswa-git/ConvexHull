#pragma once
#include"essential.h"

class Vertex
{
private:
	static size_t count;
	size_t id;
	double xCoord, yCoord;
	double angle;
public:
	Vertex(double = 0.0, double = 0.0);
	virtual ~Vertex();
	void Reassign(double = 0.0, double = 0.0);
	size_t GetId();
	double GetXCoord();
	double GetYCoord();
	void SetAngle(const double&);
	double GetAngle();
	void Print();
};
