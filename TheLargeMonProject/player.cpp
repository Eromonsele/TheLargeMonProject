#include "stdafx.h"
#include "player.h"


// constructor
Player::Player(const string &lname) : name(lname), largemon("", "", "", "", 0, 0)
{
	//empty body
}// end LargeMon constructor

// set player name
void Player::setName(const string &lname)
{
	name = lname;
}// end function

// return player name
string Player::getName() const
{
	return name;  
}// end function

// return player wins
int Player::getWins() const
{
	return wins;
}// end function

// return player losses
int Player::getLosses() const
{
	return losses;
}// end function

// return player points
int Player::getPoints() const
{
	return points;
}// end function

// return games player played
int Player::getGamesPlayed() const
{
	return gamesPlayed;
}// end function

// return player largemon
LargeMon Player::getPlayerLargeMon() const
{
	return largemon;
}// end function

// return player largemon healthpoints 
int Player::getLargeMonHealthPoints() const
{
	return largemon.getHealthPoints();
}// end function

// return player largemon attack points
int Player::getLargeMonAttackpoints() const
{
	return largemon.getAttackPoints();
}// end function

// return player largemon name
string Player::getLargeMonName() const
{
	return largemon.getName();
}// end function

// return player largemon size
string Player::getLargeMonSize() const
{
	return largemon.getSize();
}// end function

// return player largemon type
string Player::getLargeMonType() const
{
	return largemon.getType();
}// end function

// return player largemon weakness
vector<string> Player::getLargeMonWeakness() const
{
	return largemon.getLWeakness();
}// end function

// set player largemon
void Player::setPlayerLargeMon(LargeMon laremon)
{
		
	largemon = laremon;
}// end function

// set player largemon healthpoints
void Player::setLargeMonHealthPoints(int hP)
{
	largemon.setHealthPoints(hP);
}// end function

// set player largemon attackpoints
void Player::setLargeMonAttackPoints(int aP)
{
	largemon.setAttackPoints(aP);
}// end function

// simulates the singelgame
void Player::singleGame(int playerHp, int comHp)
{
	gamesPlayed++;// increase games played
	if (playerHp > comHp)// if player health points is greater than its opponent
	{
		wins++;// increase wins
		points += 3;// increase total points by 3
	}
	else
	{
		losses++;// increase losses
	}
}// end function

