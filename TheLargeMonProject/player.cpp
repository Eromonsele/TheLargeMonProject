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

void player::setPlayerLargeMon(LargeMon laremon)
{
		
	largemon = laremon;
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

