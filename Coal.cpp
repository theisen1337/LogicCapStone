#include "Coal.h"

void Coal::LeftClickInteract()
{
	al_show_native_message_box(al_get_current_display(),
		"Character Interaction",
		"Character left clicked on a coal ore",
		"Success",
		NULL, ALLEGRO_MESSAGEBOX_ERROR); //DF TURN ON DIALOG ADD ON
}

void Coal::RightClickInteract()
{
	al_show_native_message_box(al_get_current_display(),
		"Character Interaction",
		"Character right clicked on a coal ore",
		"Success",
		NULL, ALLEGRO_MESSAGEBOX_ERROR);
}

void Coal::Drop()
{
	// TODO: create a coal item obj
}

