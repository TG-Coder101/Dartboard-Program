#pragma once
#include <string>
#include "Dartboard.h"

using namespace std;

class Player
{
public:
	
	void playerthrow(Dartboard&);
	Player();
	~Player();

	string name;
	int chance;
	int score;
	int Scores_games = 0;
	int Scores_sets = 0;
	int Scores_matches = 0;

};

