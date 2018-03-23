#include "stdafx.h"
#include "combat.h"
#include <time.h>


combat::combat()
{
		
}

/*
Simple attack : this reduces the health points of the other Largemon by the amount of
“attack points” of the attacker.
*/
void combat::simpleAttack(Player &com,bool humanTurn , Player &player1)
{
	for (auto const& x : com.getLargeMonWeakness())// go through the largemon's weaknesses
	{
		if (com.getLargeMonType() == x) // if opponent's largemon type matches player's laremon weakness
		{
			// attack will have reduced by half
			com.setLargeMonHealthPoints(com.getLargeMonHealthPoints() - (player1.getLargeMonAttackpoints()/2));
			break;
		}
		else
		{
			// attack
			com.setLargeMonHealthPoints(com.getLargeMonHealthPoints() - player1.getLargeMonAttackpoints());
			break;
		}
	}	
	actionCounters++;
	if (humanTurn == true) {// if it is the human turn
		combatLog("\n" + player1.getName() + " performed a simple attack. COM Health Points now: " + to_string(com.getLargeMonHealthPoints()));	// add to the combat log	
		setTurn(false);// change turn to AI
		simpleHumanCounter++;
	}
	else{
		combatLog("\nCOM performed a basic attack." + player1.getName() + " Health Points now: " + to_string(player1.getLargeMonHealthPoints()));
		setTurn(true);
		comSimpleCounter++;
	}
	
}
/*
Special attack: this is an attack that can be used only on Largemons of the antagonist
type. For instance, a Water Largemon can use a special attack only against a Fire
Largemon. The special attack can be used only once per combat, and reduces the heal
points of the attacked by twice the attack points of the attacker.
*/
void combat::specialAttack(Player &com, bool humanTurn, Player &player1)
{
	for (auto const& x : com.getLargeMonWeakness())// go through the largemon's weaknesses
	{
		if (player1.getLargeMonType() == x) // if opponent's largemon type matches player's laremon weakness
		{
			//attack will have reduced by half
			com.setLargeMonHealthPoints(com.getLargeMonHealthPoints() - ((player1.getLargeMonAttackpoints() * 2)));
			break;
		}		
	}
	
	if (humanTurn == true)// if it is the human turn
	{
		combatLog("\n" + player1.getName() + " performed special attack. COM Health Points now: " + to_string(com.getLargeMonHealthPoints()));// add to the combat log
		setTurn(false);// change turn to AI
		simpleHumanCounter= 0;
	}
	else
	{
		combatLog("\nCOM used defend." + player1.getName() + " Health Points now: " + to_string(player1.getLargeMonHealthPoints()));
		setTurn(true);
		comSimpleCounter = 0;
	}
}
/*
Defend: a Largemon recovers a small amount of its health points.
*/
void combat::defend(bool humanTurn, Player &player1)
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
//write each session to the combat log
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
// initialize combat session
void combat::initCombat(Player player1)
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

// returns true or false if it is the humans turn
bool combat::getTurn() const
{
	return humanturn;
}
// sets humanturn
void combat::setTurn(bool a)
{
	humanturn = a;
}

void combat::comActions(Player &com, Player &human)
{
	switch (rand() % 2)
	{
	case 0:
		simpleAttack(human, false, com);
		break;
	case 1:
		defend( false, com);
		break;
	case 2:
		if (comSimpleCounter >= 5)
		{
			specialAttack(human, false, com);
			break;
		}
		else {
			break;
		}		
	default:
		simpleAttack(human, false, com);
		break;
	}
}
