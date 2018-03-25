#pragma once
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
	LargeMon(string, string, string, string,int ,int );
	
	void set_type(const string &);// set LargeMon type
	string get_type() const;// get LargeMon type

	void set_name(const string &);// set LargeMon name
	string get_name() const;// get LargeMon name

	void set_size(const string &);// set LargeMon Size
	string get_size() const;// get LargeMon Size

	void set_description(const string &);// set LargeMon Description
	string get_description() const;// get LargeMon Description

	void set_attack_points(int );// set LargeMon AttackPoints
	int get_attack_points()const;// get LargeMon  AttackPoints

	void set_health_points(int );	// set LargeMon HealthPoints
	int get_health_points()const;// get LargeMon HealthPoints

	void set_antagonist(const string &);	// set LargeMon antagonist or weakness
	vector <string> getLWeakness() const; // get LargeMon antagonist or weakness
	
private:
	string ltype_, lname_, lsize_, ldescription_;
	int lattack_points_, lhealth_points_;
	vector <string> l_weakness_;
};

