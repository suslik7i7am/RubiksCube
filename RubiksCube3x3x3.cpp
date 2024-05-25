#include "RubiksCube3x3x3.h"

void RubiksCube3x3x3::smoothRotation(int numberOfTheCoordinateAxis, int side, int direction, int tick) {// ({0,1,2}, {-1,1}, {-1,1}, [0.0-1.0] )
	/*if (animationStartFrame == -1) {
		animationStartFrame = tick;
		std::cout << "=====  " << tick << "\n";
		animationActive = true;
	}*/
	//std::cout << cubes[0][0][1].animationAngleRotate.z <<"\n";
	switch (numberOfTheCoordinateAxis) {
	case 0: {
		for (int i = side; i <= side; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					cubes[i][j][k].animationAngleRotate.x += direction * (1) / 100.0;
				}
			}
			if (abs(cubes[side][0][0].animationAngleRotate.x) <= 0.001) {
				for (int j = 0; j < 3; j++) {
					for (int k = 0; k < 3; k++) {
						//cubes[side][j][k].animationAngleRotate.x = (cubes[i][j][k].animationAngleRotate.x / abs(cubes[i][j][k].animationAngleRotate.x));
						//cubes[side][j][k].angleRotate.x += cubes[i][j][k].animationAngleRotate.x;
						//cubes[side][j][k].angleRotate.y += cubes[i][j][k].animationAngleRotate.y;
						//cubes[side][j][k].angleRotate.z += cubes[i][j][k].animationAngleRotate.z;
						cubes[side][j][k].animationAngleRotate = Coords(0, 0, 0);

					}
				}
				animationActive = false;
				//std::cout << "-";
			}
		}
		break;
	}
	case 1: {
		
		for (int i = 0; i < 3; i++) {
			for (int j = side; j <= side; j++) {
				for (int k = 0; k < 3; k++) {
					cubes[i][j][k].animationAngleRotate.y += direction * (1) / 100.0;
				}
			}
			
		}
		//std::cout << cubes[0][side][0].animationAngleRotate.y << "\n";
		if (abs(cubes[0][side][0].animationAngleRotate.y) <= 0.001) {
			
			for (int i = 0; i < 3; i++) {
				for (int k = 0; k < 3; k++) {
					/*cubes[i][side][k].animationAngleRotate.y = (cubes[i][side][k].animationAngleRotate.y / abs(cubes[i][side][k].animationAngleRotate.y));
					cubes[i][side][k].angleRotate.x += cubes[i][side][k].animationAngleRotate.x;
					cubes[i][side][k].angleRotate.y += cubes[i][side][k].animationAngleRotate.y;
					cubes[i][side][k].angleRotate.z += cubes[i][side][k].animationAngleRotate.z;*/
					cubes[i][side][k].animationAngleRotate = Coords(0, 0, 0);

				}
			}
			animationActive = false;
			//std::cout << "-";
		}
		break;
	}
	case 2: {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = side; k <= side; k++) {
					cubes[i][j][k].animationAngleRotate.z += direction * (1) / 100.0;
				}
			}

		}
		//std::cout << cubes[0][side][0].animationAngleRotate.y << "\n";
		if (abs(cubes[0][0][side].animationAngleRotate.z) <= 0.001) {

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					/*cubes[i][side][k].animationAngleRotate.y = (cubes[i][side][k].animationAngleRotate.y / abs(cubes[i][side][k].animationAngleRotate.y));
					cubes[i][side][k].angleRotate.x += cubes[i][side][k].animationAngleRotate.x;
					cubes[i][side][k].angleRotate.y += cubes[i][side][k].animationAngleRotate.y;
					cubes[i][side][k].angleRotate.z += cubes[i][side][k].animationAngleRotate.z;*/
					cubes[i][j][side].animationAngleRotate = Coords(0, 0, 0);

				}
			}
			animationActive = false;
			std::cout << "-";
		}
		break;
	}
	default:{
		  std::cout << "Error\n";
		  exit(1);
		  break;
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
				//std::cout << cubes[i][j][k].angleRotate.y << " ";
				glPushMatrix();
				//std::cout << cubes[i][j][k].angleRotate.x << " " << cubes[i][j][k].angleRotate.y << " " << cubes[i][j][k].angleRotate.z << "\n";
				//glRotatef(90, 0, 1, 0);
				if (i == 0) {
					//cubes[i][j][k].angleRotate.x = 2;
					//glRotatef(180, 1, 0, 0);
					//glRotatef(90, 1, 0, 0);
				}
				cubes[i][j][k].display();
				//glRotatef(-10, 0, 0, 0);
				//glRotatef(270, cubes[i][j][k].angleRotate.x, cubes[i][j][k].angleRotate.y, cubes[i][j][k].angleRotate.z);
				glPopMatrix();
			}
			//std::cout << " ";
		}
		//std::cout << " | ";
	}
	//std::cout << "\n";
}

void RubiksCube3x3x3::faceRotate(int numberOfTheCoordinateAxis, int side, int direction) // numberOfTheCoordinateAxis{0,1,2} | side {0, 1, 2} | direction {-1, 1};
{
	//std::cout << "rotated\n";
	/*for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << cubes[0][i][j].id << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";*/
	if (!animationActive) {
		
		animationActive = true;
		currentRotationFaceData = Coords(numberOfTheCoordinateAxis, side, direction);
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
						faceAfterRotate[j][k].animationAngleRotate.x = -direction;
						faceAfterRotate[j][k].pathRotation.push_back(Coords(numberOfTheCoordinateAxis, side, direction));
						//faceAfterRotate[j][k].angleRotate.x += 1;
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
						faceAfterRotate[i][k].animationAngleRotate.y = -direction;
						faceAfterRotate[i][k].pathRotation.push_back(Coords(numberOfTheCoordinateAxis, side, direction));
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
						
						faceAfterRotate[i][j].animationAngleRotate.z = -direction;
						
						faceAfterRotate[i][j].pathRotation.push_back(Coords(numberOfTheCoordinateAxis, side, direction));
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

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					std::cout << cubes[i][j][k].rotationDirectionConverter[0] << cubes[i][j][k].rotationDirectionConverter[1] <<
						cubes[i][j][k].rotationDirectionConverter[2] << " ";
				}
				std::cout << "\n";
			}
			std::cout << "------------------------\n";
		}
		std::cout << "\n\n\n\n";

	}
	
}

void RubiksCube3x3x3::update(int totalFPS)
{
	if (animationActive) {
		smoothRotation(currentRotationFaceData.x, currentRotationFaceData.y, currentRotationFaceData.z, totalFPS);
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
				if (i + j + k == 0) {
					cubes[i][j][k] = SmallCube(0.5, (float)i - 1, (float)j - 1, (float)k - 1, "");
					cubes[i][j][k].id = 1;
				}
			}
		}
	}
}
