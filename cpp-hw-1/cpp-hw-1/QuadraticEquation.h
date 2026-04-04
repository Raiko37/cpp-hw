#pragma once
#include<string>

class QuadraticEquation
{
public:
	double a;
	double b;
	double c;

	// для начальной инициализации
	QuadraticEquation();


	// получение из строки формата "a b c"
	QuadraticEquation(std::string equation_string);

	~QuadraticEquation();
};

