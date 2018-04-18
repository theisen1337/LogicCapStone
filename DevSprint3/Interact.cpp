#include "Interact.h"

// #####################
// # OLD K-D TREE CODE #
// #####################
/*

const int MAX_DIM = 3;

struct kd_node_t
{
	double x[MAX_DIM];
	struct kd_node_t *left, *right;
};

inline double dist(struct kd_node_t *a, struct kd_node_t *b, int dim)
{
	double t, d = 0;
	while (dim--)
	{
		t = a->x[dim] - b->x[dim];
		d += t*t;
	}
	return d;
}

inline void swap(struct kd_node_t *x, struct kd_node_t *y)
{
	double tmp[MAX_DIM];
	memcpy(tmp, x->x, sizeof(tmp));
	memcpy(x->x, y->x, sizeof(tmp));
	memcpy(y->x, tmp, sizeof(tmp));
}

struct kd_node_t* find_median(struct kd_node_t *start, struct kd_node_t *end, int idx)
{
	if (end <= start) return NULL;
	if (end == start + 1) return start;

	struct kd_node_t *p, *store, *md = start + (end - start) / 2;
	double pivot;

	while (1)
	{
		pivot = md->x[idx];

		swap(md, end - 1);
		for (store = p = start; p < end; p++)
		{
			if (p->x[idx] < pivot)
			{
				if (p != store)
					swap(p, store);
				store++;
			}
		}
		swap(store, end - 1);

		// if the median has duplicate values
		if (store->x[idx] == md->x[idx])
			return md;

		if (store > md) end = store;
		else start = store;
	}
}

struct kd_node_t* make_tree(struct kd_node_t *t, int len, int i, int dim)
{
	struct kd_node_t *n;

	if (!len) return 0;

	if ((n = find_median(t, t + len, i)))
	{
		i = (i + 1) % dim;
		n->left = make_tree(t, n - t, i dim);
		n->right = make_tree(n + 1, t + len - (n + 1), i, dim);
	}
	return n;
}

// Global for Now, Will Change
int visited = 0;

void nearest(struct kd_node_t *root, struct kd_node_t *nd, int i, int dim, struct kd_node_t **best, double *best_dist)
{
	double d, dx, dx2;

	// If there is no root, then return
	if (!root) return;

	// Calculate Distance
	// root = root tree
	// nd = mouse position
	// dim = number of dimensions
	d = dist(root, nd, dim);

	dx = root->x[i] - nd->x[i];
	dx2 = dx * dx;

	visited++;

	// If found is not a set variable or if new distance is less than current best
	if (!*best || d < *best_dist)
	{
		// Set the new best distance
		*best_dist = d;
		// update the root
		*best = root;
	}

	// If there is no best distance, return
	if (!*best_dist) return;

	// Performs dimension shifts (horizontal, vertical, horizontal, etc.)
	if (++i >= dim) i = 0;

	// Recursively search left tree
	nearest(dx > 0 ? root->left : root->right, nd, i, dim, best, best_dist);

	// If dx2 is larger than the best_dist, then return (base case)
	if (dx2 >= *best_dist) return;

	// recursively search right tree
	nearest(dx > 0 ? root->right : root->left, nd, i, dim, best, best_dist);
}

// PLACE BELOW CODE IN INITIALIZATION

struct kd_node_t wp[] = { current X, Y positions }
struct kd_node_t testNode = { mouse positioning }
struct kd_node_t *root, *found;
double best_dist;

root = make_tree(wp, sizeof(wp) / sizeof(wp[1]), 0, 2);

visited = 0;
found = 0;

// Root = Origin of Tree
// TestNode = Where Mouse is Located
// 0 is single iteration
// 2 is the dimensions
// Found is where the nearest coordinate is
// best_dist is what the distance is
nearest(root, &testNode, 0, 2, &found, &best_dist);

cout << "Searching for " + testNode.x[0] + testNode.x[1] << endl;
cout << "Found " + found->x[0], found->x[1];
cout << "Distance " + sqrt(best_dist);
cout << "Visited " + visited + " nodes.";

*/

