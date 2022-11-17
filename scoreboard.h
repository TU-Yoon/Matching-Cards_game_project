#pragma once
#include <iostream>

class Score {
public:
	int score = 0;
	string name;
};
void saveScore(int score);
void compareScore(int score);
void scoreBoard();