#pragma once
#include "SmallCube.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class RubiksCube3x3x3
{
protected:
	std::vector<std::vector<std::vector<SmallCube>>> cubes;
	int animationStartFrame = -1;
	bool animationEnded = false;
	Coords currentRotationFaceData;
public:
	double animationSpeed = 1;

	void smoothRotation(int numberOfTheCoordinateAxis, int side, int direction, int tick); // ({0,1,2}, {-1,1}, {-1,1}, [0.0-1.0] )
	bool animationActive;
	void display();
	void update(int totalFPS);
	void faceRotate(int numberOfTheCoordinateAxis, int side, int direction);
	RubiksCube3x3x3();
};

