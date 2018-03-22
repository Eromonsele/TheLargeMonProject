#include "stdafx.h"
#include "player.h"



player::player(const string &lname) : name(lname), largemon("", "", "", "", 0, 0)
{

}

void player::setName(const string &lname)
{
	name = lname;
}

string player::getName() const
{
	return name;
}

int player::getWins() const
{
	return wins;
}

int player::getLosses() const
{
	return losses;
}

int player::getPoints() const
{
	return points;
}

int player::getGamesPlayed() const
{
	return gamesPlayed;
}

LargeMon player::getPlayerLargeMon() const
{
	return largemon;
}

int player::getLargeMonHealthPoints() const
{
	return largemon.getHealthPoints();
}

int player::getLargeMonAttackpoints() const
{
	return largemon.getAttackPoints();
}

string player::getLargeMonName() const
{
	return largemon.getName();
}

string player::getLargeMonSize() const
{
	return largemon.getSize();
}

string player::getLargeMonType() const
{
	return largemon.getType();
}

vector<string> player::getLargeMonWeakness() const
{
	return largemon.getLWeakness();
}

void player::setPlayerLargeMon(LargeMon laremon)
{
		
	largemon = laremon;
}

void player::setLargeMonHealthPoints(int hP)
{
	largemon.setHealthPoints(hP);
}

void player::setLargeMonAttackPoints(int aP)
{
	largemon.setAttackPoints(aP);
}


void player::singleGame(int playerHp, int comHp)
{
	gamesPlayed++;
	if (playerHp > comHp)
	{
		wins++;
		points += 3;
	}
	else
	{
		losses++;
	}
}

