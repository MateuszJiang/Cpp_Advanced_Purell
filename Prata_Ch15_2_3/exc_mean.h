#pragma once
// exc_mean.h -- exception classes for hmean(), gmean()
#include <iostream>
#include <stdexcept>

class bad_mean_types : public std::logic_error
{
protected:
	double v1;
	double v2;
public:
	bad_mean_types(double a = 0, double b = 0,
		const std::string& s = "logic_error - common bad mean calculation")
		: std::logic_error(s), v1(a), v2(b)
	{}
	virtual void report() = 0;
};

class bad_hmean : public bad_mean_types
{
public:
	bad_hmean(double a = 0, double b = 0, 
		const std::string& s= "logic_error - bad hmean")
		: bad_mean_types(a,b,s)
	{}
	void report() { std::cout << v1 << "   " << v2 << std::endl; }
};

class bad_gmean : public bad_mean_types
{
public:
	bad_gmean(double a = 0, double b = 0, 
		const std::string& s = "logic_error - bad gmean")
		: bad_mean_types(a, b, s)
	{}
	void report() 
	{ 
		std::cout << v1 << "   " << v2 << std::endl; 
	}
};
