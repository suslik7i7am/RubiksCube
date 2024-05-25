#pragma once
#include "Coords.h"
#include "Color.cpp"
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <string>
#include <vector>
#include <cmath>

class SmallCube
{
private:
	std::string includedColors;
	Color grey;
	Coords converteDirection(Coords angles);
	
public:
	std::vector<Coords> pathRotation;
	void rotate(Coords data);
	Coords position;
	float size;
	//Coords rotationAngles;
	void renderCube();
public:
	std::vector<int> rotationDirectionConverter;
	int id = 0;
	Coords angleRotate;
	Coords animationAngleRotate;
	SmallCube() = default;
	SmallCube(float size, float x, float y, float z);
	SmallCube(float size, float x, float y, float z, std::string includedColors);
	
	void display();
};

