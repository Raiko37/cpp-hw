#pragma once
#include "Student.h"
#include "ScoreTable.h"
#include "Letter.h"

class Teacher
{
	std::vector<QuadraticEquation> equations; // уравнения для выдачи
	std::vector<Student> students; // массив студентов
	std::vector<Letter> unchecked_letters; // массив непроверенных писем
	ScoreTable table; // таблица успеваемости

public:

	// конструктор 
	Teacher(std::vector<QuadraticEquation> equations, std::vector<Student> students);

	~Teacher();

	// возвращает количество непроверенных писем
	int uncheckedLettersAmount();

	// выдаёт новые уравнения ученикам. Если решения прошлых не были запрошены через getLetters, то уравнения у учеников просто заменятся
	void giveEquations();

	// запрашивает письма у учеников и добавляет их в массив непроверенных писем
	void getLetters();

	// проверяет все скопившиеся письма
	void checkLetters();


	// печатает таблицу в консоль
	void publishScores();
};

