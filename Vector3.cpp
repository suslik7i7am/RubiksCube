#include <cmath>
#include <vector>
#include "Coords.h"

//Coords rotate(Coords point, float angleX, float angleY, float angleZ) {
//	float a = angleX, b = angleY, c = angleZ;
//	std::vector<std::vector<float>> rotationMatrix(3, std::vector<float>(3, 0));
//	rotationMatrix[0] = { cos(b) * cos(c),   -sin(c) * cos(b),   sin(b) };
//	rotationMatrix[1] = { sin(a) * sin(b) * cos(c) + sin(c) * cos(a),    -sin(a) * sin(b) * sin(c) + cos(a) * cos(c),   -sin(a) * cos(b) };
//	rotationMatrix[2] = { sin(a) * sin(c) - sin(b) * cos(a) * cos(c),   sin(a) * cos(c) + sin(b) * sin(c) * cos(a),   cos(a) * cos(b) };
//	
//	return Coords(rotationMatrix[0][0] * point.x + rotationMatrix[0][1] * point.y + rotationMatrix[0][2] * point.z,
//		rotationMatrix[1][0] * point.x + rotationMatrix[1][1] * point.y + rotationMatrix[1][2] * point.z,
//		rotationMatrix[2][0] * point.x + rotationMatrix[2][1] * point.y + rotationMatrix[2][2] * point.z);
//
//}