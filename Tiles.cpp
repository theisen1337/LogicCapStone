#include "Tiles.h"

//#include <boost/filesystem.hpp> //check out Boost Filesystem

FileIO IO = *(LogisticsGame::getIO());


Tiles::Tiles()
{
	loadTiles();
}

void Tiles::loadTiles()
{
	load_Terrian();
	load_Grass();
	load_Ore();
}

void Tiles::load_Terrian()
{
	if (!IO.DirectoryExist("Terrain"))
	{
		IO.CreateDir("Terrain");
	}
}

void Tiles::load_Grass()
{
	if (!IO.DirectoryExist("Terrain\\Grass"))
	{
		IO.CreateDir("Terrain\\Grass");
	}

	std::string test[] = { "grass1.png" , "grass2.png" , "grass3.png" , "grass4.png" };

	for (int i = 0; i < 4; i++)
	{
		std::string file = "Terrain\\Grass\\" + test[i];
		ALLEGRO_BITMAP *testImage = al_load_bitmap(file.c_str());
		arrTiles.push_back(testImage);
		grassCount++;
	}
}

void Tiles::load_Ore()
{
	if (!IO.DirectoryExist("Terrain\\Ore"))
	{
		IO.CreateDir("Terrain\\Ore");
	}
	
	std::string Ores[] = { "Coal.png" };

	for (int i = 0; i < 1; i++)
	{
		std::string file = "Terrain\\Ore\\" + Ores[i];
		ALLEGRO_BITMAP *testImage = al_load_bitmap(file.c_str());
		arrTiles.push_back(testImage);
		OreCount++;
	}
	OreOffset = grassCount;
}

Tiles::~Tiles()
{
}

ALLEGRO_BITMAP * Tiles::getTile(unsigned int index)
{
	if (index >= (arrTiles.size())  )
	{
		//error out of bounds
		return nullptr;
	}
	return (arrTiles.at(index));
}

int Tiles::getTotal()
{
	/*if (type == "GRASS")
	{
		return grassTiles.size();
	}
	else if (type == "")
	{
		return arrTiles.size();
	}*/
	return arrTiles.size();
}
