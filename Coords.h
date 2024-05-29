#pragma once
#include <cmath>
class Coords
{
public:
	float x, y, z;
	Coords(float X, float Y, float Z);
	Coords();
	bool operator==(const Coords& other);
	Coords& intCast();
	Coords& operator=(const Coords& othet);
};

