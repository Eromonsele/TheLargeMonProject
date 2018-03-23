#include "stdafx.h"
#include "largeMon.h"
#include <map>

/**
* The largemon objects, holds the largemon healthpoints, attackpoints
* name, description,size and weakness
*
* Author: Eromosele Okhilua
* 
*/

// constructor
LargeMon::LargeMon(const string &type, const string &name, const string &lsize, const string &description, int attackpoints, int healthPoints)
	:ltype(type), lname(name), lsize(lsize), ldescription(description), lattackPoints(attackpoints), lhealthPoints(healthPoints)
{
	//empty body
}// end Largemon constructor

 // set LargeMon type
void LargeMon::setType(const string &type)
{
	ltype = type;
}// end function

// set LargeMon name
void LargeMon::setName(const string &name)
{
	lname = name;
}// end function

// set LargeMon Size
void LargeMon::setSize(const string &size)
{
	lsize = size;
}// end function

// set LargeMon Description
void LargeMon::setDescription(const string &description)
{
	ldescription = description;
}// end function

// set LargeMon AttackPoints
void LargeMon::setAttackPoints(int attackpoints)
{
	lattackPoints = attackpoints;
}// end function

// set LargeMon HealthPoints
void LargeMon::setHealthPoints(int healthPoints)
{
	lhealthPoints = healthPoints;
}// end function setHealthPoints

// set LargeMon antagonist or weakness
void LargeMon::setAntagonist(const string &s)
{
	map<string, vector<string>> const m{
		{ "Fire",{ "Water","Rock","Ground" } },
		{ "Water",{ "Grass","Electric" } },
		{ "Normal",{ "Fighting" } },
		{ "Grass",{ "Fire","Ice" } },
		{ "Electric",{ "Ground" } },
		{ "Psychic",{ "Ghost" } },
		{ "Fighting",{ "Psychic" } },
		{ "Ghost",{ "Ghost" } },
		{ "Rock",{ "Water","Grass", "Fighting", "Ground" } },
		{ "Ground",{ "Water","Grass","Ice" } },
		{ "Ice",{ "Fire","Fighting","Rock" } },
		{ "Poison",{ "Psychic","Ground" } },
		{ "Dragon",{ "Ice","Dragon" } }
	};

	for (auto const& x : m) {
		if (s == x.first)
		{
			for (auto const& y : x.second) {
				lWeakness.push_back(y);
			}
		}
		else
		{

		}
	}
} // end function setAntagonist

// return largemon type
string LargeMon::getType() const
{
	return ltype;
}// end function getType

// return largemon name
string LargeMon::getName() const
{
	return lname;
}// end function getName

// return largemon size
string LargeMon::getSize() const
{
	return lsize;
}// end function getSize

// return largemon description
string LargeMon::getDescription() const
{
	return ldescription;
}// end function getDescription

// return largemon attackpoints
int LargeMon::getAttackPoints() const
{
	return lattackPoints;
}// end function getAttackPoints

// return largemon health points
int LargeMon::getHealthPoints() const
{
	return lhealthPoints;
}// end function getHealthPoints

// return largemon weakness
vector<string> LargeMon::getLWeakness() const
{
	return lWeakness;
}// end function getWeakness
