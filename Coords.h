#pragma once
class Coords
{
public:
	float x, y, z;
	Coords(float X, float Y, float Z);
	Coords();
	bool operator==(const Coords& other);
	Coords& operator=(const Coords& othet);
};

