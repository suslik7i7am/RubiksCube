#pragma once
#include "Coords.h"
#include "Color.cpp"
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <string>


class SmallCube
{
private:
	std::string includedColors;
	Color grey;
	
public:
	Coords position;
	float size;
	//Coords rotationAngles;
	void renderCube();
public:
	Coords angleRotate;
	Coords animationAngleRotate;
	SmallCube() = default;
	SmallCube(float size, float x, float y, float z);
	SmallCube(float size, float x, float y, float z, std::string includedColors);
	void display();
};

