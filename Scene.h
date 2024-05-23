#pragma once
#include "Coords.h"
#include "SmallCube.h"
#include <vector>
#include <cmath>
#include <algorithm>
class Scene
{
private:
	static Scene sceneInstance;
	struct Mouse
	{
	private:

	public:
		bool leftButtonPressed;
		bool rightButtonPressed;
		int cursorPositionX, cursorPositionY;
		int cursorOffsetX = -10e9, cursorOffsetY = -10e9;
		int positionRightButtonUpX, positionRightButtonUpY;
		int deltaMouseCursorX, deltaMouseCursorY;
		Mouse() = default;
		void MouseProcessing(int mouseX, int mouseY);
		void mouseButtonsProcessing(int button, int state, int x, int y);
		
	};
	Mouse mouse;
	Coords cameraPositionAngles; 
	Coords cameraPositionCoordinates3;
	float cameraDistanseToCoord0;
	static void PassiveMotionFuncST(int mouseX, int mouseY);
	static void mouseFuncST(int button, int state, int x, int y);
	static void activeMouseProcessingST(int mouseX, int mouseY);

	void update(int value);
	static void updateST(int value);
	void updateCameraPosition();


	void display();
	static void displayST();
	//SmallCube X;
public:
	void play();
	Scene();
};

