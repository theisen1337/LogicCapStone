#pragma once

#include <vector>
#include "Ore.h"
#include "Tile.h"

using namespace std;

class Generation
{
public:
	vector < vector<Tile> > createTileGrid(int xAxis, int yAxis, Tile til);
	vector < vector<Ore> > createOreGrid(int xAxis, int yAxis, Ore oreo);
	void showTiles(vector < vector <Tile> > tiles);
	void lakeAlGore(vector < vector <Tile> > &tiles);
	void oreAlGore(vector < vector <Ore> > &ores, vector < vector <Tile> > &tiles);
	void revampOre(vector < vector <Ore> > &ores);
private:
	Tile til;
	Ore ore;
	int xAxis; //may be useless and rely on TileMap's SIZE_X number instead 
	int yAxis;

};