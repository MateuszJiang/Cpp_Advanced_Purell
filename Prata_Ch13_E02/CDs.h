#pragma once

class Cd 
{ // represents a CD disk
private:
	char *performers;
	char *label;
	int numberOfSelections;
	double playtime; // in minutes
public:
	Cd() {}
	Cd(const char* s1, const char* s2, int n, double x);
	Cd(const Cd& d);
	virtual ~Cd();
	virtual void Report() const;
	Cd& operator=(const Cd& d);
};

class Classic : public Cd
{
private:
	char *primary_work;
public:
	Classic() {};
	~Classic();
	Classic(const char* s1, const char* s2, const char* s3, int n, double x);
	Classic(const Classic& d);
	Classic& operator=(const Classic& d);
	virtual void Report() const override;
};