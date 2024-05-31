
#include <cmath>
#include <iostream>
#include <vector>
#include "SmallCube.h"
#include "Scene.h"
using namespace std;





int main(int argc, char** argv) {
    
    cout << "Rules:\nTo rotate a face, click the button indicating the color of the selected face.\n\tY - yellow\n\tW - white\n\tO - orange\n\tB - blue\n\tR - red\n\tG - green\n to turn in the opposite direction, press the combination[color] + ['-']";
   
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
