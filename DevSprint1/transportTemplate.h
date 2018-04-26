#pragma once
#include "Transport.h"

class SlowTrack : public Transport
{
public:
	SlowTrack();
	void Init();
private:
};

class FastTrack : public Transport
{
public:
	FastTrack();
	void Init();
private:
};
