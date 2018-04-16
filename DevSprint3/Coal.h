#pragma once

#include "OreBase.h"

#include "allegro5/allegro_native_dialog.h"

class Coal : public OreBase
{
public:
	
	//! Constructor
	Coal() : OreBase()
	{
		setTravelSpeed(2);
		setHealth(3);
	}

	//! Performs Interactions
	void Interact();

	//! What Happens when Ore is Left Clicked
	void leftClickInteract();

	//! What Happens when Ore is Right Clicked
	void rightClickInteract();

	//! What Happens when Ore is Mined
	void Drop();
};