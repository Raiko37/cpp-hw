#pragma once
#include "QuadraticEquation.h"
#include <vector>
#include <string>
#include "Teacher.h"

void NormalSolve(QuadraticEquation eq, double& root_first, double& root_second);

void ParseFile(std::vector<std::string>& arr, std::string file_name);

void PrintSep();

void Interface(Teacher& teacher);

void StartModel();