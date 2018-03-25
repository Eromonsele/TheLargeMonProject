#include "stdafx.h"
#include "largeMon.h"
#include <map>
#include <utility>

/**
* The largemon objects, holds the largemon healthpoints, attackpoints
* name, description,size and weakness
*
* Author: Eromosele Okhilua
* 
*/

// constructor
LargeMon::LargeMon(string type, string name, string lsize, string description, int attackpoints, int healthPoints)
	:ltype_(std::move(type)), lname_(std::move(name)), lsize_(std::move(lsize)), ldescription_(std::move(description)), lattack_points_(attackpoints), lhealth_points_(healthPoints)
{
	//empty body
}// end Largemon constructor

 // set LargeMon type
void LargeMon::set_type(const string &type)
{
	ltype_ = type;
}// end function

// set LargeMon name
void LargeMon::set_name(const string &name)
{
	lname_ = name;
}// end function

// set LargeMon Size
void LargeMon::set_size(const string &size)
{
	lsize_ = size;
}// end function

// set LargeMon Description
void LargeMon::set_description(const string &description)
{
	ldescription_ = description;
}// end function

// set LargeMon AttackPoints
void LargeMon::set_attack_points(int attackpoints)
{
	lattack_points_ = attackpoints;
}// end function

// set LargeMon HealthPoints
void LargeMon::set_health_points(int healthPoints)
{
	lhealth_points_ = healthPoints;
}// end function setHealthPoints

// set LargeMon antagonist or weakness
void LargeMon::set_antagonist(const string &s)
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
				l_weakness_.push_back(y);
			}
		}
		else
		{

		}
	}
} // end function setAntagonist

// return largemon type
string LargeMon::get_type() const
{
	return ltype_;
}// end function getType

// return largemon name
string LargeMon::get_name() const
{
	return lname_;
}// end function getName

// return largemon size
string LargeMon::get_size() const
{
	return lsize_;
}// end function getSize

// return largemon description
string LargeMon::get_description() const
{
	return ldescription_;
}// end function getDescription

// return largemon attackpoints
int LargeMon::get_attack_points() const
{
	return lattack_points_;
}// end function getAttackPoints

// return largemon health points
int LargeMon::get_health_points() const
{
	return lhealth_points_;
}// end function getHealthPoints

// return largemon weakness
vector<string> LargeMon::getLWeakness() const
{
	return l_weakness_;
}// end function getWeakness
