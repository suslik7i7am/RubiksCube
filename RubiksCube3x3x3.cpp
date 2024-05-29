#include "RubiksCube3x3x3.h"

void RubiksCube3x3x3::smoothRotation(int numberOfTheCoordinateAxis, int side, int direction, int tick) {// ({0,1,2}, {-1,1}, {-1,1}, [0.0-1.0] )
	/*if (animationStartFrame == -1) {
		animationStartFrame = tick;
		std::cout << "=====  " << tick << "\n";
		animationActive = true;
	}*/
	if (animationStartFrame == -1) {
		animationStartFrame = tick;
	}

	int progress = tick - animationStartFrame;

	switch (numberOfTheCoordinateAxis) {
	case 0: {
		for (int i = side; i <= side; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					cubes[i][j][k].animationAngleRotate.x += direction * (1) / 100.0 * animationSpeed;
				}
			}
		}
		break;
	}
	case 1: {
		for (int i = 0; i < 3; i++) {
			for (int j = side; j <= side; j++) {
				for (int k = 0; k < 3; k++) {
					cubes[i][j][k].animationAngleRotate.y += direction * (1) / 100.0 * animationSpeed;
				}
			}
		}
		break;
	}
	case 2: {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = side; k <= side; k++) {
					cubes[i][j][k].animationAngleRotate.z += direction * (1) / 100.0 * animationSpeed;
				}
			}
		}
		break;
	}
	default: {
		std::cout << "Error\n";
		exit(1);
		break;
	}
	}


	if (progress >= 100 / animationSpeed) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					cubes[i][j][k].animationAngleRotate = Coords(0, 0, 0);
				}
			}
		}
		animationEnded = true;
		animationActive = false;
		faceRotate(numberOfTheCoordinateAxis, side, direction); // выключение animationActive;
		animationStartFrame = -1;
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
				cubes[i][j][k].position = Coords(i - 1, j - 1, k - 1);
				cubes[i][j][k].display();
				//glRotatef(-10, 0, 0, 0);
				//glRotatef(270, cubes[i][j][k].angleRotate.x, cubes[i][j][k].angleRotate.y, cubes[i][j][k].angleRotate.z);
				glPopMatrix();
			}
		}
	}
}

void RubiksCube3x3x3::update(int totalFPS)
{
	std::cout << animationActive << " " << animationEnded << "\n";
	if (animationActive) {
		smoothRotation(currentRotationFaceData.x, currentRotationFaceData.y, currentRotationFaceData.z, totalFPS);
	}
}


void RubiksCube3x3x3::faceRotate(int numberOfTheCoordinateAxis, int side, int direction)
{
	if (animationActive) {
		return;
	}
	
	std::cout << "rotated!!!\n";
	currentRotationFaceData = Coords(numberOfTheCoordinateAxis, side, direction);
	animationActive = true;
	if (animationEnded) {

		//animationActive = true;

		switch (numberOfTheCoordinateAxis) {
		case 0: {
			
			for (int i = side; i <= side; i++) {
				std::vector<std::vector<SmallCube>> faceAfterRotate(3, std::vector<SmallCube>(3));
				for (int k = 2; k >= 0; k--) {
					for (int j = 0; j < 3; j++) {
						if (direction == -1) {
							faceAfterRotate[j][k] = cubes[i][2 - k][j];
						}
						else {
							faceAfterRotate[j][k] = cubes[i][k][2 - j];
						}
						faceAfterRotate[j][k].rotate(Coords(direction, 0, 0));
					}
				}
				
				cubes[i] = faceAfterRotate;
			}
			break;
		}
		case 1: {
			std::vector<std::vector<SmallCube>> faceAfterRotate(3, std::vector<SmallCube>(3));
			for (int i = 0; i < 3; i++) {
				for (int j = side; j <= side; j++) {
					for (int k = 0; k < 3; k++) {
						if (direction == 1) {
							faceAfterRotate[i][k] = cubes[2 - k][j][i];
						}
						else {
							faceAfterRotate[i][k] = cubes[k][j][2 - i];
						}
						faceAfterRotate[i][k].rotate(Coords(0, direction, 0));
					}
				}
			}
			for (int i = 0; i < 3; i++) {
				for (int j = side; j <= side; j++) {
					for (int k = 0; k < 3; k++) {
						cubes[i][j][k] = faceAfterRotate[i][k];
					}
				}
			}
			break;
		}
		case 2: {
			std::vector<std::vector<SmallCube>> faceAfterRotate(3, std::vector<SmallCube>(3));
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					for (int k = side; k <= side; k++) {
						if (direction == 1) {
							faceAfterRotate[i][j] = cubes[2 - j][i][k];
						}
						else {
							faceAfterRotate[i][j] = cubes[j][2 - i][k];
						}
						faceAfterRotate[i][j].rotate(Coords(0, 0, direction));
					}
				}
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					for (int k = side; k <= side; k++) {
						cubes[i][j][k] = faceAfterRotate[i][j];
					}
				}
			}
			break;
		}
		default: {
			std::cout << "incorrect numberOfTheCoordinateAxis, in  void RubiksCube3x3x3::faceRotate\n";
			exit(1);
			break;
		}
		}


		animationEnded = false;
		animationActive = false;
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
				
				cubes[i][j][k] = SmallCube(0.3, (float)i - 1, (float)j - 1, (float)k - 1, colors);
			}
		}
	}
}
