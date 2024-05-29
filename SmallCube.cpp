#include "SmallCube.h"
#include <iostream>


Coords rotateVector3(Coords point, Coords angles) {
	float a = angles.x * 3.1415926535 / 2, b = angles.y * 3.1415926535 / 2, c = angles.z * 3.1415926535 / 2;
	std::vector<std::vector<float>> rotationMatrix(3, std::vector<float>(3, 0));
	rotationMatrix[0] = { cos(b) * cos(c),   -sin(c) * cos(b),   sin(b) };
	rotationMatrix[1] = { sin(a) * sin(b) * cos(c) + sin(c) * cos(a),    -sin(a) * sin(b) * sin(c) + cos(a) * cos(c),   -sin(a) * cos(b) };
	rotationMatrix[2] = { sin(a) * sin(c) - sin(b) * cos(a) * cos(c),   sin(a) * cos(c) + sin(b) * sin(c) * cos(a),   cos(a) * cos(b) };
	
	return Coords(rotationMatrix[0][0] * point.x + rotationMatrix[0][1] * point.y + rotationMatrix[0][2] * point.z,
		rotationMatrix[1][0] * point.x + rotationMatrix[1][1] * point.y + rotationMatrix[1][2] * point.z,
		rotationMatrix[2][0] * point.x + rotationMatrix[2][1] * point.y + rotationMatrix[2][2] * point.z);

}



std::vector<Coords> SmallCube::generatingVertex(Coords normal, bool isWidht)
{
    ///////////////////////////////////     //////  //////  //  //  //////  //////
    float width = 0.1;              ///     //      //  //  /// //  ///       //
    Color widthColor(0.1, 0.1, 0.1);///     //      //  //  // ///     ///    //
    ///////////////////////////////////     //////  //////  //  //  //////    //
    std::vector<Coords> vertex(4);
    float x = this->position.x;
    float y = this->position.y;
    float z = this->position.z;
    if (!isWidht) {
        size -= width;
        if (normal == Coords(1, 0, 0)) { // синий
            x += width + 0.001;
            vertex = {
            Coords(size + x, -size + y, -size + z),
            Coords(size + x, size + y, -size + z),
            Coords(size + x, size + y, size + z),
            Coords(size + x, -size + y, size + z) };
            x -= width + 0.001;
        }

        if (normal == Coords(0, 1, 0)) { // красный
            y += width + 0.001;
            vertex = {
            Coords(-size + x, size + y, -size + z),
            Coords(-size + x, size + y, size + z),
            Coords(size + x, size + y, size + z),
            Coords(size + x, size + y, -size + z) };
            y -= width + 0.001;
        }
        if (normal == Coords(0, 0, 1)) { // желтый
            z += width + 0.001;
            vertex = {
            Coords(-size + x, -size + y, size + z),
            Coords(size + x, -size + y, size + z),
            Coords(size + x, size + y, size + z),
            Coords(-size + x, size + y, size + z) };
            z -= width + 0.001;
        }
        size += width;
        //////////////////
        size -= width;
        if (normal == Coords(-1, 0, 0)) {// зеленый
            x -= width + 0.001;
            vertex = {
            Coords(-size + x, -size + y, -size + z),
            Coords(-size + x, size + y, -size + z),
            Coords(-size + x, size + y, size + z),
            Coords(-size + x, -size + y, size + z) };
            x += width + 0.001;
        }
        if (normal == Coords(0, -1, 0)) { // оранжевый
            y -= width + 0.001;
            vertex = {
            Coords(-size + x, -size + y, -size + z),
            Coords(-size + x, -size + y, size + z),
            Coords(size + x, -size + y, size + z),
            Coords(size + x, -size + y, -size + z) };
            y += width + 0.001;
        }
        if (normal == Coords(0, 0, -1)) { // белый
            z -= width + 0.001;
            vertex = {
            Coords(-size + x, -size + y, -size + z),
            Coords(size + x, -size + y, -size + z),
            Coords(size + x, size + y, -size + z),
            Coords(-size + x, size + y, -size + z) };
            z += width + 0.001;
        }
        size += width;
    }
    else {/////////////////////////////////////////////////////////////////////////////////////////////
        if (normal == Coords(1, 0, 0)) { // синий
           
            vertex = {
            Coords(size + x, -size + y, -size + z),
            Coords(size + x, size + y, -size + z),
            Coords(size + x, size + y, size + z),
            Coords(size + x, -size + y, size + z) };
           
        }
        if (normal == Coords(0, 1, 0)) { // красный
            
            vertex = {
            Coords(-size + x, size + y, -size + z),
            Coords(-size + x, size + y, size + z),
            Coords(size + x, size + y, size + z),
            Coords(size + x, size + y, -size + z) };
            
        }
        if (normal == Coords(0, 0, 1)) { // желтый
            
            vertex = {
            Coords(-size + x, -size + y, size + z),
            Coords(size + x, -size + y, size + z),
            Coords(size + x, size + y, size + z),
            Coords(-size + x, size + y, size + z) };
           
        }   
        //////////////////
        if (normal == Coords(-1, 0, 0)) {// зеленый
            
            vertex = {
            Coords(-size + x, -size + y, -size + z),
            Coords(-size + x, size + y, -size + z),
            Coords(-size + x, size + y, size + z),
            Coords(-size + x, -size + y, size + z) };
           
        }
        if (normal == Coords(0, -1, 0)) { // оранжевый
           
            vertex = {
            Coords(-size + x, -size + y, -size + z),
            Coords(-size + x, -size + y, size + z),
            Coords(size + x, -size + y, size + z),
            Coords(size + x, -size + y, -size + z) };
            
        }
        if (normal == Coords(0, 0, -1)) { // белый
            
            vertex = {
            Coords(-size + x, -size + y, -size + z),
            Coords(size + x, -size + y, -size + z),
            Coords(size + x, size + y, -size + z),
            Coords(-size + x, size + y, -size + z) }; 
        }
    }
    return vertex;
}

