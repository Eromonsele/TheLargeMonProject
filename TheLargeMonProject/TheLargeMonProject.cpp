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
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	vector <Player *> m_player(2);
	while (true)
	{
		if (x == 1)
		{
			int j;			
			cout << "Press 1 to add a player" << endl;
			cin >> j;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			while (true)
			{
				if (j == 1)
				{
					int m;
					string xword;
					cout << "Type in players name :" << endl;
					cin >> xword;

					// initialise player name
					Player p1(xword);
					// add to user vector
					m_player[0] = &p1;
					// initialise player name
					Player com("COM");
					m_player[1] = &com;
					cout << m_player[0]->getName() << " has been created and " << m_player[1]->getName() << " has been created" << endl;
					cout << "Press 1 to generate largemon" << endl;
					cin >> m;					
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					while (true)
					{
						if (m == 1)
						{
							// initial largemon generation 
							l.con.assign_largemon_to_player(*m_player[0], *m_player[1]);
				
							while (true)
							{	
								string optionChar;
								//display user's largemon attributes
								l.con.display_largemon_attributes(*m_player[0]);
								// check if user wants his largemon
								cout << "Do you wish to regenerate a new largemon?" << endl;
								cout << "Input Y(Yes) or N(No):" << endl;
								cin >> optionChar;							
								// if the option is yes, regenerate largemon 
								if (optionChar == "Y" || optionChar == "y" || optionChar == "Yes" || optionChar == "YES")
								{
									// largemon generation
									l.con.assign_largemon_to_player(*m_player[0], *m_player[1]);						
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
							session.init_combat(*m_player[0]);
							
							cout << "Combat Begins" << endl;
							int exitgame = 1;
							while (true)
							{
								while (exitgame == 1)
								{
									l.con.game_session(*m_player[0], *m_player[1]);// run the game event session									
									l.con.display_health_points(*m_player[0], *m_player[1]);// display health Points
									exitgame = l.con.check_game_status(*m_player[0], *m_player[1]);
									if (exitgame == 0)
									{
										break;
									}
								}
								break;
							}
							return 0;
						}
						else {	
							cout << "\nThat is not a valid option" << endl;
							cout << "Press 1 to generate largemon" << endl;
							cin >> m;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
					}
				}
				else
				{
					cout << "\nThat is not a valid option" << endl;
					cout << "Press 1 to add a player" << endl;
					cin >> j;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					
				
				}
			}
		}
		else if (x == 0){
			cout << "GOODBYE" << endl;
			return 0;
		}
		else
		{
			
			
			cout<<"\nThat is not a valid option" <<endl;
			cout << "Press 1 to start the game" << endl;
			cout << "Press 0 to exit the game" << endl;			
			cin >> x;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}// end of project

