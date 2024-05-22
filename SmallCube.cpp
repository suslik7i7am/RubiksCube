#include "SmallCube.h"
#include <iostream>
void SmallCube::renderCube()
{
    //std::cout << size << "\n";
    glBegin(GL_QUADS);
    float x = this->position.x;
    float y = this->position.y;
    float z = this->position.z;
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

SmallCube::SmallCube(float size, float x, float y, float z)
{
	this->size = size;
	this->position = Coords(x, y, z);
}

void SmallCube::display()
{
    renderCube();
}

