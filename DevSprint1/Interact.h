#pragma once
//! Interactions

/*!
	This allows the user to Interact with Objects and the World Itself (Zoom, Rotate, Etc.)
*/

//! Include Allegro Addons
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"

//! Include Standard Libraries
#include <string>
#include <math.h>
#include <vector>
#include <array>

//! Include Custom Classes
#include "MainDraw.h"
#include "World.h"
#include "ItemBase.h"
#include "ItemLayer.h"
#include "MachineLayer.h"
#include "OreLayer.h"
#include "CharacterMovement.h"
#include "ObjectManager.h"

//! Interaction Class
class Interact
{
public:

	//! Used to Tell if Mouse was Pressed by Left or Right Button
	int mouse;

	//! Parameters Used for Camera Effects [Will Likely be Removed]
	float zoom = 0.5, rotate = 0.0f;

	//! Used when Drawing
	bool redraw = true;

	//! Gives Positioning to Center of Map [Should be Renamed and Made Constant]
	float scroll_x = 100 * 32 / 2;
	float scroll_y = 100 * 32 / 2;

	//! Counter to Show In-Game FPS
	int fps, fps_accum;
	double fps_time;

	//! Variables for the Positioning and Movement of our Character as well as it's Image
	int charXPosition = 0;
	int charYPosition = 0;
	ALLEGRO_BITMAP *character = al_load_bitmap("Terrain//Dev//test.png");
	CharacterMovement movement;
	int mapXBoundary = 6100;
	int mapYBoundary = 6100;

	//! Constructor
	Interact();
	
	//! Deconstructor
	~Interact();

	//! Main Function for Interacting with Objects
	void interactions(int mouse_x, int mouse_y, int mouse_b, ObjectManager &OM);

	//! Allows Keyboard and Mouse Functionality
	//! Parameters:
	//! <> &Map -> Reference to our Game Map
	//! <> &Art -> Reference to Drawing Capabilities
	//! <> *display -> Gives access to the Window Display
	//! <> *font -> Gives access to the Game Font
	//! <> *queue -> Gives access to the Queue for Different Events
	//! <> &OM -> References the Object Manager for Accessibility
	bool beginInteractions(World &Map,MainDraw &Art, ALLEGRO_DISPLAY * display, ALLEGRO_FONT * font, ALLEGRO_EVENT_QUEUE  *queue, ObjectManager &OM);

private:

	//! X and Y Positioning of Initial Mouse Button Press
	int start_x;
	int start_y;

	//! X and Y of Ending Mouse Button Release
	int end_x;
	int end_y;

	//! Used to Store Distance Between Objects
	float distance;
};