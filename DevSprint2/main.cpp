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

//#include "main.h"
#include "StateManager.h"





int main(void) 
{
	try
	{
		static StateManager game;
		game.run();
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}