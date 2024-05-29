
#include <cmath>
#include <iostream>
#include <vector>
#include "SmallCube.h"
using namespace std;

float rotateAngle = 0.0f;



//void displayCube(float size, float x, float y, float z) {
//    glTranslatef(0.0, 0.0, 0.0);
//    renderCube(0.7, 1, 0, 1);
//}

SmallCube X(0.5, 0, 0, 0);
Coords cameraPosition(4.0, 0.0, 0.0);


//////////////////////////////////////////////////////////////////////







#include "Scene.h"


int main(int argc, char** argv) {
    //cout << (round(-0.3) == -0) << endl;
    cout << "hello world";
   
    glutInit(&argc, argv);
   
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Colorful Rotating Cube");

    glEnable(GL_DEPTH_TEST);
    //glutDisplayFunc(display);
    //glutTimerFunc(16, update, 0);
    Scene mainScene;
    mainScene.play();
   /* glutDisplayFunc(&Scene::displayST);
    glutTimerFunc(16, &Scene::updateST, 0);
    glutMouseFunc(&Scene::mouseFuncST);
    glutPassiveMotionFunc(&Scene::PassiveMotionFuncST);*/
    //glutKeyboardFunc(keyFunc);
    //glutMouseFunc(mouseClick);
    //glutPassiveMotionFunc(onMouseMove);

    cout << 2 << endl;
    glutMainLoop();

    return 0;
}
