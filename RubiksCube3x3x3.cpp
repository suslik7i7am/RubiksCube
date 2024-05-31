#include "RubiksCube3x3x3.h"

std::vector<std::vector<std::vector<bool>>> RubiksCube3x3x3::generateInPlace()
{
	
	std::vector<std::vector<std::vector<bool>>> ans(3, std::vector<std::vector<bool>>(3, std::vector<bool>(3, false)));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (colorsInPlaces[i][j][k] == cubes[i][j][k].includedColors && 
					cubes[i][j][k].faceNormal[0] == Coords(1, 0, 0) && cubes[i][j][k].faceNormal[1] == Coords(0, 1, 0) && cubes[i][j][k].faceNormal[2] == Coords(0, 0, 1)) {
					ans[i][j][k] = true;
				}
			}
		}
	}
	return ans;
}

void RubiksCube3x3x3::optimization()
{
	bool upd = true;
	while (upd) {
		upd = false;
		for (int i = 0; i < commandStack.size() - 3; i++) {
			
			if (commandStack.size() >= 4) {
				if (commandStack[i] == commandStack[i + 1] && commandStack[i + 1] == commandStack[i + 2]
					&& commandStack[i + 2] == commandStack[i + 3]) {
					commandStack.erase(commandStack.begin() + i, commandStack.begin() + i + 4);

					upd = true;

				}
			}
			else {
				break;
			}
		}
	}
	
	upd = true;
	while (upd) {
		upd = false;
		for (int i = 0; i < commandStack.size() - 1; i++) {
			if (commandStack.size() >= 2) {
				if (commandStack[i].x == commandStack[i + 1].x && commandStack[i].y == commandStack[i + 1].y
					&& commandStack[i].z == -commandStack[i + 1].z) {
					commandStack.erase(commandStack.begin() + i, commandStack.begin() + i + 2);
					upd = true;
					
				}
			}
			else {
				upd = false;
				break;
			}
		}
	}
	//return;
	//std::cout << "aaaa\n";
	upd = true;
	while (upd) {
		upd = false;
		for (int i = 0; i < commandStack.size() - 2; i++) {
			if (commandStack.size() >= 3) {
				if (commandStack[i] == commandStack[i + 1] && commandStack[i + 1] == commandStack[i + 2]) {
					commandStack[i + 2].z *= -1;
					commandStack.erase(commandStack.begin() + i, commandStack.begin() + i + 2);
					
					upd = true;
					
				}
			}
			else {
				break;
			}
		}
	}
	//std::cout << "optimized\n";
}

SmallCube RubiksCube3x3x3::getSmallCube(int i, int j, int k)
{
	return cubes[i][j][k];
}

void RubiksCube3x3x3::solve()
{
	if (!buildingActive) {
		system("cls");
		optimization();
		buildingActive = true;
		if (random && buildingActive) {
			animationSpeed = 50;
		}
		else {
			animationSpeed = 10;
		}
	}
}

void RubiksCube3x3x3::randomCondition()
{
	if (!animationActive && !buildingActive) {
		for (int i = 0; i < 100; i++) {
			Coords move(rand() % 3, rand() % 2 * 2, rand() % 2 * 2 - 1);
			commandStackForRandomCondition.push_back(move);
		}
		randomBuildingActive = true;
		random = true;
	}
}

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
					cubes[i][j][k].animationAngleRotate.z -= direction * (1) / 100.0 * animationSpeed;
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
	if (buildingActive) {
		if (commandStack.size() <= 0) {
			animationSpeed = 10;
			random = false;
		}
		
	}
	else {
		animationSpeed = 10;
	}
	if (animationActive) {
		smoothRotation(currentRotationFaceData.x, currentRotationFaceData.y, currentRotationFaceData.z, totalFPS);
	}
	if (!animationActive && !animationEnded) {
		if (buildingActive) {
			if (commandStack.empty()) {
				buildingActive = false;
			}
			else {
				
				faceRotate(commandStack.back().x, commandStack.back().y, -commandStack.back().z);
				commandStack.pop_back();
			}
		}
		if (randomBuildingActive) {
			if (commandStackForRandomCondition.empty()) {
				randomBuildingActive = false;
			}
			else {
				faceRotate(commandStackForRandomCondition.back().x, commandStackForRandomCondition.back().y, -commandStackForRandomCondition.back().z);
				commandStackForRandomCondition.pop_back();
			}
		}
	}
}


void RubiksCube3x3x3::faceRotate(int numberOfTheCoordinateAxis, int side, int direction)
{

	if (animationActive) {
		return;
	}
	if (buildingActive && !animationEnded) {
		std::cout << "turne the ";
			switch (numberOfTheCoordinateAxis)
			{
			case 0: {
				std::cout << (side == 0 ? "GREEN" : "BLUE");
				break;
			};
			case 1: {
				std::cout << (side == 0 ? "ORANGE" : "RED");
				break; 
			};
			case 2: {
				std::cout << (side == 0 ? "WHITE" : "YELLOW");
				break; 
			};
			default:
				break;

			};
		std::cout << " face " << (direction == 1 ? "clockwise" : "counterclockwise") << "\n";

	}
	if (!buildingActive && !animationEnded) {
		commandStack.push_back(Coords(numberOfTheCoordinateAxis, side, direction));
	}

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
						faceAfterRotate[i][j].rotate(Coords(0, 0, -direction));
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
	colorsInPlaces = std::vector<std::vector<std::vector<std::string>>>(3, std::vector<std::vector<std::string>>(3, std::vector<std::string>(3)));

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
				colorsInPlaces[i][j][k] = colors;
			}
		}
	}
	inPlace = std::vector<std::vector<std::vector<bool>>>(3, std::vector<std::vector<bool>>(3, std::vector<bool>(3)));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				inPlace[i][j][k] = true;
			}
		}
	}

		
}
