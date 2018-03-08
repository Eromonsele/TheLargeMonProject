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
	
	void simpleAttack(player &, bool, player &);
	void specialAttack(LargeMon , bool, player);
	void defend(bool, player );	
	void combatLog(string );
	void initCombat(player);

	bool getTurn() const;
	void setTurn(bool);

	void comActions(player, player);

private:
	bool humanturn;	
	int actionCounters = 0;
	int simpleHumanCounter = 0; 
	int comSimpleCounter = 0;
};

