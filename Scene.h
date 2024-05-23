#pragma once
#include "Coords.h"
#include "SmallCube.h"

class Scene
{
public:
	static Scene sceneInstance;
	struct Mouse
	{
		bool leftButtonPressed;
		bool rightButtonPressed;
		int cursorPositionX, cursorPositionY;
		Mouse() = default;
	};
	Mouse mouse;
	Coords cameraPosition;
	void passiveMouseProcessing(int mouseX, int mouseY);
    void mouseProcessing(int button, int state, int x, int y);
	void activeMouseProcessing(int mouseX, int mouseY);
	static void PassiveMotionFuncST(int mouseX, int mouseY);
	static void mouseFuncST(int button, int state, int x, int y);
	static void activeMouseProcessingST(int mouseX, int mouseY);

	void update(int value);
	static void updateST(int value);
	void display();
	static void displayST();
	SmallCube X;
public:
	void play();
	Scene();
};

