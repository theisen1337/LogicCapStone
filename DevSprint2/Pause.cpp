#include "Pause.h"
#include <iostream>
#include <string> 
using namespace std;
//ALLEGRO_EVENT event;

Pause::Pause()
{

}

Pause::~Pause() 
{

}

void Pause::menuExit()
{
	exit(0); // simply exit the program

	// or change the state to return to a main menu, if/when that is made
	// if so, then make this a change state
}

void Pause::draw(int displayW, int displayH)
{
	//int x = charX - 100; //was for char placement
	//int yPlace = charY + 110;
	//al_draw_filled_rounded_rectangle(float x1, float y1, float x2, float y2, float rx, float ry, ALLEGRO_COLOR color)

	int x = displayW + 220; // the display position + the spacing before the topleft corner of the pic
	int yPlace = displayH + 50; // the display position + the spacing before the topleft corner of the pic

	//int x = al_get_display_width(display); //based off of display
	//int yPlace = al_get_display_height(display);
	string bitButton; //for the button string name
	string bitNum; //file number	
	for (int i = 0; i < 4; i++) //uses a loop to create all of the button bitmaps
	{
		yBut[i] = yPlace; //use the array of Y positions
		

		bitNum = to_string(i); //changes i into a string of the same number
		bitButton = "Buttons//Button"; //file location much like "Terrain//Water//water3.png" in the Tiles.cpp file
		bitButton += bitNum; //adds the number to the location string
		bitButton += ".png"; //file type
		const char *buttonLoc = bitButton.c_str(); //converts to const char pointer

		//button[i] = al_load_bitmap("Buttons//Button\i\.png"); //will load the image of Button\i\ in the i position
		//button[i] = al_load_bitmap(bitButton); //doesn't like strings, really really wants const char pointers
		button[i] = al_load_bitmap(buttonLoc);
		//button[i] = al_load_bitmap("Terrain//Water//water3.png"); testing
		al_draw_bitmap(button[i], x, yBut[i], NULL); //make button

		yPlace += 70; //increase the yPlace to move the buttons down MUST BE GREATER THAN THAT HEIGHT!
	}

	//Hard coded
	//al_draw_bitmap(button[0], 100, 50, NULL); //Resume
	//al_draw_bitmap(button[1], 100, 120, NULL); //Save
	//al_draw_bitmap(button[2], 100, 190, NULL); //Load
	//al_draw_bitmap(button[3], 100, 260, NULL); //Exit
}

void Pause::buttonHover(int x, int mouseX, int mouseY) //check to see if the mouse is over the button
{
	for (int i = 0; i < 4; i++) //loop to check all of the buttons to see if the hovering is happening
	{
		if ((mouseX >= x) && (mouseX <= x + w) && (mouseY >= yBut[i]) && (mouseY <= yBut[i] + h))
		{
			hover[i] = true; // if this is true, then a mouse click or button press, whatever is choses, will activate the desired effect
		}

		else
		{
			hover[i] = false; //need to reset to false, otherwise we get that glitch where the mouse is always hovered over
		}
	}

	//Hard Coded
	/*
	if ((mouseX >= 100) && (mouseX <= 300) && (mouseY >= 50) && (mouseY <= 105))
	{
		hover[0] = true;
	}
	else if ((mouseX >= 100) && (mouseX <= 300) && (mouseY >= 120) && (mouseY <= 175))
	{
		hover[1] = true;
	}
	else if ((mouseX >= 100) && (mouseX <= 300) && (mouseY >= 190) && (mouseY <= 245))
	{
		hover[2] = true;
	}
	else if ((mouseX >= 100) && (mouseX <= 300) && (mouseY >= 260) && (mouseY <= 315))
	{
		hover[3] = true;
	}
	else
	{
		for(int i = 0; i < 4; i++
		{
			hover[i];
		}
	}
	*/
}

bool Pause::getHover(int i) //get the hover bool from arry position [i]
{
	if (i > 3) //if i tries to go beyond the array, then we just return false
	{
		//cout << "DEBUG";
		return false;
	}
	else
	{
		return hover[i];
	}
	
}


// Need to check on the Interacts or StateManager w/e will be better suited for the job
/*
if(Pause.getHover(0) == true && event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
{
	stateChangerThing == enumGame;
}

if(Pause.getHover(1) == true && event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
{
	stateChangerThing = enumSaveMenu;
	OR
	SaveLoad.SaveGame(); stateChangerThing = enumGame;
}
if(Pause.getHover(2) == true && event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
{
	stateChangerThing == enumLoadMenu;
	OR
	SaveLoad.LoadGame(); al_rest(double howeverLongItMayTakeToLoadOrJustLetItLoad); stateChangerThing = enumGame
}
if(Pause.getHover(3) == true && event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
{
	possibleConfirmationChoice();
	stateChancerThing = mainMenu;
	OR
	exit(0); //probably this for starting out
}
*/