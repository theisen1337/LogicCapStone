#pragma once
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include <iostream>
#include <string> 
#include <filesystem>

class Pause
{
public:
	//! open menu
	//void menuOpen();
	Pause();
	~Pause();

	//! close menu
	void menuExit();

	//! array of bools associated with the array of buttons to check if the button is hovered over
	bool hover[4];

	//! If we're using the same button for both opening and closing the start menu, then we check if it's already open
	bool startMenuOpened = false; //Can be put in the game loop to check if the menu is opened, and if so, then we have a different interaction

	int yBut[4]; //for the Y position of the buttons

	//! Draw the menu buttons
	void draw(int displayW, int displayH); //int charX, int charY

	//! makes a true/false check to see if the mouse position is above the button. CouldMaybePossibly make a new image to indicate that the mouse is hovered
	void buttonHover(int x, int mouseX, int mouseY);

	//! Return the bool. Used for If statements for state-changing
	bool getHover(int i);

	//! 4 button options of Resume, Save, Load, Exit
	ALLEGRO_BITMAP *button[4];


private:
	//! X and Y positions and Width and Height
	//int x = 100;
	//int y;
	int w = 200;
	int h = 55;
	//int yPlace = 50;

};

/*
al_rest(double) pauses for double seconds
ALLEGRO_BITMAP *name = thing
al_destroy_bitmap(bitmap) prevents memory leaks
changeState(type &state, type newState) to change the state, discuss during interivew
*/

/*
	Statemanager, can use the al_rest to pause based on the time of the loop, though I believe many things could go wrong. 
		But seperating the states into 2-3 different states (game loop, pause menu loop, possible start menu loop), would be a way to go.
		Use a function to change the state (public enum), then have a check each loop. (might be a more effective way, but this one seems to be the best)
*/