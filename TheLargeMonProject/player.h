#pragma once
#include <iostream>
#include "largeMon.h"
using namespace std;
/**
*The user player object
* Author: Eromosele Okhilua
*
*/
class Player
{
public:
	Player(const string &);	

	void setName(const string &);// set Player name
	string getName() const; // get player name

	int getWins() const; // get Player Wins
	int getLosses() const;	// get Player Losses
	int getPoints() const; // get Player Points
	int getGamesPlayed() const;// get Games Player played

	void setPlayerLargeMon(LargeMon);//set player largemon
	LargeMon getPlayerLargeMon() const;// get Player largemon

	void setLargeMonHealthPoints(int);// set largemon health points
	int getLargeMonHealthPoints() const;// get player largemon health points

	void setLargeMonAttackPoints(int);// set player largemon attack points
	int getLargeMonAttackpoints() const;// get player largemon attack points

	string getLargeMonName() const; // get player largemon name
	string getLargeMonSize() const; // get player largemon size
	string getLargeMonType() const; // get player largemon type
	vector<string> getLargeMonWeakness() const; // get player largemon weakness	

	void singleGame(int , int );// simulates a single game
	
	
private:
	string name;
	int wins = 0;
	int losses = 0;	
	int points = 0;
	int gamesPlayed = 0;	
	LargeMon largemon;
};

