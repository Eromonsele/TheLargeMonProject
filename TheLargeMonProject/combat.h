#pragma once

#include <string>
#include <iostream>
#include "player.h"

class Combat
{
public:
	
	/**
	 * \brief 
	 */
	Combat();
	
	void simple_attack(Player &, bool, Player &);// Simple Attack
	void special_attack(Player &, bool, Player &);// Special Attack
	void defend(bool, Player& );// Defend function	
	void combat_log(const string&) const;// print to combat log	
	void init_combat(const Player&);// init combat session

	bool get_turn() const;// get turn
	void set_turn(bool);// set players turn

	void com_actions(Player &, Player &);// AI actions

private:
	bool humanturn_{};	
	int action_counters_ = 0;
	int simple_human_counter_ = 0; 
	int com_simple_counter_ = 0;
};