// ####################
// # Create our Event #
// ####################
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
	if (active)
	{
		active = false;
		interactMode = true;
	}
	else
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
	if (OM.hotbar[index].machine)
	{
		// Calculates Positioning of Machines
		int machineX = X / 64; machineX *= 64;
		int machineY = Y / 64; machineY *= 64;

		OM.addMachine(machineX, machineY, index);
		OM.hotbar[index].num -= 1;

		cout << "Placed " << OM.hotbar[index].machineType << endl << endl;

		if (OM.hotbar[index].num == 0)
			cout << "Slot " << index + 1 << " is Empty" << endl;
		else if (OM.hotbar[index].num == 1)
			cout << "Slot " << index + 1 << " Now Contains: " << OM.hotbar[index].num << " " << OM.hotbar[index].machineType << endl;
		else
			cout << "Slot " << index + 1 << " Now Contains: " << OM.hotbar[index].num << " " << OM.hotbar[index].machineType << "'s" << endl;

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
	else if (OM.hotbar[0].item)
	{
		// Calculates Positioning of Items
		int itemX = X - 8;
		int itemY = Y - 8;

		OM.addItem(itemX, itemY, index);
		OM.hotbar[index].num -= 1;

		cout << "Placed " << OM.hotbar[index].itemType << endl << endl;

		if (OM.hotbar[index].num == 0)
			cout << "Slot " << index + 1 << " is Empty" << endl;
		else if (OM.hotbar[index].num == 1)
			cout << "Slot " << index + 1 << " New Contains: " << OM.hotbar[index].num << " " << OM.hotbar[index].itemType << endl;
		else
			cout << "Slot " << index + 1 << " New Contains: " << OM.hotbar[index].num << " " << OM.hotbar[index].itemType << "'s" << endl;
		
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
		cout << "ERROR, NO TYPE DEFINED. FIX ME" << endl;
	}
}

// ##############################
// # Spawn Objects onto the Map #
// ##############################
void Interact::spawnObject(ObjectManager &OM, int X, int Y)
{
	// If Spawning Machine
	// If Spawning Item
	// If Spawning Track
}

// ##############################
// # Prints Current Hotbar Slot #
// ##############################
void Interact::printSlot(ObjectManager &OM, bool &slot, int index)
{
	swapActive(slot);

	if (slot)
	{
		if (OM.hotbar[index].num != 0)
		{
			if (OM.hotbar[index].machine)
			{
				if (OM.hotbar[index].num == 1)
				{
					cout << "Slot " << index + 1 << " Contains: " << OM.hotbar[index].num << " " << OM.hotbar[index].machineType << endl;
				}
				else
				{
					cout << "Slot " << index + 1 << " Contains: " << OM.hotbar[index].num << " " << OM.hotbar[index].machineType << "'s" << endl;
				}
			}
			else if (OM.hotbar[index].item)
			{
				if (OM.hotbar[index].num == 1)
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
		cout << "[ h" << i+1 << " ] = ";
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
				cout << "ERROR, FIX ME" << endl;
		}
	}
}

// #################
// # Place Objects #
// #################
void Interact::placement(int mouseX, int mouseY, int mouseB, ObjectManager &OM)
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
void Interact::interactions(int mouseX, int mouseY, int mouseB, ObjectManager &OM, float screenX, float screenY)
{
	int prevDistance = 0;
	int newDistance = 0;
	// Stores X Position of Object [UPDATE IN FUTURE FOR BETTER METHOD]
	int objectX = 1000000;
	// Stores Y Position of Object [UPDATE IN FUTURE FOR BETTER METHOD]
	int objectY = 1000000;
	// Stores Index in Array of Object
	int objectIndex = 0;

	// Initializes Distance
	prevDistance = sqrt(pow((mouseX - objectX), 2) + pow((mouseY - objectY), 2));

	// #########################
	// # LOOP FOR ITEM OBJECTS #
	// #########################

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
			objectX += 8;
			objectY += 8;

			objectIndex = i;
		}
	}

	// Calculate Distance Between Mouse and Center of Object
	newDistance = sqrt(pow((mouseX - objectX), 2) + pow((mouseY - objectY), 2));

	// Print Distance for Debugging
	/*std::cout << "Distance to Nearest Object: " << newDistance << endl;*/

	// Set Boundaries of Object
	maxX = objectX + 8; minX = objectX - 8;
	maxY = objectY + 8; minY = objectY - 8;

	if ((mouseX < maxX && mouseX > minX) && (mouseY < maxY && mouseY > minY)) // If user clicks on an object ...
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
			OM.getIL().arrItems[objectIndex].rightClick();
			return;
		}
		else // If Somehow No Button was Pressed (Possibly Error) ...
		{
			cout << "ERROR, Please fix" << endl;
			return;
		}
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
			objectX += 32;
			objectY += 32;

			objectIndex = j;
		}
	}

	// Calculates the Newest Distance between Mouse and Center of Object
	newDistance = sqrt(pow((mouseX - objectX), 2) + pow((mouseY - objectY), 2));

	// Print Distance for Debugging
	/*std::cout << "Distance to Nearest Object: " << newDistance << endl;*/

	// Sets the Boundaries of the Nearest Object
	maxX = objectX + 32; minX = objectX - 32;
	maxY = objectY + 32; minY = objectY - 32;

	if ((mouseX < maxX && mouseX > minX) && (mouseY < maxY && mouseY > minY)) // If the User Clicked Within the Object's Boundaries ...
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
			OM.getML().arrMachines[objectIndex].rightClick();
			return;
		}
		else // If Somehow No Button was Pressed (Possibly Error or middle mouse click) ...
		{
			cout << "ERROR, Please Fix" << endl;
			return;
		}
	}

	// LOOP THROUGH ORE OBJECTS (CURRENTLY NONE) (ALSO DEPRECIATED)
	/*
	for (int k = 0; k < oreLayer.arrOres.size(); k++)
	{
		new_distance = sqrt(pow((mouse_x - oreLayer.arrOres[k].getXCoordinate()), 2) + pow((mouse_y - oreLayer.arrOres[k].getYCoordinate()), 2));

		if (new_distance < prev_distance)
		{
			prev_distance = new_distance;
			object_x = oreLayer.arrOres[k].getXCoordinate();
			object_y = oreLayer.arrOres[k].getYCoordinate();
			object_index = k;
		}
	}
	
	if (prev_distance < 10)
	{
		if (mouse == 1)
		{
			oreLayer.arrOres[object_index].leftClick();
			return;
		}
		else if (mouse == 2)
		{
			oreLayer.arrOres[object_index].rightClick();
			return;
		}
		else
		{
			return;
		}
	}*/
}

