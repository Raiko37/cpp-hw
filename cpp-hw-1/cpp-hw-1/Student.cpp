#include "Student.h"
#include "StudentType.h"
#include "Letter.h"
#include "QuadraticEquation.h"
#include "Functions.h"

#include<string>
#include<random>


// решает уравнение с учетом типа ученика
void Student::solveEquation(double& root_first, double& root_second) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0, 1);

	switch (type) {
	case StudentType::GOOD:
		NormalSolve(equation, root_first, root_second);
		break;
	case StudentType::AVERAGE:
		NormalSolve(equation, root_first, root_second);



		if (dist(gen)) {
			root_first += 1;
			root_second -= 1;
		}
		break;
	case StudentType::BAD:
		root_first = 0;
		root_second = 0;
		break;
	}
}



Student::Student(std::string name, StudentType type) {
	this->name = name;
	this->type = type;
}

// сеттер для уравнения
void Student::setEquation(QuadraticEquation equation) {
	this->equation = equation;
}

// составляет и возвращает письмо с решениями
Letter Student::composeLetter() {
	double root_first, root_second;

	solveEquation(root_first, root_second);

	return Letter(name, equation, root_first, root_second);
}
