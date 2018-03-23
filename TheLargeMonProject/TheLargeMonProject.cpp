// TheLargeMonProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "largeMon.h"
#include "LargeMonGenerator.h"
#include "player.h"
#include "combat.h"
#include <fstream>

int main()
{

	int x;
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
			cout << "Type in players name" << endl;
			cin >> xword;
			Player p1(xword);
			m_Player[0] = &p1;
			Player com("COM");
			m_Player[1] = &com;
			cout << m_Player[0]->getName() << " has been created and " << m_Player[1]->getName() << " has been created" << endl;
			cout << "Press 1 to generate largemon" << endl;
			cin >> x;
			if (x == 1)
			{

				LargeMonGenerator lh;
				m_Player[0]->setPlayerLargeMon(lh.beginGeneration());
				m_Player[1]->setPlayerLargeMon(lh.beginGeneration());
				cout << "generated" << endl;
				cout << "Combat begin" << endl;
				combat session;
				session.initCombat(*m_Player[0]);
				int option;
				cout << "Combat Begins" << endl;
				session.setTurn(true);
				int exitGame = 1;
				while (exitGame != 0)
				{
					if (m_Player[0]->getLargeMonHealthPoints() < 0 || m_Player[1]->getLargeMonHealthPoints() < 0)
					{
						cout << "GAME OVER!!!!!!!!" << endl;
						m_Player[0]->singleGame(m_Player[0]->getLargeMonHealthPoints(), m_Player[1]->getLargeMonHealthPoints());
						m_Player[1]->singleGame(m_Player[1]->getLargeMonHealthPoints(), m_Player[0]->getLargeMonHealthPoints());

						if (m_Player[0]->getLargeMonHealthPoints() < 0)
						{
							session.combatLog("\n" + m_Player[1]->getName() + " Destroyed " + m_Player[0]->getName());
							cout << m_Player[1]->getName() << " WINS!!!!!" << endl;							
						}
						else if (m_Player[1]->getLargeMonHealthPoints() < 0)
						{
							session.combatLog("\n" + m_Player[0]->getName() + " Destroyed " + m_Player[1]->getName());
							cout << m_Player[0]->getName() << " WINS!!!!!" << endl;
							
						}
						session.combatLog("\n********************************************************************************************");
						 exitGame = 0;
					}

					if (session.getTurn() == true)
					{

						cout << "\n" << m_Player[0]->getName() + " turn" << endl;
						cout << "Pick a battle action" << endl;
						cout << "Option 1: Simple Attack\nOption 2: Defend\nOption 3: Special Attack" << endl;
						cin >> option;
						switch (option)
						{
						case 1:
							session.simpleAttack(*m_Player[1], true, *m_Player[0]);
							break;
						case 2:
							session.defend(true, *m_Player[0]);
							break;
						case 3:
							session.specialAttack(*m_Player[1], true, *m_Player[0]);
							break;
						default:
							break;
						}

					}
					else
					{
						cout << "\n" << m_Player[1]->getName() + " turn" << endl;
						session.comActions(*m_Player[1], *m_Player[0]);
					}
					cout << "human current healthpoints : " << m_Player[0]->getPlayerLargeMon().getHealthPoints() << endl;
					cout << "com current healthpoints : " << m_Player[1]->getPlayerLargeMon().getHealthPoints() << endl;
				}

				

			}


		}
	}
	else {
		return 0;
	}	
}

