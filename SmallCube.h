#pragma once
#include "Coords.h"
#include "Color.cpp"
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

class SmallCube
{
protected:
	Coords position;
	float size;
	Coords rotationAngles;
	void renderCube();
public:

	SmallCube() = default;
	SmallCube(float size, float x, float y, float z);
	void display();
};

