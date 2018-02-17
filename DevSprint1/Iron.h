#pragma once

#include "ore.h"

class Iron : public Ore
{
	Iron() : Ore()
	{
		setTravelSpeed(2);
		setHealth(2);
	}
	void LeftClickInteract();
	void RightClickInteract();
	void Drop();
};