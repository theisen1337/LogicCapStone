#include "Iron.h"

void Iron::LeftClickInteract()
{
	al_show_native_message_box(al_get_current_display(),
		"Character Interaction",
		"Character left clicked on an iron ore",
		"Success",
		NULL, ALLEGRO_MESSAGEBOX_ERROR); ////DF TURN ON DIALOG ADD ON
}

void Iron::RightClickInteract()
{
	al_show_native_message_box(al_get_current_display(),
		"Character Interaction",
		"Character right clicked on an iron ore",
		"Success",
		NULL, ALLEGRO_MESSAGEBOX_ERROR);
}

void Iron::Drop()
{
}
