#pragma once

#include "Ore.h"
#include "allegro5/allegro_native_dialog.h"

class Coal : public Ore
{
public:
	Coal() : Ore()
	{
		setTravelSpeed(2);
		setHealth(3);
	}
	void Interact();
	void leftClickInteract();
	void rightClickInteract();
	void Drop();
};