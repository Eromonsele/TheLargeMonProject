#include "stdafx.h"
#include "LargeMonGenerator.h"
#include <sstream>


LargeMonGenerator::LargeMonGenerator()
{
}



LargeMon LargeMonGenerator::beginGeneration()
{
	int hp = rand() % 70 + 30;
	int ap = rand() % 5 + 5;
	string type;
	string size;
	string name;
	string decspt;
	string x;
	vector<string> largeMonDescriptors;	
	int sum = 0;

	ifstream lx = readfile("LargeMonTypes.txt");

	while (!lx.eof()) {
		lx >> x;
		largeMonDescriptors.push_back(x);
	}
	type = largeMonDescriptors[rand() % largeMonDescriptors.size()];
	largeMonDescriptors.clear();
	
	lx = readfile("LargeMonSizes.txt");
	while (!lx.eof()) {
		lx >> x;
		largeMonDescriptors.push_back(x);
	}
	size = largeMonDescriptors[rand() % largeMonDescriptors.size()];
	largeMonDescriptors.clear();

	lx = readfile("LargeMonDescriptor.txt");
	while (!lx.eof()) {
		lx >> x;
		largeMonDescriptors.push_back(x);
	}
	
	decspt = largeMonDescriptors[rand() % largeMonDescriptors.size()];
	decspt.append("-like");
	name = nameGenerator();
	
	LargeMon large(type,name,size,decspt,ap,hp);
	large.setAntagonist(large.getType());
	lx.close();
	return large;
}

ifstream LargeMonGenerator::readfile(string file)
{
	ifstream largemonFile;
	largemonFile.open(file);
	if (!largemonFile)
	{
		cout << "Unable to open file";
		exit(1);
	}	
	return largemonFile;
}

string LargeMonGenerator::nameGenerator()
{
	string letters = "abcdefghijklmnopqrstvuwxyz";
	string name;
	for (int i = 0; i < rand() % 3 + 7; i++)
	{
		name.append(1,letters[rand() % letters.size()]);
	}
	name.append("mon");
	return name;
}

