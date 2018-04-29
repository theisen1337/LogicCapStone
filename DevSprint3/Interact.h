#pragma once

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

#include "GlobalConstants.h"

class Interact
{
public:

	//! Constructor
	Interact();
	
	//! Deconstructor
	~Interact();

	//! Swaps the Active Placement Modes
	void swapActive(bool &active);

	//! Check for Active State
	int checkActive();

	//! Place Objects onto the Map and Update Hotbar
	void placeObject(ObjectManager &OM, int X, int Y, int index);

	//! Spawn Objects into the Game for Testing
	void spawnObject(ObjectManager &OM, int X, int Y);

	//! Prints out the Current Hotbar Slot
	void printSlot(ObjectManager &OM, bool &slot, int index);

	//! Prints out the Entire Hotbar
	void printHotbar(ObjectManager &OM);

	int findSlot(ObjectManager &OM, std::string name);

	//! Searches for Closest Object on Map
	void objectSearch(ObjectManager &OM, int mouseX, int mouseY);

	//! Main Function for Placing Objects
	void placement(ObjectManager &OM, int mouseX, int mouseY);

	//! Main Function for Interacting with Objects
	void interactions(ObjectManager &OM, World &Map, int mouse_x, int mouse_y);

	/*! Allows Keyboard and Mouse Functionality
		- Parameters:
		<> &Map -> Reference to our Game Map
		<> &Art -> Reference to Drawing Capabilities
		<> *display -> Gives access to the Window Display
		<> *font -> Gives access to the Game Font
		<> *queue -> Gives access to the Queue for Different Events
		<> &OM -> References the Object Manager for Accessibility
	*/
	bool beginInteractions(World &Map,MainDraw &Art, ALLEGRO_DISPLAY * display, ALLEGRO_FONT * font, ALLEGRO_EVENT_QUEUE  *queue, ObjectManager &OM, float screenX, float screenY, GlobalStatics &globStatic);

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

	//! Variables to store which chunck the character is in
	int chunkX = charXPosition % (GC::chunkDim * GC::tileDim);
	int chunkY = charYPosition % (GC::chunkDim * GC::tileDim);

	CharacterMovement movement = CharacterMovement(charXPosition, charYPosition);
	int numberOfChunks = 5;
	int mapXBoundary = GC::chunkDim * GC::tileDim * numberOfChunks - GC::charImgWidth;
	int mapYBoundary = GC::chunkDim * GC::tileDim * numberOfChunks - GC::charImgHeight;

	//! Gives positioning with player in the center
	float scrollX = charYPosition + GC::charImgWidth / 2;
	float scrollY = charXPosition + GC::charImgHeight / 2;


	//! bool for debug menu
	bool showDebugMenu = false;

	//! bool for fps
	bool showFPS = true;

	bool GameInteractions(World &Map, MainDraw &Art, ALLEGRO_DISPLAY * display, ALLEGRO_FONT * font, ALLEGRO_EVENT_QUEUE  *queue, ObjectManager &OM, float screenX, float screenY, GlobalStatics &globStatic);
	bool MainMenuInteractions(GlobalStatics &globStatic);


private:

	//! Struct to Store Closest Object Information
	struct CloseObject
	{
		bool machine = false;
		bool item = false;
		bool ore = false;
		int objectX = 0;
		int objectY = 0;
		int objectIndex = 0;
		std::string objectName = "";
	};

	CloseObject closeObject;

	//! Transformed X and Y Position from Button Press
	float startX, startY;

	//! Transformed X and Y Position from Button Release
	float endX, endY;

	//! Used to Store Distance Between Objects
	float distance;

	//! The X and Y Positions of the Screen Before and After Scrolling
	float startScreenX;
	float startScreenY;
	float endScreenX;
	float endScreenY;

	//! The Max/Mins are Used to Define the Boundaries of an Object
	float maxX, minX, maxY, minY;

	//! Booleans Used to Determine Placement State
	bool slot1 = false; bool slot2 = false; bool slot3 = false; bool slot4 = false;
	bool slot5 = false; bool slot6 = false; bool slot7 = false; bool slot8 = false;
	bool machineMode = false; bool itemMode = false; bool trackMode = false;
	bool interactMode = true;

	//! Array to Store Boolean States
	bool *stateArray[12] = { &slot1, &slot2, &slot3, &slot4,
							&slot5, &slot6, &slot7, &slot8,
							&machineMode, &itemMode, &trackMode, 
							&interactMode };
};