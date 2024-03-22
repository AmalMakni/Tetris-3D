#pragma once
#include "Tetramino.h"

class LongPiece : public Tetramino
{
public:
	LongPiece(float xPos, float yPos, float zPos, float cubeSideLength, int rotation);
	~LongPiece() {};
	int getPieceType() { return 1; };
};
