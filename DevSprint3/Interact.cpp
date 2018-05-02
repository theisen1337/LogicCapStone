#include "Interact.h"

// Creates Allegro Event for Monitoring Inputs
ALLEGRO_EVENT event;

// ###############
// # Constructor #
// ###############
Interact::Interact() {}

// #################
// # Deconstructor #
// #################
Interact::~Interact() {}

// ##############################
// # Swap Active Placement Mode #
// ##############################
void Interact::swapActive(bool &active)
{
	if (active) // If you are in a mode other than interact ...
	{
		interactMode = true;

		active = false;
	}
	else // If you are in interact mode ...
	{
		slot1 = false; slot2 = false; slot3 = false; slot4 = false;
		slot5 = false; slot6 = false; slot7 = false; slot8 = false;
		machineMode = false; itemMode = false; interactMode = false;

		active = true;
	}
}

// ####################################
// # Checks the Active Placement Mode #
// ####################################
int Interact::checkActive()
{
	for (int i = 0; i < sizeof(stateArray); i++)
	{
		if (*stateArray[i] == true)
		{
			return i;
		}
	}

	return -1;
}

// ###############################
// # Places Objects onto the Map #
// ###############################
void Interact::placeObject(ObjectManager &OM, int X, int Y, int index)
{
	if (OM.hotbar[index].machine) // If placing machine from hotbar ...
	{
		// Calculates Positioning of Machines
		int machineX = X / 64; machineX *= 64;
		int machineY = Y / 64; machineY *= 64;

		// Places Machine In-game
		OM.addMachine(machineX, machineY, index);
		OM.hotbar[index].num -= 1;

		cout << "Placed " << OM.hotbar[index].machineType << endl << endl;

		if (OM.hotbar[index].num == 0) // If out of objects in hotbar slot ...
		{
			cout << "Slot " << index + 1 << " is Empty" << endl;
			OM.hotbar[index].machine = false;
			OM.hotbar[index].machineType = "";
		}
		else if (OM.hotbar[index].num == 1) // If plural ...
		{
			cout << "Slot " << index + 1 << " Now Contains: " << OM.hotbar[index].num << " " << OM.hotbar[index].machineType << endl;
		}
		else
		{
			cout << "Slot " << index + 1 << " Now Contains: " << OM.hotbar[index].num << " " << OM.hotbar[index].machineType << "'s" << endl;
		}

		std::vector<string> arrHotbar;
		for (int i = 0; i < 8; i++)
		{
			if (i == index)
			{
				arrHotbar.push_back("X");
			}
			else
			{
				arrHotbar.push_back(" ");
			}
		}

		cout << "[ " << arrHotbar[0] << " ] ";
		cout << "[ " << arrHotbar[1] << " ] ";
		cout << "[ " << arrHotbar[2] << " ] ";
		cout << "[ " << arrHotbar[3] << " ] ";
		cout << "[ " << arrHotbar[4] << " ] ";
		cout << "[ " << arrHotbar[5] << " ] ";
		cout << "[ " << arrHotbar[6] << " ] ";
		cout << "[ " << arrHotbar[7] << " ] " << endl << endl;
	}
	else if (OM.hotbar[index].item) // If placing item from hotbar ...
	{
		int itemX = X - 8;
		int itemY = Y - 8;

		OM.addItem(itemX, itemY, index);
		OM.hotbar[index].num -= 1;

		cout << "Placed " << OM.hotbar[index].itemType << endl << endl;

		if (OM.hotbar[index].num == 0) 
		{
			cout << "Slot " << index + 1 << " is Empty" << endl;
			OM.hotbar[index].item = false;
			OM.hotbar[index].itemType = "";
		}
		else if (OM.hotbar[index].num == 1)
		{
			cout << "Slot " << index + 1 << " New Contains: " << OM.hotbar[index].num << " " << OM.hotbar[index].itemType << endl;
		}
		else
		{
			cout << "Slot " << index + 1 << " New Contains: " << OM.hotbar[index].num << " " << OM.hotbar[index].itemType << "'s" << endl;
		}
		
		std::vector<string> arrHotbar;
		for (int i = 0; i < 8; i++)
		{
			if (i == index)
			{
				arrHotbar.push_back("X");
			}
			else
			{
				arrHotbar.push_back(" ");
			}
		}

		cout << "[ " << arrHotbar[0] << " ] ";
		cout << "[ " << arrHotbar[1] << " ] ";
		cout << "[ " << arrHotbar[2] << " ] ";
		cout << "[ " << arrHotbar[3] << " ] ";
		cout << "[ " << arrHotbar[4] << " ] ";
		cout << "[ " << arrHotbar[5] << " ] ";
		cout << "[ " << arrHotbar[6] << " ] ";
		cout << "[ " << arrHotbar[7] << " ] " << endl << endl;
	}
	else
	{
		cout << "Slot " << index + 1 << "is Empty" << endl;
	}
}

