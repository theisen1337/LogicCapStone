#include "Interact.h"

//World Map = *(LogisticsGame::getMap());

Interact::Interact() {}

ALLEGRO_EVENT event;

Interact::~Interact() {}



// This calls the appropriate interaction functions in whatever object got clicked
void Interact::interactions(int mouse_x, int mouse_y, int mouse_b, ItemLayer itemLayer, OreLayer oreLayer, MachineLayer machineLayer)
{
	// NOTES:
	// Nested For Loop to Check Every Item in Chunk
	// Chunk information is pulled from Character Class
	// Then go down to tile information (32 tiles per chunk)
	// Analyze all objects within the Chunk associated with a tile (x, y)
	// Apply distance formula and find the closest object
	// Check if closest object is within clicking threshold
	// ***What to do with items??***
	// ***X, and Y of object indpenedent or dependent on chunks??***

	int prev_distance = 0;
	int new_distance = 0;
	int object_x = 1000000;
	int object_y = 1000000;
	int object_index = 0;

	// Sets Original Distance (Very High as We Want the First Object Right Away)
	prev_distance = sqrt(pow((mouse_x - object_x), 2) + pow((mouse_y - object_y), 2));

	// Loops through and finds closest item to the mouse release
	for (int i; i < itemLayer.arrItems.size(); i++)
	{
		new_distance = sqrt(pow((mouse_x - itemLayer.arrItems[i].getCoordinateX()), 2) + pow((mouse_y - itemLayer.arrItems[i].getCoordinateY()), 2));

		if (new_distance < prev_distance)
		{
			prev_distance = new_distance;
			object_x = itemLayer.arrItems[i].getCoordinateX();
			object_y = itemLayer.arrItems[i].getCoordinateY();
			object_index = i;
		}
	}

	// Checks if closest item is within 10 pixels of the mouse, if so, call object leftClick and rightClick function
	if (prev_distance < 10)
	{
		if (mouse == 1)
		{
			itemLayer.arrItems[object_index].leftClick();
			return;
		}
		else if (mouse == 2)
		{
			itemLayer.arrItems[object_index].rightClick();
			return;
		}
		else
		{
			return;
		}
	}

	for (int j; j < machineLayer.arrMachines.size(); j++)
	{
		new_distance = sqrt(pow((mouse_x - machineLayer.arrMachines[j].getPlacementX()), 2) + pow((mouse_y - machineLayer.arrMachines[j].getPlacementY()), 2));

		if (new_distance < prev_distance)
		{
			prev_distance = new_distance;
			object_x = machineLayer.arrMachines[j].getPlacementX();
			object_y = machineLayer.arrMachines[j].getPlacementY();
			object_index = j;
		}
	}

	if (prev_distance < 10)
	{
		if (mouse == 1)
		{
			machineLayer.arrMachines[object_index].leftClick();
			return;
		}
		else if (mouse == 2)
		{
			machineLayer.arrMachines[object_index].rightClick();
			return;
		}
		else
		{
			return;
		}
	}

	for (int k; k < oreLayer.arrOres.size(); k++)
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
	}
}

bool Interact::beginInteractions(World &Map, Artist &Art, ALLEGRO_DISPLAY * display, ALLEGRO_FONT * font, ALLEGRO_EVENT_QUEUE  *queue, ItemLayer itemLayer, OreLayer oreLayer, MachineLayer machineLayer)
{
	al_wait_for_event(queue, &event);

	// Checks to See if Window Closed
	if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{
		return false;
	}
	
	// Checks for Keyboard Presses
	if (event.type == ALLEGRO_EVENT_KEY_DOWN) 
	{
		if (event.keyboard.keycode == ALLEGRO_KEY_R)
			Map.initialGeneration();
		if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
			return false;
	}

	// Character Movement
	if (event.type == ALLEGRO_EVENT_KEY_CHAR)
	{
		if (event.keyboard.keycode == ALLEGRO_KEY_UP)
		{
			movement.moveCharacterUp();
			if (movement.getCharacterYPosition() < 0)
			{
				movement.setCharacterYPosition(0);
			}
		}
		if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
		{
			movement.moveCharacterDown();
			if (movement.getCharacterYPosition() > mapYBoundary)
			{
				movement.setCharacterYPosition(mapYBoundary);
			}
		}
		if (event.keyboard.keycode == ALLEGRO_KEY_LEFT)
		{
			movement.moveCharacterLeft();
			if (movement.getCharacterXPosition() < 0)
			{
				movement.setCharacterXPosition(0);
			}
		}
		if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
		{
			movement.moveCharacterRight();
			if (movement.getCharacterXPosition() > mapXBoundary)
			{
				movement.setCharacterXPosition(mapXBoundary);
			}
		}
	}

	// Checks for Mouse Button Press
	if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) 
	{
		start_x = event.mouse.x;
		start_y = event.mouse.y;
		mouse = event.mouse.button;
	}

	// Checks for Mouse Button Release
	if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) 
	{
		end_x = event.mouse.x;
		end_y = event.mouse.y;

		distance = sqrt(pow((end_x - start_x), 2) + pow((end_y - start_y), 2));

		if (distance < 2)
		{
			interactions(end_x, end_y, mouse, itemLayer, oreLayer, machineLayer);
		}

		mouse = 0;
	}

	// Actions for Mouse Movement
	if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
		/* Left button scrolls. */
		if (mouse == 1) {
			//leftClick();
			float x = event.mouse.dx / zoom;
			float y = event.mouse.dy / zoom;
			scroll_x -= x * cos(rotate) + y * sin(rotate);
			scroll_y -= y * cos(rotate) - x * sin(rotate);
		}
		/* Right button zooms/rotates. */
		if (mouse == 2) {
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
	if (event.type == ALLEGRO_EVENT_DISPLAY_RESIZE) {
		al_acknowledge_resize(display);
		redraw = true;
	}
	return true;
}

