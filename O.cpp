#include "O.h"

OPiece::OPiece(float xPos, float yPos, float zPos, float cubeSideLength, int rotation) : Tetramino(xPos, yPos, zPos, cubeSideLength, rotation) {
	color1 = 0.969f;
	color2 = 0.949f;
	color3 = 0.549f;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++) {
				matrix[i][j][k] = 0;
			}
	matrix[2][2][2] = 2;
	matrix[2][3][2] = 1;
	matrix[3][2][2] = 1;
	matrix[3][3][2] = 1;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++) {
				initialMatrix[i][j][k] = matrix[i][j][k];
			}
}

