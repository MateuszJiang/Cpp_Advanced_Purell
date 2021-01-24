#include "Wine.h"

Wine::Wine(const char* l, int numberOfYears, const int yr[], const int bot[])
	:PairArray(numberOfYears, numberOfYears), std::string("sss")
{

	NumberOfYears = numberOfYears;
	for (int i = 0; i < numberOfYears; i++)
	{
		PairArray::first[i] = yr[i];
		PairArray::second[i] = bot[i];
	}
}
Wine::Wine(const char* l, int numberOfYears)
	:PairArray(numberOfYears, numberOfYears), std::string("sss")
{
	NumberOfYears = numberOfYears;
}

void Wine::GetBottles()
{
	for (int i = 0; i < NumberOfYears; i++)
	{
		PairArray::first[i] = i;
		PairArray::second[i] = i;
	}
}
std::string Wine::Label()
{
	return std::string::data();
}

int Wine::Sum()
{
	return PairArray::second.sum();
}

void Wine::Show()
{
	for (int i = 0; i < NumberOfYears; i++)
	{
		std::cout << PairArray::second[i] << std::endl;
	}
}