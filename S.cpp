#include "S.h"

SPiece::SPiece(float xPos, float yPos, float zPos, float cubeSideLength, int rotation) : Tetramino(xPos, yPos, zPos, cubeSideLength, rotation) {
	color1 = 0.753f;
	color2 = 0.392f;
	color3 = 0.941f;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++) {
				matrix[i][j][k] = 0;
			}
	matrix[2][2][2] = 2;
	matrix[1][2][2] = 1;
	matrix[2][3][2] = 1;
	matrix[3][3][2] = 1;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++) {
				initialMatrix[i][j][k] = matrix[i][j][k];
			}
}