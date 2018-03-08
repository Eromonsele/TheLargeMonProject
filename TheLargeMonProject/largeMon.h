#pragma once
#include <iostream>
using namespace std;

class LargeMon
{
public:	
	LargeMon(const string &, const string &,const string &, const string & ,int ,int );
	
	void setType(const string &);
	void setName(const string &);
	void setSize(const string &);
	void setDescription(const string &);
	void setAttackPoints(int );
	void setHealthPoints(int );

	string getType() const;
	string getName() const;
	string getSize() const;
	string getDescription() const;
	int getAttackPoints()const;
	int getHealthPoints()const;
	
private:
	string ltype;
	string lname;
	string lsize;
	string ldescription;
	int lattackPoints;
	int lhealthPoints;	
};

