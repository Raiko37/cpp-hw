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
	Student(const std::string& name, const StudentType type) : name(name), type(type) {};


	const std::string& getName() const { return name; }

	// сеттер для уравнения
	void setEquation(const QuadraticEquation& equation){
		this->equation = equation;
	};

	// составляет и возвращает письмо с решениями
	Letter composeLetter();
};

