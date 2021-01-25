#pragma once
#include <string>
#include <iostream>

class Person
{
private:
	std::string FirstName;
	std::string LastName;
public:
	Person() : FirstName("FN"), LastName("LN") {}
	virtual ~Person() {}

	Person(std::string firstName, std::string lastName);
	virtual void Show();
};

class Gunslinger : public virtual Person
{
private:
	int NotchesOnGun;
public:
	Gunslinger() : Person(), NotchesOnGun(0) {}
	virtual ~Gunslinger() {}

	Gunslinger(std::string firstName, std::string lastName, int notchesOnGun = 1);

	double Draw(); //returns draw time, I know its stupid but I didnt make this task
	virtual void Show() override;
};

class PokerPlayer : virtual public Person
{
public:
	PokerPlayer() : Person() {}
	virtual ~PokerPlayer() {}

	PokerPlayer(std::string firstName, std::string lastName);
	int Draw();
	virtual void Show() override;
};

class BadDude : public PokerPlayer, public Gunslinger
{
public:
	BadDude() : PokerPlayer(), Gunslinger(), Person() {}
	virtual ~BadDude() {}

	BadDude(std::string firstName, std::string lastName);

	void Gdraw() { std::cout << Gunslinger::Draw() << std::endl; }
	void Cdraw() { std::cout << PokerPlayer::Draw() << std::endl; }
	virtual void Show() override;
};