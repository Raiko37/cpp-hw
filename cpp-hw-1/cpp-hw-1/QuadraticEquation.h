#pragma once
#include<string>

class QuadraticEquation
{
public:
	double a;
	double b;
	double c;

	QuadraticEquation() : a(0.0), b(0.0), c(0.0) {}; // он подчёркивает красным пустое место, но всё компилируется

	// получение из строки формата "a b c"
	QuadraticEquation(std::string equation_string);

	~QuadraticEquation();

	static void normalSolve(QuadraticEquation& eq, double& root_first, double& root_second);
};

