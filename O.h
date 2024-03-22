#pragma once
#include "Tetramino.h"

class OPiece : public Tetramino {
public:
	OPiece(float xPos, float yPos, float zPos, float cubeSideLength, int rotation);
	~OPiece() {};
	int getPieceType() { return 5; };
};