// ##############################
// # Spawn Objects onto the Map # [Not Implemented Yet]
// ##############################
void Interact::spawnObject(ObjectManager &OM, int X, int Y)
{
	if (*stateArray[8] == true) // Spawn Machines
	{
		//OM.addMachine(OM, X, Y);
		// Need way to specify type of machine
	}
	else if (*stateArray[9] == true) // Spawn Items
	{

	}
	else if (*stateArray[10] == true) // Spawn Tracks
	{

	}
	else
	{
		cout << "You tried to spawn an object, but currently are not able to. This shouldn't happen. You broke it bill." << endl;
	}
}

// ##############################
// # Prints Current Hotbar Slot #
// ##############################
void Interact::printSlot(ObjectManager &OM, bool &slot, int index)
{
	swapActive(slot);

	if (slot) // If you are selecting a hotbar slot ...
	{
		if (OM.hotbar[index].num != 0) // If there are objects in the slot ...
		{
			if (OM.hotbar[index].machine) // If the objects are machines ...
			{
				if (OM.hotbar[index].num == 1) // Plural Printing
				{
					cout << "Slot " << index + 1 << " Contains: " << OM.hotbar[index].num << " " << OM.hotbar[index].machineType << endl;
				}
				else
				{
					cout << "Slot " << index + 1 << " Contains: " << OM.hotbar[index].num << " " << OM.hotbar[index].machineType << "'s" << endl;
				}
			}
			else if (OM.hotbar[index].item) // If the objects are item ...
			{
				if (OM.hotbar[index].num == 1) // Plural Printing
				{
					cout << "Slot " << index + 1 << " Contains: " << OM.hotbar[index].num << " " << OM.hotbar[index].itemType << endl;
				}
				else
				{
					cout << "Slot " << index + 1 << " Contains: " << OM.hotbar[index].num << " " << OM.hotbar[index].itemType << "'s" << endl;
				}
			}
			else
			{
				cout << "Slot " << index + 1 << " is Empty" << endl;
			}

			std::vector<string> arrHotbar;
			for (int i = 0; i < 8; i++)
			{
				if (i == index)
				{
					arrHotbar.push_back("X");
				}
				else
				{
					arrHotbar.push_back(" ");
				}
			}

			cout << "[ " << arrHotbar[0] << " ] ";
			cout << "[ " << arrHotbar[1] << " ] ";
			cout << "[ " << arrHotbar[2] << " ] ";
			cout << "[ " << arrHotbar[3] << " ] ";
			cout << "[ " << arrHotbar[4] << " ] ";
			cout << "[ " << arrHotbar[5] << " ] ";
			cout << "[ " << arrHotbar[6] << " ] ";
			cout << "[ " << arrHotbar[7] << " ] " << endl << endl;
		}
	}
	else
	{
		cout << "Slot " << index + 1 << " Deselected" << endl;
		cout << "Enable Interact Mode" << endl;
	}
}

// ########################
// # Prints Entire Hotbar #
// ########################
void Interact::printHotbar(ObjectManager &OM)
{
	cout << "#########################################################################################################" << endl << endl;
	cout << "[ h1 ] [ h2 ] [ h3 ] [ h4 ] [ h5 ] [ h6 ] [ h7 ] [ h8 ] " << endl << endl;


	for (int i = 0; i < 8; i++)
	{
		cout << "[ h" << i + 1 << " ] = ";

		if (OM.hotbar[i].num == 0)
		{
			cout << "Empty" << endl;
		}
		else
		{
			if (OM.hotbar[i].machine)
			{
				if (OM.hotbar[i].num == 1)
				{
					cout << OM.hotbar[i].num << " " << OM.hotbar[i].machineType << endl;
				}
				else
				{
					cout << OM.hotbar[i].num << " " << OM.hotbar[i].machineType << "'s" << endl;
				}
			}
			else if (OM.hotbar[i].item)
			{
				if (OM.hotbar[i].num == 1)
				{
					cout << OM.hotbar[i].num << " " << OM.hotbar[i].itemType << endl;
				}
				else
				{
					cout << OM.hotbar[i].num << " " << OM.hotbar[i].itemType << "'s" << endl;
				}
			}
			else
			{
				cout << "ERROR, FIX ME" << endl;
			}
		}
	}
}

// ################################
// # Finds First Open Hotbar Slot #
// ################################
int Interact::findSlot(ObjectManager &OM, std::string name)
{
	// Checks if Item is Already in Hotbar
	for (int i = 0; i < 8; i++)
	{
		if (name.compare(OM.hotbar[i].itemType) == 0)
		{
			return i;
		}
		else if (name.compare(OM.hotbar[i].machineType) == 0)
		{
			return i;
		}
	}

	// Checks for Empty Slots in Hotbar
	for (int j = 0; j < 8; j++)
	{
		if (!OM.hotbar[j].item && !OM.hotbar[j].machine)
		{
			return j;
		}
	}
}

