#include "Interact.h"

TileMap Map = *(LogisticsGame::getMap());

Interact::Interact() {}
Interact::Interact(ALLEGRO_TIMER * timer, ALLEGRO_DISPLAY * display)
{
	queue = al_create_event_queue();
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));

	al_wait_for_event(queue, &event);
}

Interact::~Interact() {}

// Function is called when mouse is left clicked from main
void Interact::leftClick()
{
	// Check mouse position (x and y)
	// Check relative position to other objects within 10 pixels of the cursor
	// Then call the function of the appropriate object
}

// Function is called when mouse is right clicked
void Interact::rightClick()
{
	// Check mouse position (x and y)
	// Check relative position to other objects within 10 pixels of the cursor
	// Then call the function of the appropriate object
}

// This calls the appropriate interaction functions in whatever object got clicked
void Interact::callFunctions()
{
	//If X object was clicked,
	//	If left clicked,
	//		Call function
	//	If right clicked,
	//		Call function

	// If Y object ...
}

void Interact::beginInteractions(TileMap Map, ALLEGRO_DISPLAY * display, ALLEGRO_FONT * font)
{
	while (1) {

		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			break;

		if (event.type == ALLEGRO_EVENT_KEY_DOWN) 
		{
			if (event.keyboard.keycode == ALLEGRO_KEY_R)
				Map.Generate_Terrain();
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				break;
		}
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			mouse = event.mouse.button;
		}
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			mouse = 0;
		}
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
		if (event.type == ALLEGRO_EVENT_TIMER)
			redraw = true;
		if (event.type == ALLEGRO_EVENT_DISPLAY_RESIZE) {
			al_acknowledge_resize(display);
			redraw = true;
		}

		if (redraw && al_is_event_queue_empty(queue)) {
			redraw = false;
			double t = al_get_time();
			//tile_map_draw(); //draw
			Map.TileMapDraw(*display, scroll_x, scroll_y, zoom, rotate);
			if (font) {
				al_draw_filled_rounded_rectangle(4, 4, 100, 30,
					8, 8, al_map_rgba(0, 0, 0, 200));
				al_draw_textf(font, al_map_rgb(255, 255, 255),
					54, 8, ALLEGRO_ALIGN_CENTRE, "FPS: %d", fps);
			}
			al_flip_display();
			fps_accum++;
			if (t - fps_time >= 1) {
				fps = fps_accum;
				fps_accum = 0;
				fps_time = t;
			}
		}
	}
}