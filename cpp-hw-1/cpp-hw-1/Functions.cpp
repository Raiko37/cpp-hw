#include "Functions.h"
#include "QuadraticEquation.h"
#include "Teacher.h"

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<random>

#include<cmath>


// нормальное решение уравнения, без ошибок
void NormalSolve(QuadraticEquation eq, double& root_first, double& root_second) {
	double discr = eq.b * eq.b - 4 * eq.a * eq.c;

	if (discr > 0) {
		root_first = (-eq.b + sqrt(discr)) / (2 * eq.a);
		root_second = (-eq.b - sqrt(discr)) / (2 * eq.a);
	}
	else if (discr == 0) {
		root_first = (-eq.b) / (2 * eq.a);
		root_second = root_first;
	}
	else {
		root_first = 0;
		root_second = 0;
		std::cout << "Уравнение с мнимыми корнями\n";  // этого произойти не должно
	}
}

// ОСНОВНЫЕ КЛАССЫ










// достаёт из текстового файла данные построчно 
void ParseFile(std::vector<std::string>& arr, std::string file_name) {
	std::fstream file(file_name);

	if (!file.is_open()) {
		std::cerr << "Не удалось открыть файл " << file_name << "\n";
		return;
	}

	std::string line;

	while (std::getline(file, line)) {
		arr.push_back(line);
	}


	file.close();
}


// просто печать большого разделителя
void PrintSep() {
	std::cout << "------------------------------------------------\n";
}

// интерфейс для интерактива
void Interface(Teacher& teacher) {
	std::cout << "Welcome to the class modeling program!\n\n";
	while (true) {
		PrintSep();
		std::cout << "Options:\n"
			<< "1. Give students random equations\n"
			<< "2. Ask students to send their letters\n"
			<< "3. Check all letters\n"
			<< "4. Give equations and check immediately\n"
			<< "5. Publish the score table\n"
			<< "6. Exit the program\n";
		PrintSep();
		std::cout << "Current unchecked letters: " << teacher.unchekedLettersAmount() << "\n";
		int option;
		std::cout << "Your option is: ";
		std::cin >> option;

		switch (option) {
		case 1:
			teacher.giveEquations();
			std::cout << "You gave students new equations!\n\n\n";
			break;
		case 2:
			teacher.getLetters();
			std::cout << "The students have sent you their letters!\n\n\n";
			break;
		case 3:
			teacher.checkLetters();
			std::cout << "You checked all the letters!\n\n\n";
			break;
		case 4:
			teacher.giveEquations();
			teacher.getLetters();
			teacher.checkLetters();
			std::cout << "You gave new equations and checked them!\n\n\n";
			break;
		case 5:
			teacher.publishScores();
			std::cout << "\n\n";
			break;
		case 6:
			std::cout << "It's time for the teacher and the students to rest\n"
				<< "Thanks for using the program!\n";
			return;
			break; // на всякий случай
		default:
			std::cout << "Seems it isn't an option. Try again\n\n\n";
		}
	}
}

// инициализируем и создаём всё нужное
void StartModel() {


	std::vector<std::string> names;
	std::vector<std::string> equation_strings;

	// достаём данные из файлов
	ParseFile(names, "Students.txt");
	ParseFile(equation_strings, "Equations.txt");


	// рандомизатор
	std::vector<Student> students;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0, 2);

	// создаём учеников
	for (auto name : names) {
		students.push_back(Student(name, static_cast<StudentType>(dist(gen))));
	}


	std::vector<QuadraticEquation> equations;

	// переводим строки в тип уравнения
	for (auto eq : equation_strings) {
		equations.push_back(QuadraticEquation(eq));
	}


	Teacher teacher(std::move(equations), std::move(students), names); // перемещение через move, тут эти массивы уже не нужны будут
	// преподаватель создан

	Interface(teacher);

}