// ####################################
// # Search for Closest Object on Map #
// ####################################
void Interact::objectSearch(ObjectManager &OM, int mouseX, int mouseY)
{
	int prevDistance = 0;
	int newDistance = 0;
	int objectX = 1000000; // IMPROVE
	int objectY = 1000000; // IMPROVE
	int objectIndex = 0;

	// Initialize Distance
	prevDistance = sqrt(pow((mouseX - objectX), 2) + pow((mouseY - objectY), 2));

	// ##################
	// # LOOP FOR ITEMS #
	// ##################

	// Loops Through the Item Layer and Finds Closest Item to the Mouse Release
	for (int i = 0; i < OM.getIL().arrItems.size(); i++)
	{
		// Calculates New Distance Between Mouse and Object from Item Layer
		newDistance = sqrt(pow((mouseX - OM.getIL().arrItems[i].getCoordinateX()), 2) + pow((mouseY - OM.getIL().arrItems[i].getCoordinateY()), 2));

		if (newDistance < prevDistance) // If the Newly Calculated Distance is Closer than the Previous ...
		{
			prevDistance = newDistance;

			// Grab X and Y of Object
			objectX = OM.getIL().arrItems[i].getCoordinateX();
			objectY = OM.getIL().arrItems[i].getCoordinateY();

			// Set X and Y to Center of Object
			objectX += 8; closeObject.objectX = objectX;
			objectY += 8; closeObject.objectY = objectY;

			objectIndex = i; closeObject.objectIndex = objectIndex;

			closeObject.objectName = OM.getIL().arrItems[i].getName();
		}
	}

	// Set Boundaries of Object
	maxX = objectX + 8; minX = objectX - 8;
	maxY = objectY + 8; minY = objectY - 8;

	if ((mouseX < maxX && mouseX > minX) && (mouseY < maxY && mouseY > minY)) // If user clicks on an Item ...
	{
		closeObject.machine = false; closeObject.ore = false;
		closeObject.item = true;
		return;
	}

	// #########################
	// # LOOP FOR THE MACHINES #
	// #########################

	// Loops Through the Machine Layer and Finds Closest Machine to the Mouse Release
	for (int j = 0; j < OM.getML().arrMachines.size(); j++)
	{
		// Calculates New Distance Between Mouse and Object from Machine Layer
		newDistance = sqrt(pow((mouseX - OM.getML().arrMachines[j].getPlacementX()), 2) + pow((mouseY - OM.getML().arrMachines[j].getPlacementY()), 2));

		if (newDistance < prevDistance) // If the Newly Calculated Distance is Closer than the Previous ...
		{
			prevDistance = newDistance;

			// Grab World X and Y
			objectX = OM.getML().arrMachines[j].getPlacementX();
			objectY = OM.getML().arrMachines[j].getPlacementY();

			// Set X and Y to Center of Object
			objectX += 32; closeObject.objectX = objectX;
			objectY += 32; closeObject.objectY = objectY;

			objectIndex = j; closeObject.objectIndex = objectIndex;

			closeObject.objectName = OM.getML().arrMachines[j].getName();
		}
	}

	// Sets the Boundaries of the Nearest Object
	maxX = objectX + 32; minX = objectX - 32;
	maxY = objectY + 32; minY = objectY - 32;

	if ((mouseX < maxX && mouseX > minX) && (mouseY < maxY && mouseY > minY)) // If the User Clicked Within the Object's Boundaries ...
	{
		closeObject.item = false; closeObject.ore = false;
		closeObject.machine = true;
		return;
	}

	// #####################
	// # LOOP FOR THE ORES #
	// #####################

	// Loops through the Ore Layer and Finds Closest Ore to Mouse Release
	for (int k = 0; k < OM.getOL().layer.size(); k++)
	{
		// Calculate New Distance Between Mouse and Object from Ore Layer
		newDistance = sqrt(pow((mouseX - OM.getOL().layer[k].getLocX()), 2) + pow((mouseY - OM.getOL().layer[k].getLocY()), 2));

		if (newDistance < prevDistance) // If Newly Calculated Distance is Closer than Previous ...
		{
			prevDistance = newDistance;

			// Grab World X and Y
			objectX = OM.getOL().layer[k].getLocX();
			objectY = OM.getOL().layer[k].getLocY();

			// Set X and Y to Center of Object
			objectX += 32; 
			closeObject.objectX = objectX;
			objectY += 32; 
			closeObject.objectY = objectY;

			objectIndex = k; closeObject.objectIndex = objectIndex;

			closeObject.objectName = OM.getOL().layer[k].getName();
		}
	}

	// Sets Boundaries of Nearest Object
	maxX = objectX + 32; minX = objectX - 32;
	maxY = objectY + 32; minY = objectY - 32;

	if ((mouseX < maxX && mouseX > minX) && (mouseY < maxY && mouseY > minY))
	{
		closeObject.item = false; closeObject.machine = false;
		closeObject.ore = true;
		return;
	}

	closeObject.machine = false;
	closeObject.item = false;
	closeObject.ore = false;
	closeObject.objectX = 0;
	closeObject.objectY = 0;
	closeObject.objectIndex = 0;
}

