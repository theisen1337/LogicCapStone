// generate.cpp : Defines the entry point for the console application.
//


#include <stdio.h>
#include <math.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Ore.h"
#include "Tile.h"
#include "Generate.h"

using namespace std;

/*creates the initial grid using the starting variables. This may not be neccessary since we have the chunks*/
vector < vector <Tile> > Generation::createTileGrid(int xAxis, int yAxis, Tile til)
{
	vector < vector<Tile> >tileGrid;
	for (int i = 0; i < yAxis; i++) //grid[this][][] 
	{
		vector<Tile> grid0;
		tileGrid.push_back(grid0);
		for (int j = 0; j < xAxis; j++) //grid[][this][]
		{
			int randy = rand() % 13; //creates the GRASS, DIRT and WATER tiles randomly
			if (randy < 9) //9 out of 13 chance for GRASS
			{
				til.setType(Tile::GRASS);
			}
			else if (randy < 12) //3 out of 13 chance for DIRT
			{
				til.setType(Tile::DIRT);
			}
			else //1 out of 13 chacne for WATER
			{
				til.setType(Tile::WATER);
			}
			//til.setChunkX(j); //This is the X axis. [y][x] because matrix logic
			//til.setChunkY(i); //may rework the chunky cheeses here depending on how the chunks are meant to work
			tileGrid[i].push_back(til);
		}
	}
	return tileGrid;
}

/*Creates a 2D vector*/
vector < vector<Ore> > Generation::createOreGrid(int xAxis, int yAxis, Ore oreo)
{
	
	vector < vector<Ore> > oreGrid;
	for (int i = 0; i < yAxis; i++) //grid[this][][]
	{
		vector<Ore> grid0;
		oreGrid.push_back(grid0);
		for (int j = 0; j < xAxis; j++) //grid[][this][]
		{
			int randy = rand() % 15;
			if (randy == 0) //1 out of 15 chance for COAL
			{
				oreo.setType(COAL);
			}
			else if (randy == 1) //1 out of 15 chance for IRON
			{
				oreo.setType(IRON);
			}
			else //13 out of 15 chacne for EMPTY
			{
				oreo.setType(EMPTY);
			}
			oreGrid[i].push_back(oreo);
		}
	}
	return oreGrid;
}

/*The showTiles function will probably not be used and will instead rely on the TileMap class*/
void Generation::showTiles(vector < vector <Tile> > tiles)
{
	for (int i = 0; i < tiles.size(); i++)
	{
		for (int j = 0; j < tiles[i].size(); j++)
		{
			//tiles.genPicture(); show the 
			//tiles.getChunkX(j);
			//tiles.getChunkY(i);
			//cout << " ";
		}
		cout << endl;
	}
}

