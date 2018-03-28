#pragma once
#include "TransportBase.h"

class SlowTrack : public TransportBase
{
public:
	SlowTrack();
	void Init();
private:
};

class FastTrack : public TransportBase
{
public:
	FastTrack();
	void Init();
private:
};
