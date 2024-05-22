#pragma once
#include "Coords.h"
#include "SmallCube.h"

class Scene
{
protected:
	static Scene sceneInstance;
	struct Mouse
	{
		bool leftButtonPressed;
		bool rightButtonPressed;
		Mouse() = default;
	};
	Mouse mouse;
	Coords cameraPosition;
	void processingActions(int mouseX, int mouseY);
    void mouseProcessing(int button, int state, int x, int y);
	static void PassiveMotionFuncST(int mouseX, int mouseY);
	static void mouseFuncST(int button, int state, int x, int y);

	void update(int value);
	static void updateST(int value);
public:
	void play();
	Scene();
};

