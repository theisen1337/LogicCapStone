// generate.cpp : Defines the entry point for the console application.
///


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
vector < vector <Tile> > Generation::setTileGrid(vector < vector <Tile> > tile)
{
	for (int i = 0; i < chunkSize; i++) //grid[this][][] 
	{

		for (int j = 0; j < chunkSize; j++) //grid[][this][]
		{
			int randy = rand() % 13; //creates the GRASS, DIRT and WATER tiles randomly
			if (randy < 3) //3 out of 13 chance for DIRT
			{
				tile[i][j].setType(Tile::DIRT);
			}
			else if (randy == 4) //1 out of 13 chacne for WATER
			{
				tile[i][j].setType(Tile::WATER);
			}
			//til.setChunkX(j); //This is the X axis. [y][x] because matrix logic
			//til.setChunkY(i); //may rework the chunky cheeses here depending on how the chunks are meant to work

		}
	}
	return tile;
}

/*Creates a 2D vector*/
vector < vector<Tile> > Generation::setOreGrid(vector < vector<Tile> > oreo, vector < vector<Tile> > tiles)
{
	
	for (int i = 0; i < chunkSize; i++) //grid[this][][]
	{
		for (int j = 0; j < chunkSize; j++) //grid[][this][]
		{
			if (tiles[i][j].getType() != Tile::WATER) 
			{
				int randy = rand() % 15;
				if (randy == 0) //1 out of 15 chance for COAL
				{
					oreo[i][j].setType(Tile::COAL);
				}
				else if (randy == 1) //1 out of 15 chance for IRON
				{
					oreo[i][j].setType(Tile::IRON);
				}
			}
		}
	}
	return oreo;
}

