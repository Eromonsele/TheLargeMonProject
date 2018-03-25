#include "stdafx.h"
#include "Controller.h"

/*
The Controller

Author: Eromosele Okhilua
Version: 
*/
Controller::Controller()
{
	session.set_turn(true);

}


Controller::~Controller()
{
}
// checks the status of the game, after every turn
int Controller::check_game_status(Player &player_one, Player &computer) const
{
	if (player_one.getLargeMonHealthPoints() < 0 || computer.getLargeMonHealthPoints() < 0)// if healthpoints less than zero
	{
		cout << "GAME OVER!!!!!!!!" << endl;// print to console
		player_one.singleGame(player_one.getLargeMonHealthPoints(), computer.getLargeMonHealthPoints());// single game simulation for the human player
		computer.singleGame(computer.getLargeMonHealthPoints(), player_one.getLargeMonHealthPoints());// single game simulation for the AI

		if (player_one.getLargeMonHealthPoints() < 0)// if healthpoints is less than zero
		{
			session.combat_log("\n" + computer.getName() + " Destroyed " + player_one.getName());// print to the combat log
			cout << computer.getName() << " WINS!!!!!" << endl;// print to the console
			session.combat_log("\n********************************************************************************************");
			return 0;
			
		}
		else if (computer.getLargeMonHealthPoints() < 0)// if healthpoints is less than zero
		{
			session.combat_log("\n" + player_one.getName() + " Destroyed " + computer.getName());// print to the combat log
			cout << player_one.getName() << " WINS!!!!!" << endl;// print to the console
			session.combat_log("\n********************************************************************************************");
			return 0;
		}else
		{
			return 1;
		}
		
		
	}
	else
	{
		return 1;
	}


	
}

void Controller::game_session(Player &player_one, Player &computer)
{
	int option = 0;
	if (session.get_turn())
	{

		cout << "\n" << player_one.getName() + " turn" << endl;
		cout << "Pick a battle action" << endl;
		cout << "Option 1: Simple Attack\nOption 2: Defend\nOption 3: Special Attack" << endl;
		//cin >> option;
		//cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		do
		{
			while (!(cin >> option))
			{
				cout << "Incorrect input, Please try again : " << endl;
				cout << "Option 1: Simple Attack\nOption 2: Defend\nOption 3: Special Attack" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if (option < 0)
			{
				cout << "Incorrect input, Please try again : " << endl;
				cout << "Option 1: Simple Attack\nOption 2: Defend\nOption 3: Special Attack" << endl;
			}
		}
		while (option < 0 ||  option > 3);
			switch (option)
			{
			case 1:
				session.simple_attack(computer, true, player_one);
				break;
			case 2:
				session.defend(true, player_one);
				break;
			case 3:
				session.special_attack(computer, true, player_one);
				break;
			
			default:
				std::cout << "You have selected nothing, therefore we play for you" << endl;
				session.simple_attack(computer, true, player_one);
				break;
			}

		
		
	}
	else
	{
		cout << "\n" << computer.getName() + " turn" << endl;
		session.com_actions(computer, player_one);
	}
}

void Controller::display_health_points(Player &player_one, Player &computer) const
{
	cout << "human current healthpoints : " << player_one.getPlayerLargeMon().get_health_points() << endl;
	cout << "com current healthpoints : " << computer.getPlayerLargeMon().get_health_points() << endl;
}

void Controller::assign_largemon_to_player(Player &player_one, Player &computer)
{
	
	player_one.setPlayerLargeMon(lh.begin_generation());
	computer.setPlayerLargeMon(lh.begin_generation());
}

void Controller::display_largemon_attributes(Player &user) const
{
	cout << "\nPlayer Name: " << user.getName() << endl;
	cout << "Generated LargeMon" << endl;
	cout << "LargeMon Name: " << user.getLargeMonName() << endl;
	cout << "LargeMon Description: " + user.getLargeMonName() + " is a " + user.getLargeMonSize() + " " + user.getPlayerLargeMon().get_description() + " " + user.getLargeMonType() + " type." << endl;
	
}

