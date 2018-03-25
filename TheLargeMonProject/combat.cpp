#include "stdafx.h"
#include "combat.h"
#include <ctime>
#include <fstream>


/*
Combat class: implements various battle functions such as simple attack, special attack and defence.
Author: Eromosele Okhilua
Student Number: u1671506
*/

/**
 * \brief 
 * constructor
 */
Combat::Combat()
{
	//empty body
} // end constructor

/**
 * \brief 
 * Simple attack : this reduces the health points of the other Largemon by the amount of 
 *					“attack points” of the attacker.
 * \param com this is opponent player
 * \param human_turn this indicates whose turn it is it
 * \param player1 this is attacking player
 */
void Combat::simple_attack(Player &com, const bool human_turn , Player &player1)
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
	action_counters_++;
	if (human_turn) {// if it is the human turn
		// print to the combat log
		combat_log("\n" + player1.getName() + " performed a simple attack. COM Health Points now: " + to_string(com.getLargeMonHealthPoints()));	// add to the combat log	
		cout << "\n" + player1.getName() + " performed a simple attack." << endl;
		set_turn(false);// change turn to AI
		simple_human_counter_++;
	}
	else{
		// print to the combat log
		combat_log("\nCOM performed a simple attack." + com.getName() + " Health Points now: " + to_string(com.getLargeMonHealthPoints()));
		cout << "\nCOM performed a simple attack." << endl;
		set_turn(true);
		com_simple_counter_ ++;
	}
	
}

/**
 * \brief
 * Special attack: this is an attack that can be used only on Largemons of the antagonist 
 *					type. For instance, a Water Largemon can use a special attack only against a Fire
 *					Largemon. The special attack can be used only once per combat, and reduces the heal
 *					points of the attacked by twice the attack points of the attacker.
 * \param com this is opponent player
 * \param human_turn this indicates whose turn it is it
 * \param player1 this is attacking player
 */
void Combat::special_attack(Player &com, const bool human_turn, Player &player1)
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
	
	if (human_turn)// if it is the human turn
	{
		// print to the combat log
		combat_log("\n" + player1.getName() + " performed special attack. COM Health Points now: " + to_string(com.getLargeMonHealthPoints()));// add to the combat log
		cout << "\n" + player1.getName() + " performed a special attack." << endl;
		set_turn(false);// change turn to AI
		simple_human_counter_= 0;
	}
	else
	{	
		// print to the combat log
		combat_log("\nCOM performed a special attack." + com.getName() + " Health Points now: " + to_string(com.getLargeMonHealthPoints()));
		cout << "\n" + com.getName() + " performed a special attack." << endl;
		set_turn(true);
		com_simple_counter_ = 0;
	}
}

/**
 * \brief  
 * Defend: a Largemon recovers a small amount of its health points.
 * \param human_turn this indicates whose turn it is it
 * \param player1 this is attacking player
 */
void Combat::defend(const bool human_turn, Player &player1)
{
	const auto i = player1.getLargeMonHealthPoints() + 3;
	player1.setLargeMonHealthPoints(i);
	action_counters_++;
	if (human_turn) 
	{
		// print to the combat log
		combat_log("\n" + player1.getName() + " performed defend.Health Points now: " + to_string(player1.getLargeMonHealthPoints()));		
		set_turn(false);
		simple_human_counter_++;
	}
	else
	{
		// print to the combat log
		combat_log("\nCOM used defend. Health Points now:" + to_string(player1.getLargeMonHealthPoints()));		
		set_turn(true);
		com_simple_counter_++;
	}
	cout << "\n" + player1.getName() + " performed defence." << endl;
}
//write each session to the combat log
/**
 * \brief 
 * \param action 
 */
void Combat::combat_log(const string& action) const
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
void Combat::init_combat(const Player& player1)
{
	auto result = time(nullptr);	
	char dr[26];
	ctime_s(dr,sizeof dr,&result);
	combat_log("\nsession started on");
	const string stuff = &dr[0];
	combat_log("\nDate and time of game: " + stuff);
	combat_log("Human Player Name : " + player1.getName());
	combat_log("\nLargemon used : " + player1.getLargeMonName());
	combat_log("\nEvents:");
}

// returns true or false if it is the humans turn
bool Combat::get_turn() const
{
	return humanturn_;
}
// sets humanturn
void Combat::set_turn(bool a)
{
	humanturn_ = a;
}
// randomly select an action to be performed by the AI
void Combat::com_actions(Player &com, Player &human)
{
	switch (rand() % 3)
	{
	case 0:
		simple_attack(human, false, com);
		break;
	case 1:
		defend( false, com);
		break;
	case 2:
		if (com_simple_counter_ >= 5)
		{
			special_attack(human, false, com);
			break;
		}
		else {		
			cout << "Sorry can't work now" << endl;
			simple_attack(human, false, com);
			break;
		}		
	default:
		simple_attack(human, false, com);
		break;
	}
}
