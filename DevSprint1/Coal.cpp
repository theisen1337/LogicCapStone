#include "Coal.h"

void Coal::Interact()
{
}

void Coal::leftClickInteract()
{
	al_show_native_message_box(al_get_current_display(),
		"Character Interaction",
		"Character left clicked on a coal ore",
		"Success",
		NULL, ALLEGRO_MESSAGEBOX_ERROR);
}

void Coal::rightClickInteract()
{
	al_show_native_message_box(al_get_current_display(),
		"Character Interaction",
		"Character right clicked on a coal ore",
		"Success",
		NULL, ALLEGRO_MESSAGEBOX_ERROR);
}

void Coal::Drop()
{
	// TODO: create a coal Items obj
}

