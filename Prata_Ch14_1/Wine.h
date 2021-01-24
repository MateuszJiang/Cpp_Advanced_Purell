#include <valarray>
#include <string>
#include <iostream>

typedef std::valarray<int> ArrayInt;
typedef std::pair<ArrayInt, ArrayInt> PairArray;

class Wine : private std::string, private PairArray
{
private:
	int NumberOfYears;
public:
	Wine(const char* l, int numberOfYears, const int yr[], const int bot[]);
	Wine(const char* l, int numberOfYears);
	Wine() = delete;

	void GetBottles();
	std::string Label();
	int Sum();
	void Show();
};