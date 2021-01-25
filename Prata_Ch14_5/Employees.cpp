#pragma once

#include "Employees.h"

abstr_emp::abstr_emp()
	: fname("xxx"), lname("xxx"), job("xxx")
{}

abstr_emp::abstr_emp(const std::string& fn, const std::string& ln, const std::string& j)
	: fname(fn), lname(ln), job(j)
{}

abstr_emp::~abstr_emp()
{}

void abstr_emp::ShowAll() const
{
	std::cout << " " << fname << " " << lname << " " << job << std::endl;
}

void abstr_emp::SetAll()
{
	fname = "fname";
	lname = "lname";
	job = "job";
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
	os << " " << e.fname << " " << e.lname << " " << e.job;
	return os;
}

employee::employee()
	:abstr_emp()
{}

employee::employee(const std::string& fn, const std::string& ln, const std::string& j)
	: abstr_emp(fn, ln, j)
{}

void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

manager::manager()
	:abstr_emp(), inchargeof(0)
{}

manager::manager(const std::string& fn, const std::string& ln,
	const std::string& j, int ico)
	: abstr_emp(fn, ln, j), inchargeof(ico)
{}

manager::manager(const abstr_emp& e, int ico)
	: abstr_emp(e), inchargeof(ico)
{}

manager::manager(const manager& m)
	: abstr_emp(m)
{
	inchargeof = m.inchargeof;
}

void manager::ShowAll() const
{
	std::cout << *this << inchargeof << std::endl;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	inchargeof = 2;
}


fink::fink()
	:abstr_emp(), reportsto("rpo")
{}

fink::fink(const std::string& fn, const std::string& ln,
	const std::string& j, const std::string& rpo)
	: abstr_emp(fn, ln, j), reportsto(rpo)
{}

fink::fink(const abstr_emp& e, const std::string& rpo)
	: abstr_emp(e), reportsto(rpo)
{}

fink::fink(const fink& e)
	: abstr_emp(e)
{
	reportsto = e.reportsto;
}

void fink::ShowAll() const
{
	std::cout << *this << reportsto << std::endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	reportsto = "rposet";
}

highfink::highfink()
	:abstr_emp(), manager(), fink()
{}

highfink::highfink(const std::string& fn, const std::string& ln,
	const std::string& j, const std::string& rpo, int ico)
	: abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{}

highfink::highfink(const abstr_emp& e, const std::string& rpo, int ico)
	:abstr_emp(e), manager(e, ico), fink(e, rpo)
{}

highfink::highfink(const fink& f, int ico)
	:abstr_emp(f), manager(f, ico), fink(f)
{}

highfink::highfink(const manager& m, const std::string& rpo)
	:abstr_emp(m), manager(m), fink(m, rpo)
{}

highfink::highfink(const highfink& h)
	: abstr_emp(h), manager(h), fink(h)
{}

void highfink::ShowAll() const
{
	std::cout << *this << ReportsTo() << InChargeOf() << std::endl;
 }

void highfink::SetAll()
{
	abstr_emp::SetAll();
	std::string x = ReportsTo();
	x = "HighFinkRPO";
	int y = InChargeOf();
	y = 100;
}