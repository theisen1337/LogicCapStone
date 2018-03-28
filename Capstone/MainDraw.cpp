#include "MainDraw.h"
	

void MainDraw::Init()
{	
	ia.Initialize();
	//atlas = al_load_bitmap("Resources//terrainAtlasOld.png");
	terrainAtlas = ia.LoadImageAtlas(ImageAtlas::Terrain);
	terrainRef = ia.getTerrainRef();
	characterAtlas = ia.LoadImageAtlas(ImageAtlas::Character);
	characterRef = ia.getCharacterRef();
	machineAtlas = ia.LoadImageAtlas(ImageAtlas::Machine);
	machineRef = ia.getMachineRef();
	itemAtlas = ia.LoadImageAtlas(ImageAtlas::Item);
	itemRef = ia.getItemRef();

}


void MainDraw::Draw(ObjectManager &OM)
{
	OM.Draw();
}

void MainDraw::drawWorld(World &world, ALLEGRO_DISPLAY & dis)
{
	//atlas = ia.LoadImageAtlas(ImageAtlas::Terrain);
	//ref = ia.getTerrainRef();


	al_set_target_backbuffer(&dis);
	al_clear_to_color(al_map_rgb(0, 0, 0));

	world.drawWorld(terrainAtlas, dis, terrainRef);
}

void MainDraw::drawCharacter(CharacterPlayer & c, CharacterMovement & movement)
{
	//atlas = ia.LoadImageAtlas(ImageAtlas::Character);
	//ref = ia.getCharacterRef();

	for (int i = 0; i < characterRef.size(); i++)
	{
		for (int j = 0; j < characterRef[i].size(); j++)
		{
			if (characterRef[i][j].compare(c.getRef())== 0)
			{
				al_draw_scaled_bitmap(characterAtlas, i*GC::charImgDim, j*GC::charImgDim, 48, 48, movement.getCharacterXPosition(), movement.getCharacterYPosition(), GC::charImgDim, GC::charImgDim, 0);
				break;
			}
		}
	}
}
