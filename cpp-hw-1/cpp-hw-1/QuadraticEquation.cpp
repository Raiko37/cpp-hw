#include<string>
#include<sstream>
#include "QuadraticEquation.h"


// для начальной инициализации
QuadraticEquation::QuadraticEquation() {
	this->a = 0;
	this->b = 0;
	this->c = 0;
}


// получение из строки формата "a b c"
QuadraticEquation::QuadraticEquation(std::string equation_string) {
	std::istringstream iss(equation_string);

	iss >> this->a >> this->b >> this->c;
}

QuadraticEquation::~QuadraticEquation() {};
