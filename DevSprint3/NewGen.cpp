// generate.cpp : Defines the entry point for the console application.
/*************************
TODO
- Look through the lakeAlGore. It spawned a WATER tile in the top left and did NOT spawn a WATER tile
to to the right or below even though there is supposed to be a 100% chance of that happening		(Proof in the screenshot lakeAlGore_is_not_working.png
- Look through both lakeAlGore and oreAlGore. It SEEEEMS like the ore is spawning above the water,
or the water is spawning below the ore. Most likely the former.
- There is a small chance of a bug. Not entirely sure where the issue is, or if it is even in the
generate.cpp code, but it is worth looking into.
- Change the tile under the ore. It should change it to DIRT (Talk to Dustin about that)
- EDIT THY NUMBERS! The map looks like shit because the RNG values are out of whack yo.
Look at the water, definitely look at the Ores, and maybe get rid of the DIRT spawn
- The problem with the oversized ore is in the oreAlGore, not neccessarily in the setOreGrid

**************************/

//Switch WATER and ORE algorithms
#include "NewGen.h"

using namespace std;
// Just a warning, the vectors spawn in a [x][y] format as opposed to the traditional [y][x] format :crying_emoji:


/*creates the initial grid using the starting variables. This may not be neccessary since we have the chunks*/

vector < vector<Tile> > NewGen::initTerrain(vector < vector <Tile> > tiles, Tile::Types type)
{
	for (int i = 0; i < chunkSize; i++) //grid[this][][] 
	{

		for (int j = 0; j < chunkSize; j++) //grid[][this][]
		{
			tiles[i][j].setType(type);
		}
	}

	return tiles;
}
vector < vector<Tile> > NewGen::initOre(vector < vector <Tile> > ores, Tile::Types type)
{
	for (int i = 0; i < chunkSize; i++) //grid[this][][] 
	{

		for (int j = 0; j < chunkSize; j++) //grid[][this][]
		{
			ores[i][j].setType(type);
		}
	}

	return ores;
}

vector < vector <Tile> > NewGen::setTileGrid(vector < vector <Tile> > tiles, Tile::Types type)
{
	for (int i = 0; i < chunkSize; i++) //grid[this][][] 
	{

		for (int j = 0; j < chunkSize; j++) //grid[][this][]
		{
			int randy = rand() % 40; //creates the GRASS, DIRT and WATER tiles randomly

			if (randy == 4)
			{
				tiles[i][j].setType(type);
			}
		}
	}

	return tiles;
}

/*Creates a 2D vector*/
vector < vector<Tile> > NewGen::setOreGrid(vector < vector<Tile> > ores, vector < vector<Tile> > &tiles, Tile::Types ore1, Tile::Types ore2, Tile::Types aqua)
{
	int firstore1 = 1;
	int firstore2 = 1;
	for (int i = 0; i < chunkSize / 2; i++) //grid[this][]
	{
		for (int j = 0; j < chunkSize / 2; j++) //grid[][this]
		{
			if (tiles[i][j].getType() != aqua)
			{
				int randy = rand() % 150;
				if (randy == 0 && firstore1 == 1) //1 out of X chance for COAL
				{
					ores[i][j].setType(ore1);
					//tiles[i][j].setType(Tile::DIRT);
					firstore1 = 0;
				}
				else if (randy == 1 && firstore2 == 1) //1 out of X chance for IRON
				{
					ores[i][j].setType(ore2);
					//tiles[i][j].setType(Tile::DIRT);
					firstore2 = 0;
				}
			}
		}
	}
	return ores;
}

void NewGen::resetChance(int baseChance)
{
	chance = baseChance;
}

