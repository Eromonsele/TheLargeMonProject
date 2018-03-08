#include "stdafx.h"
#include "largeMon.h"

LargeMon::LargeMon(const string &type, const string &name, const string &lsize, const string &description, int attackpoints, int healthPoints)
	:ltype(type), lname(name), lsize(lsize), ldescription(description), lattackPoints(attackpoints),lhealthPoints(healthPoints)
{
}



void LargeMon::setType(const string &type)
{
	ltype = type;
}

void LargeMon::setName(const string &name)
{
	lname = name;
}

void LargeMon::setSize(const string &size)
{
	lsize = size;
}

void LargeMon::setDescription(const string &description)
{
	ldescription = description;
}

void LargeMon::setAttackPoints(int attackpoints)
{
	lattackPoints = attackpoints;
}

void LargeMon::setHealthPoints(int healthPoints)
{
	lhealthPoints = healthPoints;
}

string LargeMon::getType() const
{
	return ltype;
}

string LargeMon::getName() const
{
	return lname;
}

string LargeMon::getSize() const
{
	return lsize;
}

string LargeMon::getDescription() const
{
	return ldescription;
}

int LargeMon::getAttackPoints() const
{
	return lattackPoints;
}

int LargeMon::getHealthPoints() const
{
	return lhealthPoints;
}
