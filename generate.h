#pragma once

#include <stdio.h>
#include <math.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "stdafx.h"
#include "Ore.h"
#include "Tile.h"

class Generation
{
public:
	vector < vector<Tile> > createTileGrid(int xAxis, int yAxis);
	vector < vector<Ore> > createOreGrid(int xAxis, int yAxis);
	void showTiles(vector < vector <Tile> > tiles);
	void lakeAlGore(vector < vector <Tile> > &tiles);
	void orAlGore(vector < vector <Ore> > ores, vector < vector <Tile> > &tiles);
	void revampOre(vector < vector <Ore> > &ores);
private:
	Tile til;
	Ore ore;
	int xAxis;
	int yAxis;

};