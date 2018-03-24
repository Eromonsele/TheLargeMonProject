#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "largeMon.h"
#include <fstream>

using namespace std;
/*
This class generates a largemon( type, name, size, description, health points).
This class also stores the largemon generated in an external documents.

Author: Eromosele Okhilua

*/

class LargeMonGenerator
{
public:
	LargeMonGenerator();	
	LargeMon beginGeneration();//
	ifstream readfile(string); // returns a list containing information of an external documents
	string nameGenerator(); // creates and return the largemon name
	void generatedLargemonLog(string, string, string, string,int, int); // creates and stores a log of largemon generated
private:
	vector <LargeMon> m_LargeMon;
};

