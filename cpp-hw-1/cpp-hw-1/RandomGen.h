#pragma once
#include<random>
class RandomGen
{
public:
	inline static std::mt19937 gen{ std::random_device{}()};

};

