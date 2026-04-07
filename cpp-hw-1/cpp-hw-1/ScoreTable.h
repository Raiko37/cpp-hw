#pragma once

#include<unordered_map>
#include<string>
#include <vector>
#include "Student.h"

class ScoreTable
{
	std::unordered_map<std::string, int> scores;

public:
	ScoreTable(std::vector<Student>& m_students);

	~ScoreTable();

	// апдейт таблицы, выдаёт балл указанному ученику
	void scoreUpdate(std::string& name);

	// собственно, печать таблицы
	void printScores();
};

