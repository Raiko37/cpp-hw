#include "ScoreTable.h"
#include<unordered_map>
#include<iostream>
#include<string>
#include "Student.h"

ScoreTable::ScoreTable(std::vector<Student>& m_students) {
	for (auto& student : m_students) {
		scores[student.getName()]; // пользуюсь тем фактом, что запрос несуществующего ключа создаст его со значением 0 
	}
}

ScoreTable::~ScoreTable() {};

// апдейт таблицы, выдаёт балл указанному ученику
void ScoreTable::scoreUpdate(std::string& name) {
	scores[name] += 1;
}

// собственно, печать таблицы
void ScoreTable::printScores() {
	std::cout << "\n";
	for (const auto& [name, score] : scores) {
		std::cout << name << ": " << score << "\n";
	}
}



