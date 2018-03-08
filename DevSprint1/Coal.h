#pragma once

#include "OreBase.h"
#include "allegro5/allegro_native_dialog.h"

class Coal : public OreBase
{
public:
	Coal() : OreBase()
	{
		setTravelSpeed(2);
		setHealth(3);
	}
	void Interact();
	void leftClickInteract();
	void rightClickInteract();
	void Drop();
};