void NewGen::spreadOre(vector < vector <Tile> > &ores, vector < vector <Tile> > &tiles, Tile::Types ore, int i, int j, int baseChance)
{
	int chance = baseChance;
	randy = rand() % chance;
	int bl = baseChance / 4; //25% to either spawn right or down and 1/4 chancer
	int bll = baseChance / 2; //50% to spawn both right and down and 2/4 chancer
	int blll = baseChance * 3 / 4; // 3/4 chancer

	if (randy < bl && i != chunkSize - 1 && tiles[i + 1][j].type != Tile::WATER && tiles[i + 1][j].type != Tile::QUICK)
	{
		ores[i + 1][j].type = ore; //% chance of making the lower tile a lake. also allows for another Lake roll
		//tiles[i + 1][j].type = Tile::DIRT;
		chance++; //decreases the % chance of increasing the Lake size

	}
	else if (randy < bl && i == chunkSize - 1 && tiles[i - 1][j].type != Tile::WATER && tiles[i - 1][j].type != Tile::QUICK) //if we're already at the bottom, then we can't just make one below it
	{
		if (j == tiles.size() - 1) //if we are at the very very bottom-right corner of the world.
		{
			chance = baseChance;
		}
		else
		{
			ores[i - 1][j].type = ore; //small chance of adding another Lake tile above the current Lake tile (chances are, there is already one there)
			//tiles[i - 1][j].type = Tile::DIRT;
		}
	}
	else if (randy < bll && j != chunkSize - 1 && tiles[i][j + 1].type != Tile::WATER && tiles[i][j + 1].type != Tile::QUICK)
	{
		ores[i][j + 1].type = ore; //% chance of making the right tile a lake. also allows for another Lake roll
		//tiles[i][j + 1].type = Tile::DIRT;
		chance++; //decreases the % chance of increasing the Lake size
	}
	else if (randy < bll && j == chunkSize - 1 && tiles[i][j - 1].type != Tile::WATER && tiles[i][j - 1].type != Tile::QUICK)
	{
		if (i == tiles.size() - 1)
		{
			chance = baseChance;
		}
		else
		{
			ores[i][j - 1].type = ore; //small chance of adding a Lake tile to the left. chances are, there is already a Lake tile there.
			//tiles[i][j - 1].type = Tile::DIRT;
		}
	}
	else if (randy < blll && i > 0)
	{
		if (ores[i - 1][j].type == ore && i != chunkSize - 1 && tiles[i + 1][j].type != Tile::WATER && tiles[i + 1][j].type != Tile::QUICK)
		{
			ores[i + 1][j].type = ore; //% chance of making the lower tile a lake. also allows for another Lake roll
			//tiles[i + 1][j].type = Tile::DIRT;
			chance++;
		}
		else if (tiles[i - 1][j].type != Tile::WATER && tiles[i - 1][j].type != Tile::QUICK)
		{
			ores[i - 1][j].type = ore; //% chance of making the upper tile a Lake as well
			//tiles[i - 1][j].type = Tile::DIRT;
			chance++;
		}
	}
	else if (randy < baseChance && j > 0)
	{
		if (ores[i][j - 1].type == ore && j != chunkSize - 1 && tiles[i][j + 1].type != Tile::WATER && tiles[i][j + 1].type != Tile::QUICK)
		{
			ores[i][j + 1].type = ore; //% chance of making the lower tile a lake. also allows for another Lake roll
			//tiles[i][j + 1].type = Tile::DIRT;
			chance++;
		}
		else if (tiles[i][j - 1].type != Tile::WATER && tiles[i][j - 1].type != Tile::QUICK)
		{
			ores[i][j - 1].type = ore; //% chance of making the left tile a Lake as well
			//tiles[i][j - 1].type = Tile::DIRT;
			chance++;
		}
	}
	else
	{
		if (i != chunkSize - 1 && j != chunkSize - 1 && (ores[i + 1][j].type == ore || ores[i][j + 1].type == ore)) //Check this
		{
			chance = baseChance; //returns the Lake change for the first time.
		}
	}
}
/*Edits the Tiles vector(s) to turn the random water tiles into lakes*/ //Might use this to switch Ore and Lake algorithm
vector < vector<Tile> > NewGen::newOreAlGore(vector < vector <Tile> > &ores, vector < vector <Tile> > &tiles, Tile::Types ore1, Tile::Types ore2, int baseChance) //revamped lake algorithm to work with ores instead of water
{
	int chance = baseChance; //% chance of making a new lake. It increases as the lake size increases
	int bl = baseChance / 4; //25% to either spawn right or down and 1/4 chancer
	int bll = baseChance / 2; //50% to spawn both right and down and 2/4 chancer
	int blll = baseChance * 3 / 4; // 3/4 chancer
	int firstLake = 1;
	Tile::Types thisOre;

	for (int i = 0; i < chunkSize; i++)
	{
		for (int j = 0; j < chunkSize; j++)
		{
			if (ores[i][j].type == ore1 || ores[i][j].type == ore2) 
			{
				randy = rand() % chance; //obtain the random number
				thisOre = ores[i][j].getType();

				if (chance == baseChance && firstLake == 1) //if the WATER tile we hit the very first
				{
					//25% chance the first Lake tile will spread downward, leading to another check with 100% spread chance.
					//Cannot happen if already at the bottom, otherwise we get an error for placing an 'L' outside of the grid
					if (randy < bl && i != chunkSize - 1 && tiles[i + 1][j].type != Tile::WATER && tiles[i + 1][j].type != Tile::QUICK) //bl = 3
					{
						ores[i + 1][j].type = thisOre;
						//tiles[i + 1][j].type = Tile::DIRT;
						firstLake = 0; //may or may not require more rigging. The house must always win!!
					}
					//25% chance the first Lake tile will spread rightward, leading to another check with 100% spread chance
					//Cannot happen if already at the right edge, otherwise we get an error for placing an 'L' outside of the grid
					else if (randy < bll && j != chunkSize - 1 && tiles[i][j + 1].type != Tile::WATER && tiles[i][j + 1].type != Tile::QUICK) //bll = 6
					{
						ores[i][j + 1].type = thisOre;
						//tiles[i][j + 1].type = Tile::DIRT;
						firstLake = 0;
					}
					//50% chance the first Lake tile will spread downward, leading to another check with 100% spread chance
					//HOWEVER we might be at the edge, which causes many issues, we will rig it a bit more with THREE OPTIONS
					else if (randy >= bll && i != chunkSize - 1 && j == chunkSize - 1 && tiles[i + 1][j].type != Tile::WATER && tiles[i + 1][j].type != Tile::QUICK) //if we're not at the bottom, but at the right, then we only change the lower tile
					{
						ores[i + 1][j].type = thisOre;
						//tiles[i + 1][j].type = Tile::DIRT;
						firstLake = 0;
					}
					else if (randy >= bll && i == chunkSize - 1 && j != chunkSize - 1 && tiles[i][j + 1].type != Tile::WATER && tiles[i][j + 1].type != Tile::QUICK) //if we're not at the right but at the bottom, then we only change the right
					{
						ores[i][j + 1].type = thisOre;
						//tiles[i][j + 1].type = Tile::DIRT;
						firstLake = 0;
					}
					else if (randy >= bll && i != chunkSize - 1 && j != chunkSize - 1) //If we are NOT at the bottom and not the right, then we change both
					{
						if (tiles[i + 1][j].type != Tile::WATER && tiles[i + 1][j].type != Tile::QUICK)
						{
							ores[i + 1][j].type = thisOre;
							//tiles[i + 1][j].type = Tile::DIRT;
						}
						if (tiles[i][j + 1].type != Tile::WATER && tiles[i][j + 1].type != Tile::QUICK)
						{
							ores[i][j + 1].type = thisOre;
							//tiles[i][j + 1].type = Tile::DIRT;
						}
						
						firstLake = 0;
					}
					else
					{
						//std::cout << randy << "OOOOPS THIS SHOULD NOT HAPPEN DUDE!!!"; //DEBUG
						firstLake = 0;
					}
				}

				//Now if we find us a WATER tile and it isn't the first one we found, then we go on with a normal algorithm 
				else
				{
					spreadOre(ores, tiles, thisOre, i, j, baseChance);
				}
			}
		}
	}
	return ores;
}