// ####################################
// # Mouse and Keyboard Functionality #
// ####################################
bool Interact::beginInteractions(World &Map, MainDraw &Art, ALLEGRO_DISPLAY * display, ALLEGRO_FONT * font, ALLEGRO_EVENT_QUEUE  *queue, ObjectManager &OM, float screenX, float screenY)
{
	al_wait_for_event(queue, &event);

	// Checks to See if Window Closed
	if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{
		return false;
	}

	switch (event.type)
	{
	case ALLEGRO_EVENT_KEY_DOWN:
		switch (event.keyboard.keycode)
		{
		case ALLEGRO_KEY_UP:
			movement.vy -= movement.getSpeed();
			break;
		case ALLEGRO_KEY_DOWN:
			movement.vy += movement.getSpeed();
			break;
		case ALLEGRO_KEY_LEFT:
			movement.vx -= movement.getSpeed();
			break;
		case ALLEGRO_KEY_RIGHT:
			movement.vx += movement.getSpeed();
			break;
		case ALLEGRO_KEY_R:
			Map.initialGeneration();
		case ALLEGRO_KEY_ESCAPE:
			return false;
		}
		break;

	case ALLEGRO_EVENT_KEY_UP:
		switch (event.keyboard.keycode)
		{
		case ALLEGRO_KEY_UP:
			movement.vy += movement.getSpeed();
			break;

		case ALLEGRO_KEY_DOWN:
			movement.vy -= movement.getSpeed();
			break;

		case ALLEGRO_KEY_LEFT:
			movement.vx += movement.getSpeed();
			break;

		case ALLEGRO_KEY_RIGHT:
			movement.vx -= movement.getSpeed();
			break;

		case ALLEGRO_KEY_P:
			al_show_native_message_box(al_get_current_display(),
				"",
				"Paused",
				"",
				NULL, ALLEGRO_MESSAGEBOX_ERROR);
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

		if (movement.getCharacterXPosition() > mapXBoundary)
		{
			movement.setCharacterXPosition(mapXBoundary);
		}
		else if (movement.getCharacterXPosition() < 0)
		{
			movement.setCharacterXPosition(0);
		}

		movement.moveCharacterY();

		if (movement.getCharacterYPosition() > mapYBoundary)
		{
			movement.setCharacterYPosition(mapYBoundary);
		}
		else if (movement.getCharacterYPosition() < 0)
		{
			movement.setCharacterYPosition(0);
		}

		break;
		redraw = true; // WHY IS THIS HERE?
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
				placement(endX, endY, mouse, OM);
			}
			else
			{
				interactions(endX, endY, mouse, OM, endScreenX, endScreenY);
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
