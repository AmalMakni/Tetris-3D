#ifndef TETRAMINO_H_INCLUDED
#define TETRAMINO_H_INCLUDED
#pragma once

#include <GLFW/glfw3.h>
#include <iostream>
#include "ElemCube.h"

class Tetramino {
protected:
	GLfloat color1;
	GLfloat color2;
	GLfloat color3;
	int matrix[5][5][5];
	int initialMatrix[5][5][5];
	float xPos;
	float yPos;
	float zPos;
	float cubeSideLength;
	int rotation;
	float initX;
	float initY;
	float initZ;
	int initRotation;
public:
	Tetramino(float xPos, float yPos, float zPos, float cubeSideLength, int rotation) : xPos(xPos), yPos(yPos), zPos(zPos), cubeSideLength(cubeSideLength), rotation(rotation) {};
	Tetramino() {};
	virtual int getPieceType() =0;
	virtual void draw();
	float getXPos() { return xPos; };
	float getYPos() { return yPos; };
	float getZPos() { return zPos; };
	GLfloat getColorR() { return color1; }
	GLfloat getColorG() { return color2; }
	GLfloat getColorB() { return color3; }
	int getBlockType(int i, int j, int k) { return matrix[i][j][k]; }
	void moveDown(float y) { yPos -= y; };
	void moveRight(float x) { xPos += x; };
	void moveLeft(float x) { xPos -= x; };
	void moveForward(float z) { zPos += z; };
	void moveBackward(float z) { zPos -= z; };
	virtual void setRotation(int r);
	virtual ~Tetramino() {};

};

#endif // TETRAMINO_H_INCLUDED
