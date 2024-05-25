#include "SmallCube.h"
#include <iostream>
Coords SmallCube::converteDirection(Coords angles)
{
    Coords ans;
    int i = 0;
    //std::cout << angles.x << " " << angles.y << " " << angles.x << "    " << rotationDirectionConverter[0] << " "
        //<< rotationDirectionConverter[1] << " " << rotationDirectionConverter[2]  << "\n";
    if (abs(rotationDirectionConverter[i]) == 1)
        ans.x = angles.x * abs((double)rotationDirectionConverter[i]) / rotationDirectionConverter[i];
    if (abs(rotationDirectionConverter[i]) == 2)
        ans.x = angles.y * abs((double)rotationDirectionConverter[i]) / rotationDirectionConverter[i];
    if (abs(rotationDirectionConverter[i]) == 3)
        ans.x = angles.z * abs((double)rotationDirectionConverter[i]) / rotationDirectionConverter[i];
    i = 1;
    if (abs(rotationDirectionConverter[i]) == 1)
        ans.y = angles.x * abs((double)rotationDirectionConverter[i]) / rotationDirectionConverter[i];
    if (abs(rotationDirectionConverter[i]) == 2)
        ans.y = angles.y * abs((double)rotationDirectionConverter[i]) / rotationDirectionConverter[i];
    if (abs(rotationDirectionConverter[i]) == 3)
        ans.y = angles.z * abs((double)rotationDirectionConverter[i]) / rotationDirectionConverter[i];
    i = 2;
    if (abs(rotationDirectionConverter[i]) == 1)
        ans.z = angles.x * abs((double)rotationDirectionConverter[i]) / rotationDirectionConverter[i];
    if (abs(rotationDirectionConverter[i]) == 2)
        ans.z = angles.y * abs((double)rotationDirectionConverter[i]) / rotationDirectionConverter[i];
    if (abs(rotationDirectionConverter[i]) == 3)
        ans.z = angles.z * abs((double)rotationDirectionConverter[i]) / rotationDirectionConverter[i];
    //std::cout << ans.x << " " << ans.y << " " << ans.x << "\n";
    return ans;
}
void SmallCube::rotate(Coords data)
{
    std::vector<int> newRDC = rotationDirectionConverter;
    if (data.x == 0) {
        //std::cout << "OSb X\n";
        if (data.z == 1) {
            newRDC[1] = rotationDirectionConverter[2];
            newRDC[2] = -rotationDirectionConverter[1];
        }
        else {
            newRDC[1] = -rotationDirectionConverter[1];
            newRDC[2] = rotationDirectionConverter[2];
        }
    }
    if (data.x == 1) {
        //std::cout << "OSb Y\n";
        if (data.z == 1) {
            newRDC[0] = -rotationDirectionConverter[2];
            newRDC[2] = rotationDirectionConverter[0];
        }
        else {
            newRDC[0] = rotationDirectionConverter[2];
            newRDC[2] = -rotationDirectionConverter[0];
        }
    }
    if (data.x == 2) {
        //std::cout << "OSb Z\n";
        if (data.z == 1) {
            newRDC[0] = rotationDirectionConverter[1];
            newRDC[1] = rotationDirectionConverter[0];
        }
        else {
            newRDC[0] = rotationDirectionConverter[1];
            newRDC[1] = rotationDirectionConverter[0];
        }
    }
    rotationDirectionConverter = newRDC;
}



void SmallCube::renderCube()
{
    if (position == Coords(-1, -1, 0)) {
        std::cout << rotationDirectionConverter[0] << rotationDirectionConverter[1] << rotationDirectionConverter[2] << "\n";
    }
    //std::cout << size << "\n";
    // rotate
    rotationDirectionConverter = { 1,2,3 };
    for(int i = 0 ; i < pathRotation.size(); i++){
        glRotatef(90 * pathRotation[i].z, pathRotation[i].x == 0, pathRotation[i].x == 1, pathRotation[i].x == 2);
        
            rotate(pathRotation[i]);
        
    }

    Coords actualAnglesRotation = converteDirection(animationAngleRotate);
    //std::cout << actualAnglesRotation.x << " " << actualAnglesRotation.y << " " << actualAnglesRotation.z << "\n";
    glRotatef(90 * (actualAnglesRotation.x), 1, 0, 0);
    glRotatef(90 * (actualAnglesRotation.y), 0, 1, 0);
    glRotatef(90 * (actualAnglesRotation.z), 0, 0, 1);

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
    rotationDirectionConverter = { 1, 2, 3 };
    angleRotate = Coords(0, 0, 0);
    this->grey = Color(0.3, 0.3, 0.3);
    this->size = size;
    this->position = Coords(x, y, z);
    includedColors = "RGBOWY";
}

SmallCube::SmallCube(float size, float x, float y, float z, std::string includedColors)
{
    rotationDirectionConverter = { 1, 2, 3 };
    angleRotate = Coords(0, 0, 0);
    this->grey = Color(0.3, 0.3, 0.3);
    this->size = size;
    this->position = Coords(x, y, z);
    this->includedColors = includedColors;
}

void SmallCube::display()
{
    //angleRotate = Coords(0, 0, 0);
    //glPopMatrix();
    renderCube();
    //glPopMatrix();
}

