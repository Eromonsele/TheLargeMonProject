/*
TheLargeMonProject.cpp : Defines the entry point for the console application.

Author: Eromosele Okhilua
Student Number: u1671506

*/

#include "stdafx.h"
#include "TheLargeMonProject.h"


int main()
{
	TheLargeMonProject l;	
	//Controller con;// the contoller	
	int x;
	cout << "Welcome to the LargeMon Project" <<endl;
	cout << "////////////////////////////////////////////" << endl;
	cout << "Press 1 to start the game" << endl;
	cout << "Press 0 to exit the game" << endl;
	cin >> x;
	vector <Player *> m_Player(2);
	if (x == 1)
	{
		int x;
		cout << "Press 1 to add a player" << endl;
		cin >> x;
		if (x == 1)
		{
			int x;
			string xword;
			cout << "Type in players name :" << endl;
			cin >> xword;
			// initialise player name
			Player p1(xword);
			// add to user vector
			m_Player[0] = &p1;
			// initialise player name
			Player com("COM");
			m_Player[1] = &com;
			cout << m_Player[0]->getName() << " has been created and " << m_Player[1]->getName() << " has been created" << endl;
			cout << "Press 1 to generate largemon" << endl;
			cin >> x;
			if (x == 1)
			{
				// initial largemon generation 
				l.con.assignLargemonToPlayer(*m_Player[0], *m_Player[1]);
				
				while (true)
				{	
					string optionChar;
					//display user's largemon attributes
					l.con.displayLargemonAttributes(*m_Player[0]);
					// check if user wants his largemon
					cout << "Do you wish to regenerate a new largemon?" << endl;
					cout << "Input Y(Yes) or N(No):" << endl;
					cin >> optionChar;
					// if the option is yes, regenerate largemon 
					if (optionChar == "Y" || optionChar == "y" || optionChar == "Yes" || optionChar == "YES")
					{
						// largemon generation
						l.con.assignLargemonToPlayer(*m_Player[0], *m_Player[1]);						
					}
					else if (optionChar == "N" || optionChar == "n" || optionChar == "No" || optionChar == "NO")
					{
						break;
					}
					else {
						cout << "You haven't selected Yes or No" << endl;
					}
				}
				// Begin the combat session
				Combat session;
				// Initialize the combat session
				session.initCombat(*m_Player[0]);
				int option;
				cout << "Combat Begins" << endl;				
				int exitGame = 1;
				while (exitGame != 0 )
				{
					exitGame = l.con.checkGameStatus(*m_Player[0], *m_Player[1]);
					l.con.gameSession(*m_Player[0], *m_Player[1]);// run the game event session
					l.con.displayHealthPoints(*m_Player[0], *m_Player[1]);// display health Points
				}
			}
			else {				
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else {
		return 0;
	}	
}// end of project

