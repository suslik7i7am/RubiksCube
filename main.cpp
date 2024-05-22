#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <cmath>
#include <iostream>

using namespace std;

float rotateAngle = 0.0f;


struct Color
{
    float r, g, b;
    Color(float r, float g, float b) {
        this->r = r;
        this->g = g;
        this->b = b;
    }

};



void renderCube(float size, float x, float y, float z) {
    glBegin(GL_QUADS);
    glTranslatef(x, y, z);

    float width = 0.1;
    Color widthColor(0.1, 0.1, 0.1);

    glColor3f(widthColor.r, widthColor.g, widthColor.b); // Каемка
    glVertex3f(-size + x, -size + y, -size + z);
    glVertex3f(size + x, -size + y, -size + z);
    glVertex3f(size + x, size + y, -size + z);
    glVertex3f(-size + x, size + y, -size + z);
    size -= width;
    z -= width + 0.001;
    glColor3f(1.0, 1.0, 1.0); // Белый
    glVertex3f(-size + x, -size + y, -size + z);
    glVertex3f(size + x, -size + y, -size + z);
    glVertex3f(size + x, size + y, -size + z);
    glVertex3f(-size + x, size + y, -size + z);
    size += width;
    z += width + 0.001;


    glColor3f(widthColor.r, widthColor.g, widthColor.b); // каемка
    glVertex3f(-size + x, -size + y, size + z);
    glVertex3f(size + x, -size + y, size + z);
    glVertex3f(size + x, size + y, size + z);
    glVertex3f(-size + x, size + y, size + z);
    size -= width;
    z += width + 0.001;
    glColor3f(1.0, 0.835, 0.0); // желтый
    glVertex3f(-size + x, -size + y, size + z);
    glVertex3f(size + x, -size + y, size + z);
    glVertex3f(size + x, size + y, size + z);
    glVertex3f(-size + x, size + y, size + z);
    size += width;
    z -= width + 0.001;


    glColor3f(widthColor.r, widthColor.g, widthColor.b); // каемка
    glVertex3f(-size + x, -size + y, -size + z);
    glVertex3f(-size + x, size + y, -size + z);
    glVertex3f(-size + x, size + y, size + z);
    glVertex3f(-size + x, -size + y, size + z);
    size -= width;
    x -= width + 0.001;
    glColor3f(0.0, 0.608, 0.282); // зеленый
    glVertex3f(-size + x, -size + y, -size + z);
    glVertex3f(-size + x, size + y, -size + z);
    glVertex3f(-size + x, size + y, size + z);
    glVertex3f(-size + x, -size + y, size + z);
    size += width;
    x += width + 0.001;


    glColor3f(widthColor.r, widthColor.g, widthColor.b); // каемка
    glVertex3f(size + x, -size + y, -size + z);
    glVertex3f(size + x, size + y, -size + z);
    glVertex3f(size + x, size + y, size + z);
    glVertex3f(size + x, -size + y, size + z);
    size -= width;
    x += width + 0.001;
    glColor3f(0.0, 0.275, 0.678); // Синий
    glVertex3f(size + x, -size + y, -size + z);
    glVertex3f(size + x, size + y, -size + z);
    glVertex3f(size + x, size + y, size + z);
    glVertex3f(size + x, -size + y, size + z);
    size += width;
    x -= width + 0.001;


    glColor3f(widthColor.r, widthColor.g, widthColor.b); // каемка
    glVertex3f(-size + x, -size + y, -size + z);
    glVertex3f(-size + x, -size + y, size + z);
    glVertex3f(size + x, -size + y, size + z);
    glVertex3f(size + x, -size + y, -size + z);
    size -= width;
    y -= width + 0.001;
    glColor3f(0.718, 0.071, 0.204); // Крассный
    glVertex3f(-size + x, -size + y, -size + z);
    glVertex3f(-size + x, -size + y, size + z);
    glVertex3f(size + x, -size + y, size + z);
    glVertex3f(size + x, -size + y, -size + z);
    size += width;
    y += width + 0.001;

    glColor3f(widthColor.r, widthColor.g, widthColor.b); // каемка
    glVertex3f(-size + x, size + y, -size + z);
    glVertex3f(-size + x, size + y, size + z);
    glVertex3f(size + x, size + y, size + z);
    glVertex3f(size + x, size + y, -size + z);
    size -= width;
    y += width + 0.001;
    glColor3f(1.0, 0.345, 0); // Оранжевый
    glVertex3f(-size + x, size + y, -size + z);
    glVertex3f(-size + x, size + y, size + z);
    glVertex3f(size + x, size + y, size + z);
    glVertex3f(size + x, size + y, -size + z);
    size += width;
    y -= width + 0.001;

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
    gluLookAt(4.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glRotatef(rotateAngle, 1.0, -1.0, 1.0);
    renderCube(0.5 ,0,0,0);
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
