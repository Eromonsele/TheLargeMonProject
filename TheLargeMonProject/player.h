#pragma once
#include <iostream>
#include "LargeMonGenerator.h"
#include "largeMon.h"
using namespace std;

class player
{
public:
	player(const string &);	

	void setName(const string &);
	string getName() const;

	int getWins() const;
	int getLosses() const;	
	int getPoints() const;
	int getGamesPlayed() const;
	LargeMon getPlayerLargeMon() const;

	void setPlayerLargeMon(LargeMon );

	void singleGame(int , int );	
	
private:
	string name;
	int wins = 0;
	int losses = 0;	
	int points = 0;
	int gamesPlayed = 0;	
	LargeMon largemon;
};

