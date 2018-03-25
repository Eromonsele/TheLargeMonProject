#include "stdafx.h"
#include "LargeMonGenerator.h"
#include <sstream>
#include <iostream>

/**
 *This class generates a largemon( type, name, size, description, health points).
 *This class also stores the largemon generated in an external documents.
 *
 *Author: Eromosele Okhilua
 *
*/

// constructor
LargeMonGenerator::LargeMonGenerator()
{
	// empty body
}// end constructor



/**
 * \brief This method generates the information for the largemon, and returns the largemon generated
 * \return The largemon generated
 */
LargeMon LargeMonGenerator::begin_generation()
{
	int hp = rand() % 70 + 30;// the health points generated randomly
	int ap = rand() % 5 + 5;// the attack points generated randomly
	string x;
	
	vector<string> large_mon_descriptors;


	ifstream lx = readfile("LargeMonTypes.txt");// gets largemon information from external file

	while (!lx.eof()) {// while it is not the end of the file
		lx >> x;// assign the information in the file to a string
		large_mon_descriptors.push_back(x);// add that string to the vector
	}
	string type = large_mon_descriptors[rand() % large_mon_descriptors.size()]; // pick at random from the vector, and assign to largemon
	large_mon_descriptors.clear();// clear the vector
	
	lx = readfile("LargeMonSizes.txt");
	while (!lx.eof()) {// while it is not the end of the file
		lx >> x;// assign the information in the file to a string
		large_mon_descriptors.push_back(x);// add that string to the vector
	}
	string size = large_mon_descriptors[rand() % large_mon_descriptors.size()];// pick at random from the vector, and assign to largemon
	large_mon_descriptors.clear();// clear the vector

	lx = readfile("LargeMonDescriptor.txt");
	while (!lx.eof()) {// while it is not the end of the file
		lx >> x;// assign the information in the file to a string
		large_mon_descriptors.push_back(x);// add that string to the vector
	}
	
	string decspt = large_mon_descriptors[rand() % large_mon_descriptors.size()];// pick at random from the vector, and assign to largemon
	decspt.append("-like");// adds a suffix to the largemon description
	string name = name_generator();// generates the largemon name
	
	LargeMon large(type,name,size,decspt,ap,hp);// initializes the largemon
	large.set_antagonist(large.get_type());// sets the largemon generated antagonist
	generated_largemon_log(large.get_type(), large.get_name(), large.get_size(), large.get_description(), large.get_attack_points(), large.get_health_points());// adds largemon info to external file
	lx.close(); // close ifstream
	return large;
}// end function beginGeneration()

// Reads and gets infomation stored in an external file
ifstream LargeMonGenerator::readfile(const string& file) const
{
	ifstream largemonFile;
	largemonFile.open(file);
	if (!largemonFile)// if file is not found
	{
		cout << "Unable to open file";
		exit(1);// exit the program
	}	
	return largemonFile;
}// end function

// Generates and returns largemon name at random
string LargeMonGenerator::name_generator() const
{
	string letters = "abcdefghijklmnopqrstvuwxyz";//used as an array of letters
	string name;
	for (int i = 0; i < rand() % 7 + 3; i++)
	{
		name.append(1,letters[rand() % letters.size()]);
	}
	name.append("-mon");
	return name;
}//end function

//Stores the generated largemon to an external file
void LargeMonGenerator::generated_largemon_log(const string& t, const string& n, const string& s, const string& d, int h, int a) 
{
	
	ofstream out_file("LargemonLog.txt", ios::app);// appends to an already created file
	if (!out_file)
	{
		cerr << "File not opened" << endl;
		exit(1);
	}

	out_file <<": Largemon Name: " + n + " Largemon Description : " + n + " is a " + s + " " + d + " " + t +
		" type largemon \n";
}