void SmallCube::rotate(Coords anglesRotations)
{
    for (int i = 0; i < faceNormal.size(); i++) {
        faceNormal[i] = rotateVector3(faceNormal[i], anglesRotations).intCast();
    }
}

void SmallCube::renderCube()
{
    //std::cout << size << "\n";
    glRotatef(90 * (angleRotate.x + animationAngleRotate.x), 1, 0, 0);
    glRotatef(90 * (angleRotate.y + animationAngleRotate.y), 0, 1, 0);
    glRotatef(90 * (angleRotate.z + animationAngleRotate.z), 0, 0, 1);
    glBegin(GL_QUADS);
    float x = this->position.x;
    float y = this->position.y;
    float z = this->position.z;
    glTranslatef(x, y, z);
    
    float width = 0.1;
    Color widthColor(0.1, 0.1, 0.1);

    std::vector<Coords> vertex;

    std::vector<Color> colors = { Color(0.0, 0.275, 0.678), Color(0.718, 0.071, 0.204), Color(1.0, 0.835, 0.0),
        Color(0.0, 0.608, 0.282), Color(1.0, 0.345, 0), Color(1.0, 1.0, 1.0) };
    std::string letterOfColor = "BRYGOW";
    for (int numFace = 0; numFace < 6; numFace++) {
        vertex = generatingVertex(faceNormal[numFace], true);
        glColor3f(widthColor.r, widthColor.g, widthColor.b); // Каемка
        for (int i = 0; i < 4; i++)
            glVertex3f(vertex[i].x, vertex[i].y, vertex[i].z);

        if (includedColors.find(letterOfColor[numFace]) != std::string::npos) {
            glColor3f(colors[numFace].r, colors[numFace].g, colors[numFace].b); // цвет грани
        }
        else {
            glColor3f(grey.r, grey.g, grey.b);
        }
        vertex = generatingVertex(faceNormal[numFace], false);
        for (int i = 0; i < 4; i++)
            glVertex3f(vertex[i].x, vertex[i].y, vertex[i].z);
    }

    glEnd();
}

void fillFaceNormal(std::vector<Coords>& faceNormal) {
    faceNormal = { Coords(1, 0, 0),
    Coords(0, 1, 0),
    Coords(0, 0, 1),
    Coords(-1, 0, 0),
    Coords(0, -1, 0),
    Coords(0, 0, -1), };
}

SmallCube::SmallCube(float size, float x, float y, float z)
{
    fillFaceNormal(faceNormal);
    angleRotate = Coords(0, 0, 0);
    this->grey = Color(0.3, 0.3, 0.3);
    this->size = size;
    this->position = Coords(x, y, z);
    includedColors = "RGBOWY";
}

SmallCube::SmallCube(float size, float x, float y, float z, std::string includedColors)
{
    fillFaceNormal(faceNormal);
    angleRotate = Coords(0, 0, 0);
    this->grey = Color(0.3, 0.3, 0.3);
    this->size = size;
    this->position = Coords(x, y, z);
    this->includedColors = includedColors;
}

void SmallCube::display()
{
    //angleRotate = Coords(0, 0, 0);
    renderCube();
}

