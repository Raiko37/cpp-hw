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

	Letter(std::string& name, QuadraticEquation& equation, double root_first, double root_second): name(name),
		equation(equation), root_first(root_first), root_second(root_second) {};
	~Letter() = default;
};

