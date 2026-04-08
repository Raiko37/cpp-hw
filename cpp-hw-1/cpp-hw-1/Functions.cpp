#include "Functions.h"
#include "QuadraticEquation.h"
#include "Teacher.h"

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "RandomGen.h"

#include<cmath>
#include <ios>
#include <limits>
#include<cstdlib>



// ОСНОВНЫЕ КЛАССЫ










// достаёт из текстового файла данные построчно 
void ParseFile(std::vector<std::string>& arr, const std::string& file_name) {
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

		
		std::cout << "Current unchecked letters: " << teacher.uncheckedLettersAmount() << "\n";
		int option;
		std::cout << "Your option is: ";
		
		if (std::cin >> option) {
			switch (option) {
			case 1:
				teacher.giveEquations();
				system("cls");
				std::cout << "You gave students new equations!\n\n\n";
				break;
			case 2:
				teacher.getLetters();
				system("cls");
				std::cout << "The students have sent you their letters!\n\n\n";
				break;
			case 3:
				teacher.checkLetters();
				system("cls");
				std::cout << "You checked all the letters!\n\n\n";
				break;
			case 4:
				teacher.giveEquations();
				teacher.getLetters();
				teacher.checkLetters();
				system("cls");
				std::cout << "You gave new equations and checked them!\n\n\n";
				break;
			case 5:
				system("cls");
				teacher.publishScores();
				std::cout << "\n\n";
				break;
			case 6:
				system("cls");
				std::cout << "It's time for the teacher and the students to rest\n"
					<< "Thanks for using the program!\n";
				return;
			default:
				system("cls");
				std::cout << "Seems it isn't an option. Try again\n\n\n";
			}
		}
		else {
			system("cls");
			std::cout << "Error: not a number\n\n\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		
	}
}

// инициализируем и создаём всё нужное
void StartModel() {


	std::vector<std::string> names;
	std::vector<std::string> equation_strings;

	std::string students_file = "Students.txt";
	std::string eq_file = "Equations.txt";

	// достаём данные из файлов
	ParseFile(names, students_file);
	ParseFile(equation_strings, eq_file);


	// рандомизатор
	std::vector<Student> students;
	students.reserve(names.size());

	std::uniform_int_distribution<int> dist(0, 2);

	// создаём учеников
	for (auto& name : names) {
		students.push_back(Student(name, static_cast<StudentType>(dist(RandomGen::gen))));
	}


	std::vector<QuadraticEquation> equations;
	equations.reserve(equation_strings.size());

	// переводим строки в тип уравнения
	for (auto& eq : equation_strings) {
		equations.push_back(QuadraticEquation(eq));
	}


	Teacher teacher(std::move(equations), std::move(students)); // перемещение через move, тут эти массивы уже не нужны будут
	// преподаватель создан

	Interface(teacher);

}