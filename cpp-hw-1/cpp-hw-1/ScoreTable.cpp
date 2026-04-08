#include "ScoreTable.h"
#include<unordered_map>
#include<iostream>
#include<string>


ScoreTable::ScoreTable(const std::vector<std::string>& names) {
	for (const auto& name : names) {
		scores[name] = 0; // пользуюсь тем фактом, что запрос несуществующего ключа создаст его со значением 0 
	}
}

ScoreTable::~ScoreTable() {};

// апдейт таблицы, выдаёт балл указанному ученику
void ScoreTable::scoreUpdate(const std::string& name) {
	scores[name] += 1;
}

// собственно, печать таблицы
void ScoreTable::printScores() {
	std::cout << "\n";
	for (const auto& [name, score] : scores) {
		std::cout << name << ": " << score << "\n";
	}
}



