#pragma once
#include "QuadraticEquation.h"
#include "StudentType.h"
#include "Letter.h"

class Student
{
private:
	std::string name;
	QuadraticEquation equation;
	StudentType type;

	// решает уравнение с учетом типа ученика
	void solveEquation(double& root_first, double& root_second);


public:
	Student(std::string name, StudentType type);

	// сеттер для уравнения
	void setEquation(QuadraticEquation equation);

	// составляет и возвращает письмо с решениями
	Letter composeLetter();
};

