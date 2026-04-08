#pragma once
#include<string>

class QuadraticEquation
{
public:
	double a = 0;
	double b = 0;
	double c = 0;

	QuadraticEquation() = default; // он подчёркивает красным пустое место, но всё компилируется

	// получение из строки формата "a b c"
	QuadraticEquation(const std::string equation_string);

	~QuadraticEquation();

	static void normalSolve(const QuadraticEquation& eq, double& root_first, double& root_second);
};

