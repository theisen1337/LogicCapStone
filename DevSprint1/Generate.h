#pragma once

#include <vector>
#include "Ore.h"
#include "Tile.h"
//
using namespace std;

class Generation
{
public:
	vector < vector<Tile> > setTileGrid(vector < vector <Tile> > tile);
	vector < vector<Tile> > setOreGrid(vector < vector<Tile> > oreo, vector < vector<Tile> > tiles);
	void showTiles(vector < vector <Tile> > tiles);
	vector < vector <Tile> > lakeAlGore(vector < vector <Tile> > tiles);
	vector < vector <Tile> > oreAlGore(vector < vector <Tile> > ores, vector < vector <Tile> > tiles);
	vector < vector <Tile> > revampOre(vector < vector <Tile> > ores);
private:
	int chunkSize = 32;
};