#include "Interact.h"

//World Map = *(LogisticsGame::getMap());

Interact::Interact() { }

ALLEGRO_EVENT event;

Interact::~Interact() {}

// This calls the appropriate interaction functions in whatever object got clicked
void Interact::interactions(int mouse_x, int mouse_y, int mouse_b, ObjectManager &OM)
{

	int prev_distance = 0;
	int new_distance = 0;
	int object_x = 1000000;
	int object_y = 1000000;
	int object_index = 0;

	// Sets Original Distance (Very High as We Want the First Object Right Away)
	prev_distance = sqrt(pow((mouse_x - object_x), 2) + pow((mouse_y - object_y), 2));

	// Loops through and finds closest item to the mouse release
	for (int i = 0; i < OM.getIL().arrItems.size(); i++)
	{
		new_distance = sqrt(pow((mouse_x - OM.getIL().arrItems[i].getCoordinateX()), 2) + pow((mouse_y - OM.getIL().arrItems[i].getCoordinateY()), 2));

		if (new_distance < prev_distance)
		{
			prev_distance = new_distance;
			object_x = OM.getIL().arrItems[i].getCoordinateX();
			object_y = OM.getIL().arrItems[i].getCoordinateY();
			object_index = i;
		}
	}

	// Checks if closest item is within 10 pixels of the mouse, if so, call object leftClick and rightClick function
	if (prev_distance < 10)
	{
		if (mouse == 1)
		{
			OM.getIL().arrItems[object_index].leftClick();
			return;
		}
		else if (mouse == 2)
		{
			OM.getIL().arrItems[object_index].rightClick();
			return;
		}
		else
		{
			return;
		}
	}

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
		redraw = true;
	}

	// Checks for Mouse Button Press
	if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) 
	{
		al_get_mouse_state(&mousepos);
		mouse = event.mouse.button;
		float mouseposX = (float)mousepos.x;
		float mouseposY = (float)mousepos.y;

		startX = mouseposX + abs(screenX);
		startY = mouseposY + abs(screenY);

		std::cout << "Start Mouse: (" << mouseposX << ", " << mouseposY << ")" << endl;
		std::cout << "Start Screen: (" << abs(screenX) << ", " << abs(screenY) << ")" << endl;
		std::cout << "Initial Coordinates: (" << startX << ", " << startY << ")" << endl << endl;
	}

	// Checks for Mouse Button Release
	if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) 
	{
		al_get_mouse_state(&mousepos);
		float mouseposX = (float)mousepos.x;
		float mouseposY = (float)mousepos.y;

		endX = mouseposX + abs(screenX);
		endY = mouseposY + abs(screenY);

		std::cout << "End Mouse: (" << mouseposX << ", " << mouseposY << ")" << endl;
		std::cout << "End Screen: (" << abs(screenX) << ", " << abs(screenY) << ")" << endl;
		std::cout << "End Coordinates: (" << endX << ", " << endY << ")" << endl << endl;

		distance = sqrt(pow((endX - startX), 2) + pow((endY - startY), 2));

		if (distance < 2)
		{
			interactions(endX, endY, mouse, OM);
		}

		mouse = 0;
	}

	// Actions for Mouse Movement
	if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
		/* Left button scrolls. */
		if (mouse == 1) {
			float x = event.mouse.dx / zoom;
			float y = event.mouse.dy / zoom;
			scroll_x -= x * cos(rotate) + y * sin(rotate);
			scroll_y -= y * cos(rotate) - x * sin(rotate);
		}
		/* Right button zooms/rotates. */
		if (mouse == 2) {
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
	if (event.type == ALLEGRO_EVENT_DISPLAY_RESIZE) {
		al_acknowledge_resize(display);
		redraw = true;
	}
	return true;
}