/*The showTiles function will probably not be used and will instead rely on the TileMap class*/
void Generation::showTiles(vector < vector <Tile> > tiles)
{
	for (int i = 0; i < chunkSize; i++)
	{
		for (int j = 0; j < chunkSize; j++)
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
vector < vector <Tile> > Generation::lakeAlGore(vector < vector <Tile> > tiles) //edits the tile
{
	int randy; //for random number generation
	int chance = 4; //% chance of making a new lake. It increases as the lake size increases
	int firstLake = 1;
	for (int i = 0; i < chunkSize; i++)
	{
		for (int j = 0; j < chunkSize; j++)
		{

			if (tiles[i][j].type == Tile::WATER) //checks to see if we have a WATER tile
			{
				randy = rand() % chance; //obtain the random number

				if (chance == 4 && firstLake == 1) //if the WATER tile we hit the very first
				{
					//25% chance the first Lake tile will spread downward, leading to another check with 100% spread chance.
					//Cannot happen if already at the bottom, otherwise we get an error for placing an 'L' outside of the grid
					if (randy == 0 && i != chunkSize - 1)
					{
						tiles[i + 1][j].type = Tile::WATER;
						firstLake = 0; //may or may not require more rigging. The house must always win!!
					}
					//25% chance the first Lake tile will spread rightward, leading to another check with 100% spread chance
					//Cannot happen if already at the right edge, otherwise we get an error for placing an 'L' outside of the grid
					else if (randy == 1 && j != chunkSize - 1)
					{
						tiles[i][j + 1].type = Tile::WATER;
						firstLake = 0;
					}
					//50% chance the first Lake tile will spread downward, leading to another check with 100% spread chance
					//HOWEVER we might be at the edge, which causes many issues, we will rig it a bit more with THREE OPTIONS
					else if (randy > 1 && i != chunkSize - 1 && j == chunkSize - 1) //if we're not at the bottom, but at the right, then we only change the lower tile
					{
						tiles[i + 1][j].type = Tile::WATER;
						firstLake = 0;
					}
					else if (randy > 1 && i == chunkSize - 1 && j != chunkSize - 1) //if we're not at the right but at the bottom, then we only change the right
					{
						tiles[i][j + 1].type = Tile::WATER;
						firstLake = 0;
					}
					else if (randy > 1 && i != chunkSize - 1 && j != chunkSize - 1) //If we are NOT at the bottom and not the right, then we change both
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
					if (randy == 0 && i != chunkSize - 1)
					{
						tiles[i + 1][j].type = Tile::WATER; //% chance of making the lower tile a lake. also allows for another Lake roll
						chance++; //decreases the % chance of increasing the Lake size

					}
					else if (randy == 0 && i == chunkSize - 1) //if we're already at the bottom, then we can't just make one below it
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
					else if (randy == 1 && j != chunkSize - 1)
					{
						tiles[i][j + 1].type = Tile::WATER; //% chance of making the right tile a lake. also allows for another Lake roll
						chance++; //decreases the % chance of increasing the Lake size
					}
					else if (randy == 1 && j == chunkSize - 1)
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
						if (tiles[i - 1][j].type == Tile::WATER && i != chunkSize - 1)
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
						if (tiles[i][j - 1].type == Tile::WATER && j != chunkSize - 1)
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
						if ((i != chunkSize - 1 && j != chunkSize - 1) && (tiles[i + 1][j].type == Tile::WATER || tiles[i][j + 1].type == Tile::WATER))
						{
							chance = 4; //returns the Lake change for the first time.
							firstLake = 1;
						}
					}
				}
			}
		}
	}
	return tiles;
}

/*Edits ore tiles to look like globs of ore*/
vector < vector <Tile> > Generation::oreAlGore(vector < vector <Tile> > ores, vector < vector <Tile> > tiles)
{
	int up, dwn, l, r, uu, dd, ll, rr; //four different points
	for (int i = 0; i < chunkSize; i++) //This tries to expand the ores
	{
		for (int j = 0; j < chunkSize; j++)
		{
			//chacne = x; Not needed yet. Used for later Sprint for editting spawn chances, expanding chances, etc etc.
			//randy = rand() % chance; // Need for later

			if (ores[i][j].type == Tile::COAL)
			{
				up = rand() % 3 + 1;
				dwn = rand() % 3 + 1;
				l = rand() % 3 + 1;
				r = rand() % 3 + 1;

				for (int a = 1; a < up + 1; a++) //for all the UPPER tiles. use same loop for the left, right, and lower rows
				{
					if (i - a >= 0 && tiles[i - a][j].type != Tile::WATER && ores[i - a][j].type != Tile::COAL)
					{
						ores[i - a][j].type = Tile::TEMP_COAL; //Makes a temperary COAL tile. This way, we can expand the coal without causing any massive issues
						tiles[i - a][j].type = Tile::DIRT;

						ll = rand() % (up - a + 1); //'leftLeft' is a random chance between 0 and (upper limit - #ofLoop) Further description in Notes
						for (int x = 1; x <= ll; x++)
						{
							if (j - x >= 0 && tiles[i - a][j - x].type != Tile::WATER && ores[i - a][j - x].type != Tile::COAL)
							{
								ores[i - a][j - x].type = Tile::TEMP_COAL;
								tiles[i - a][j - x].type = Tile::DIRT;
							}
						}
						rr = rand() % (up - a + 1); //repeat for the other
						for (int x = 1; x <= rr; x++)
						{
							if (j + x < chunkSize && tiles[i - a][j + x].type != Tile::WATER && ores[i - a][j + x].type != Tile::COAL)
							{
								ores[i - a][j + x].type = Tile::TEMP_COAL;
								tiles[i - a][j + x].type = Tile::DIRT;
							}
						}
					}
				}

				for (int b = 1; b < r + 1; b++) //RIGHT
				{
					if (j + b < chunkSize && tiles[i][j + b].type != Tile::WATER && ores[i][j + b].type != Tile::COAL)
					{
						ores[i][j + b].type = Tile::TEMP_COAL;
						tiles[i][j + b].type = Tile::DIRT;

						uu = rand() % (r - b + 1);
						for (int x = 1; x <= uu; x++)
						{
							if (i - x >= 0 && tiles[i - x][j + b].type != Tile::WATER && ores[i - x][j + b].type != Tile::COAL)
							{
								ores[i - x][j + b].type = Tile::TEMP_COAL;
								tiles[i - x][j + b].type = Tile::DIRT;
							}
						}
						dd = rand() % (r - b + 1);
						for (int x = 1; x <= dd; x++)
						{
							if (i + x < chunkSize && tiles[i + x][j + b].type != Tile::WATER && ores[i + x][j + b].type != Tile::COAL)
							{
								ores[i + x][j + b].type = Tile::TEMP_COAL;
								tiles[i + x][j + b].type = Tile::DIRT;
							}
						}

					}
				}

				for (int c = 1; c < dwn + 1; c++) //LOWER
				{
					if (i + c < chunkSize && tiles[i + c][j].type != Tile::WATER && ores[i + c][j].type != Tile::COAL)
					{
						ores[i + c][j].type = Tile::TEMP_COAL;
						tiles[i + c][j].type = Tile::DIRT; //NEED

						ll = rand() % (dwn - c + 1);
						for (int x = 1; x <= ll; x++)
						{
							if (j - x >= 0 && tiles[i + c][j - x].type != Tile::WATER && ores[i + c][j - x].type != Tile::COAL)
							{
								ores[i + c][j - x].type = Tile::TEMP_COAL;
								tiles[i + c][j - x].type = Tile::DIRT;
							}
						}
						rr = rand() % (dwn - c + 1);
						for (int x = 1; x <= rr; x++)
						{
							if (j + x < chunkSize && tiles[i + c][j + x].type != Tile::WATER && ores[i + c][j + x].type != Tile::COAL)
							{
								ores[i + c][j + x].type = Tile::TEMP_COAL;
								tiles[i + c][j + x].type = Tile::DIRT;
							}
						}
					}
				}

				for (int d = 1; d < l + 1; d++) //LEFT
				{
					if (j - d >= 0 && tiles[i][j - d].type != Tile::WATER && ores[i][j - d].type != Tile::COAL)
					{
						ores[i][j - d].type = Tile::TEMP_COAL;
						tiles[i][j - d].type = Tile::DIRT; //NEED

						uu = rand() % (l - d + 1);
						for (int x = 1; x <= uu; x++)
						{
							if (i - x >= 0 && tiles[i - x][j - d].type != Tile::WATER && ores[i - x][j - d].type != Tile::COAL)
							{
								ores[i - x][j - d].type = Tile::TEMP_COAL;
								tiles[i - x][j - d].type = Tile::DIRT;
							}
						}
						dd = rand() % (l - d + 1);
						for (int x = 1; x <= dd; x++)
						{
							if (i + x < chunkSize && tiles[i + x][j - d].type != Tile::WATER && ores[i + x][j - d].type != Tile::COAL)
							{
								ores[i + x][j - d].type = Tile::TEMP_COAL;
								tiles[i + x][j - d].type = Tile::DIRT;
							}
						}
					}
				}

			}

			if (ores[i][j].getType() == Tile::IRON)
			{
				up = rand() % 3 + 1;
				dwn = rand() % 3 + 1;
				l = rand() % 3 + 1;
				r = rand() % 3 + 1;

				for (int a = 1; a < up + 1; a++) //for all the UPPER tiles. use same loop for the left, right, and lower rows
				{
					if (i - a >= 0 && tiles[i - a][j].type != Tile::WATER && ores[i - a][j].type != Tile::COAL && ores[i - a][j].type != Tile::TEMP_COAL && ores[i - a][j].type != Tile::IRON)
					{
						ores[i - a][j].type = Tile::TEMP_IRON; //make it a small c as a temp
						tiles[i - a][j].type = Tile::DIRT; //NEED

						ll = rand() % (up - a + 1); //leftLeft is a random chance between 0 and (upper limit - #ofLoop) Further description in Notes
						for (int x = 1; x <= ll; x++)
						{
							if (j - x >= 0 && tiles[i - a][j - x].type != Tile::WATER && ores[i - a][j - x].type != Tile::COAL && ores[i - a][j - x].type != Tile::TEMP_COAL && ores[i - a][j - x].type != Tile::IRON)
							{
								ores[i - a][j - x].type = Tile::TEMP_IRON;
								tiles[i - a][j - x].type = Tile::DIRT;
							}
						}
						rr = rand() % (up - a + 1); //repeat for the other
						for (int x = 1; x <= rr; x++)
						{
							if (j + x < chunkSize && tiles[i - a][j + x].type != Tile::WATER && ores[i - a][j + x].type != Tile::COAL && ores[i - a][j + x].type != Tile::TEMP_COAL && ores[i - a][j + x].type != Tile::IRON)
							{
								ores[i - a][j + x].type = Tile::TEMP_IRON;
								tiles[i - a][j + x].type = Tile::DIRT;
							}
						}
					}
				}

				for (int b = 1; b < r + 1; b++) //RIGHT
				{
					if (j + b < chunkSize && tiles[i][j + b].type != Tile::WATER && ores[i][j + b].type != Tile::COAL && ores[i][j + b].type != Tile::TEMP_COAL && ores[i][j + b].type != Tile::IRON)
					{
						ores[i][j + b].type = Tile::TEMP_IRON;
						tiles[i][j + b].type = Tile::DIRT; //NEED

						uu = rand() % (r - b + 1);
						for (int x = 1; x <= uu; x++)
						{
							if (i - x >= 0 && tiles[i - x][j + b].type != Tile::WATER && ores[i - x][j + b].type != Tile::COAL && ores[i - x][j + b].type != Tile::TEMP_COAL && ores[i - x][j + b].type != Tile::IRON)
							{
								ores[i - x][j + b].type = Tile::TEMP_IRON;
								tiles[i - x][j + b].type = Tile::DIRT;
							}
						}
						dd = rand() % (r - b + 1);
						for (int x = 1; x <= dd; x++)
						{
							if (i + x < chunkSize && tiles[i + x][j + b].type != Tile::WATER && ores[i + x][j + b].type != Tile::COAL && ores[i + x][j + b].type != Tile::TEMP_COAL && ores[i + x][j + b].type != Tile::IRON)
							{
								ores[i + x][j + b].type = Tile::TEMP_IRON;
								tiles[i + x][j + b].type = Tile::DIRT;
							}
						}
					}
				}

				for (int c = 1; c < dwn + 1; c++) //LOWER
				{
					if (i + c < chunkSize && tiles[i + c][j].type != Tile::WATER && ores[i + c][j].type != Tile::COAL && ores[i + c][j].type != Tile::TEMP_COAL && ores[i + c][j].type != Tile::IRON)
					{
						ores[i + c][j].type = Tile::TEMP_IRON;
						tiles[i + c][j].type = Tile::DIRT; //NEED

						ll = rand() % (dwn - c + 1);
						for (int x = 1; x <= ll; x++)
						{
							if (j - x >= 0 && tiles[i + c][j - x].type != Tile::WATER && ores[i + c][j - x].type != Tile::COAL && ores[i + c][j - x].type != Tile::TEMP_COAL && ores[i + c][j - x].type != Tile::IRON)
							{
								ores[i + c][j - x].type = Tile::TEMP_IRON;
								tiles[i + c][j - x].type = Tile::DIRT;
							}
						}
						rr = rand() % (dwn - c + 1);
						for (int x = 1; x <= rr; x++)
						{
							if (j + x < chunkSize && tiles[i + c][j + x].type != Tile::WATER && ores[i + c][j + x].type != Tile::COAL && ores[i + c][j + x].type != Tile::TEMP_COAL && ores[i + c][j + x].type != Tile::IRON)
							{
								ores[i + c][j + x].type = Tile::TEMP_IRON;
								tiles[i + c][j + x].type = Tile::DIRT;
							}
						}
					}
				}

				for (int d = 1; d < l + 1; d++) //LEFT
				{
					if (j - d >= 0 && tiles[i][j - d].type != Tile::WATER && ores[i][j - d].type != Tile::COAL && ores[i][j - d].type != Tile::TEMP_COAL && ores[i][j - d].type != Tile::IRON)
					{
						ores[i][j - d].type = Tile::TEMP_IRON;
						tiles[i][j - d].type = Tile::DIRT; //NEED

						uu = rand() % (l - d + 1);
						for (int x = 1; x <= uu; x++)
						{
							if (i - x >= 0 && tiles[i - x][j - d].type != Tile::WATER && ores[i - x][j - d].type != Tile::COAL && ores[i - x][j - d].type != Tile::TEMP_COAL && ores[i - x][j - d].type != Tile::IRON)
							{
								ores[i - x][j - d].type = Tile::TEMP_IRON;
								tiles[i - x][j - d].type = Tile::DIRT;
							}
						}

						dd = rand() % (l - d + 1);
						for (int x = 1; x <= dd; x++)
						{
							if (i + x < chunkSize && tiles[i + x][j - d].type != Tile::WATER && ores[i + x][j - d].type != Tile::COAL && ores[i + x][j - d].type != Tile::TEMP_COAL && ores[i + x][j - d].type != Tile::IRON)
							{
								ores[i + x][j - d].type = Tile::TEMP_IRON;
								tiles[i + x][j - d].type = Tile::DIRT;
							}
						}
					}
				}
			}
		}
	}
	return ores;
}

/*Changes TEMP_ORE Types to ORE Types: Must be used AFTER the oreAlGore function*/
vector < vector <Tile> > Generation::revampOre(vector < vector <Tile> > ores)
{
	for (int i = 0; i < chunkSize; i++) //Changes the temp slots into their designated tile type
	{
		for (int j = 0; j < chunkSize; j++)
		{
			if (ores[i][j].getType() == Tile::TEMP_COAL)
			{
				ores[i][j].setType(Tile::COAL);
			}
			if (ores[i][j].getType() == Tile::TEMP_IRON)
			{
				ores[i][j].setType(Tile::IRON);
			}
		}
	}
	return ores;
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

