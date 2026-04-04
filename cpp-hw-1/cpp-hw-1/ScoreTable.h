#pragma once

#include<unordered_map>
#include<string>
#include <vector>
class ScoreTable
{
	std::unordered_map<std::string, int> scores;

public:
	ScoreTable(std::vector<std::string> names);

	~ScoreTable();

	// апдейт таблицы, выдаёт балл указанному ученику
	void scoreUpdate(std::string name);

	// собственно, печать таблицы
	void printScores();
};

