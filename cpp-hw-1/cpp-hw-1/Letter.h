#pragma once

#include<string>
#include "QuadraticEquation.h"

class Letter
{
public:
	std::string name;
	QuadraticEquation equation;
	double root_first;
	double root_second;

	Letter(std::string name, QuadraticEquation equation, double root_first, double root_second);
	~Letter();
};

