#include <iostream>

#include "People.h"

int main()
{
    const int CASES = 4;
    Person* people[4];

    people[0] = new Person("Person", "Person");
    people[1] = new Gunslinger("Person", "Gunslinger");
    people[2] = new PokerPlayer("Person", "PokerPlayer");
    people[3] = new BadDude("Person", "BadDude");

    for (int i = 0; i < CASES; i++)
    {
        people[i]->Show();
    }
}
