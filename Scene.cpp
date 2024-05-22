#include "Scene.h"
Scene Scene::sceneInstance; // creating instance


void Scene::processingActions(int mouseX, int mouseY)
{

}

void Scene::mouseProcessing(int button, int state, int x, int y)
{
    if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN) {
            mouse.rightButtonPressed = true;
        }
        else if (state == GLUT_UP) {
            mouse.rightButtonPressed = false;
        }
        
    }
}

void Scene::PassiveMotionFuncST(int mouseX, int mouseY)
{
    sceneInstance.processingActions(mouseX, mouseY);
}

void Scene::mouseFuncST(int button, int state, int x, int y)
{
	sceneInstance.mouseProcessing(button, state, x, y);
}

void Scene::update(int value)
{
}

void Scene::updateST(int value)
{
    sceneInstance.update(value);
}

void Scene::play()
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Colorful Rotating Cube");

    
    glEnable(GL_DEPTH_TEST);
    //glutDisplayFunc(display);
    glutTimerFunc(16, &Scene::updateST, 0);
	glutMouseFunc(&Scene::mouseFuncST);
	glutPassiveMotionFunc(&Scene::PassiveMotionFuncST);
}

Scene::Scene()
{
	cameraPosition = Coords(4.0, 0, 0);
}
