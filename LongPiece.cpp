#include "LongPiece.h"
#include "ElemCube.h"
#include <GLFW/glfw3.h>
#include <iostream>

LongPiece::LongPiece(float xPos, float yPos, float zPos, float cubeSideLength, int rotation) : Tetramino(xPos, yPos, zPos, cubeSideLength, rotation) {
	color1 = 0.647f;
	color2 = 0.941f;
	color3 = 0.392f;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++) {
				if (j < 4 && k == 2 && i == 2) {
					if (i == 2)
						matrix[i][j][k] = 2;
					else
						matrix[i][j][k] = 1;
				}
				else
					matrix[i][j][k] = 0;
			}
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++) {
				initialMatrix[i][j][k] = matrix[i][j][k];
			}

}