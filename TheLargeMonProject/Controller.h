#pragma once
#include "LargeMonGenerator.h"
#include "player.h"
#include "combat.h"

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
	int check_game_status(Player &, Player & ) const;// check the game status
	void game_session(Player & , Player & );
	void display_health_points(Player & , Player & ) const;// Display the health points
	void assign_largemon_to_player(Player &, Player &);// Assign Largemon to a player
	void display_largemon_attributes(Player &) const;// Display Largemon Attributes
	Combat session;
	LargeMonGenerator lh;	
};


