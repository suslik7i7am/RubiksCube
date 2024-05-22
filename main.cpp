
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
void display() {
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

void update(int value) {
    
    rotateAngle += 1.0f;
    if (rotateAngle > 360.0f) {
        rotateAngle -= 360.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void keyFunc(unsigned char key, int x, int y)
{
    cout << "(" << (int)key << ")" << key << " x:" << x << " y:" << y << endl;
}
//////////////////////////////////////////////////////////////////////


Coords rotate(Coords point, float angleX, float angleY, float angleZ) {
    float a = angleX, b = angleY, c = angleZ;
    std::vector<std::vector<float>> rotationMatrix(3, std::vector<float>(3, 0));
    rotationMatrix[0] = { cos(b) * cos(c),   -sin(c) * cos(b),   sin(b) };
    rotationMatrix[1] = { sin(a) * sin(b) * cos(c) + sin(c) * cos(a),    -sin(a) * sin(b) * sin(c) + cos(a) * cos(c),   -sin(a) * cos(b) };
    rotationMatrix[2] = { sin(a) * sin(c) - sin(b) * cos(a) * cos(c),   sin(a) * cos(c) + sin(b) * sin(c) * cos(a),   cos(a) * cos(b) };

    return Coords(rotationMatrix[0][0] * point.x + rotationMatrix[0][1] * point.y + rotationMatrix[0][2] * point.z,
        rotationMatrix[1][0] * point.x + rotationMatrix[1][1] * point.y + rotationMatrix[1][2] * point.z,
        rotationMatrix[2][0] * point.x + rotationMatrix[2][1] * point.y + rotationMatrix[2][2] * point.z);

}
//
//void mouseClick(int button, int state, int x, int y) {
//    Coords delta(0,0,0);
//    cout << endl;
//    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
//        //cout << x << " " << y << " -> ";
//        //delta.x -= x;
//        delta.y -= y;
//    }
//    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
//        //cout << x << " " << y << "\n";
//        //delta.x += x;
//        delta.y += y;
//        cout << delta.x << " " << delta.y << endl;
//        cameraPosition = rotate(cameraPosition, delta.x / 1000, delta.y / 1000, 0);
//
//    }
//
//}

void onMouseMove(int x, int y) {
    int mouseX, mouseY;
    mouseX = x;
    mouseY = y;
    std::cout << "Mouse position - x: " << mouseX << ", y: " << mouseY << std::endl;
}





int main(int argc, char** argv) {
    //try version 2
    cout << "hello world";
   
    glutInit(&argc, argv);
   
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Colorful Rotating Cube");
    
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);
    //glutKeyboardFunc(keyFunc);
    //glutMouseFunc(mouseClick);
    glutPassiveMotionFunc(onMouseMove);
    glutMainLoop();

    return 0;
}
