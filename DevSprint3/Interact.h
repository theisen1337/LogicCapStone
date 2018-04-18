#pragma once

/*

This Function allows us to interact with objects, the world, and even the character

*/

// Include Allegro Addons
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_font.h"

// Include Custom Classes
#include "MainDraw.h"
#include "World.h"
#include "ItemBase.h"
#include "ItemLayer.h"
#include "MachineLayer.h"
#include "OreLayer.h"
#include "CharacterMovement.h"
#include "ObjectManager.h"

// Include Standard Libraries
#include <math.h>
#include <vector>
#include <array>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Interact
{
public:

	//! Constructor
	Interact();
	
	//! Deconstructor
	~Interact();

	//! Main Function for Interacting with Objects
	void interactions(int mouse_x, int mouse_y, int mouse_b, ObjectManager &OM, float screenX, float screenY);

	/*! Allows Keyboard and Mouse Functionality
		- Parameters:
		<> &Map -> Reference to our Game Map
		<> &Art -> Reference to Drawing Capabilities
		<> *display -> Gives access to the Window Display
		<> *font -> Gives access to the Game Font
		<> *queue -> Gives access to the Queue for Different Events
		<> &OM -> References the Object Manager for Accessibility
	*/
	bool beginInteractions(World &Map,MainDraw &Art, ALLEGRO_DISPLAY * display, ALLEGRO_FONT * font, ALLEGRO_EVENT_QUEUE  *queue, ObjectManager &OM, float screenX, float screenY);

	//! Used to Tell if Mouse was Pressed by Left or Right Button
	ALLEGRO_MOUSE_STATE mousepos;

	//! Keep track of pressed mouse button.
	int mouse;

	//! Parameters Used for Camera Effects [Currently Not Used]
	float zoom = 0.5, rotate = 0.0f;

	//! Used when Drawing
	bool redraw = true;


	//! Counter to Show In-Game FPS
	int fps, fpsAccum;
	double fpsTime;

	//! Variables for the Positioning and Movement of our Character as well as it's Image
	int charXPosition = 1000;
	int charYPosition = 1000;
	ALLEGRO_BITMAP *character = al_load_bitmap("Terrain//Dev//test.png");
	CharacterMovement movement = CharacterMovement(charXPosition, charYPosition);
	int numberOfChunks = 5;
	int mapXBoundary = 32 * 64 * al_get_bitmap_width(character);
	int mapYBoundary = 32 * 64 * al_get_bitmap_height(character);

	//! Gives positioning with player in the center
	float scrollX = charYPosition + al_get_bitmap_height(character) / 2;
	float scrollY = charXPosition + al_get_bitmap_width(character) / 2;


	//! bool for debug menu
	bool showDebugMenu = false;

	//! bool for fps
	bool showFPS = true;


private:

	//! Transformed X and Y Position from Button Press
	float startX;
	float startY;

	//! Transformed X and Y Position from Button Release
	float endX;
	float endY;

	//! Used to Store Distance Between Objects
	float distance;

	//! The X and Y Positions of the Screen Before and After Scrolling
	float startScreenX;
	float startScreenY;
	float endScreenX;
	float endScreenY;

	//! The Max/Mins are Used to Define the Boundaries of an Object
	float maxX;
	float minX;
	float maxY;
	float minY;
};