#pragma once
#include "Tetramino.h"
class LPiece : public Tetramino {
public:
	LPiece(float xPos, float yPos, float zPos, float cubeSideLength, int rotation);
	~LPiece() {};
	int getPieceType() { return 2; };
};


