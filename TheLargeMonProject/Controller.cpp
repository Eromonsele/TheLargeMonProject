#include "stdafx.h"
#include "Controller.h"

/*
The Controller

Author: Eromosele Okhilua
Version: 
*/
Controller::Controller()
{
	session.setTurn(true);
}


Controller::~Controller()
{
}
// checks the status of the game, after every turn
int Controller::checkGameStatus(Player &playerOne, Player &computer)
{
	if (playerOne.getLargeMonHealthPoints() < 0 || computer.getLargeMonHealthPoints() < 0)// if healthpoints less than zero
	{
		cout << "GAME OVER!!!!!!!!" << endl;
		playerOne.singleGame(playerOne.getLargeMonHealthPoints(), computer.getLargeMonHealthPoints());// single game simulation for the human player
		computer.singleGame(computer.getLargeMonHealthPoints(), playerOne.getLargeMonHealthPoints());// single game simulation for the AI

		if (playerOne.getLargeMonHealthPoints() < 0)// if healthpoints is less than zero
		{
			session.combatLog("\n" + computer.getName() + " Destroyed " + playerOne.getName());// print to the combat log
			cout << computer.getName() << " WINS!!!!!" << endl;// print to the console
			session.combatLog("\n********************************************************************************************");
			return 0;
		}
		else if (computer.getLargeMonHealthPoints() < 0)// if healthpoints is less than zero
		{
			session.combatLog("\n" + playerOne.getName() + " Destroyed " + computer.getName());// print to the combat log
			cout << playerOne.getName() << " WINS!!!!!" << endl;// print to the console
			session.combatLog("\n********************************************************************************************");
			return 0;
		}
		
		return 1;
	}
}

void Controller::gameSession(Player &playerOne, Player &computer)
{
	int option = 0;
	if (session.getTurn() == true)
	{

		cout << "\n" << playerOne.getName() + " turn" << endl;
		cout << "Pick a battle action" << endl;
		cout << "Option 1: Simple Attack\nOption 2: Defend\nOption 3: Special Attack" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			session.simpleAttack(computer, true, playerOne);
			break;
		case 2:
			session.defend(true, playerOne);
			break;
		case 3:
			session.specialAttack(computer, true, playerOne);
			break;
		default:
			break;
		}

	}
	else
	{
		cout << "\n" << computer.getName() + " turn" << endl;
		session.comActions(computer, playerOne);
	}
}

void Controller::displayHealthPoints(Player &playerOne, Player &computer)
{
	cout << "human current healthpoints : " << playerOne.getPlayerLargeMon().getHealthPoints() << endl;
	cout << "com current healthpoints : " << computer.getPlayerLargeMon().getHealthPoints() << endl;
}

void Controller::assignLargemonToPlayer(Player &playerOne, Player &computer)
{
	LargeMonGenerator lh;
	playerOne.setPlayerLargeMon(lh.beginGeneration());
	computer.setPlayerLargeMon(lh.beginGeneration());
}

void Controller::displayLargemonAttributes(Player &user)
{
	cout << "\nPlayer Name: " << user.getName() << endl;
	cout << "Generated LargeMon" << endl;
	cout << "LargeMon Name: " << user.getLargeMonName() << endl;
	cout << "LargeMon Description: " + user.getLargeMonName() + " is a " + user.getLargeMonSize() + " " + user.getPlayerLargeMon().getDescription() + " " + user.getLargeMonType() + " type." << endl;
	
}

