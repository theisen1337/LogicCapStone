#include "MainDraw.h"
	

void MainDraw::Init()
{	
	ia.Initialize();
	atlas = al_load_bitmap("Resources//terrainAtlasOld.png");

}


void MainDraw::Draw(ObjectManager &OM)
{
	//ML.Draw();
	//TL.Compute();
}

void MainDraw::drawWorld(World &world, ALLEGRO_DISPLAY & dis)
{
	al_set_target_backbuffer(&dis);
	al_clear_to_color(al_map_rgb(0, 0, 0));

	world.drawWorld(atlas, dis);
}

void MainDraw::drawCharacter(CharacterPlayer & c, CharacterMovement movement)
{
	
	al_draw_scaled_bitmap(c.getPic(), 0, 0, 48, 48, movement.getCharacterXPosition(), movement.getCharacterYPosition(), 48, 48, 0);

}
