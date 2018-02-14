/* Simple Allegro 5 tilemap example from allegro.cc:
*
* http://www.allegro.cc/forums/thread/606482
*
* Also see here for more info:
*
* http://wiki.allegro.cc/index.php?title=Allegro_5_Tutorial
*
* Place fixed_font.tga and icon.tga from the Allegro 5 examples/data
* folder next to the .exe and there will be an FPS counter and an
* icon.
*
* Left mouse = Pan
* Right mouse = Rotozoom
* Esc = Quit
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_native_dialog.h"
#include "CharacterMovement.h"

#include "TileMap.h"

/* Our window. */
ALLEGRO_DISPLAY *display;
/* Our tiles atlas. */
//ALLEGRO_BITMAP *tiles;
/* Our tilemap. */
ALLEGRO_BITMAP *BlahtestImage;

/* Keep track of pressed mouse button. */
int mouse;
/* Camera parameters. */
float zoom = 0.5, rotate;
float scroll_x, scroll_y;
/* Our icon and font. */

//ALLEGRO_BITMAP *icon;
ALLEGRO_FONT *font;
/* Simple FPS counter. */
int fps, fps_accum;
double fps_time;

//Character movement DF
ALLEGRO_BITMAP *character;
int xPosition = -44;
int yPosition = 0;
int initialCharacterWidth = 0;
int initialCharacterHeight = 0;
int charPositionX = 320; //starting x position for character
int charPositionY = 240; //starting y position for character

//map boundaries DF
int leftMapBoundary = -3179;
int rightMapBoundary = -44;
int topMapBoundary = -2380;
int bottomMapBoundary = 757;

CharacterMovement move(xPosition, yPosition);

int main(void) {
	ALLEGRO_TIMER *timer;
	ALLEGRO_EVENT_QUEUE *queue;
	bool redraw = true;

	srand(time(NULL));

	/* Init Allegro 5 + addons. */
	al_init();
	al_init_image_addon();
	al_init_primitives_addon();
	al_init_font_addon();
	al_install_mouse();
	al_install_keyboard();

	/* Create our window. */
	al_set_new_display_flags(ALLEGRO_RESIZABLE);
	display = al_create_display(640, 480);
	al_set_window_title(display, "Allegro 5 Tilemap Example");


	/* The example will work without those, but there will be no
	* FPS display and no icon.
	*/
	font = al_create_builtin_font(); // al_load_font("fixed_font.tga", 0, 0);
	TileMap Map;



	al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

	//tile_map_create();
	Map.CreateTileBuffer(*display);
	Map.Generate_Terrain();

	timer = al_create_timer(1.0 / 60);
	queue = al_create_event_queue();
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_start_timer(timer);

	/* Center of map. */
	scroll_x = 100 * 32 / 2;
	scroll_y = 100 * 32 / 2;

	//Intial make of character bitmap Character Movement DF
	character = al_load_bitmap("Character.PNG");
	initialCharacterHeight = al_get_bitmap_height(character);
	initialCharacterWidth = al_get_bitmap_width(character);



	while (1) {
		//tile_map_create();
		ALLEGRO_EVENT event;
		al_wait_for_event(queue, &event);


		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			break;
		if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (event.keyboard.keycode == ALLEGRO_KEY_R)
			{
				Map.Generate_Terrain();
				move.setCharacterXPosition(0);
				move.setCharacterYPosition(0);
			}
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				break;
			
		}
#pragma region CharacterMovement
		if (event.type == ALLEGRO_EVENT_KEY_CHAR)
		{
			if (event.keyboard.keycode == ALLEGRO_KEY_UP)
			{
				move.moveCharacterUp();
				if (move.getCharacterYPosition() < topMapBoundary)
				{
					move.setCharacterYPosition(topMapBoundary);
				}
			}
			if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
			{
				move.moveCharacterDown();
				if (move.getCharacterYPosition() > bottomMapBoundary)
				{
					move.setCharacterYPosition(bottomMapBoundary);
				}
			}
			if (event.keyboard.keycode == ALLEGRO_KEY_LEFT)
			{
				move.moveCharacterLeft();
				if (move.getCharacterXPosition() < leftMapBoundary)
				{
					move.setCharacterXPosition(leftMapBoundary);
				}
				
			}
			if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
			{
				move.moveCharacterRight();
				if (move.getCharacterXPosition() > rightMapBoundary)
				{
					move.setCharacterXPosition(rightMapBoundary);
				}
			}
		}
		//Character Movement DF
#pragma endregion CharacterMovement
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			mouse = event.mouse.button;
		}
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			mouse = 0;
		}
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
			//Map.TileMapDraw(*display, scroll_x, scroll_y, zoom, rotate);
			Map.TileMapDraw(*display, 48 * 50 + 300 + move.getCharacterXPosition(), 48 * 50 + 300 + move.getCharacterYPosition(), zoom, rotate);
			if (font) {
				al_draw_filled_rounded_rectangle(4, 4, 100, 75,
					8, 8, al_map_rgba(0, 0, 0, 200));
				al_draw_textf(font, al_map_rgb(255, 255, 255),
					54, 15, ALLEGRO_ALIGN_CENTRE, "FPS: %d", fps);
				al_draw_textf(font, al_map_rgb(255, 255, 255),
					54, 30, ALLEGRO_ALIGN_CENTRE, "char width: %d", (int)((double)initialCharacterWidth * (double)zoom));
				al_draw_textf(font, al_map_rgb(255, 255, 255),
					54, 45, ALLEGRO_ALIGN_CENTRE, "char height: %d", (int)((double)initialCharacterHeight * (double)zoom));
				al_draw_textf(font, al_map_rgb(255, 255, 255),
					54, 60, ALLEGRO_ALIGN_CENTRE, "xPosition: %d", move.getCharacterXPosition());
				al_draw_textf(font, al_map_rgb(255, 255, 255),
					54, 75, ALLEGRO_ALIGN_CENTRE, "Zoom: %f", zoom);

				
			}


			//Code to draw the character, also scales and rotates it Character Movement DF
			al_draw_scaled_rotated_bitmap(character,
				((float)((double)initialCharacterHeight * (double)zoom)) / 2,
				((float)((double)initialCharacterWidth * (double)zoom)) / 2,
				charPositionX,
				charPositionY,
				zoom,
				zoom,
				rotate,
				0);
			
			
			al_flip_display();
			fps_accum++;
			if (t - fps_time >= 1) {
				fps = fps_accum;
				fps_accum = 0;
				fps_time = t;
			}
		}
	}


	return 0;
}