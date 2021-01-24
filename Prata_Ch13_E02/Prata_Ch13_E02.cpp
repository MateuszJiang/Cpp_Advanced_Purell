/*
Derive a Classic class that adds an array of char members that will hold a string
identifying the primary work on the CD. If the base class requires that any functions
be virtual, modify the base-class declaration to make it so. If a declared
method is not needed, remove it from the definition.Test your product with the
following program:
Do Programming Exercise 1 but use dynamic memory allocation instead of fixedsize
arrays for the various strings tracked by the two classes.
*/
#include <iostream>
#include "CDs.h" 

using namespace std;

void Bravo(const Cd& disk);

int main()
{
	const char * d1 = "Beatles";
	Cd c1(d1, d1, 14, 35.5);
	Classic c2 = Classic(d1,
		d1, d1, 2, 57.17);
	Cd* pcd = &c1;
	cout << "Using object directly:\n";
	c1.Report(); // use Cd method
	c2.Report(); // use Classic method
	cout << "Using type cd * pointer to objects:\n";
	pcd->Report(); // use Cd method for cd object
	pcd = &c2;
	pcd->Report(); // use Classic method for classic object
	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);
	cout << "Testing assignment: ";
	Classic copy;
	copy = c2;
	copy.Report();
	return 0;
}

void Bravo(const Cd& disk)
{
	disk.Report();
}