#include "Coords.h"

Coords::Coords(float X, float Y, float Z)
{
	x = X;
	y = Y;
	z = Z;
}

Coords::Coords()
{
	x = 0; y = 0; z = 0;
}

Coords& Coords::operator=(const Coords& othet)
{
	this->x = othet.x;
	this->y = othet.y;
	this->z = othet.z;
	return *this;
}

bool Coords::operator==(const Coords& other)
{
	return(x == other.x && y == other.y && z == other.z);
}


