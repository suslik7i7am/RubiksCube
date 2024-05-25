#pragma once
#include "Coords.h"
#include "SmallCube.h"
#include <vector>
#include <cmath>
#include <algorithm>
#include "RubiksCube3x3x3.h"

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

	struct Keyboard
	{
	public:
		void keyboardProcessing(unsigned char key, int x, int y, bool presed);
		Keyboard();
		std::vector<bool> buttonPresed;
	};
	Keyboard keyboard;
	Mouse mouse;
	Coords cameraPositionAngles; 
	Coords cameraPositionCoordinates3;
	float cameraDistanseToCoord0;
	static void PassiveMotionFuncST(int mouseX, int mouseY);
	static void mouseFuncST(int button, int state, int x, int y);
	static void activeMouseProcessingST(int mouseX, int mouseY);
	static void keyboardProcessingST(unsigned char key, int x, int y);
	static void keyboardSpecialProcessingST(int key, int x, int y);

	void update(int value);
	static void updateST(int value);
	void updateCameraPosition();


	void display();
	static void displayST();
	RubiksCube3x3x3 mainCube;
	
	int totalFPS;
public:
	void play();
	Scene();
};

