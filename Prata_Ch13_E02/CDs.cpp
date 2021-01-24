#include "CDs.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	int size = strlen(s1) + 1;
	performers = new char[size];
	strcpy_s(performers, size, s1);
	size = strlen(s2) + 1;
	label = new char[size];
	strcpy_s(label, size, s2);
	numberOfSelections = n;
	playtime = x;
}

Cd::Cd(const Cd& d)
{
	int size = strlen(d.performers) + 1;
	performers = new char[size];
	strcpy_s(performers, size, d.performers);
	size = strlen(d.label) + 1;
	label = new char[size];
	strcpy_s(label, size, d.label);
	numberOfSelections = d.numberOfSelections;
	playtime = d.playtime;
}

Cd& Cd::operator=(const Cd& d)
{
	delete[] performers;
	delete[] label;
	int size = strlen(d.performers) + 1;
	performers = new char[size];
	strcpy_s(performers, size, d.performers);
	size = strlen(d.label) + 1;
	label = new char[size];
	strcpy_s(label, size, d.label);
	numberOfSelections = d.numberOfSelections;
	playtime = d.playtime;
	return *this;
}

Cd::~Cd()
{
	delete[] performers;
	delete[] label;
}

void Cd::Report() const
{
	std::cout << performers << ", " << label << ", " << numberOfSelections << ", " << performers << std::endl;
}

Classic::Classic(const char* s1, const char* s2, const char* s3, int n, double x)
	:Cd(s1, s2, n, x)
{
	int size = strlen(s3) + 1;
	primary_work = new char[size];
	strcpy_s(primary_work, size, s3);
}

Classic::Classic(const Classic& d)
	:Cd(d)
{
	int size = strlen(d.primary_work) + 1;
	primary_work = new char[size];
	strcpy_s(primary_work, size, d.primary_work);
}

Classic& Classic::operator=(const Classic& d)
{
	Cd::operator=(d);
	delete[] primary_work;
	int size = strlen(d.primary_work) + 1;
	primary_work = new char[size];
	strcpy_s(primary_work, size, d.primary_work);
	return *this;
}


Classic::~Classic()
{
	delete[] primary_work;
}

void Classic::Report() const
{
	Cd::Report();
	std::cout << primary_work << std::endl;
}