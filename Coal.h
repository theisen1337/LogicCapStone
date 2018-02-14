#pragma once

#include "Ore.h"

class Coal : public Ore
{
public:
	Coal() : Ore()
	{
		setTravelSpeed(2);
		setHealth(3);
	}
	void LeftClickInteract();
	void RightClickInteract();
	void Drop();
};