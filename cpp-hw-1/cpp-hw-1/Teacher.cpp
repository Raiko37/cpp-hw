#include "Teacher.h"
#include "Letter.h"
#include "QuadraticEquation.h"
#include "Student.h"
#include "ScoreTable.h"
#include "Functions.h"
#include<vector>
#include "RandomGen.h"




// конструктор 
Teacher::Teacher(std::vector<QuadraticEquation> m_equations, std::vector<Student> m_students, std::vector<std::string> names) :
	equations(std::move(m_equations)),
	students(std::move(m_students)),
	table(students) {
}

Teacher::~Teacher() {};

// возвращает количество непроверенных писем
int Teacher::uncheckedLettersAmount() {
	return unchecked_letters.size();
}

// выдаёт новые уравнения ученикам. Если решения прошлых не были запрошены через getLetters, то уравнения у учеников просто заменятся
void Teacher::giveEquations() {
	std::uniform_int_distribution<int> dist(0, equations.size() - 1);
	
	for (auto& student : students) {
		student.setEquation(equations[dist(RandomGen::gen)]);
	}
}

// запрашивает письма у учеников и добавляет их в массив непроверенных писем
void Teacher::getLetters() {
	for (auto& student : students) {
		unchecked_letters.push_back(student.composeLetter());
	}
}

// проверяет все скопившиеся письма
void Teacher::checkLetters() {
	double real_first;
	double real_second;

	for (auto& letter : unchecked_letters) {
		QuadraticEquation::normalSolve(letter.equation, real_first, real_second);

		const double eps = 1e-13;

		bool isRight = (std::abs(real_first - letter.root_first) < eps && std::abs(real_second - letter.root_second) < eps) ||
			(std::abs(real_first - letter.root_second) < eps && std::abs(real_second - letter.root_first) < eps);

		if (isRight) {
			table.scoreUpdate(letter.name);
		}
	}

	unchecked_letters.clear();
}


// печатает таблицу в консоль
void Teacher::publishScores() {
	table.printScores();
}
