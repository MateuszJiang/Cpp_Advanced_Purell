#include "People.h"
#include <random>
#include <time.h>

Person::Person(std::string firstName, std::string lastName)
	: FirstName(firstName), LastName(lastName)
{}

void Person::Show()
{
	std::cout << FirstName << " " << LastName << std::endl;
}

Gunslinger::Gunslinger(std::string firstName, std::string lastName, int notchesOnGun)
	: Person(firstName, lastName), NotchesOnGun(notchesOnGun)
{}

double Gunslinger::Draw()
{
	return 1.32;
}

void Gunslinger::Show()
{
	Person::Show();
	std::cout << NotchesOnGun << " " << Draw() << std::endl;
}

PokerPlayer::PokerPlayer(std::string firstName, std::string lastName)
	:Person(firstName, lastName)
{}

int PokerPlayer::Draw()
{
	srand(time(nullptr));
	int x = std::rand() / (RAND_MAX / 52);
	return x;
}

void PokerPlayer::Show()
{
	Person::Show();
	std::cout << Draw() << std::endl;
}

BadDude::BadDude(std::string firstName, std::string lastName)
	:Person(firstName, lastName), Gunslinger(), PokerPlayer()
{}

void BadDude::Show()
{
	Person::Show();
	Gdraw();
	Cdraw();
}