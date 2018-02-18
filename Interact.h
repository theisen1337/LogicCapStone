#pragma once

#include <string>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"

#include "Draw.h"
#include "World.h"
#include "Items.h"

class Interact
{
public:
	Interact();
	//Interact(ALLEGRO_TIMER * timer, ALLEGRO_DISPLAY * display);
	~Interact();

	void leftClick();
	void rightClick();

	void callFunctions();

	int beginInteractions(World &Map,Draw &Art, ALLEGRO_DISPLAY * display, ALLEGRO_FONT * font, ALLEGRO_EVENT_QUEUE  *queue);

	void Redraw();


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

private:
	//ALLEGRO_EVENT_QUEUE *queue;
	//ALLEGRO_EVENT event;

	
};