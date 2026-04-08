#pragma once
#include "QuadraticEquation.h"
#include <vector>
#include <string>
#include "Teacher.h"



void ParseFile(std::vector<std::string>& arr, const std::string& file_name);

void PrintSep();

void Interface(Teacher& teacher);

void StartModel();