#include "Letter.h"
#include "QuadraticEquation.h"
#include<string>




Letter::Letter(std::string name, QuadraticEquation& equation, double root_first, double root_second) {
	this->name = name;
	this->equation = equation;
	this->root_first = root_first;
	this->root_second = root_second;
}

Letter::~Letter() {};
