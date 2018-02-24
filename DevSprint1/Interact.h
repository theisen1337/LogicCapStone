#pragma once

#include <string>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"

#include "Artist.h"
#include "World.h"
#include "Items.h"

#include "ItemLayer.h"
#include "MachineLayer.h"
#include "OreLayer.h"

#include <math.h>
#include <vector>
#include <array>

#include "CharacterMovement.h"

class Interact
{
public:
	Interact();
	//Interact(ALLEGRO_TIMER * timer, ALLEGRO_DISPLAY * display);
	~Interact();

	void interactions(int x, int y, int mouse, ItemLayer itemLayer, OreLayer oreLayer, MachineLayer machineLayer);

	bool beginInteractions(World &Map,Artist &Art, ALLEGRO_DISPLAY * display, ALLEGRO_FONT * font, ALLEGRO_EVENT_QUEUE  *queue, ItemLayer itemLayer, OreLayer oreLayer, MachineLayer machineLayer);



	/* Keep track of pressed mouse button. */
	int mouse;
	/* Camera parameters. */
	float zoom = 0.5, rotate = 0.0f;

	bool redraw = true;

	/* Center of map. */
	float scroll_x = 100 * 32 / 2;
	float scroll_y = 100 * 32 / 2;

	/* Simple FPS counter. */
	int fps, fps_accum;
	double fps_time;

	/* Character Position and Image DF*/
	int charXPosition = 0;
	int charYPosition = 0;
	ALLEGRO_BITMAP *character = al_load_bitmap("Terrain//Dev//test.png");
	CharacterMovement movement;
	int mapXBoundary = 6100;
	int mapYBoundary = 6100;

private:
	//ALLEGRO_EVENT_QUEUE *queue;
	//ALLEGRO_EVENT event;

	int start_x;
	int start_y;
	int end_x;
	int end_y;
	float distance;
};