#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <cmath>
#include <iostream>

using namespace std;

float rotateAngle = 0.0f;

void renderCube(float size, float x, float y, float z) {
    glBegin(GL_QUADS);
    glTranslatef(x, y, z);
    glColor3f(1.0, 0.0, 0.0); // �������
    glVertex3f(-size + x, -size + y, -size + z);
    glVertex3f(size + x, -size + y, -size + z);
    glVertex3f(size + x, size + y, -size + z);
    glVertex3f(-size + x, size + y, -size + z);

    glColor3f(0.0, 1.0, 0.0); // �������
    glVertex3f(-size + x, -size + y, size + z);
    glVertex3f(size + x, -size + y, size + z);
    glVertex3f(size + x, size + y, size + z);
    glVertex3f(-size + x, size + y, size + z);

    glColor3f(0.0, 0.0, 1.0); // �����
    glVertex3f(-size + x, -size + y, -size + z);
    glVertex3f(-size + x, size + y, -size + z);
    glVertex3f(-size + x, size + y, size + z);
    glVertex3f(-size + x, -size + y, size + z);

    glColor3f(1.0, 1.0, 0.0); // ������
    glVertex3f(size + x, -size + y, -size + z);
    glVertex3f(size + x, size + y, -size + z);
    glVertex3f(size + x, size + y, size + z);
    glVertex3f(size + x, -size + y, size + z);

    glColor3f(1.0, 0.0, 1.0); // ����������
    glVertex3f(-size + x, -size + y, -size + z);
    glVertex3f(-size + x, -size + y, size + z);
    glVertex3f(size + x, -size + y, size + z);
    glVertex3f(size + x, -size + y, -size + z);

    glColor3f(0.0, 1.0, 1.0); // ���������
    glVertex3f(-size + x, size + y, -size + z);
    glVertex3f(-size + x, size + y, size + z);
    glVertex3f(size + x, size + y, size + z);
    glVertex3f(size + x, size + y, -size + z);
    
    glEnd();
    
}

void displayCube(float size, float x, float y, float z) {
    glTranslatef(0.0, 0.0, 0.0);
    renderCube(0.7, 1, 0, 1);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 10.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glRotatef(rotateAngle, 0.0, 0.0, 1.0);
    renderCube(0.5 ,0,1,0);
    glPopMatrix(); //����� ��������� ������� ���������� ������������ ����������� �������
    glPushMatrix();//
    
    glRotatef(0, 0.0, 0.0, 1.0);
    renderCube(0.5, 0, 0, 1.1);
    glPopMatrix(); // ---//----
    glPushMatrix();//


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
    //try version 2
    cout << "hello world";
   
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
