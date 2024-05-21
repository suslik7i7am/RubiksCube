#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <cmath>
#include <iostream>

using namespace std;

float rotateAngle = 0.0f;

void renderCube(float size) {
    glBegin(GL_QUADS);

    glColor3f(1.0, 0.0, 0.0); // Красный
    glVertex3f(-size, -size, -size);
    glVertex3f(size, -size, -size);
    glVertex3f(size, size, -size);
    glVertex3f(-size, size, -size);

    glColor3f(0.0, 1.0, 0.0); // Зеленый
    glVertex3f(-size, -size, size);
    glVertex3f(size, -size, size);
    glVertex3f(size, size, size);
    glVertex3f(-size, size, size);

    glColor3f(0.0, 0.0, 1.0); // Синий
    glVertex3f(-size, -size, -size);
    glVertex3f(-size, size, -size);
    glVertex3f(-size, size, size);
    glVertex3f(-size, -size, size);

    glColor3f(1.0, 1.0, 0.0); // Желтый
    glVertex3f(size, -size, -size);
    glVertex3f(size, size, -size);
    glVertex3f(size, size, size);
    glVertex3f(size, -size, size);

    glColor3f(1.0, 0.0, 1.0); // Фиолетовый
    glVertex3f(-size, -size, -size);
    glVertex3f(-size, -size, size);
    glVertex3f(size, -size, size);
    glVertex3f(size, -size, -size);

    glColor3f(0.0, 1.0, 1.0); // Бирюзовый
    glVertex3f(-size, size, -size);
    glVertex3f(-size, size, size);
    glVertex3f(size, size, size);
    glVertex3f(size, size, -size);

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 10.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glRotatef(rotateAngle, 0.0, 1.0, 0.0);
    //glTranslatef(-1.0, 0.0, 0.0);
    renderCube(0.7);

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
int main(int argc, char** argv) {
    

   
    glutInit(&argc, argv);
   
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Colorful Rotating Cube");
    
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);
    glutKeyboardFunc(keyFunc);


    glutMainLoop();

    return 0;
}
