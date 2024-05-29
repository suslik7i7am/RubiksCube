#include "Scene.h"
#include <iostream>

Scene Scene::sceneInstance; // creating instance


void Scene::Mouse::MouseProcessing(int mouseX, int mouseY)
{
    cursorPositionX = mouseX;
    cursorPositionY = mouseY;
}

void Scene::Mouse::mouseButtonsProcessing(int button, int state, int x, int y)
{
    if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN) {
            rightButtonPressed = true;
            cursorOffsetX = x;
            cursorOffsetY = y;
        }
        else if (state == GLUT_UP) {
            rightButtonPressed = false;
            positionRightButtonUpX = deltaMouseCursorX;
            positionRightButtonUpY = deltaMouseCursorY;
            positionRightButtonUpY = std::min(std::max((double)positionRightButtonUpY, -3.14159265358979323846 * 100 / 2 + 10e-4), 3.14159265358979323846 * 100 / 2 - 10e-4);
        }
        
    }
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            leftButtonPressed = true;
        }
        else if (state == GLUT_UP) {
            leftButtonPressed = false;
        }

    }
}



void Scene::PassiveMotionFuncST(int mouseX, int mouseY)
{
    sceneInstance.mouse.MouseProcessing(mouseX, mouseY);
}

void Scene::mouseFuncST(int button, int state, int x, int y)
{
	sceneInstance.mouse.mouseButtonsProcessing(button, state, x, y);
}

void Scene::activeMouseProcessingST(int mouseX, int mouseY)
{
    sceneInstance.mouse.MouseProcessing(mouseX, mouseY);
}

void Scene::updateCameraPosition()
{
    mouse.deltaMouseCursorX = mouse.positionRightButtonUpX + mouse.cursorPositionX - mouse.cursorOffsetX;
    mouse.deltaMouseCursorY = mouse.positionRightButtonUpY + mouse.cursorPositionY - mouse.cursorOffsetY;
    cameraPositionAngles.y = -mouse.deltaMouseCursorX / 100.0;
    if (cameraPositionAngles.y < 0) {
        cameraPositionAngles.y += 2 * 3.14159265358979323846;
    }
    else if(cameraPositionAngles.y > 2 * 3.14159265358979323846){
        cameraPositionAngles.y -= 2 * 3.14159265358979323846;
    }
    cameraPositionAngles.z = mouse.deltaMouseCursorY / 100.0;
    if (cameraPositionAngles.z < -3.14159265358979323846 / 2) {
        cameraPositionAngles.z = -3.14159265358979323846 / 2 + 10e-4;
    }
    else if (cameraPositionAngles.z >  3.14159265358979323846 / 2) {
        cameraPositionAngles.z = 3.14159265358979323846 / 2 - 10e-4; 
    }

    Coords point = Coords(cameraDistanseToCoord0, 0, 0);
    float a = cameraPositionAngles.x,
        b = cameraPositionAngles.y,
        c = cameraPositionAngles.z;


    std::vector<std::vector<float>> rotationMatrix(3, std::vector<float>(3, 0));
    rotationMatrix[0] = { cos(b) * cos(c),   -sin(c) * cos(b),   sin(b) };
    rotationMatrix[1] = { sin(a) * sin(b) * cos(c) + sin(c) * cos(a),    -sin(a) * sin(b) * sin(c) + cos(a) * cos(c),   -sin(a) * cos(b) };
    rotationMatrix[2] = { sin(a) * sin(c) - sin(b) * cos(a) * cos(c),   sin(a) * cos(c) + sin(b) * sin(c) * cos(a),   cos(a) * cos(b) };

    cameraPositionCoordinates3 = Coords(rotationMatrix[0][0] * point.x + rotationMatrix[0][1] * point.y + rotationMatrix[0][2] * point.z,
        rotationMatrix[1][0] * point.x + rotationMatrix[1][1] * point.y + rotationMatrix[1][2] * point.z,
        rotationMatrix[2][0] * point.x + rotationMatrix[2][1] * point.y + rotationMatrix[2][2] * point.z);
    
}



void Scene::update(int value)
{
    if (mouse.rightButtonPressed) {
        updateCameraPosition();
    }
    totalFPS++;
    
    //std::cout << totalFPS << "\n";

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
    gluPerspective(45.0, 1.0, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    gluLookAt(cameraPositionCoordinates3.x, cameraPositionCoordinates3.y, cameraPositionCoordinates3.z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glRotatef(0, 1.0, -1.0, 1.0);

    glPopMatrix(); //����� ��������� ������� ���������� ������������ ����������� �������
   
   


    
    
   
    mainCube.display();

   


    glutSwapBuffers();
}

void Scene::displayST()
{
    sceneInstance.display();
}


void Scene::play()
{
    
  
    glutDisplayFunc(&Scene::displayST);
    glutTimerFunc(10, &Scene::updateST, 0);
    glutMouseFunc(&Scene::mouseFuncST);
    glutPassiveMotionFunc(&Scene::PassiveMotionFuncST);
    glutMotionFunc(&Scene::activeMouseProcessingST);
    glutMainLoop();
}


Scene::Scene()
{
    //X =  SmallCube(0.5, 0, 0, 0);
    //X.angleRotate = Coords(0, 0, 0);
    cameraDistanseToCoord0 = 10.0;
    cameraPositionCoordinates3 = Coords(cameraDistanseToCoord0, cameraDistanseToCoord0, cameraDistanseToCoord0);
}
