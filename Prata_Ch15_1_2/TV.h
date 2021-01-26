#pragma once

#include "Remote.h"

class Tv
{
	friend class Remote;
public:
	enum State { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };
	Tv(int s = Off, int mc = 125) : state(s), volume(5),
		maxchannel(mc), channel(2), mode(Cable), input(TV) {}
	void onoff() { state = (state == On) ? Off : On; }
	bool ison() const { return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
	void set_input() { input = (input == TV) ? DVD : TV; }
	void settings() const;
	void change_remote_interaction_mode(Remote& remote)
	{
		if (state == On)
		{
			remote.interaction_mode = (interaction_mode == Normal) ? Interactive : Normal
		}
	}
private:
	int state;
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;
};