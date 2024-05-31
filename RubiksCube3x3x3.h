#pragma once
#include "SmallCube.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
 
class RubiksCube3x3x3
{
private:
	std::vector<std::vector<std::vector<std::string>>>
		colorsInPlaces;
protected:
	std::vector<std::vector<std::vector<SmallCube>>> cubes;
	int animationStartFrame = -1;
	bool animationEnded = false;
	Coords currentRotationFaceData;

	std::vector<Coords> commandStack;
	std::vector<Coords> commandStackForRandomCondition;

	bool buildingActive = false;
	bool randomBuildingActive = false;
	bool random = false;
	std::vector<std::vector<std::vector<bool>>> generateInPlace();
	void optimization();
public:
	std::vector<std::vector<std::vector<bool>>> inPlace;
	SmallCube getSmallCube(int i, int j, int k);
	double animationSpeed = 10;
	void solve();
	void randomCondition();
	void smoothRotation(int numberOfTheCoordinateAxis, int side, int direction, int tick); // ({0,1,2}, {-1,1}, {-1,1}, [0.0-1.0] )
	bool animationActive;
	void display();
	void update(int totalFPS);
	void faceRotate(int numberOfTheCoordinateAxis, int side, int direction);
	RubiksCube3x3x3();
};

