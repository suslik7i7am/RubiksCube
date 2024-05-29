#pragma once
#include "Coords.h"
#include "Color.cpp"
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <string>
#include <vector>

class SmallCube
{
public:
	std::string includedColors;
	Color grey;
	std::vector<Coords> generatingVertex(Coords normal, bool isWidht);
	
public:
	void rotate(Coords anglesRotations);
	Coords position;
	float size;
	//Coords rotationAngles;
	void renderCube();
	std::vector<Coords> faceNormal;
public:
	Coords angleRotate;
	Coords animationAngleRotate;
	SmallCube() = default;
	SmallCube(float size, float x, float y, float z);
	SmallCube(float size, float x, float y, float z, std::string includedColors);
	void display();
};

