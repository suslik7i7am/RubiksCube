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
    if (includedColors.find('W') != std::string::npos) {
        glColor3f(1.0, 1.0, 1.0); // Белый
    }
    else {
        glColor3f(grey.r, grey.g, grey.b);
    }
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
    if (includedColors.find('Y') != std::string::npos) {
        glColor3f(1.0, 0.835, 0.0); // желтый
    }
    else {
        glColor3f(grey.r, grey.g, grey.b);
    }
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
    if (includedColors.find('G') != std::string::npos) {
        glColor3f(0.0, 0.608, 0.282); // зеленый
    }
    else {
        glColor3f(grey.r, grey.g, grey.b);
    }
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
    if (includedColors.find('B') != std::string::npos) {
        glColor3f(0.0, 0.275, 0.678); // Синий
    }
    else {
        glColor3f(grey.r, grey.g, grey.b);
    }
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
    if (includedColors.find('O') != std::string::npos) {
        glColor3f(1.0, 0.345, 0); // Оранжевый
    }
    else {
        glColor3f(grey.r, grey.g, grey.b);
    }
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
    if (includedColors.find('R') != std::string::npos) {
        glColor3f(0.718, 0.071, 0.204); // Крассный
    }
    else {
        glColor3f(grey.r, grey.g, grey.b);
    }
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
    this->grey = Color(0.3, 0.3, 0.3);
    this->size = size;
    this->position = Coords(x, y, z);
    includedColors = "RGBOWY";
}

SmallCube::SmallCube(float size, float x, float y, float z, std::string includedColors)
{
    this->grey = Color(0.3, 0.3, 0.3);
    this->size = size;
    this->position = Coords(x, y, z);
    this->includedColors = includedColors;
}

void SmallCube::display()
{
    renderCube();
}

