#pragma once

#include <stdio.h>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "OreBase.h"
#include "Tile.h"

using namespace std;

class NewGen
{
public:
	vector < vector<Tile> > initTerrain(vector < vector <Tile> > tiles, Tile::Types type);
	vector < vector<Tile> > initOre(vector < vector <Tile> > ores, Tile::Types type);

	vector < vector<Tile> > setTileGrid(vector < vector <Tile> > tiles, Tile::Types type);

	//vector < vector<Tile> > setOreGrid(vector < vector<Tile> > ores, vector < vector<Tile> > &tiles, Tile::Types ore1);
	vector < vector<Tile> > setOreGrid(vector < vector<Tile> > ores, vector < vector<Tile> > &tiles, Tile::Types ore1, Tile::Types ore2, Tile::Types aqua);
	//vector < vector<Tile> > setOreGrid(vector < vector<Tile> > ores, vector < vector<Tile> > &tiles, Tile::Types ore1, Tile::Types ore2, Tile::Types ore3);

	//vector < vector<Tile> > newOreAlGore(vector < vector <Tile> > &ores, vector < vector <Tile> > &tiles, Tile::Types ore);
	vector < vector<Tile> > newOreAlGore(vector < vector <Tile> > &ores, vector < vector <Tile> > &tiles, Tile::Types ore1, Tile::Types ore2, int baseChance);
	//vector < vector<Tile> > newOreAlGore(vector < vector <Tile> > &ores, vector < vector <Tile> > &tiles, Tile::Types ore1, Tile::Types ore2, Tile::Types ore3);

	void resetChance(int baseChance);
	void spreadOre(vector < vector <Tile> > &ores, vector < vector <Tile> > &tiles, Tile::Types ore, int i, int j, int baseChance);
	

	vector < vector<Tile> > newLakeAlGore(vector < vector <Tile> > &ores, vector < vector <Tile> > &tiles, Tile::Types aqua, Tile::Types temp, int lakeReach);
	//vector < vector <Tile> > revampWater(vector < vector <Tile> > tiles);
	vector < vector <Tile> > revamp(vector < vector <Tile> > tiles, Tile::Types temp, Tile::Types newTile);

private:
	int randy; //for random number generation
	int chunkSize = 32;
	//int lakeReach = 3; //is now part of the function
	int chance;
	//int baseChance = 12; //is now part of the function
	int up, dwn, l, r, uu, dd, ll, rr; //four different points
};

/********************************
*	In the Chunk.cpp genChunk() put this

r = rand() % 2;
//r = 0; //DEBUG
if (r == 0) //Grassland
{
cout << "Grassland!" << endl; //DEBUG
terrainLayer = gen.initTerrain(terrainLayer, Tile::GRASS);//DEBUG THIS LATER //Makes a default terrain, but this is done in intialChunk()
//oreLayer = gen.initOre(oreLayer, Tile::EMPTY); //DEBUG THIS LATER //GG ALREADY EMPTY
oreLayer = gen.setOreGrid(oreLayer, terrainLayer, Tile::COAL, Tile::IRON, Tile::WATER); //setOreGrid(vector < vector<Tile> > ores, vector < vector<Tile> > &tiles, Tile::Types ore1, Tile::Types ore2, Tile::Types aqua);
oreLayer = gen.newOreAlGore(oreLayer, terrainLayer, Tile::COAL, Tile::IRON, 12); //newOreAlGore(vector < vector <Tile> > &ores, vector < vector <Tile> > &tiles, Tile::Types ore1, Tile::Types ore2, int baseChance);
terrainLayer = gen.setTileGrid(terrainLayer, Tile::WATER); //setTileGrid(vector < vector <Tile> > tiles, Tile::Types type);
terrainLayer = gen.newLakeAlGore(oreLayer, terrainLayer, Tile::WATER, Tile::TEMP_WATER, 3); //newLakeAlGore(vector < vector <Tile> > &ores, vector < vector <Tile> > &tiles, Tile::Types aqua, Tile::Types temp, int lakeReach);
terrainLayer = gen.revamp(terrainLayer, Tile::TEMP_WATER, Tile::WATER); //revamp(vector < vector <Tile> > tiles, Tile::Types temp, Tile::Types newTile);
}
//if (r == 1) //Desert
else //desert
{
cout << "Desert" << endl; //DEBUG
terrainLayer = gen.initTerrain(terrainLayer, Tile::SAND); //DEBUG THIS LATER //Makes a default terrain, but this is one in initialChunk()
//oreLayer = gen.initOre(oreLayer, Tile::EMPTY); //DEBUG THIS LATER //GG ALREADY EMPTY
oreLayer = gen.setOreGrid(oreLayer, terrainLayer, Tile::COAL, Tile::IRON, Tile::QUICK); //setOreGrid(vector < vector<Tile> > ores, vector < vector<Tile> > &tiles, Tile::Types ore1, Tile::Types ore2, Tile::Types aqua);
oreLayer = gen.newOreAlGore(oreLayer, terrainLayer, Tile::COAL, Tile::IRON, 10); //newOreAlGore(vector < vector <Tile> > &ores, vector < vector <Tile> > &tiles, Tile::Types ore1, Tile::Types ore2, int baseChance);
terrainLayer = gen.setTileGrid(terrainLayer, Tile::QUICK); //setTileGrid(vector < vector <Tile> > tiles, Tile::Types type);
terrainLayer = gen.newLakeAlGore(oreLayer, terrainLayer, Tile::QUICK, Tile::TEMP_QUICK, 4); //newLakeAlGore(vector < vector <Tile> > &ores, vector < vector <Tile> > &tiles, Tile::Types aqua, Tile::Types temp, int lakeReach);
terrainLayer = gen.revamp(terrainLayer, Tile::TEMP_QUICK, Tile::QUICK); //revamp(vector < vector <Tile> > tiles, Tile::Types temp, Tile::Types newTile);
}



********************************/