#include "stdafx.h"
#include "combat.h"
#include <time.h>


combat::combat()
{
		
}


void combat::simpleAttack(player &com,bool humanTurn , player &player1)
{
	for (auto const& x : com.getLargeMonWeakness())
	{
		if (com.getLargeMonType() == x) 
		{
			com.setLargeMonHealthPoints(com.getLargeMonHealthPoints() - (player1.getLargeMonAttackpoints()/2));
			break;
		}
		else
		{
			com.setLargeMonHealthPoints(com.getLargeMonHealthPoints() - player1.getLargeMonAttackpoints());
			break;
		}
	}
	//com.setLargeMonHealthPoints(com.getLargeMonHealthPoints() - player1.getLargeMonAttackpoints());
	actionCounters++;
	if (humanTurn == true) {		
		combatLog("\n" + player1.getName() + " performed a simple attack. COM Health Points now: " + to_string(com.getLargeMonHealthPoints()));		
		setTurn(false);
		simpleHumanCounter++;
	}
	else{
		combatLog("\nCOM performed a basic attack." + player1.getName() + " Health Points now: " + to_string(player1.getLargeMonHealthPoints()));
		setTurn(true);
		comSimpleCounter++;
	}
	
}

void combat::specialAttack(LargeMon largemon, bool humanTurn, player player1)
{
	int attackPoints = largemon.getAttackPoints();
	actionCounters++;
	if (humanTurn == true)
	{
		combatLog("\n" + player1.getName() + " performed special attack. COM Health Points now: " + to_string(largemon.getHealthPoints()));
		setTurn(false);
		simpleHumanCounter= 0;
	}
	else
	{
		combatLog("\nCOM used defend." + player1.getName() + " Health Points now: " + to_string(largemon.getHealthPoints()));
		setTurn(true);
		comSimpleCounter = 0;
	}
}

void combat::defend(bool humanTurn, player &player1)
{
	int i = player1.getLargeMonHealthPoints() + 3;
	player1.setLargeMonHealthPoints(i);
	actionCounters++;
	if (humanTurn == true) 
	{
		combatLog("\n" + player1.getName() + " performed defend.Health Points now: " + to_string(player1.getLargeMonHealthPoints()));
		setTurn(false);
		simpleHumanCounter++;
	}
	else
	{
		combatLog("\nCOM used defend. Health Points now:" + to_string(player1.getLargeMonHealthPoints()));
		setTurn(true);
		comSimpleCounter++;
	}
}

void combat::combatLog(string action)
{
	ofstream outFile("combatLog.txt", ios::app);
	if (!outFile)
	{
		cerr << "File not opened" << endl;
		exit(1);
	}
	outFile << action;
}

void combat::initCombat(player player1)
{
	time_t result = time(NULL);	
	char dr[26];
	ctime_s(dr,sizeof dr,&result);
	combatLog("\nsession started on");
	string stuff = &dr[0];
	combatLog("\nDate and time of game: " + stuff);
	combatLog("Human Player Name : " + player1.getName());
	combatLog("\nLargemon used : " + player1.getLargeMonName());
	combatLog("\nEvents:");
}


bool combat::getTurn() const
{
	return humanturn;
}

void combat::setTurn(bool a)
{
	humanturn = a;
}

void combat::comActions(player com, player human)
{
	switch (rand() % 2)
	{
	case 0:
		//simpleAttack(human, false, com);
		break;
	case 1:
		defend( false, com);
		break;
	case 2:
		if (comSimpleCounter >= 5)
		{
			specialAttack(human.getPlayerLargeMon(), false, com);
			break;
		}
		else {
			break;
		}		
	default:
		//simpleAttack(human, false, com);
		break;
	}
}
