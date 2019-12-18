#pragma once
#include "Vertex.h"

class Vector
{
public:
	Vector(Vertex&, Vertex&);
	Vector(double=0.0, double=0.0);

	Vector operator+(const Vector&);
	Vector operator-(const Vector&);
	double operator*(const Vector&); // DOT PRODUCT
	double operator^(const Vector&); // CROSS PRODUCT
	double abs();

	double GetDx();
	double GetDy();

	void Reassign(Vertex&, Vertex&);
	void Reassign(double = 0.0, double = 0.0);

private:
	double dx, dy;
};

