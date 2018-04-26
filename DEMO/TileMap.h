#pragma once
#include "Tiles.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

class TileMap
{
public:
	TileMap();
	~TileMap();

	void Generate_Terrain();
	void Generate_Ore();

	void CreateTileBuffer(ALLEGRO_DISPLAY &dis);
	void drawTile(int i, float x, float y, float w, float h);
	void TileMapDraw(ALLEGRO_DISPLAY &dis, float scroll_x, float scroll_y, float zoom, float rotate);
private:
	int SIZE_X = 100;
	int SIZE_Y = 100;
	int arr[100 * 100];

	ALLEGRO_BITMAP *Bitmap;
	Tiles tiles;
};

