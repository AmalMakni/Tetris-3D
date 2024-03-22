#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED


#pragma once
#include"Tetramino.h"

const int B_WIDTH = 4;
const int B_HIGHT = 10;
const int B_DEPTH = 4;

class Grid {
private:
	float xPosCenter;
	float yPosCenter;
	float zPosCenter;
	float gridSpacing;
	
	int matrix[B_HIGHT][B_WIDTH][B_DEPTH];
	void upDatescore(int);
public:
	Grid(float x, float y, float z, float gridSpacing = 100);
	void draw();
	void drawBlocks();
	bool isMovementPossibe(Tetramino T, float xMvt, float yMvt, float zMvt);
	bool isRotationPossible(Tetramino T, int r);
	bool isGameOver();
	void storePiece(Tetramino t, int);
	int deletePlane(void);
	int score;
	int level;
	int getScore() { return score; };
	int getLevel() { return level; };
	void setLevel(int l) { level = l; };
};
#endif // GRID_H_INCLUDED