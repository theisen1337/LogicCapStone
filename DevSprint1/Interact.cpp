#include "Interact.h"

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

// #########################
// # Interact with Objects #
// #########################
void Interact::interactions(int mouse_x, int mouse_y, int mouse_b, ObjectManager &OM)
{
	// Stores Previously Calculated Distance
	int prev_distance = 0;
	// Stores Newly Calculated Distance
	int new_distance = 0;
	// Stores X Position of Object
	int object_x = 1000000;
	// Stores Y Position of Object
	int object_y = 1000000;
	// Stores Index in Array of Object
	int object_index = 0;

	// Initializes Distance (Very High as We Want the First Object Right Away)
	prev_distance = sqrt(pow((mouse_x - object_x), 2) + pow((mouse_y - object_y), 2));

	// Loops Through the Item Layer and Finds Closest Item to the Mouse Release
	for (int i = 0; i < OM.getIL().arrItems.size(); i++)
	{
		// Calculates New Distance Between Mouse and Object from Item Layer
		new_distance = sqrt(pow((mouse_x - OM.getIL().arrItems[i].getCoordinateX()), 2) + pow((mouse_y - OM.getIL().arrItems[i].getCoordinateY()), 2));

		// If the Newly Calculated Distance is Closer than the Previous ...
		if (new_distance < prev_distance)
		{
			// Set the New Distance to the Old Distance
			prev_distance = new_distance;
			// Store the X and Y Coordinate of the Object as well as the Index in the Array
			object_x = OM.getIL().arrItems[i].getCoordinateX();
			object_y = OM.getIL().arrItems[i].getCoordinateY();
			object_index = i;
		}
	}

	// If the smallest distance found from the for loop is less than 10 ...
	// (So if the closest object is within 10 "pixels" of the mouse)
	if (prev_distance < 10)
	{
		// If the Left Button was Pressed ...
		if (mouse == 1)
		{
			// Call the leftClick() Function of the Closest Object
			OM.getIL().arrItems[object_index].leftClick();
			return;
		}
		// If the Right Button was Pressed ...
		else if (mouse == 2)
		{
			// Call the rightClick() Function of the Closest Object
			OM.getIL().arrItems[object_index].rightClick();
			return;
		}
		// If Somehow No Button was Pressed (Possibly Error) ...
		else
		{
			return;
		}
	}

	// Loops Through the Machine Layer and Finds Closest Machine to the Mouse Release
	for (int j = 0; j < OM.getML().arrMachines.size(); j++)
	{
		new_distance = sqrt(pow((mouse_x - OM.getML().arrMachines[j].getPlacementX()), 2) + pow((mouse_y - OM.getML().arrMachines[j].getPlacementY()), 2));

		if (new_distance < prev_distance)
		{
			prev_distance = new_distance;
			object_x = OM.getML().arrMachines[j].getPlacementX();
			object_y = OM.getML().arrMachines[j].getPlacementY();
			object_index = j;
		}
	}

	if (prev_distance < 10)
	{
		if (mouse == 1)
		{
			OM.getML().arrMachines[object_index].leftClick();
			return;
		}
		else if (mouse == 2)
		{
			OM.getML().arrMachines[object_index].rightClick();
			return;
		}
		else
		{
			return;
		}
	}

	// CURRENTLY NOT NEEDED AS NO ORE INTERACTION WILL TAKE PLACE [For Now]
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
bool Interact::beginInteractions(World &Map, MainDraw &Art, ALLEGRO_DISPLAY * display, ALLEGRO_FONT * font, ALLEGRO_EVENT_QUEUE  *queue, ObjectManager &OM)
{
	// Waits for Event to Trigger (Mouse or Keyboard)
	al_wait_for_event(queue, &event);

	// Checks to See if the Window was Closed
	if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{
		return false;
	}
	
	// Checks for Keyboard Presses
	if (event.type == ALLEGRO_EVENT_KEY_DOWN) 
	{
		// If 'R' is pressed, regenerate the Terrain
		if (event.keyboard.keycode == ALLEGRO_KEY_R)
			Map.initialGeneration();

		// If 'ESC' is pressed, quit the game
		if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
			return false;
	}

	// Checks for Arrow Keys
	if (event.type == ALLEGRO_EVENT_KEY_CHAR)
	{
		// If the 'UP' Arrow Key is Pressed ...
		if (event.keyboard.keycode == ALLEGRO_KEY_UP)
		{
			// Move Character Up
			movement.moveCharacterUp();

			// If Character Reaches Top of Map, Reset Position to Top Coordinate
			if (movement.getCharacterYPosition() < 0)
			{
				movement.setCharacterYPosition(0);
			}
		}

		// If the 'DOWN' Arrow Key is Pressed ...
		if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
		{
			// Move Character Down
			movement.moveCharacterDown();

			// If Character Reaches Bottom of Map, Reset Position to Bottom Coordinate
			if (movement.getCharacterYPosition() > mapYBoundary)
			{
				movement.setCharacterYPosition(mapYBoundary);
			}
		}

		// If the 'LEFT' Arrow Key is Pressed ...
		if (event.keyboard.keycode == ALLEGRO_KEY_LEFT)
		{
			// Move Character Left
			movement.moveCharacterLeft();

			// If Character Reaches Left Boundary, Reset Position to Last Left Coordinate
			if (movement.getCharacterXPosition() < 0)
			{
				movement.setCharacterXPosition(0);
			}
		}

		// If the 'RIGHT' Arrow Key is Pressed ...
		if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
		{
			// Move Character Right
			movement.moveCharacterRight();

			// If Character Reaches Right Boundary, Reset Position to Last Right Coordinate
			if (movement.getCharacterXPosition() > mapXBoundary)
			{
				movement.setCharacterXPosition(mapXBoundary);
			}
		}
	}

	// Checks for Mouse Button Press
	if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) 
	{
		// Save X and Y Coordinate of Where Mouse was Pressed
		start_x = event.mouse.x;
		start_y = event.mouse.y;

		// Save Whether it was a Left or Right Click
		mouse = event.mouse.button;
	}

	// Checks for Mouse Button Release
	if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) 
	{
		// Save X and Y Coordinate of Where Mouse was Released
		end_x = event.mouse.x;
		end_y = event.mouse.y;

		// Calculate Distance Between Mouse Click and Release
		distance = sqrt(pow((end_x - start_x), 2) + pow((end_y - start_y), 2));

		// If there was Less than Two "Pixels" between Mouse Positions ...
		if (distance < 2)
		{
			// Run the Interactions Function
			interactions(end_x, end_y, mouse, OM);
		}

		// Reset Mouse Button
		mouse = 0;
	}

	// Actions for Mouse Movement
	if (event.type == ALLEGRO_EVENT_MOUSE_AXES) 
	{
		
		// If it was a Left Click, Scroll Across the Map
		if (mouse == 1) 
		{
			float x = event.mouse.dx / zoom;
			float y = event.mouse.dy / zoom;
			scroll_x -= x * cos(rotate) + y * sin(rotate);
			scroll_y -= y * cos(rotate) - x * sin(rotate);
		}
		
		// If it was a Right Click, Zoom/Rotate the Map
		if (mouse == 2) 
		{
			rotate += event.mouse.dx * 0.01;
			zoom += event.mouse.dy * 0.01 * zoom;
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