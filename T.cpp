#include "T.h"

TPiece::TPiece(float xPos, float yPos, float zPos, float cubeSideLength, int rotation) : Tetramino(xPos, yPos, zPos, cubeSideLength, rotation) {
	color1 = 0.969f;
	color2 = 0.549f;
	color3 = 0.816f;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++) {
				if (i == 2 && k == 2 && 0 < j && j < 4) {
					if (j == 2)
						matrix[i][j][k] = 2;
					else
						matrix[i][j][k] = 1;
				}
				else
					matrix[i][j][k] = 0;
			}
	matrix[3][2][2] = 1;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++) {
				initialMatrix[i][j][k] = matrix[i][j][k];
			}
}