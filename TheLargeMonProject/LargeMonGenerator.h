#pragma once
#include <vector>
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
	LargeMon begin_generation();//
	ifstream readfile(const string&) const; // returns a list containing information of an external documents
	string name_generator() const; // creates and return the largemon name
	void generated_largemon_log(const string&, const string&, const string&, const string&,int, int); // creates and stores a log of largemon generated
private:
	vector <LargeMon> m_large_mon_;
};

