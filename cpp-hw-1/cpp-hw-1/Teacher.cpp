#include "Teacher.h"
#include "Letter.h"
#include "QuadraticEquation.h"
#include "Student.h"
#include "ScoreTable.h"
#include "Functions.h"
#include<vector>
#include<random>




// конструктор 
Teacher::Teacher(std::vector<QuadraticEquation> m_equations, std::vector<Student> m_students, std::vector<std::string> names) :
	equations(std::move(m_equations)),
	students(std::move(m_students)),
	table(names) {
}

Teacher::~Teacher() {};

// возвращает количество непроверенных писем
int Teacher::unchekedLettersAmount() {
	return uncheked_letters.size();
}

// выдаёт новые уравнения ученикам. Если решения прошлых не были запрошены через getLetters, то уравнения у учеников просто заменятся
void Teacher::giveEquations() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0, equations.size() - 1);

	for (auto& student : students) {
		student.setEquation(equations[dist(gen)]);
	}
}

// запрашивает письма у учеников и добавляет их в массив непроверенных писем
void Teacher::getLetters() {
	for (auto& student : students) {
		uncheked_letters.push_back(student.composeLetter());
	}
}

// проверяет все скопившиеся письма
void Teacher::checkLetters() {
	double real_first;
	double real_second;

	for (auto letter : uncheked_letters) {
		NormalSolve(letter.equation, real_first, real_second);

		bool isRight = (real_first == letter.root_first && real_second == letter.root_second) ||
			(real_first == letter.root_second && real_second == letter.root_first);

		if (isRight) {
			table.scoreUpdate(letter.name);
		}
	}

	uncheked_letters.clear();
}


// печатает таблицу в консоль
void Teacher::publishScores() {
	table.printScores();
}
