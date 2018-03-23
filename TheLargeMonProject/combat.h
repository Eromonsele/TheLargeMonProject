#pragma once

#include "largeMon.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <stdio.h>
#include "player.h"
class combat
{
public:
	
	combat();
	
	void simpleAttack(Player &, bool, Player &);
	void specialAttack(Player &, bool, Player &);
	void defend(bool, Player& );	
	void combatLog(string );
	void initCombat(Player);

	bool getTurn() const;
	void setTurn(bool);

	void comActions(Player &, Player &);

private:
	bool humanturn;	
	int actionCounters = 0;
	int simpleHumanCounter = 0; 
	int comSimpleCounter = 0;
};