/*Edits the Tiles vector(s) to turn the random water tiles into lakes*/
void Generation::lakeAlGore(vector < vector <Tile> > &tiles) //edits the tile
{
	int randy; //for random number generation
	int chance = 4; //% chance of making a new lake. It increases as the lake size increases
	int firstLake = 1;
	for (int i = 0; i < tiles.size(); i++)
	{
		for (int j = 0; j < tiles[i].size(); j++)
		{

			if (tiles[i][j].type == Tile::WATER) //checks to see if we have a WATER tile
			{
				randy = rand() % chance; //obtain the random number

				if (chance == 4 && firstLake == 1) //if the WATER tile we hit the very first
				{
					//25% chance the first Lake tile will spread downward, leading to another check with 100% spread chance.
					//Cannot happen if already at the bottom, otherwise we get an error for placing an 'L' outside of the grid
					if (randy == 0 && i != tiles.size() - 1)
					{
						tiles[i + 1][j].type = Tile::WATER;
						firstLake = 0; //may or may not require more rigging. The house must always win!!
					}
					//25% chance the first Lake tile will spread rightward, leading to another check with 100% spread chance
					//Cannot happen if already at the right edge, otherwise we get an error for placing an 'L' outside of the grid
					else if (randy == 1 && j != tiles[i].size() - 1)
					{
						tiles[i][j + 1].type = Tile::WATER;
						firstLake = 0;
					}
					//50% chance the first Lake tile will spread downward, leading to another check with 100% spread chance
					//HOWEVER we might be at the edge, which causes many issues, we will rig it a bit more with THREE OPTIONS
					else if (randy > 1 && i != tiles.size() - 1 && j == tiles[i].size() - 1) //if we're not at the bottom, but at the right, then we only change the lower tile
					{
						tiles[i + 1][j].type = Tile::WATER;
						firstLake = 0;
					}
					else if (randy > 1 && i == tiles.size() - 1 && j != tiles[i].size() - 1) //if we're not at the right but at the bottom, then we only change the right
					{
						tiles[i][j + 1].type = Tile::WATER;
						firstLake = 0;
					}
					else if (randy > 1 && i != tiles.size() - 1 && j != tiles[i].size() - 1) //If we are NOT at the bottom and not the right, then we change both
					{
						tiles[i + 1][j].type = Tile::WATER;
						tiles[i][j + 1].type = Tile::WATER;
						firstLake = 0;
					}
					else
					{
						firstLake = 0;
					}
				}

				//Now if we find us a WATER tile and it isn't the first one we found, then we go on with a normal algorithm 
				else
				{
					if (randy == 0 && i != tiles.size() - 1)
					{
						tiles[i + 1][j].type = Tile::WATER; //% chance of making the lower tile a lake. also allows for another Lake roll
						chance++; //decreases the % chance of increasing the Lake size

					}
					else if (randy == 0 && i == tiles.size() - 1) //if we're already at the bottom, then we can't just make one below it
					{
						if (j == tiles.size() - 1) //if we are at the very very bottom-right corner of the world.
						{
							chance = 4;
							firstLake = 1;
						}
						else
						{
							tiles[i - 1][j].type = Tile::WATER; //small chance of adding another Lake tile above the current Lake tile (chances are, there is already one there)
						}
					}
					else if (randy == 1 && j != tiles[j].size() - 1)
					{
						tiles[i][j + 1].type = Tile::WATER; //% chance of making the right tile a lake. also allows for another Lake roll
						chance++; //decreases the % chance of increasing the Lake size
					}
					else if (randy == 1 && j == tiles[i].size() - 1)
					{
						if (i == tiles.size() - 1)
						{
							chance = 4;
							firstLake = 1;
						}
						else
						{
							tiles[i][j - 1].type = Tile::WATER; //small chance of adding a Lake tile to the left. chances are, there is already a Lake tile there.
						}
					}
					else if (randy == 2 && i > 0)
					{
						if (tiles[i - 1][j].type == Tile::WATER && i != tiles.size() - 1)
						{
							tiles[i + 1][j].type = Tile::WATER; //% chance of making the lower tile a lake. also allows for another Lake roll
							chance++; //decreases the % chance of increasing the Lake size
						}
						else
						{
							tiles[i - 1][j].type = Tile::WATER; //% chance of making the upper tile a Lake as well
							chance++; //decreases the % chance of increasing the Lake size
						}
					}
					else if (randy == 3 && j > 0)
					{
						if (tiles[i][j - 1].type == Tile::WATER && j != tiles[i].size() - 1)
						{
							tiles[i][j + 1].type = Tile::WATER; //% chance of making the lower tile a lake. also allows for another Lake roll
							chance++; //decreases the % chance of increasing the Lake size
						}
						else
						{
							tiles[i][j - 1].type = Tile::WATER; //% chance of making the left tile a Lake as well
							chance++; //decreases the % chance of increasing the Lake size
						}
					}
					else
					{
						if (i != tiles.size() - 1 || j != tiles[i].size() - 1 || tiles[i + 1][j].type == Tile::WATER || tiles[i][j + 1].type == Tile::WATER)
						{
							chance = 4; //returns the Lake change for the first time.
							firstLake = 1;
						}
					}
				}
			}
		}
	}
}

