#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "largeMon.h"
#include <fstream>

using namespace std;

class LargeMonGenerator
{
public:
	LargeMonGenerator();	
	LargeMon beginGeneration();
	ifstream readfile(string);
	string nameGenerator();
private:
	vector <LargeMon> m_LargeMon;
};

