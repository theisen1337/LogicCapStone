#include "MainDraw.h"
	

void MainDraw::Init()
{							//"Terrain//Machine//Miner//Miner_ON.png"

}

void MainDraw::Draw(ObjectManager &OM)
{
	//ML.Draw();
	//TL.Compute();
}

void MainDraw::tileBuffer(ALLEGRO_DISPLAY & dis, World & world)
{
	//al_set_new_bitmap_flags(ALLEGRO_VIDEO_BITMAP);
	Bitmap = al_create_bitmap(4096, 4096);
	al_set_target_bitmap(Bitmap);
	//These two loops are for looping through world vector
	for (int j = 0; j < 2; j++)
	{
		for (int k = 0; k < 2; k++)
		{

			//al_draw_scaled_bitmap(world.getChunk()[j][k].getMap(),
			//	0, 0,
			//	2048, 2048,
			//	(j*2048), (k*2048),
			//2048, 2048, 0);
			//Draw the temp bitmap	
			al_draw_bitmap(world.getChunk()[j][k].getMap(), (j * 2048), (k * 2048), 0);
		}
	}
	al_set_target_backbuffer(&dis);
}

void MainDraw::drawWorld(World world)
{
	
	al_clear_to_color(al_map_rgb(0, 0, 0));

	/*
	for (int j = 0; j < worldDim; j++)
	{
	for (int k = 0; k < worldDim; k++)
	{
	al_draw_scaled_bitmap(world.getChunk()[j][k].getMap(),
	0, 0,
	2048, 2048,
	(j * 2048), (k * 2048),
	2048, 2048, 0);

	//al_draw_bitmap(world.getChunk()[j][k].getMap(),
	//(j * 2048), (k * 2048), 0);
	}
	}*/

	//Draw the world Map
	al_draw_bitmap(Bitmap, 0, 0, 0);


}

void MainDraw::drawCharacter(CharacterPlayer & c, CharacterMovement movement)
{
	
	al_draw_scaled_bitmap(c.getPic(), 0, 0, 48, 48, movement.getCharacterXPosition(), movement.getCharacterYPosition(), 48, 48, 0);

}
