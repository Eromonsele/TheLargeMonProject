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
	vector <player *> m_Player(2);
	if (x == 1)
	{
		int x;
		cout << "Press 1 to add a player" << endl;
		cin >> x;
		if (x == 1)
		{
			int x;
			string xword;
			cout <<"Type in players name" << endl;
			cin >> xword;
			player p1(xword);
			m_Player[0] = &p1;
			player com("COM");				
			m_Player[1] = &com;			
			cout <<m_Player[0]->getName() << " has been created and " << m_Player[1]->getName() << " has been created" << endl;
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
				
				while (true)
				{
					if (session.getTurn() == true)
					{
						cout << "human current healthpoints : " << m_Player[0]->getPlayerLargeMon().getHealthPoints() << endl;
						cout << "com current healthpoints : " << m_Player[1]->getPlayerLargeMon().getHealthPoints() << endl;
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
							session.specialAttack(m_Player[1]->getPlayerLargeMon(), true, *m_Player[0]);
							break;
						default:
							break;
						}
					}
					else
					{
						cout << "human current healthpoints : " << m_Player[0]->getPlayerLargeMon().getHealthPoints() << endl;
						cout << "com current healthpoints : " << m_Player[1]->getPlayerLargeMon().getHealthPoints() << endl;
						cout << "\n" << m_Player[1]->getName() + " turn" << endl;						
						session.comActions(*m_Player[1], *m_Player[0]);						
					}
					
				}
				
				
			}
		}
		else {
			return 0;
		}
		
	}
	else {
		return 0;
	}	
	return 0;
}

