#pragma once
#include <iostream>
#include <vector>
using namespace std;
/**
* The largemon objects, holds the largemon healthpoints, attackpoints
* name, description,size and weakness
*
* Author: Eromosele Okhilua
*
*/
class LargeMon
{
public:	
	LargeMon(const string &, const string &,const string &, const string & ,int ,int );
	
	void setType(const string &);// set LargeMon type
	string getType() const;// get LargeMon type

	void setName(const string &);// set LargeMon name
	string getName() const;// get LargeMon name

	void setSize(const string &);// set LargeMon Size
	string getSize() const;// get LargeMon Size

	void setDescription(const string &);// set LargeMon Description
	string getDescription() const;// get LargeMon Description

	void setAttackPoints(int );// set LargeMon AttackPoints
	int getAttackPoints()const;// get LargeMon  AttackPoints

	void setHealthPoints(int );	// set LargeMon HealthPoints
	int getHealthPoints()const;// get LargeMon HealthPoints

	void setAntagonist(const string &);	// set LargeMon antagonist or weakness
	vector <string> getLWeakness() const; // get LargeMon antagonist or weakness
	
private:
	string ltype;
	string lname;
	string lsize;
	string ldescription;
	int lattackPoints;
	int lhealthPoints;
	vector <string> lWeakness;
};

