#include "L.h"


LPiece::LPiece(float xPos, float yPos, float zPos, float cubeSideLength, int rotation) : Tetramino(xPos, yPos, zPos, cubeSideLength, rotation) {
	color1 = 0.549;
	color2 = 0.969;
	color3 = 0.929;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++) {
				matrix[i][j][k] = 0;
			}
	matrix[2][2][2] = 2;
	matrix[1][3][2] = 1;
	matrix[2][1][2] = 1;
	matrix[2][3][2] = 1;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++) {
				initialMatrix[i][j][k] = matrix[i][j][k];
			}
}