vector < vector<Tile> > NewGen::newLakeAlGore(vector < vector <Tile> > &ores, vector < vector <Tile> > &tiles, Tile::Types aqua, Tile::Types temp, int lakeReach)
{
	for (int i = 0; i < chunkSize; i++) //This tries to expand the ores
	{
		for (int j = 0; j < chunkSize; j++)
		{
			if (tiles[i][j].type == aqua)
			{
				up = rand() % lakeReach + 1;
				dwn = rand() % lakeReach + 1;
				l = rand() % lakeReach + 1;
				r = rand() % lakeReach + 1;

				for (int a = 1; a < up + 1; a++) //for all the UPPER tiles. use same loop for the left, right, and lower rows
				{
					if (i - a >= 0 && ores[i - a][j].type != Tile::IRON && ores[i - a][j].type != Tile::COAL)
					{
						tiles[i - a][j].type = temp; //Makes a temperary COAL tile. This way, we can expand the coal without causing any massive issues
																 //tiles[i - a][j].type = Tile::DIRT;

						ll = rand() % (up - a + 1); //'leftLeft' is a random chance between 0 and (upper limit - #ofLoop) Further description in Notes
						for (int x = 1; x <= ll; x++)
						{
							if (j - x >= 0 && ores[i - a][j - x].type != Tile::IRON && ores[i - a][j - x].type != Tile::COAL)
							{
								tiles[i - a][j - x].type = temp;
								//cout << i-a + " " + j-x << endl; //debug
								//tiles[i - a][j - x].type = Tile::DIRT;
							}

						}
						rr = rand() % (up - a + 1); //repeat for the other
						for (int x = 1; x <= rr; x++)
						{
							if (j + x < chunkSize && ores[i - a][j + x].type != Tile::IRON && ores[i - a][j + x].type != Tile::COAL)
							{
								tiles[i - a][j + x].type = temp;
								//tiles[i - a][j + x].type = Tile::DIRT;
							}
						}
					}
				}

				for (int b = 1; b < r + 1; b++) //RIGHT
				{
					if (j + b < chunkSize && ores[i][j + b].type != Tile::IRON && ores[i][j + b].type != Tile::COAL)
					{
						tiles[i][j + b].type = temp;
						//tiles[i][j + b].type = Tile::DIRT;

						uu = rand() % (r - b + 1);
						for (int x = 1; x <= uu; x++)
						{
							if (i - x >= 0 && ores[i - x][j + b].type != Tile::IRON && ores[i - x][j + b].type != Tile::COAL)
							{
								tiles[i - x][j + b].type = temp;
								//tiles[i - x][j + b].type = Tile::DIRT;
							}
						}
						dd = rand() % (r - b + 1);
						for (int x = 1; x <= dd; x++)
						{
							if (i + x < chunkSize && ores[i + x][j + b].type != Tile::IRON && ores[i + x][j + b].type != Tile::COAL)
							{
								tiles[i + x][j + b].type = temp;
								//tiles[i + x][j + b].type = Tile::DIRT;
							}
						}

					}
				}

				for (int c = 1; c < dwn + 1; c++) //LOWER
				{
					if (i + c < chunkSize && ores[i + c][j].type != Tile::IRON && ores[i + c][j].type != Tile::COAL)
					{
						tiles[i + c][j].type = temp;
						//tiles[i + c][j].type = Tile::DIRT;

						ll = rand() % (dwn - c + 1);
						for (int x = 1; x <= ll; x++)
						{
							if (j - x >= 0 && ores[i + c][j - x].type != Tile::IRON && ores[i + c][j - x].type != Tile::COAL)
							{
								tiles[i + c][j - x].type = temp;
								//tiles[i + c][j - x].type = Tile::DIRT;
							}
						}
						rr = rand() % (dwn - c + 1);
						for (int x = 1; x <= rr; x++)
						{
							if (j + x < chunkSize && ores[i + c][j + x].type != Tile::IRON && ores[i + c][j + x].type != Tile::COAL)
							{
								tiles[i + c][j + x].type = temp;
								//tiles[i + c][j + x].type = Tile::DIRT;
							}
						}
					}
				}

				for (int d = 1; d < l + 1; d++) //LEFT
				{
					if (j - d >= 0 && ores[i][j - d].type != Tile::IRON && ores[i][j - d].type != Tile::COAL)
					{
						tiles[i][j - d].type = temp;
						//tiles[i][j - d].type = Tile::DIRT; //NEED

						uu = rand() % (l - d + 1);
						for (int x = 1; x <= uu; x++)
						{
							if (i - x >= 0 && ores[i - x][j - d].type != Tile::IRON && ores[i - x][j - d].type != Tile::COAL)
							{
								tiles[i - x][j - d].type = temp;
								//tiles[i - x][j - d].type = Tile::DIRT;
							}
						}
						dd = rand() % (l - d + 1);
						for (int x = 1; x <= dd; x++)
						{
							if (i + x < chunkSize && ores[i + x][j - d].type != Tile::IRON && ores[i + x][j - d].type != Tile::COAL)
							{
								tiles[i + x][j - d].type = temp;
								//tiles[i + x][j - d].type = Tile::DIRT;
							}
						}
					}
				}

			}
		}
	}
	return tiles;
}


vector < vector <Tile> > NewGen::revamp(vector < vector <Tile> > tiles, Tile::Types temp, Tile::Types newTile)
{
	for (int i = 0; i < chunkSize; i++) //Changes the temp slots into their designated tile type
	{
		for (int j = 0; j < chunkSize; j++)
		{
			if (tiles[i][j].getType() == temp)
			{
				tiles[i][j].setType(newTile);
			}
		}
	}
	return tiles;
}
