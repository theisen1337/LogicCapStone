#pragma once

// Standard Includes
#include <stdio.h>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>

// Custom Includes
#include "OreBase.h"
#include "Tile.h"

using namespace std;

class Generation
{
public:
	//! creates the initial grid using the starting variables. This may not be neccessary since we have the chunks
	vector < vector<Tile> > setTileGrid(vector < vector <Tile> > tile);
	
	//! Sets the Ore Grid and Creates 2-D Vector
	vector < vector<Tile> > setOreGrid(vector < vector<Tile> > oreo, vector < vector<Tile> > &tiles);

	//! Edits the Tiles vector(s) to turn the random water tiles into lakes //Might use this to switch Ore and Lake algorithm
	vector < vector<Tile> > newOreAlGore(vector < vector <Tile> > &ores, vector < vector <Tile> > &tiles);

	//! Creates New Lake Algorithm
	vector < vector<Tile> > newLakeAlGore(vector < vector <Tile> > &ores, vector < vector <Tile> > &tiles);

	//! Revamps the Water
	vector < vector <Tile> > revampWater(vector < vector <Tile> > tiles);

private:

	int chunkSize = 32;
	int oreReach = 3; //was 3
	int baseChance = 12; //was 4
};