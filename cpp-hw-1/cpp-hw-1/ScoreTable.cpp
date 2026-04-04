#include "ScoreTable.h"
#include<unordered_map>
#include<iostream>
#include<string>


ScoreTable::ScoreTable(std::vector<std::string> names) {
	for (auto name : names) {
		scores[name]; // пользуюсь тем фактом, что запрос несуществующего ключа создаст его со значением 0 
	}
}

ScoreTable::~ScoreTable() {};

// апдейт таблицы, выдаёт балл указанному ученику
void ScoreTable::scoreUpdate(std::string name) {
	scores[name] += 1;
}

// собственно, печать таблицы
void ScoreTable::printScores() {
	std::cout << "\n";
	for (auto& [name, score] : scores) {
		std::cout << name << ": " << score << "\n";
	}
}



