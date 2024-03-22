#ifndef PODIUM_H_INCLUDED
#define PODIUM_H_INCLUDED
#include "PodiumUI.h"

#include "BestScore.h"

using namespace std;

#define MAX_SCORE 3

class Podium
{
private :
	BestScore bScores[MAX_SCORE];
	int nbScores=0;
	void savePodium();
public :
	Podium(void);
	void render(void);
	bool isPodiumScore(int bs);
	void addPodium(BestScore bs);
};
#endif // PODIUM_H_INCLUDED
