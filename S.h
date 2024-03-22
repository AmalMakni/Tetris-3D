#pragma once
#include "Tetramino.h"

class SPiece : public Tetramino {
public:
	SPiece(float xPos, float yPos, float zPos, float cubeSideLength, int rotation);
	~SPiece() {};
	int getPieceType() { return 4; };
};