// #################
// # Place Objects #
// #################
void Interact::placement(ObjectManager &OM, int mouseX, int mouseY)
{
	switch (checkActive())
	{
	case 0:
		if (OM.hotbar[0].num != 0) // If the hotbar slot 1 is not empty ...
		{
			placeObject(OM, mouseX, mouseY, 0);
		}
		break;

	case 1:
		if (OM.hotbar[1].num != 0) // If the hotbar slot 2 is not empty ...
		{
			placeObject(OM, mouseX, mouseY, 1);
		}
		break;

	case 2:
		if (OM.hotbar[2].num != 0) // If the hotbar slot 3 is not empty ...
		{
			placeObject(OM, mouseX, mouseY, 2);
		}
		break;

	case 3:
		if (OM.hotbar[3].num != 0) // If the hotbar slot 4 is not empty ...
		{
			placeObject(OM, mouseX, mouseY, 3);
		}
		break;

	case 4:
		if (OM.hotbar[4].num != 0) // If the hotbar slot 5 is not empty ...
		{
			placeObject(OM, mouseX, mouseY, 4);
		}
		break;

	case 5:
		if (OM.hotbar[5].num != 0) // If the hotbar slot 6 is not empty ...
		{
			placeObject(OM, mouseX, mouseY, 5);
		}
		break;

	case 6:
		if (OM.hotbar[6].num != 0) // If the hotbar slot 7 is not empty ...
		{
			placeObject(OM, mouseX, mouseY, 6);
		}
		break;

	case 7:
		if (OM.hotbar[7].num != 0) // If the hotbar slot 8 is not empty ...
		{
			placeObject(OM, mouseX, mouseY, 7);
		}
		break;

	case 8:
		// Place Machine Object
		spawnObject(OM, mouseX, mouseY);
		break;

	case 9:
		// Place Item Object
		spawnObject(OM, mouseX, mouseY);
		break;

	case 10:
		// Place Track Object
		spawnObject(OM, mouseX, mouseY);
		break;

	case 11:
		// No Placement [Case Not Needed]
		std::cout << "Not Needed Case" << endl;
		break;

	case -1:
		// Nothing is Active [ERROR]
		std::cout << "ERROR" << endl;
		break;
	}
}

// #########################
// # Interact with Objects #
// #########################
void Interact::interactions(ObjectManager &OM, World &Map, int mouseX, int mouseY)
{
	objectSearch(OM, mouseX, mouseY);

	//cout << "Object is item? " << closeObject.item << endl;
	//cout << "Object is machine? " << closeObject.machine << endl;
	//cout << "Object is ore? " << closeObject.ore << endl;
	//cout << "ObjectX: " << closeObject.objectX << endl;
	//cout << "ObjectY: " << closeObject.objectY << endl;
	//cout << "ObjectIndex: " << closeObject.objectIndex << endl;

	int objectIndex = closeObject.objectIndex;

	int hotbarIndex;

	if (closeObject.machine)
	{
		if (mouse == 1) // If the Left Button was Pressed ...
		{
			// 'Left Click' Machine
			OM.getML().arrMachines[objectIndex].leftClick();
			return;
		}
		else if (mouse == 2) // If the Right Button was Pressed ...
		{
			// 'Right Click' Machine
			//OM.getML().arrMachines[objectIndex].rightClick();
			//return;

			//std::string name = OM.getML().arrMachines[objectIndex].getName();

			hotbarIndex = findSlot(OM, closeObject.objectName);

			OM.hotbar[hotbarIndex].machine = true;
			OM.hotbar[hotbarIndex].machineType = closeObject.objectName;
			OM.hotbar[hotbarIndex].num++;

			OM.getML().arrMachines.erase(OM.getML().arrMachines.begin() + objectIndex);
			return;
		}
		else // If Somehow No Button was Pressed (Possibly Error or middle mouse click) ...
		{
			cout << "ERROR, Please Fix" << endl;
			return;
		}
	}
	else if (closeObject.item)
	{
		if (mouse == 1) // If the Left Button was Pressed ...
		{
			// 'Left Click' Object
			OM.getIL().arrItems[objectIndex].leftClick();
			return;
		}
		else if (mouse == 2) // If the Right Button was Pressed ...
		{
			// 'Right Click' Object

			hotbarIndex = findSlot(OM, closeObject.objectName);

			OM.hotbar[hotbarIndex].item = true;
			OM.hotbar[hotbarIndex].itemType = closeObject.objectName;
			OM.hotbar[hotbarIndex].num++;

			OM.getIL().arrItems.erase(OM.getIL().arrItems.begin() + objectIndex);
			return;
		}
		else // If Somehow No Button was Pressed (Possibly Error) ...
		{
			cout << "ERROR, Please fix" << endl;
			return;
		}
	}
	else if (closeObject.ore)
	{
		if (mouse == 1) // If left clicked ...
		{
			// 'Left Click' Ore
			OM.getOL().layer[objectIndex].leftClickInteract();
			return;
		}
		else if (mouse == 2)
		{
			// 'Right Click' Ore
			OM.getOL().layer[objectIndex].rightClickInteract();

			if (OM.getOL().layer[objectIndex].getHealth() == 0)
			{
				if (OM.getOL().layer[objectIndex].getStatus())
				{
					hotbarIndex = findSlot(OM, closeObject.objectName);

					OM.hotbar[hotbarIndex].item = true;
					OM.hotbar[hotbarIndex].itemType = closeObject.objectName; // Set to coal item name
					OM.hotbar[hotbarIndex].num++;

					OM.getOL().layer[objectIndex].setStatus(false);

					Map.getChunk()[OM.getOL().layer[objectIndex].getWorldX()][OM.getOL().layer[objectIndex].getWorldY()].toggleGen();
				}
			}
			return;
		}
		else
		{
			cout << "Error, please fix" << endl;
			return;
		}
	}
}

