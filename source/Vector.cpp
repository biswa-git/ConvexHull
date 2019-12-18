#include "Vector.h"

Vector::Vector(Vertex& vStart, Vertex& vEnd)
{
	dx = vEnd.GetXCoord() - vStart.GetXCoord();
	dy = vEnd.GetYCoord() - vStart.GetYCoord();
}

Vector::Vector(double dx, double dy) :dx(dx), dy(dy)
{
}

Vector Vector::operator+(const Vector& V)
{
	Vector sum(this->dx + V.dx, this->dy + V.dy);
	return sum;
}

Vector Vector::operator-(const Vector& V)
{
	Vector sum(this->dx - V.dx, this->dy - V.dy);
	return sum;
}

double Vector::operator*(const Vector& V)
{
	return (this->dx * V.dx + this->dy * V.dy);
}

double Vector::operator^(const Vector& V)
{
	return (this->dx * V.dy - this->dy * V.dx);
}

double Vector::abs()
{
	return sqrt(dx * dx + dy * dy);
}

double Vector::GetDx()
{
	return dx;
}

double Vector::GetDy()
{
	return dy;
}

void Vector::Reassign(Vertex& vStart, Vertex& vEnd)
{
	dx = vEnd.GetXCoord() - vStart.GetXCoord();
	dy = vEnd.GetYCoord() - vStart.GetYCoord();

}

void Vector::Reassign(double dx, double dy)
{
	this->dx = dx;
	this->dy = dy;
}
