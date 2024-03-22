#include "BestScore.h"

#include <string>
#include <iostream>
#include <fstream>
using namespace std;
#include <chrono>

void timeNow(std::string* tn);


BestScore::BestScore(void)
{
}

BestScore::BestScore(string wname, int score, string timeDate)
{
	WName = wname;
	WScore = score;
    if (timeDate == "")    timeNow(&timeDate);
    WDateTime = timeDate;
}

string BestScore::name(void)
{
	return string(WName);
}

int BestScore::score(void)
{
	return WScore;
}

string BestScore::time(void)
{
	return string(WDateTime);
}

//Lire l'heure et la adte systeme
void timeNow(std::string* tn) {
    auto start = std::chrono::system_clock::now();
    auto legacyStart = std::chrono::system_clock::to_time_t(start);
    char tmBuff[50];
    ctime_s(tmBuff, sizeof(tmBuff), &legacyStart);
    //Enlever retour chario
    int i = 0;
    while (i < 50) {
        if (tmBuff[i] == '\n')
            tmBuff[i] = '\0';
        i++;
    }
    //Fin Enlever retour chario
    std::string s = tmBuff;
    *tn = s;
}
