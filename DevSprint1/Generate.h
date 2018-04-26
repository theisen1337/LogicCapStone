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
	vector < vector<Tile> > setOreGrid(vector < vector<Tile> > oreo, vector < vector<Tile> > &tiles);
	vector < vector<Tile> > newOreAlGore(vector < vector <Tile> > &ores, vector < vector <Tile> > &tiles);
	vector < vector<Tile> > newLakeAlGore(vector < vector <Tile> > &ores, vector < vector <Tile> > &tiles);
	vector < vector <Tile> > revampWater(vector < vector <Tile> > tiles);

	/*Use before the Great Switch of Water Ore. The code in left in another cpp file*/
	//vector < vector <Tile> > revampOre(vector < vector <Tile> > ores);
	//vector < vector <Tile> > lakeAlGore(vector < vector <Tile> > tiles);
	//void oreAlGore(vector < vector <Tile> > &ores, vector < vector <Tile> > &tiles); //vector < vector <Tile> > 
	//void waterYouDoing(vector < vector <Tile> > &ores, vector < vector <Tile> > &tiles); //TESTING switching the Ore and Lake algorithms
	//void oreoCookie(vector < vector <Tile> > &ores, vector < vector <Tile> > &tiles);
private:
	int chunkSize = 32;
	int oreReach = 3; //was 3
	int baseChance = 12; //was 4
};