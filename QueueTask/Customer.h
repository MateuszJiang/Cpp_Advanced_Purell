#pragma once

#include <cstdlib>

class Customer
{
private:
	long arrival_time;
	int process_time;
public:
	Customer() { arrival_time = process_time = 0; }
	void set(long when_arrived) 
	{
		arrival_time = when_arrived;
		process_time = std::rand() % 3 + 1;
	}
	long when_arrived() const { return arrival_time; }
	int get_processing_time() const { return process_time; }
};