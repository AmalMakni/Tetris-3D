#include "Tetramino.h"
#include "ElemCube.h"
#include <GLFW/glfw3.h>

void Tetramino::draw() {
	for (int i = -2; i < 3; i++)
		for (int j = -2; j < 3; j++)
			for (int k = -2; k < 3; k++) {
				if (matrix[i + 2][j + 2][k + 2] != 0) {
					ElemCube::drawCube(xPos + j * cubeSideLength, yPos + i * cubeSideLength, zPos + k * cubeSideLength, cubeSideLength, color1, color2, color3);
				}
				/*if (rotation == 1)
					std::cout << i+2<<":"<<j+2<<":"<<k +2<<" " << matrix[i+2][j+2][k+2]<<std::endl;*/

			}


}

void Tetramino::setRotation(int r) {
	rotation = r;
	int temp = 0;
	if (r == 0) {
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				for (int k = 0; k < 5; k++) {
					matrix[i][j][k] = initialMatrix[i][j][k];
				}
	}
	else if (r < 4) {
		for (int i = 0; i < 5; i++)
			for (int j = i + 1; j < 5; j++)
				for (int k = 0; k < 5; k++)
				{

					temp = matrix[i][j][k];
					matrix[i][j][k] = matrix[j][i][k];
					matrix[j][i][k] = temp;
				}
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 5; j++)
				for (int k = 0; k < 5; k++)

				{
					temp = matrix[i][j][k];
					matrix[i][j][k] = matrix[4 - i][j][k];
					matrix[4 - i][j][k] = temp;
				}
	}
	else if (r < 8) {
		for (int k = 0; k < 5; k++)
			for (int i = 0; i < 5; i++)
				for (int j = i + 1; j < 5; j++)
				{

					temp = matrix[k][i][j];
					matrix[k][i][j] = matrix[k][j][i];
					matrix[k][j][i] = temp;
				}
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 5; j++)
				for (int k = 0; k < 5; k++)

				{
					temp = matrix[j][k][i];
					matrix[j][k][i] = matrix[j][k][4 - i];
					matrix[j][k][4 - i] = temp;
				}
	}
	else if (r == 8 || r == 12) {
		for (int j = 0; j < 5; j++)
			for (int i = 0; i < 5; i++)
				for (int k = i + 1; k < 5; k++)
				{

					temp = matrix[i][j][k];
					matrix[i][j][k] = matrix[k][j][i];
					matrix[k][j][i] = temp;
				}
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 5; j++)
				for (int k = 0; k < 5; k++)

				{
					temp = matrix[j][k][i];
					matrix[j][k][i] = matrix[j][k][4 - i];
					matrix[j][k][4 - i] = temp;
				}
	}
	else if (r < 12 && 8 < r || r < 16 && r>12 || r > 16 && r < 20) {
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				for (int k = j + 1; k < 5; k++)
				{

					temp = matrix[i][j][k];
					matrix[i][j][k] = matrix[i][k][j];
					matrix[i][k][j] = temp;
				}
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 5; j++)
				for (int k = 0; k < 5; k++)

				{
					temp = matrix[k][i][j];
					matrix[k][i][j] = matrix[k][4 - i][j];
					matrix[k][4 - i][j] = temp;
				}
	}
	else if (r == 16) {
		for (int j = 0; j < 5; j++)
			for (int i = 0; i < 5; i++)
				for (int k = i + 1; k < 5; k++)
				{

					temp = matrix[i][j][k];
					matrix[i][j][k] = matrix[k][j][i];
					matrix[k][j][i] = temp;
				}
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 5; j++)
				for (int k = 0; k < 5; k++)

				{
					temp = matrix[i][k][j];
					matrix[i][k][j] = matrix[4 - i][k][j];
					matrix[4 - i][k][j] = temp;
				}

	}
}

