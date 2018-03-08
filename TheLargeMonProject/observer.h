#pragma once

#include "largeMon.h"
#include <iostream>
#include <iomanip>
#include <vector>

class observer
{
public:
	observer();
	~observer();
private:
	vector <largeMon> largeMons;
};

