#include "RubiksCube3x3x3.h"

void RubiksCube3x3x3::smoothRotation(int numberOfTheCoordinateAxis, int side, int direction, int tick) {// ({0,1,2}, {-1,1}, {-1,1}, [0.0-1.0] )
	/*if (animationStartFrame == -1) {
		animationStartFrame = tick;
		std::cout << "=====  " << tick << "\n";
		animationActive = true;
	}*/
	std::cout << "d";
	if (numberOfTheCoordinateAxis == 0) {
		for (int i = side + 1; i <= side + 1; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					cubes[i][j][k].animationAngleRotate.x += direction * (1) / 100.0;
				}
			}
			if (abs(cubes[i][0][0].animationAngleRotate.x) > 1) {
				for (int j = 0; j < 3; j++) {
					for (int k = 0; k < 3; k++) {
						cubes[i][j][k].animationAngleRotate.x = (cubes[i][j][k].animationAngleRotate.x / abs(cubes[i][j][k].animationAngleRotate.x));
						cubes[i][j][k].angleRotate.x += cubes[i][j][k].animationAngleRotate.x;
						cubes[i][j][k].angleRotate.y += cubes[i][j][k].animationAngleRotate.y;
						cubes[i][j][k].angleRotate.z += cubes[i][j][k].animationAngleRotate.z;
						cubes[i][j][k].animationAngleRotate = Coords(0, 0, 0);

					}
				}
				animationActive = false;
				std::cout << "-";
			}
		}
	}
	
}

void RubiksCube3x3x3::display()
{
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				glPushMatrix();
				//std::cout << cubes[i][j][k].angleRotate.x << " " << cubes[i][j][k].angleRotate.y << " " << cubes[i][j][k].angleRotate.z << "\n";
				//glRotatef(90, 0, 1, 0);
				
				cubes[i][j][k].display();
				//glRotatef(-10, 0, 0, 0);
				//glRotatef(270, cubes[i][j][k].angleRotate.x, cubes[i][j][k].angleRotate.y, cubes[i][j][k].angleRotate.z);
				glPopMatrix();
			}
		}
	}
}

void RubiksCube3x3x3::faceRotate()
{
	//std::cout << "rotated\n";
	if (!animationActive) {
		animationActive = true;

		for (int i = 0; i <= 0; i++) {
			std::vector<std::vector<SmallCube>> faceAfterRotate(3, std::vector<SmallCube>(3));
			for (int k = 2; k >= 0; k--) {
				for (int j = 0; j < 3; j++) {
					faceAfterRotate[j][k] = cubes[i][2 - k][j];
					//faceAfterRotate[j][k].angleRotate.x += 1;
				}
			}
			cubes[i] = faceAfterRotate;
		}
	}
}

RubiksCube3x3x3::RubiksCube3x3x3()
{
	cubes = std::vector<std::vector<std::vector<SmallCube>>>(3, std::vector<std::vector<SmallCube>>(3, std::vector<SmallCube>(3)));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				std::string colors = "";
				if (i == 0)
					colors.push_back('G');
				if (i == 2)
					colors.push_back('B');
				if (j == 0)
					colors.push_back('O');
				if (j == 2)
					colors.push_back('R');
				if (k == 0)
					colors.push_back('W');
				if (k == 2)
					colors.push_back('Y');
				
				cubes[i][j][k] = SmallCube(0.5, (float)i - 1, (float)j - 1, (float)k - 1, colors);
			}
		}
	}
}
