#pragma once
#include "largeMon.h"
#include "LargeMonGenerator.h"
#include "player.h"
#include "combat.h"
#include <fstream>

/*
The Controller

Author: Eromosele Okhilua
Version:
*/
class Controller
{
public:
	Controller();
	~Controller();
	int checkGameStatus(Player &, Player & );// check the game status
	void gameSession(Player & , Player & );
	void displayHealthPoints(Player & , Player & );// Display the health points
	void assignLargemonToPlayer(Player &, Player &);
	void displayLargemonAttributes(Player &);
	Combat session;
};

