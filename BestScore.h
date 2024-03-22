#pragma once
#include <string>
using namespace std;

class BestScore
{
public:
	//void doParty(void);
	BestScore(void);
	BestScore(string wname, int score, string timeDate="");
	string name(void);
	int score(void);
	string time(void);

private:
	string WDateTime;
	string WName;
	int WScore;
};

