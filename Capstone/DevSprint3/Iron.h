#pragma once

#include "OreBase.h"
#include "allegro5/allegro_native_dialog.h"

class Iron : public OreBase
{
	Iron() : OreBase()
	{
		setTravelSpeed(2);
		setHealth(2);
	}
	void LeftClickInteract();
	void RightClickInteract();
	void Drop();
};