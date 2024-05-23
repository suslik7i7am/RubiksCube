#include "Scene.h"
#include <iostream>

Scene Scene::sceneInstance; // creating instance


void Scene::passiveMouseProcessing(int mouseX, int mouseY)
{
    mouse.cursorPositionX = mouseX;
    mouse.cursorPositionY = mouseY;
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
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            mouse.leftButtonPressed = true;
        }
        else if (state == GLUT_UP) {
            mouse.leftButtonPressed = false;
        }

    }
}

void Scene::activeMouseProcessing(int mouseX, int mouseY)
{
    mouse.cursorPositionX = mouseX;
    mouse.cursorPositionY = mouseY;
}


void Scene::PassiveMotionFuncST(int mouseX, int mouseY)
{
    sceneInstance.passiveMouseProcessing(mouseX, mouseY);
}

void Scene::mouseFuncST(int button, int state, int x, int y)
{
	sceneInstance.mouseProcessing(button, state, x, y);
}

void Scene::activeMouseProcessingST(int mouseX, int mouseY)
{
    sceneInstance.activeMouseProcessing(mouseX, mouseY);
}

void Scene::update(int value)
{
    std::cout << mouse.cursorPositionX << " " << mouse.cursorPositionY;
    if (mouse.leftButtonPressed) {
        std::cout << " + ";
    }
    else {
        std::cout << " - ";
    }

    if (mouse.rightButtonPressed) {
        std::cout << "+ ";
    }
    else {
        std::cout << "- ";
    }

    std::cout << "\n";
}

void Scene::updateST(int value)
{
    sceneInstance.update(value);
    glutPostRedisplay();
    glutTimerFunc(16, updateST, 0);
}


void Scene::display() {
    //std::cout << cameraPosition.x << " " << cameraPosition.y << " " << cameraPosition.z << "\n";
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 10.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    gluLookAt(cameraPosition.x, cameraPosition.y, cameraPosition.z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glRotatef(0, 1.0, -1.0, 1.0);
    //renderCube(0.5 ,0,0,0);

    X.display();
    glPopMatrix(); //после отрисовки объекта необходимо использовать независимые матрицы
    glPushMatrix();//

    //glRotatef(0, 0.0, 0.0, 1.0);
    //renderCube(0.5, 0, 0, 1);
    //glPopMatrix(); // ---//----
    //glPushMatrix();//

    //glRotatef(0, 0.0, 0.0, 1.0);
    //renderCube(0.5, 1, 0, 0);
    //glPopMatrix(); // ---//----
    //glPushMatrix();//

    //glRotatef(0, 0.0, 0.0, 1.0);
    //renderCube(0.5, 1, -1, 1);
    //glPopMatrix(); // ---//----
    //glPushMatrix();//


    glutSwapBuffers();
}

void Scene::displayST()
{
    sceneInstance.display();
}


void Scene::play()
{
    SmallCube X = SmallCube(0.5, 0, 0, 0);
  
    glutDisplayFunc(&Scene::displayST);
    glutTimerFunc(16, &Scene::updateST, 0);
    glutMouseFunc(&Scene::mouseFuncST);
    glutPassiveMotionFunc(&Scene::PassiveMotionFuncST);
    glutMotionFunc(&Scene::activeMouseProcessingST);
    //glutMainLoop();
}

Scene::Scene()
{
	cameraPosition = Coords(4.0, 0, 0);
}
