#include<string>
#include<sstream>
#include "QuadraticEquation.h"
#include<iostream>




// получение из строки формата "a b c"
QuadraticEquation::QuadraticEquation(std::string equation_string) {
	std::istringstream iss(equation_string);

	iss >> this->a >> this->b >> this->c;
}

QuadraticEquation::~QuadraticEquation() {};



// нормальное решение уравнения, без ошибок
void QuadraticEquation::normalSolve(QuadraticEquation& eq, double& root_first, double& root_second) {
	double discr = eq.b * eq.b - 4 * eq.a * eq.c;

	const double eps = 1e-13;

	if (eq.a == 0.0) {
		std::cout << "Не квадратное уравнение\n";
		return;
	}

	if (std::abs(discr) < eps) {
		root_first = (-eq.b) / (2 * eq.a);
		root_second = root_first;
	}
	else if (discr > 0) {
		root_first = (-eq.b + sqrt(discr)) / (2 * eq.a);
		root_second = (-eq.b - sqrt(discr)) / (2 * eq.a);
	}
	else {
		root_first = 0;
		root_second = 0;
		std::cout << "Уравнение с мнимыми корнями\n";  // этого произойти не должно
	}
}