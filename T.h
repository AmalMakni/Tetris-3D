#pragma once
#include "Tetramino.h"
class TPiece : public Tetramino {
public:
	TPiece(float xPos, float yPos, float zPos, float cubeSideLength, int rotation);
	~TPiece() {};
	int getPieceType() { return 3; };
};