// ############################################
// # Main Game Loop for Checking Interactions #
// ############################################
bool Interact::beginInteractions(World &Map, MainDraw &Art, ALLEGRO_DISPLAY * display, ALLEGRO_FONT * font, ALLEGRO_EVENT_QUEUE  *queue, ObjectManager &OM, float screenX, float screenY, GlobalStatics &globStatic)
{
	al_wait_for_event(queue, &event);
	switch (globStatic.getState())
	{
	case GlobalStatics::MAINMENU:
		return MainMenuInteractions(globStatic);
		break;

	case GlobalStatics::GAME:
		return GameInteractions(Map, Art, display, font, queue, OM, screenX, screenY, globStatic);
		break;

	case GlobalStatics::PAUSE:

		break;

	default:

		break;
	}
	
}

// ###################################
// # Interactions with Game Elements #
// ###################################
bool Interact::GameInteractions(World & Map, MainDraw & Art, ALLEGRO_DISPLAY * display, ALLEGRO_FONT * font, ALLEGRO_EVENT_QUEUE * queue, ObjectManager & OM, float screenX, float screenY, GlobalStatics & globStatic)
{
	// Checks to See if Window Closed
	if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{
		return false;
	}

	switch (event.type)
	{
	case ALLEGRO_EVENT_KEY_DOWN:
		if (event.keyboard.keycode == ALLEGRO_KEY_UP)
		{
			movement.vy -= movement.getSpeed();
			movement.CharCompass.N = true;
		}
		else if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
		{
			movement.vx += movement.getSpeed();
			movement.CharCompass.E = true;
		}
		else if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
		{
			movement.vy += movement.getSpeed();
			movement.CharCompass.S = true;
		}
		else if (event.keyboard.keycode == ALLEGRO_KEY_LEFT)
		{
			movement.vx -= movement.getSpeed();
			movement.CharCompass.W = true;
		}
		switch (event.keyboard.keycode)
		{

		case ALLEGRO_KEY_F1:
		showDebugMenu = !showDebugMenu;
		break;
		case ALLEGRO_KEY_F2:
		showFPS = !showFPS;
		break;

		case ALLEGRO_KEY_ESCAPE:
		return false;
		}
		break;

	case ALLEGRO_EVENT_KEY_UP:
		switch (event.keyboard.keycode)
		{
		case ALLEGRO_KEY_UP:
			movement.vy += movement.getSpeed();
			movement.CharCompass.N = false;
			break;

		case ALLEGRO_KEY_DOWN:
			movement.vy -= movement.getSpeed();
			movement.CharCompass.S = false;
			break;

		case ALLEGRO_KEY_LEFT:
			movement.vx += movement.getSpeed();
			movement.CharCompass.W = false;
			break;

		case ALLEGRO_KEY_RIGHT:
			movement.vx -= movement.getSpeed();
			movement.CharCompass.E = false;
			break;

		case ALLEGRO_KEY_P:
			GS.setPause(true);
			al_show_native_message_box(al_get_current_display(),
				"",
				"Paused",
				"",
				NULL, ALLEGRO_MESSAGEBOX_ERROR);
			GS.setPause(false);
			break;

		case ALLEGRO_KEY_1:
			// Select/Deselect 1st Hotbar Slot
			printSlot(OM, slot1, 0);
			break;

		case ALLEGRO_KEY_2:
			// Select/Deselect 2nd Hotbar Slot
			printSlot(OM, slot2, 1);
			break;

		case ALLEGRO_KEY_3:
			// Select/Deselect 3rd Hotbar Slot
			printSlot(OM, slot3, 2);
			break;

		case ALLEGRO_KEY_4:
			// Select/Deselect 4th Hotbar Slot
			printSlot(OM, slot4, 3);
			break;

		case ALLEGRO_KEY_5:
			// Select/Deselect 5th Hotbar Slot
			printSlot(OM, slot5, 4);
			break;

		case ALLEGRO_KEY_6:
			// Select/Deselect 6th Hotbar Slot
			printSlot(OM, slot6, 5);
			break;

		case ALLEGRO_KEY_7:
			// Select/Deselect 7th Hotbar Slot
			printSlot(OM, slot7, 6);
			break;

		case ALLEGRO_KEY_8:
			// Select/Deselect 8th Hotbar Slot
			printSlot(OM, slot8, 7);
			break;

		case ALLEGRO_KEY_M:
			// Turn on/off Machine Spawning
			swapActive(machineMode);
			break;

		case ALLEGRO_KEY_I:
			// Turn on/off Item Spawning
			swapActive(itemMode);
			break;

		case ALLEGRO_KEY_T:
			// Turn on/off Track Spawning
			swapActive(trackMode);
			break;

		case ALLEGRO_KEY_H:
			// Print out Entire Hotbar
			printHotbar(OM);
			break;
		}
		break;

	case ALLEGRO_EVENT_TIMER:
		movement.moveCharacterX();//DF

		scrollX += movement.vx;
		if (movement.getCharacterXPosition() > mapXBoundary)
		{
			movement.setCharacterXPosition(mapXBoundary);
		}
		else if (movement.getCharacterXPosition() < 0)
		{
			movement.setCharacterXPosition(0);
		}

		//! checks to see if the camera needs to stay where it is until the player is back to the middle of the view (for left boundary)
		if (scrollX < al_get_display_width(display)  || movement.getCharacterXPosition() < al_get_display_height(display) +  100 + GC::charImgWidth)
		{
			scrollX = al_get_display_width(display);
		}
		//! checks to see if the camera needs to stay where it is until the player is back to the middle of the view (for right boundary)
		else if (scrollX > mapXBoundary - al_get_display_width(display) + GC::charImgWidth || movement.getCharacterXPosition() > mapXBoundary - al_get_display_width(display) + GC::charImgWidth)
		{
			scrollX = mapXBoundary - al_get_display_width(display) + GC::charImgWidth;
		}

		movement.moveCharacterY();
		scrollY += movement.vy;
		if (movement.getCharacterYPosition() > mapYBoundary)
		{
			movement.setCharacterYPosition(mapYBoundary);
		}
		else if (movement.getCharacterYPosition() < 0)
		{
			movement.setCharacterYPosition(0);
		}
		//! checks to see if the camera needs to stay where it is until the player is back to the middle of the view (for top boundary)
		if (scrollY < al_get_display_height(display) + GC::charImgHeight || movement.getCharacterYPosition() < al_get_display_width(display)- 100 - GC::charImgHeight)
		{
			scrollY = al_get_display_height(display) + GC::charImgHeight;
		}
		//! checks to see if the camera needs to stay where it is until the player is back to the middle of the view (for bottom boundary)
		else if (scrollY > mapYBoundary - al_get_display_height(display) + GC::charImgHeight || movement.getCharacterYPosition() > mapYBoundary - al_get_display_height(display) + GC::charImgHeight)
		{
			scrollY = mapYBoundary - al_get_display_height(display) + GC::charImgHeight;
		}

		chunkX = movement.getCharacterXPosition() / (32 * 64);
		chunkY = movement.getCharacterYPosition() / (32 * 64);

		//! check to see if the character can move into the sqaure it is trying to go into (TOP LEFT CORNER OF CHARACTER)
		if (Map.getChunk().at(chunkX).at(chunkY).getOre().at((movement.getCharacterXPosition() / GC::tileDim) % GC::chunkDim).at((movement.getCharacterYPosition() / GC::tileDim) % GC::chunkDim).getType() == Tile::COAL
			|| Map.getChunk().at(chunkX).at(chunkY).getOre().at((movement.getCharacterXPosition() / GC::tileDim) % GC::chunkDim).at((movement.getCharacterYPosition() / GC::tileDim) % GC::chunkDim).getType() == Tile::IRON
			|| Map.getChunk().at(chunkX).at(chunkY).getTiles().at((movement.getCharacterXPosition() / GC::tileDim) % GC::chunkDim).at((movement.getCharacterYPosition() / GC::tileDim) % GC::chunkDim).getType() == Tile::QUICK
			|| Map.getChunk().at(chunkX).at(chunkY).getTiles().at((movement.getCharacterXPosition() / GC::tileDim) % GC::chunkDim).at((movement.getCharacterYPosition() / GC::tileDim) % GC::chunkDim).getType() == Tile::WATER)
		{
			movement.setCharacterXPosition(movement.getCharacterXPosition() - movement.vx);
			movement.setCharacterYPosition(movement.getCharacterYPosition() - movement.vy);
			if (scrollX != al_get_display_height(display))
			{
				scrollX -= movement.vx;
			}
			if (scrollY != al_get_display_width(display))
			{
				scrollY -= movement.vy;
			}
		}
		//! check to see if the character can move into the sqaure it is trying to go into (BOTTOM LEFT CORNER OF CHARACTER)
		else if (Map.getChunk().at(chunkX).at(chunkY).getOre().at((movement.getCharacterXPosition() / GC::tileDim) % GC::chunkDim).at(((movement.getCharacterYPosition() + GC::charImgHeight) / GC::tileDim) % GC::chunkDim).getType() == Tile::COAL
			|| Map.getChunk().at(chunkX).at(chunkY).getOre().at((movement.getCharacterXPosition() / GC::tileDim) % GC::chunkDim).at(((movement.getCharacterYPosition() + GC::charImgHeight) / GC::tileDim) % GC::chunkDim).getType() == Tile::IRON
			|| Map.getChunk().at(chunkX).at(chunkY).getTiles().at((movement.getCharacterXPosition() / GC::tileDim) % GC::chunkDim).at(((movement.getCharacterYPosition() + GC::charImgHeight) / GC::tileDim) % GC::chunkDim).getType() == Tile::QUICK
			|| Map.getChunk().at(chunkX).at(chunkY).getTiles().at((movement.getCharacterXPosition() / GC::tileDim) % GC::chunkDim).at(((movement.getCharacterYPosition() + GC::charImgHeight) / GC::tileDim) % GC::chunkDim).getType() == Tile::WATER)
		{
			movement.setCharacterXPosition(movement.getCharacterXPosition() - movement.vx);
			movement.setCharacterYPosition(movement.getCharacterYPosition() - movement.vy);
			if (scrollX != al_get_display_height(display))
			{
				scrollX -= movement.vx;
			}
			if (scrollY != al_get_display_width(display))
			{
				scrollY -= movement.vy;
			}
		}
		//! check to see if the character can move into the square it is tryping to go into (TOP RIGHT CORNER OF CHARACTER)
		else if (Map.getChunk().at(chunkX).at(chunkY).getOre().at(((movement.getCharacterXPosition() + GC::charImgWidth) / GC::tileDim) % GC::chunkDim).at((movement.getCharacterYPosition() / GC::tileDim) % GC::chunkDim).getType() == Tile::COAL
			|| Map.getChunk().at(chunkX).at(chunkY).getOre().at(((movement.getCharacterXPosition() + GC::charImgWidth) / GC::tileDim) % GC::chunkDim).at((movement.getCharacterYPosition() / GC::tileDim) % GC::chunkDim).getType() == Tile::IRON
			|| Map.getChunk().at(chunkX).at(chunkY).getTiles().at(((movement.getCharacterXPosition() + GC::charImgWidth) / GC::tileDim) % GC::chunkDim).at((movement.getCharacterYPosition() / GC::tileDim) % GC::chunkDim).getType() == Tile::QUICK
			|| Map.getChunk().at(chunkX).at(chunkY).getTiles().at(((movement.getCharacterXPosition() + GC::charImgWidth) / GC::tileDim) % GC::chunkDim).at((movement.getCharacterYPosition() / GC::tileDim) % GC::chunkDim).getType() == Tile::WATER)
		{
			movement.setCharacterXPosition(movement.getCharacterXPosition() - movement.vx);
			movement.setCharacterYPosition(movement.getCharacterYPosition() - movement.vy);
			if (scrollX != al_get_display_height(display))
			{
				scrollX -= movement.vx;
			}
			if (scrollY != al_get_display_width(display))
			{
				scrollY -= movement.vy;
			}
		}
		//! check to see if the character can move into the sqaure it is trying to go into (BOTTOM RIGHT CORNER OF CHARACTER)
		else if (Map.getChunk().at(chunkX).at(chunkY).getOre().at(((movement.getCharacterXPosition() + GC::charImgWidth) / GC::tileDim) % GC::chunkDim).at(((movement.getCharacterYPosition() + GC::charImgHeight) / GC::tileDim) % GC::chunkDim).getType() == Tile::COAL
			|| Map.getChunk().at(chunkX).at(chunkY).getOre().at(((movement.getCharacterXPosition() + GC::charImgWidth) / GC::tileDim) % GC::chunkDim).at(((movement.getCharacterYPosition() + GC::charImgHeight) / GC::tileDim) % GC::chunkDim).getType() == Tile::IRON
			|| Map.getChunk().at(chunkX).at(chunkY).getTiles().at(((movement.getCharacterXPosition() + GC::charImgWidth) / GC::tileDim) % GC::chunkDim).at(((movement.getCharacterYPosition() + GC::charImgHeight) / GC::tileDim) % GC::chunkDim).getType() == Tile::QUICK
			|| Map.getChunk().at(chunkX).at(chunkY).getTiles().at(((movement.getCharacterXPosition() + GC::charImgWidth) / GC::tileDim) % GC::chunkDim).at(((movement.getCharacterYPosition() + GC::charImgHeight) / GC::tileDim) % GC::chunkDim).getType() == Tile::WATER)
		{
			movement.setCharacterXPosition(movement.getCharacterXPosition() - movement.vx);
			movement.setCharacterYPosition(movement.getCharacterYPosition() - movement.vy);
			if (scrollX != al_get_display_height(display))
			{
				scrollX -= movement.vx;
			}
			if (scrollY != al_get_display_width(display))
			{
				scrollY -= movement.vy;
			}
		}


		break;

	}

	// Checks for Mouse Button Press
	if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
		// Grab X and Y Coordinates of Top Left of Screen
		startScreenX = screenX;
		startScreenY = screenY;

		// Grab the Position and State of the Mouse
		al_get_mouse_state(&mousepos);
		mouse = event.mouse.button;
		float mouseposX = (float)mousepos.x;
		float mouseposY = (float)mousepos.y;

		// Translate the Mouse Position to World Position
		startX = mouseposX + abs(startScreenX);
		startY = mouseposY + abs(startScreenY);
		startX *= 2; startY *= 2;

		// Debug Information
		//std::cout << "Start Mouse: (" << mouseposX << ", " << mouseposY << ")" << endl;
		//std::cout << "Start Screen: (" << abs(startScreenX) << ", " << abs(startScreenY) << ")" << endl;
		//std::cout << "Initial Coordinates: (" << startX << ", " << startY << ")" << endl << endl;
	}

	// Checks for Mouse Button Release
	if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
	{
		// Grab X and Y Coordinates of Top Left of Screen
		endScreenX = screenX;
		endScreenY = screenY;

		// Grab the Position of the Mouse
		al_get_mouse_state(&mousepos);
		float mouseposX = (float)mousepos.x;
		float mouseposY = (float)mousepos.y;

		// Translate the Mouse Position to World Position
		endX = mouseposX + abs(endScreenX);
		endY = mouseposY + abs(endScreenY);
		endX *= 2; endY *= 2;

		// Debug Information
		//std::cout << "End Mouse: (" << mouseposX << ", " << mouseposY << ")" << endl;
		//std::cout << "End Screen: (" << abs(endScreenX) << ", " << abs(endScreenY) << ")" << endl;
		//std::cout << "End Coordinates: (" << endX << ", " << endY << ")" << endl << endl;

		// Calculate Distance from Start to End Position
		distance = sqrt(pow((endScreenX - startScreenX), 2) + pow((endScreenY - startScreenY), 2));

		// If you are clicking, and not dragging the screen ...
		if (distance < 2)
		{
			// If interaction mode is not enabled ...
			if (!interactMode)
			{
				placement(OM, endX, endY);
			}
			else
			{
				interactions(OM, Map, endX, endY);
			}
		}

		// Reset Mouse State
		mouse = 0;
	}

	// Actions for Mouse Movement
	if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {

		// If it was a Left Click, Scroll Across the Map
		if (mouse == 1) {
			float x = event.mouse.dx / zoom;
			float y = event.mouse.dy / zoom;
			scrollX -= x * cos(rotate) + y * sin(rotate);
			scrollY -= y * cos(rotate) - x * sin(rotate);
		}

		// If it was a Right Click, Zoom/Rotate the Map [CURRENTLY NOT AVAILABLE]
		if (mouse == 2)
		{
			//rotate += event.mouse.dx * 0.01;
			//zoom += event.mouse.dy * 0.01 * zoom;
		}

		zoom += event.mouse.dz * 0.1 * zoom;
		if (zoom < 0.1) zoom = 0.1;
		if (zoom > 10) zoom = 10;
	}

	// Checks Timer to Redraw
	if (event.type == ALLEGRO_EVENT_TIMER)
		redraw = true;

	// Redraws when Window Changes Size
	if (event.type == ALLEGRO_EVENT_DISPLAY_RESIZE)
	{
		al_acknowledge_resize(display);
		redraw = true;
	}

	return true;

}

// ###################################
// # Interactions with Menu Elements #
// ###################################
bool Interact::MainMenuInteractions(GlobalStatics & globStatic)
{

	// Checks to See if Window Closed
	if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{
		return false;
	}

	if (event.type == ALLEGRO_EVENT_KEY_UP)
	{
		if (event.keyboard.keycode == ALLEGRO_KEY_ENTER)
		{
			globStatic.setState(GlobalStatics::GAME);
			redraw = true;
		}
	}
	else if (event.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		if (event.keyboard.keycode == ALLEGRO_KEY_ENTER)
		{
			globStatic.setState(GlobalStatics::GAME);
			redraw = true;
		}
	}

}
