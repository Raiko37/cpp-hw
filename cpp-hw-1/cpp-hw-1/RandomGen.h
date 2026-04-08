#pragma once
#include<random>
namespace RandomGen
{
	inline std::mt19937 gen{ std::random_device{}()};
};

