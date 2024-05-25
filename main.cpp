#include <cmath>
#include <iostream>
#include <vector>
#include "SmallCube.h"
#include "Scene.h"
using namespace std;

Coords cameraPosition(4.0, 0.0, 0.0);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Rubiks Cube");

    glEnable(GL_DEPTH_TEST);
    Scene mainScene;
    mainScene.play();
    glutMainLoop();

    return 0;
}