/*Edits ore tiles to look like globs of ore*/
void Generation::oreAlGore(vector < vector <Ore> > &ores, vector < vector <Tile> > &tiles)
{
	int randy, chance, up, dwn, l, r, uu, dd, ll, rr; //four different points
	for (int i = 0; i < ores.size(); i++) //This tries to expand the ores
	{
		for (int j = 0; j < ores[i].size(); j++)
		{
			//chacne = x; Not needed yet. Used for later Sprint for editting spawn chances, expanding chances, etc etc.
			//randy = rand() % chance; // Need for later

			if (ores[i][j].type == COAL)
			{
				up = randy % 3 + 1;
				dwn = randy % 3 + 1;
				l = randy % 3 + 1;
				r = randy % 3 + 1;

				for (int a = 1; a < up + 1; a++) //for all the UPPER tiles. use same loop for the left, right, and lower rows
				{
					if (i - a >= 0 && tiles[i - a][j].type != WATER && ores[i - a][j].type != COAL)
					{
						ores[i - a][j].type = TEMP_COAL; //Makes a temperary COAL tile. This way, we can expand the coal without causing any massive issues
						tiles[i - a][j].type = DIRT; 

						ll = randy % (up - a + 1); //'leftLeft' is a random chance between 0 and (upper limit - #ofLoop) Further description in Notes
						for (int x = 1; x <= ll; x++)
						{
							if (j - x >= 0 && tiles[i - a][j - x].type != WATER && ores[i - a][j - x].type != COAL)
							{
								ores[i - a][j - x].type = TEMP_COAL;
								tiles[i - a][j - x].type = DIRT;
							}
						}
						rr = randy % (up - a + 1); //repeat for the other
						for (int x = 1; x <= rr; x++)
						{
							if (j + x < ores[i].size() && tiles[i - a][j + x].type != WATER && ores[i - a][j + x].type != COAL)
							{
								ores[i - a][j + x].type = TEMP_COAL;
								tiles[i - a][j + x].type = DIRT;
							}
						}
					}
				}

				for (int b = 1; b < r + 1; b++) //RIGHT
				{
					if (j + b < ores[i].size() && tiles[i][j + b].type != WATER && ores[i][j + b].type != COAL)
					{
						ores[i][j + b].type = TEMP_COAL;
						tiles[i][j + b].type = DIRT;

						uu = randy % (r - b + 1);
						for (int x = 1; x <= uu; x++)
						{
							if (i - x >= 0 && tiles[i - x][j + b].type != WATER && ores[i - x][j + b].type != COAL)
							{
								ores[i - x][j + b].type = TEMP_COAL;
								tiles[i - x][j + b].type = DIRT;
							}
						}
						dd = randy % (r - b + 1);
						for (int x = 1; x <= dd; x++)
						{
							if (i + x < ores.size() && tiles[i + x][j + b].type != WATER && ores[i + x][j + b].type != COAL)
							{
								ores[i + x][j + b].type = TEMP_COAL;
								tiles[i + x][j + b].type = DIRT;
							}
						}

					}
				}

				for (int c = 1; c < dwn + 1; c++) //LOWER
				{
					if (i + c < ores.size() && tiles[i + c][j].type != WATER && ores[i + c][j].type != COAL)
					{
						ores[i + c][j].type = TEMP_COAL;
						tiles[i + c][j].type = DIRT; //NEED

						ll = randy % (dwn - c + 1);
						for (int x = 1; x <= ll; x++)
						{
							if (j - x >= 0 && tiles[i + c][j - x].type != WATER && ores[i + c][j - x].type != COAL)
							{
								ores[i + c][j - x].type = TEMP_COAL;
								tiles[i + c][j - x].type = DIRT;
							}
						}
						rr = randy % (dwn - c + 1);
						for (int x = 1; x <= rr; x++)
						{
							if (j + x < ores[i].size() && tiles[i + c][j + x].type != WATER && ores[i + c][j + x].type != COAL)
							{
								ores[i + c][j + x].type = TEMP_COAL;
								tiles[i + c][j + x].type = DIRT;
							}
						}
					}
				}

				for (int d = 1; d < l + 1; d++) //LEFT
				{
					if (j - d >= 0 && tiles[i][j - d].type != WATER && ores[i][j - d].type != COAL)
					{
						ores[i][j - d].type = TEMP_COAL;
						tiles[i][j - d].type = DIRT; //NEED

						uu = randy % (l - d + 1);
						for (int x = 1; x <= uu; x++)
						{
							if (i - x >= 0 && tiles[i - x][j - d].type != WATER && ores[i - x][j - d].type != COAL)
							{
								ores[i - x][j - d].type = TEMP_COAL;
								tiles[i - x][j - d].type = DIRT;
							}
						}
						dd = randy % (l - d + 1);
						for (int x = 1; x <= dd; x++)
						{
							if (i + x < ores.size() && tiles[i + x][j - d].type != WATER && ores[i + x][j - d].type != COAL)
							{
								ores[i + x][j - d].type = TEMP_COAL;
								tiles[i + x][j - d].type = DIRT;
							}
						}
					}
				}

			}

			if (ores[i][j][1] == "I")
			{
				up = randy % 3 + 1;
				dwn = randy % 3 + 1;
				l = randy % 3 + 1;
				r = randy % 3 + 1;

				for (int a = 1; a < up + 1; a++) //for all the UPPER tiles. use same loop for the left, right, and lower rows
				{
					if (i - a >= 0 && tiles[i - a][j].type != WATER && ores[i - a][j].type != COAL && ores[i - a][j].type != TEMP_COAL && ores[i - a][j].type != IRON)
					{
						ores[i - a][j].type = TEMP_IRON; //make it a small c as a temp
						tiles[i - a][j].type = DIRT; //NEED

						ll = randy % (up - a + 1); //leftLeft is a random chance between 0 and (upper limit - #ofLoop) Further description in Notes
						for (int x = 1; x <= ll; x++)
						{
							if (j - x >= 0 && tiles[i - a][j - x].type != WATER && ores[i - a][j - x].type != COAL && ores[i - a][j - x].type != TEMP_COAL && ores[i - a][j - x].type != IRON)
							{
								ores[i - a][j - x].type = TEMP_IRON;
								tiles[i - a][j - x].type = DIRT;
							}
						}
						rr = randy % (up - a + 1); //repeat for the other
						for (int x = 1; x <= rr; x++)
						{
							if (j + x < ores[i].size() && tiles[i - a][j + x].type != WATER && ores[i - a][j - x].type != COAL && ores[i - a][j - x].type != TEMP_COAL && ores[i - a][j - x].type != IRON)
							{
								ores[i - a][j + x].type = TEMP_IRON;
								tiles[i - a][j + x].type = DIRT;
							}
						}
					}
				}

				for (int b = 1; b < r + 1; b++) //RIGHT
				{
					if (j + b < ores[i].size() && tiles[i][j + b].type != WATER && ores[i][j + b].type != COAL && ores[i][j + b].type != TEMP_COAL && ores[i][j + b].type != IRON)
					{
						ores[i][j + b].type = TEMP_IRON;
						tiles[i][j + b].type = DIRT; //NEED

						uu = randy % (r - b + 1);
						for (int x = 1; x <= uu; x++)
						{
							if (i - x >= 0 && tiles[i - x][j + b].type != WATER && ores[i - x][j + b].type != COAL && ores[i - x][j + b].type != TEMP_COAL && ores[i - x][j + b].type != IRON)
							{
								ores[i - x][j + b].type = TEMP_IRON;
								tiles[i - x][j + b].type = DIRT;
							}
						}
						dd = randy % (r - b + 1);
						for (int x = 1; x <= dd; x++)
						{
							if (i + x < ores.size() && tiles[i + x][j + b].type != WATER && ores[i - x][j + b].type != COAL && ores[i - x][j + b].type != TEMP_COAL && ores[i - x][j + b].type != IRON)
							{
								ores[i + x][j + b].type = TEMP_IRON;
								tiles[i + x][j + b].type = DIRT;
							}
						}
					}
				}

				for (int c = 1; c < dwn + 1; c++) //LOWER
				{
					if (i + c < ores.size() && tiles[i + c][j].type != WATER && ores[i + c][j].type != COAL && ores[i + c][j].type != TEMP_COAL && ores[i + c][j].type != IRON)
					{
						ores[i + c][j].type = TEMP_IRON;
						tiles[i + c][j].type = DIRT; //NEED

						ll = randy % (dwn - c + 1);
						for (int x = 1; x <= ll; x++)
						{
							if (j - x >= 0 && tiles[i + c][j - x].type != WATER && ores[i + c][j - x].type != COAL && ores[i + c][j - x].type != TEMP_COAL && ores[i + c][j - x].type != IRON)
							{
								ores[i + c][j - x].type = TEMP_IRON;
								tiles[i + c][j - x].type = DIRT;
							}
						}
						rr = randy % (dwn - c + 1);
						for (int x = 1; x <= rr; x++)
						{
							if (j + x < ores[i].size() && tiles[i + c][j + x].type != WATER && ores[i + c][j + x].type != COAL && ores[i + c][j + x].type != TEMP_COAL && ores[i + c][j + x].type != IRON)
							{
								ores[i + c][j + x].type = TEMP_IRON;
								tiles[i + c][j + x].type = DIRT;
							}
						}
					}
				}

				for (int d = 1; d < l + 1; d++) //LEFT
				{
					if (j - d >= 0 && tiles[i][j - d].type != WATER && ores[i][j - d].type != COAL && ores[i][j - d].type != TEMP_COAL && ores[i][j - d].type != IRON)
					{
						ores[i][j - d].type = TEMP_IRON;
						tiles[i][j - d].type = DIRT; //NEED

						uu = randy % (l - d + 1);
						for (int x = 1; x <= uu; x++)
						{
							if (i - x >= 0 && tiles[i - x][j - d].type != WATER && ores[i - x][j - d].type != COAL && ores[i - x][j - d].type != TEMP_COAL && ores[i - x][j - d].type != IRON)
							{
								ores[i - x][j - d].type = TEMP_IRON;
								tiles[i - x][j - d].type = DIRT;
							}
						}

						dd = randy % (l - d + 1);
						for (int x = 1; x <= dd; x++)
						{
							if (i + x < ores.size() && tiles[i + x][j - d].type != WATER && ores[i + x][j - d].type != COAL && ores[i + x][j - d].type != TEMP_COAL && ores[i + x][j - d].type != IRON)
							{
								ores[i + x][j - d].type = TEMP_IRON;
								tiles[i + x][j - d].type = DIRT;
							}
						}
					}
				}
			}
		}
	}
}

/*Changes TEMP_ORE Types to ORE Types: Must be used AFTER the oreAlGore function*/
void Generation::revampOre(vector < vector <Ore> > &ores)
{
	for (int i = 0; i < ores.size(); i++) //Changes the temp slots into their designated tile type
	{
		for (int j = 0; j < ores[i].size(); j++)
		{
			if (ores[i][j].type == TEMP_COAL)
			{
				ores[i][j].type == COAL;
			}
			if (ores[i][j].type == TEMP_IRON)
			{
				ores[i][j].type == IRON;
			}
		}
	}
}

/* //how it shouldcouldwould look like
int main()
{
	Tile til;
	Ore oreo; 
	int xAxis;
	int yAxis

	vector < vector <Tiles> > tiles = createOreGrid(xAxis, yAxis, til);
	vector < vector <Ore> > ores = createOreGrid(xAxis, yAxis, oreo);
	lakeAlGore(tiles);
	oreAlGore(ores);
	revampOre(ores);

	return 0;
}
*/

