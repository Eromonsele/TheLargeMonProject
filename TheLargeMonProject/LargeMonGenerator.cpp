#include "stdafx.h"
#include "LargeMonGenerator.h"
#include <sstream>
/*
This class generates a largemon( type, name, size, description, health points).
This class also stores the largemon generated in an external documents.

Author: Eromosele Okhilua

*/

// constructor
LargeMonGenerator::LargeMonGenerator()
{
	// empty body
}// end constructor


/*
This method generates the information for the largemon, and returns the largemon generated
*/
LargeMon LargeMonGenerator::beginGeneration()
{
	int hp = rand() % 70 + 30;// the health points generated randomly
	int ap = rand() % 5 + 5;// the attack points generated randomly
	string type;// the largemon type
	string size;// the largemon size
	string name;// the largemon name
	string decspt;// the largemon desc
	string x;
	
	vector<string> largeMonDescriptors;	
	int sum = 0;

	ifstream lx = readfile("LargeMonTypes.txt");// gets largemon information from external file

	while (!lx.eof()) {// while it is not the end of the file
		lx >> x;// assign the information in the file to a string
		largeMonDescriptors.push_back(x);// add that string to the vector
	}
	type = largeMonDescriptors[rand() % largeMonDescriptors.size()]; // pick at random from the vector, and assign to largemon
	largeMonDescriptors.clear();// clear the vector
	
	lx = readfile("LargeMonSizes.txt");
	while (!lx.eof()) {// while it is not the end of the file
		lx >> x;// assign the information in the file to a string
		largeMonDescriptors.push_back(x);// add that string to the vector
	}
	size = largeMonDescriptors[rand() % largeMonDescriptors.size()];// pick at random from the vector, and assign to largemon
	largeMonDescriptors.clear();// clear the vector

	lx = readfile("LargeMonDescriptor.txt");
	while (!lx.eof()) {// while it is not the end of the file
		lx >> x;// assign the information in the file to a string
		largeMonDescriptors.push_back(x);// add that string to the vector
	}
	
	decspt = largeMonDescriptors[rand() % largeMonDescriptors.size()];// pick at random from the vector, and assign to largemon
	decspt.append("-like");// adds a suffix to the largemon description
	name = nameGenerator();// generates the largemon name
	
	LargeMon large(type,name,size,decspt,ap,hp);// initializes the largemon
	large.setAntagonist(large.getType());// sets the largemon generated antagonist
	generatedLargemonLog(large.getType(), large.getName(), large.getSize(), large.getDescription(), large.getAttackPoints(), large.getHealthPoints());// adds largemon info to external file
	lx.close(); // close ifstream
	return large;
}// end function beginGeneration()

// Reads and gets infomation stored in an external file
ifstream LargeMonGenerator::readfile(string file)
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
string LargeMonGenerator::nameGenerator()
{
	string letters = "abcdefghijklmnopqrstvuwxyz";//used as an array of letters
	string name;
	for (int i = 0; i < rand() % 3 + 7; i++)
	{
		name.append(1,letters[rand() % letters.size()]);
	}
	name.append("-mon");
	return name;
}//end function

//Stores the generated largemon to an external file
void LargeMonGenerator::generatedLargemonLog(string t, string n, string s, string d, int h, int a)
{
	int number = 1;
	ofstream outFile("LargemonLog.txt", ios::app);// appends to an already created file
	if (!outFile)
	{
		cerr << "File not opened" << endl;
		exit(1);
	}

	outFile << number + ": Largemon Name: " + n + " Largemon Description : " + n + " is a " + s + " " + d + " " + t + " type largemon";
	number++;
}
