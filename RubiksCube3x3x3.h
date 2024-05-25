#pragma once
#include "SmallCube.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>

class RubiksCube3x3x3
{
public://private
	std::vector<std::vector<std::vector<SmallCube>>> cubes;
	int animationStartFrame;
	Coords currentRotationFaceData;
public:
	void smoothRotation(int numberOfTheCoordinateAxis, int side, int direction, int tick); // ({0,1,2}, {-1,1}, {-1,1}, [0.0-1.0] )
	bool animationActive;
	void display();
	void faceRotate(int numberOfTheCoordinateAxis, int side, int direction);
	void update(int totalFPS);
	void randomMoves();
	RubiksCube3x3x3();
};

