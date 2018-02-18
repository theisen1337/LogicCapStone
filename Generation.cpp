#include "Generation.h"

/*
Author's Notes
- The Algorithm is still being fixed up.
- The lines of code that are followed by a '//DEBUG' are used for, you guessed it, debugging. The usually show the RNG values or out of place phrases.
- Any suggestion will be super-duper. Make a comment next to the line or function with an  all-caps 'SUGGEST' or 'SUG' so it's easy to find
- If your suggestion or "constructive criticisms" are more broad or about the entire prototype itself, then place them in the 'SUGGESTIONS' box below
- Many of the variables are RIGGED. Search for RIGGED if you want to change them
- Codeblock's has a crappy RNG so I didn't bother with it refining the RNG and instead tested with rigged numbers.
- Known Bugs: For some odd reason, things go badly when the size exceeds 39x39
*/

/*
SUGGESTIONS
-
*/

/*
TODO Tile Generation
- Find/Use an algorithm that makes the generation look more clean
- Place more grass/dirt tiles than other tile types. Make the entire area traversable. Water should by in shapes of lakes or rivers.
- The lakes could work the same way as the Ore; place a single random water tile, then check to see if the other tiles will have water
- Rivers could be made in a different way.
*/

/*
TODO Ore Generation
- Check if there is a proper place to put the Ore (ex. no underwater coal expeditions)
- Make a few Ores generate on the map. The size of said ore will be made by checking
the adjacent tiles to see if coal is next to it and may or may not create more
via the will of RNG
-
*/

/*
TODO Tile Generation
- Find/Use an algorithm that makes the generation look more clean
- Place more grass/dirt tiles than other tile types. Make the entire area traversable. Water should by in shapes of lakes or rivers.
- The lakes could work the same way as the Ore; place a single random water tile, then check to see if the other tiles will have water
- Rivers could be made in a different way.
*/

/*
TODO Ore Generation
- Check if there is a proper place to put the Ore (ex. no underwater coal expeditions)
- Make a few Ores generate on the map. The size of said ore will be made by checking
the adjacent tiles to see if coal is next to it and may or may not create more
via the will of RNG
-
*/

/*
TODO Implement everything into the main Allegro program.
- What could possibly go wrong?
- Add a new class or just edit the current ones
*/

/*
TODO Get a head start on expansion
- .push_back or .insert based on the length or height of the current table
- create a new 'chunk' or 'biome' when the player gets too close to the edge
- chunks or biomes can be based on a Climate class or variable which would dictate what kind of tiles and ores can be generated
*/



/*
vector < vector < vector<string> > > createGrid(int xAxis, int yAxis, int height) //creates the initial grid using the starting variables
{
	
	vector < vector < vector<string> > > grid;
	for (int i = 0; i < yAxis; i++) //grid[this][][]
	{
		vector < vector<string> > grid0;
		grid.push_back(grid0);
		for (int j = 0; j < xAxis; j++) //grid[][this][]
		{
			vector<string> grid1;
			grid[i].push_back(grid1);
			for (int k = 0; k < height; k++) //grid[][][this]
			{
				//int lolSoRandom = rand() % 5;
				//string setTile = tile[lolSoRandom];
				grid[i][j].push_back("Q"); //none shall be 'Q' at the end. Just a placeholder as well as a debugger
			}
		}
	}
	return grid;
}

void showTiles(vector < vector < vector<string> > > tiles) //shows the bottom set; the tiles
{
	for (int i = 0; i < tiles.size(); i++) //works
	{
		//cout << "huh"; //debugging, please ignore
		for (int j = 0; j < tiles[i].size(); j++) //fixed
		{
			//cout << "wut"; //debugging, ignore
			cout << tiles[i][j][0] << " "; //show the current tile but with a space to separate
		}
		cout << endl;
	}
}

void showOres(vector < vector < vector<string> > > ores) //shows the second lowest set; the ores
{
	for (int i = 0; i < ores.size(); i++) //works
	{
		//cout << "huh"; //debugging, please ignore
		for (int j = 0; j < ores[i].size(); j++) //fixed
		{
			//cout << "wut"; //debugging, ignore
			cout << ores[i][j][1] << " ";
		}
		cout << endl;
	}
}
*/


std::vector<std::vector<Tile>> Generation::setTiles(std::vector<std::vector<Tile>> &tiles) //
{
	aLen = 13;
	//int aLen = sizeof(tileLetter)/sizeof(tileLetter[0]); //USED LATER AFTER DEBUGGING IS DONE
	//std::cout << aLen << std::endl; //DEBUG
						  //int ranSize = aLen; //DEBUG
						  //cout << ranSize << endl; //DEBUG
						  //int rando = rand() % sizeof(tileLetter);
						  //int rando = rand() % aLen;
						  //cout << sizeof(tileLetter) << endl; //DEBUG
	int rando;
	for (int i = 0; i < chunkSize; i++)
	{
		for (int j = 0; j < chunkSize; j++)
		{
			//int rando = rand() % sizeof(tileLetter);
			//cout << aLen; //DEBUG
			//int test = aLen; //DEBUG
			//int rando = rand() % test;
			rando = rand() % aLen; //911 NEED THIS BUT BREAKS THE CODE!! Nevermind, it's actually in the Lake Algorithm below
									   //int rando = rand() % 10; //DEBUG
			//tiles[i][j].push_back(setTile);
			
			//#######################################
			//Added/Changes By Dustin
			//#######################################
				//Changed to use tile types and setType of tiles
			Tile::Types setTile = tile[rando];
			tiles[i][j].setType(setTile);
			//#######################################


			//cout << rando; //DEBUG
						   //cout << rando; //debugging
						   //cout << setTile;
						   //cout << tiles[i][j][0];
		}
	}
	//std::cout << std::endl << std::endl; //DEBUG
						  //This is rigging the system, just to see if this algorithm works
						  //tiles[0][7][0] = "L"; //RIGGED DEBUG //FOUND THE CULPRIT!!
						  //tiles[1][1][0] = "L"; //RIGGED DEBUG
						  //tiles[2][1][0] = "L"; //RIGGED DEBUG
						  //tiles[3][1][0] = "L"; //RIGGED DEBUG
						  //tiles[4][9][0] = "L"; //RIGGED DEBUG
						  //tiles[5][6][0] = "L"; //RIGGED DEBUG
						  //tiles[5][10][0] = "L"; //RIGGED DEBUG
						  //tiles[6][1][0] = "L"; //RIGGED DEBUG
						  //tiles[6][3][0] = "L"; //RIGGED DEBUG
						  //tiles[7][7][0] = "L"; //RIGGED DEBUG
						  //tiles[10][5][0] = "L"; //RIGGED DEBUG
	//std::cout << tiles.size() - 1 << std::endl; //DEBUG
	//std::cout << tiles[0].size() - 1 << std::endl; //DEBUG

										 //DEBUG STUFF
	/*#####Debug Stuff?#####
	for (int i = 0; i < tiles.size(); i++)
	{
		for (int j = 0; j < tiles[i].size(); j++)
		{
			if (tiles[i][j][0] == "L")
			{
				std::cout << "(" << i << "," << j << ")  ";
			}
		}
	}
	*/

	int randy; //for random number generation
	int chance = 4; //% chance of making a new lake. It increases as the lake size increases
	int firstLake = 1;
	/*Lake Algorithm*/
	for (int i = 0; i < chunkSize; i++)
	{
		for (int j = 0; j < chunkSize; j++)
		{
			if (tiles[i][j].getType() == Tile::WATER) //for expanding the Lakes
			{
				randy = rand() % chance; // NEED
				//std::cout << randy; //DEBUG
							   //randy = 1;//RIGGED DEBUG DELETE
							   //we're going to rig the system to make sure that the Lake does increase in the lower or right tiles,
							   //therefore making a lake that is at least

							   //if (chance == 3 && firstLake == 1) //DEBUG
							   //cout << randy; //DEBUG
							   //cout << "Q"; //DEBUG
							   //tiles[i][j][0] = "Q"; //so this works but not in loop? They taught us NOTHING!
							   //cout << tiles[i][j][0]; //DEBUG
							   //cout << firstLake; //DEBUG

				if (chance == 4 && firstLake == 1)
				{
					//25% chance the first Lake tile will spread downward, leading to another check with 100% spread chance.
					//Cannot happen if already at the bottom, otherwise we get an error for placing an 'L' outside of the grid
					if (randy == 0 && i != chunkSize - 1)
					{
						//cout << randy; //DEBUG
						//std::cout << "d-"; //DEBUG
						tiles[i + 1][j].setType(Tile::WATER);
						firstLake = 0; //may or may not require more rigging. The house must always win!!
					}
					//25% chance the first Lake tile will spread rightward, leading to another check with 100% spread chance
					//Cannot happen if already at the right edge, otherwise we get an error for placing an 'L' outside of the grid
					else if (randy == 1 && j != chunkSize - 1)
					{
						//cout << randy; //DEBUG
						//std::cout << "r-"; //DEBUG
						tiles[i][j + 1].setType(Tile::WATER);
						firstLake = 0;
					}
					//50% chance the first Lake tile will spread downward, leading to another check with 100% spread chance
					//HOWEVER we might be at the edge, which causes many issues, we will rig it a bit more with THREE OPTIONS
					else if (randy > 1 && i != chunkSize - 1 && j == chunkSize - 1) //if we're not at the bottom, but at the right, then we only change the lower tile
					{
						//cout << randy; //DEBUG
						//std::cout << "bd-"; //DEBUG
						tiles[i + 1][j].setType(Tile::WATER);
						//tiles[i][j+1][0] = "L";
						firstLake = 0;
					}
					else if (randy > 1 && i == chunkSize - 1 && j != chunkSize - 1) //if we're not at the right but at the bottom, then we only change the right
					{
						//cout << randy; //DEBUG
						//std::cout << "br-"; //DEBUG
									   //tiles[i+1][j][0] = "L";
						tiles[i][j + 1].setType(Tile::WATER);
						firstLake = 0;
					}
					else if (randy > 1 && i != chunkSize - 1 && j != chunkSize - 1) //If we are NOT at the bottom and not the right, then we change both
					{
						//cout << randy; //DEBUG
						//std::cout << "bb-"; //DEBUG
						tiles[i + 1][j].setType(Tile::WATER);
						tiles[i][j + 1].setType(Tile::WATER);
						firstLake = 0;
					}
					else
					{
						//cout << randy; //DEBUG
						//std::cout << "n-";
						firstLake = 0;
					}
				}
				//DEBUG THIS STUFF BOY

				else
				{
					//randy = 3; //DEBUG DELETE //0 works//1 works//2 works//check 3
					if (randy == 0 && i != chunkSize - 1)
					{
						//cout << randy; //DEBUG
						//std::cout << "d"; //DEBUG
						tiles[i + 1][j].setType(Tile::WATER); //% chance of making the lower tile a lake. also allows for another Lake roll
						chance++; //decreases the % chance of increasing the Lake size

					}
					else if (randy == 0 && i == chunkSize - 1) //if we're already at the bottom, then we can't just make one below it
					{
						//cout << randy; //DEBUG
						//std::cout << "botEdge"; //DEBUG
						if (j == tiles.size() - 1) //if we are at the very very bottom-right corner of the world.
						{
							//std::cout << "resetBotEdge"; //DEBUG reset all variables
							chance = 4;
							firstLake = 1;
						}
						else
						{
							//std::cout << "AboveBotEdge"; //DEBUG
							tiles[i - 1][j].setType(Tile::WATER); //small chance of adding another Lake tile above the current Lake tile (chances are, there is already one there)
						}
					}
					else if (randy == 1 && j != chunkSize - 1)
					{
						//cout << randy; //DEBUG
						//std::cout << "r"; //DEBUG
						tiles[i][j + 1].setType(Tile::WATER); //% chance of making the right tile a lake. also allows for another Lake roll
						chance++; //decreases the % chance of increasing the Lake size
					}
					else if (randy == 1 && j == chunkSize - 1)
					{
						//cout << randy; //DEBUG
						//std::cout << "rightEdge";
						if (i == chunkSize - 1)
						{
							//std::cout << "resetRightEdge";
							chance = 4;
							firstLake = 1;
						}
						else
						{
							//std::cout << "LeftRightEdge";
							tiles[i][j - 1].setType(Tile::WATER); //small chance of adding a Lake tile to the left. chances are, there is already a Lake tile there.
						}
					}
					else if (randy == 2 && i > 0)
					{
						if (tiles[i - 1][j].getType() == Tile::WATER && i != chunkSize - 1)
						{
							//std::cout << "|"; //DEBUG
							//std::cout << "d"; //DEBUG
							tiles[i + 1][j].setType(Tile::WATER); //% chance of making the lower tile a lake. also allows for another Lake roll
							chance++; //decreases the % chance of increasing the Lake size
						}
						//TODO ^This here above us^ is trying to spawn a lake outside the world
						else
						{
							//cout << randy; //DEBUG
							//std::cout << "u"; //DEBUG
							tiles[i - 1][j].setType(Tile::WATER);//% chance of making the upper tile a Lake as well
							chance++; //decreases the % chance of increasing the Lake size
						}
					}
					else if (randy == 3 && j > 0)
					{
						if (tiles[i][j - 1].getType() == Tile::WATER && j != chunkSize - 1)
						{
							//std::cout << "|";
							//std::cout << "r";
							tiles[i][j + 1].setType(Tile::WATER); //% chance of making the lower tile a lake. also allows for another Lake roll
							chance++; //decreases the % chance of increasing the Lake size
						}
						else
						{
							//cout << randy; //DEBUG
							//std::cout << "l"; //DEBUG
							tiles[i][j - 1].setType(Tile::WATER); //% chance of making the left tile a Lake as well
							chance++; //decreases the % chance of increasing the Lake size
						}
					}
					else
					{
						//std::cout << randy + "wut"; //DEBUG
						if (i == chunkSize - 1)
						{
							//std::cout << "DownEdgy";
						}
						else if (j == chunkSize - 1)
						{
							//std::cout << "RightEdgy";
						}
						else if (tiles[i + 1][j].getType() == Tile::WATER || tiles[i][j + 1].getType() == Tile::WATER)
						{
							//std::cout << "Relook"; //the Lake isn't quite done yet, since there is at least 1 more check to make, rightward or downward //DEBUG
							//std::cout << randy; //DEBUG
						}
						else
						{
							//std::cout << randy; //DEBUG
							//std::cout << "Reset"; //DEBUG
							chance = 4; //returns the Lake change for the first time.
							firstLake = 1;
						}
					}
				}

				//std::cout << std::endl;
			}
			//std::cout << tiles[i][j][0];
		}
	}

	//std::cout << std::endl << std::endl; //DEBUG
	return tiles;
}


/* TODO: set priority to the ore, meaning that the ore will spawn no matter what the tile is, THEN change the tile below to a dirt tile*/
std::vector<std::vector<Tile>> Generation::setOres(std::vector<std::vector<Tile>> &ores, std::vector<std::vector<Tile>> &tiles) //NEED TO MAKE BLOBBY
{
	aLen = 12;
	//std::cout << aLen << std::endl; //DEBUG

						  /* Very very simple version */
						  /*
						  for (int i = 0; i < ores.size(); i++)
						  {
						  for (int j = 0; j < ores[i].size(); j++)
						  {
						  int rando = rand() % aLen;
						  string setOre = oreLetter[rando];
						  //tiles[i][j].push_back(setTile);
						  ores[i][j][1] = setOre;
						  //cout << rando; //DEBUG
						  }
						  }
						  */

						  /* This version only spawns Coal and Iron on Dirt tiles */
	int chance = 4; //size of the clunk of ore
	int randy; //random max size of the clunk

	//#######################################
	//Added/Changes By Dustin
	//#######################################
		//Not really needed anymore
	/*
	for (int i = 0; i < ores.size(); i++) //This simply sets all the ores to a blanks spot. May not be needed in the final build
	{
		for (int j = 0; j < ores[i].size(); j++)
		{
			ores[i][j][1] = "_";
		}
	}
	*/
	//#######################################

	//NEED
	for (int i = 0; i < chunkSize; i++) //This sets the random ores over the terrain
	{
		for (int j = 0; j < chunkSize; j++)
		{
			//if (ores[i][j][0] == "D" || ores[i][j][0] == "G")
			if (tiles[i][j].getType() == Tile::DIRT)
			{
				randy = rand() % aLen; //NEED
									   //rando = 0; //DEBUG
				Tile::Types setOre = ore[randy];
				ores[i][j].setType(setOre);
				//std::cout << randy; //DEBUG
				//std::cout << oreLetter[randy]; //DEBUG
				//std::cout << "(" << i << "," << j << ") ";
				//std::cout << std::endl;
			}
		}
	}


	/* TODO: debug algorithm AND change it so coal does not spawn across rivers */


	int up, dwn, l, r, uu, dd, ll, rr; //four different points
	for (int i = 0; i < chunkSize; i++) //This tries to expand the ores
	{
		for (int j = 0; j < chunkSize; j++)
		{
			randy = rand() % chance; // NEED
									 //cout << randy; //DEBUG

			if (ores[i][j].getType() == Tile::ORE_COAL) //if the tile is a Coal
			{

				up = randy % 3 + 1;
				dwn = randy % 3 + 1;
				l = randy % 3 + 1;
				r = randy % 3 + 1;
				//up = 3; //DEBUG
				//dwn = 3; //DEBUG
				//l = 3; //DEBUG
				//r = 3; //DEBUG



				//std::cout << up << " " << r << " " << dwn << " " << l << std::endl;

				for (int a = 1; a < up + 1; a++) //for all the UPPER tiles. use same loop for the left, right, and lower rows
				{
					if (i - a >= 0 && tiles[i - a][j].getType() != Tile::WATER && ores[i - a][j].getType() != Tile::ORE_COAL)
					{
						ores[i - a][j].setType(Tile::TEMP_c); //make it a small c as a temp
						tiles[i - a][j].setType(Tile::DIRT); //NEED

						ll = randy % (up - a + 1); //leftLeft is a random chance between 0 and (upper limit - #ofLoop) Further description in Notes
						for (int x = 1; x <= ll; x++)
						{
							if (j - x >= 0 && tiles[i - a][j - x].getType() != Tile::WATER && ores[i - a][j - x].getType() != Tile::ORE_COAL)
							{
								ores[i - a][j - x].setType(Tile::TEMP_c);
								tiles[i - a][j - x].setType(Tile::DIRT);
							}
						}
						rr = randy % (up - a + 1); //repeat for the other
						for (int x = 1; x <= rr; x++)
						{
							if (j + x < chunkSize &&tiles[i - a][j + x].getType() != Tile::WATER && ores[i - a][j + x].getType() != Tile::ORE_COAL)
							{
								ores[i - a][j + x].setType(Tile::TEMP_c);
								tiles[i - a][j + x].setType(Tile::DIRT);
							}
						}
					}
				}

				for (int b = 1; b < r + 1; b++) //RIGHT
				{
					if (j + b < chunkSize && tiles[i][j + b].getType() != Tile::WATER && ores[i][j + b].getType() != Tile::ORE_COAL)
					{
						ores[i][j + b].setType(Tile::TEMP_c);
						tiles[i][j + b].setType(Tile::DIRT); //NEED

						uu = randy % (r - b + 1);
						for (int x = 1; x <= uu; x++)
						{
							if (i - x >= 0 && tiles[i - x][j + b].getType() != Tile::WATER && ores[i - x][j + b].getType() != Tile::ORE_COAL)
							{
								ores[i - x][j + b].setType(Tile::TEMP_c);
								tiles[i - x][j + b].setType(Tile::DIRT);
							}
						}
						dd = randy % (r - b + 1);
						for (int x = 1; x <= dd; x++)
						{
							if (i + x < ores.size() && tiles[i + x][j + b].getType() != Tile::WATER && ores[i + x][j + b].getType() != Tile::ORE_COAL)
							{
								ores[i + x][j + b].setType(Tile::TEMP_c);
								tiles[i + x][j + b].setType(Tile::DIRT);
							}
						}

					}
				}

				for (int c = 1; c < dwn + 1; c++) //LOWER
				{
					if (i + c < chunkSize && tiles[i + c][j].getType() != Tile::WATER && ores[i + c][j].getType() != Tile::ORE_COAL)
					{
						ores[i + c][j].setType(Tile::TEMP_c);
						tiles[i + c][j].setType(Tile::DIRT); //NEED

						ll = randy % (dwn - c + 1);
						for (int x = 1; x <= ll; x++)
						{
							if (j - x >= 0 && tiles[i + c][j - x].getType() != Tile::WATER && ores[i + c][j - x].getType() != Tile::ORE_COAL)
							{
								ores[i + c][j - x].setType(Tile::TEMP_c);
								tiles[i + c][j - x].setType(Tile::DIRT);
							}
						}
						rr = randy % (dwn - c + 1);
						for (int x = 1; x <= rr; x++)
						{
							if (j + x < chunkSize && tiles[i + c][j + x].getType() != Tile::WATER && ores[i + c][j + x].getType() != Tile::ORE_COAL)
							{
								ores[i + c][j + x].setType(Tile::TEMP_c);
								tiles[i + c][j + x].setType(Tile::DIRT);
							}
						}
					}
				}


				for (int d = 1; d < l + 1; d++) //LEFT
				{
					if (j - d >= 0 && tiles[i][j - d].getType() != Tile::WATER && ores[i][j - d].getType() != Tile::ORE_COAL)
					{
						ores[i][j - d].setType(Tile::TEMP_c);
						tiles[i][j - d].setType(Tile::DIRT); //NEED

						uu = randy % (l - d + 1);
						for (int x = 1; x <= uu; x++)
						{
							if (i - x >= 0 && tiles[i - x][j - d].getType() != Tile::WATER && ores[i - x][j - d].getType() != Tile::ORE_COAL)
							{
								ores[i - x][j - d].setType(Tile::TEMP_c);
								tiles[i - x][j - d].setType(Tile::DIRT);
							}
						}
						dd = randy % (l - d + 1);
						for (int x = 1; x <= dd; x++)
						{
							if (i + x < chunkSize && tiles[i + x][j - d].getType() != Tile::WATER && ores[i + x][j - d].getType() != Tile::ORE_COAL)
							{
								ores[i + x][j - d].setType(Tile::TEMP_c);
								tiles[i + x][j - d].setType(Tile::DIRT);
							}
						}

					}
				}

			}

			if (ores[i][j].getType() == Tile::ORE_IRON)
			{
				up = randy % 3 + 1;
				dwn = randy % 3 + 1;
				l = randy % 3 + 1;
				r = randy % 3 + 1;
				//up = 3; //DEBUG
				//dwn = 3; //DEBUG
				//l = 3; //DEBUG
				//r = 3; //DEBUG
				//std::cout << up << " " << r << " " << dwn << " " << l << std::endl;

				//Breaks HERE?
				for (int a = 1; a < up + 1; a++) //for all the UPPER tiles. use same loop for the left, right, and lower rows
				{
					if (i - a >= 0 && tiles[i - a][j].getType() != Tile::WATER && ores[i - a][j].getType() != Tile::ORE_COAL && ores[i - a][j].getType() != Tile::TEMP_c && ores[i - a][j].getType() != Tile::ORE_IRON)
					{
						ores[i - a][j].setType(Tile::TEMP_i); //make it a small c as a temp
						tiles[i - a][j].setType(Tile::DIRT); //NEED

						ll = randy % (up - a + 1); //leftLeft is a random chance between 0 and (upper limit - #ofLoop) Further description in Notes
						for (int x = 1; x <= ll; x++)
						{
							if (j - x >= 0 && tiles[i - a][j - x].getType() != Tile::WATER && ores[i - a][j - x].getType() != Tile::ORE_COAL && ores[i - a][j - x].getType() != Tile::TEMP_c && ores[i - a][j - x].getType() != Tile::ORE_IRON)
							{
								ores[i - a][j - x].setType(Tile::TEMP_i);
								tiles[i - a][j - x].setType(Tile::DIRT);
							}
						}
						rr = randy % (up - a + 1); //repeat for the other
						for (int x = 1; x <= rr; x++)
						{
							if (j + x < chunkSize && tiles[i - a][j + x].getType() != Tile::WATER && ores[i - a][j + x].getType() != Tile::ORE_COAL && ores[i - a][j + x].getType() != Tile::TEMP_c && ores[i - a][j + x].getType() != Tile::ORE_IRON)
							{
								ores[i - a][j + x].setType(Tile::TEMP_i);
								tiles[i - a][j + x].setType(Tile::DIRT);
							}
						}
					}
				}

				for (int b = 1; b < r + 1; b++) //RIGHT
				{
					if (j + b < chunkSize && tiles[i][j + b].getType() != Tile::WATER && ores[i][j + b].getType() != Tile::ORE_COAL && ores[i][j + b].getType() != Tile::TEMP_c && ores[i][j + b].getType() != Tile::ORE_IRON)
					{
						ores[i][j + b].setType(Tile::TEMP_i);
						tiles[i][j + b].setType(Tile::DIRT); //NEED

						uu = randy % (r - b + 1);
						for (int x = 1; x <= uu; x++)
						{
							if (i - x >= 0 && tiles[i - x][j + b].getType() != Tile::WATER && ores[i - x][j + b].getType() != Tile::ORE_COAL && ores[i - x][j + b].getType() != Tile::TEMP_c && ores[i - x][j + b].getType() != Tile::ORE_IRON)
							{
								ores[i - x][j + b].setType(Tile::TEMP_i);
								tiles[i - x][j + b].setType(Tile::DIRT);
							}
						}
						dd = randy % (r - b + 1);
						for (int x = 1; x <= dd; x++)
						{
							//Breaking here? 
							if (i + x < chunkSize && tiles[i + x][j + b].getType() != Tile::WATER && ores[i + x][j + b].getType() != Tile::ORE_COAL && ores[i + x][j + b].getType() != Tile::TEMP_c && ores[i + x][j + b].getType() != Tile::ORE_IRON)
							{
								ores[i + x][j + b].setType(Tile::TEMP_i);
								tiles[i + x][j + b].setType(Tile::DIRT);
							}
						}
					}
				}

				for (int c = 1; c < dwn + 1; c++) //LOWER
				{
					if (i + c < chunkSize && tiles[i + c][j].getType() != Tile::WATER && ores[i + c][j].getType() != Tile::ORE_COAL && ores[i + c][j].getType() != Tile::TEMP_c && ores[i + c][j].getType() != Tile::ORE_IRON)
					{
						ores[i + c][j].setType(Tile::TEMP_i);
						tiles[i + c][j].setType(Tile::DIRT); //NEED

						ll = randy % (dwn - c + 1);
						for (int x = 1; x <= ll; x++)
						{
							if (j - x >= 0 && tiles[i + c][j - x].getType() != Tile::WATER && ores[i + c][j - x].getType() != Tile::ORE_COAL && ores[i + c][j - x].getType() != Tile::TEMP_c && ores[i + c][j - x].getType() != Tile::ORE_IRON)
							{
								ores[i + c][j - x].setType(Tile::TEMP_i);
								tiles[i + c][j - x].setType(Tile::DIRT);
							}
						}
						rr = randy % (dwn - c + 1);
						for (int x = 1; x <= rr; x++)
						{
							if (j + x < chunkSize && tiles[i + c][j + x].getType() != Tile::WATER && ores[i + c][j + x].getType() != Tile::ORE_COAL && ores[i + c][j + x].getType() != Tile::TEMP_c && ores[i + c][j + x].getType() != Tile::ORE_IRON)
							{
								ores[i + c][j + x].setType(Tile::TEMP_i);
								tiles[i + c][j + x].setType(Tile::DIRT);
							}
						}
					}
				}

				for (int d = 1; d < l + 1; d++) //LEFT
				{
					if (j - d >= 0 && tiles[i][j - d].getType() != Tile::WATER && ores[i][j - d].getType() != Tile::ORE_COAL && ores[i][j - d].getType() != Tile::TEMP_c && ores[i][j - d].getType() != Tile::ORE_IRON)
					{
						ores[i][j - d].setType(Tile::TEMP_i);
						tiles[i][j - d].setType(Tile::DIRT); //NEED

						uu = randy % (l - d + 1);
						for (int x = 1; x <= uu; x++)
						{
							if (i - x >= 0 && tiles[i - x][j - d].getType() != Tile::WATER && ores[i - x][j - d].getType() != Tile::ORE_COAL && ores[i - x][j - d].getType() != Tile::TEMP_c && ores[i - x][j - d].getType() != Tile::ORE_IRON)
							{
								ores[i - x][j - d].setType(Tile::TEMP_i);
								tiles[i - x][j - d].setType(Tile::DIRT);
							}
						}

						dd = randy % (l - d + 1);
						for (int x = 1; x <= dd; x++)
						{
							if (i + x < chunkSize && tiles[i + x][j - d].getType() != Tile::WATER && ores[i + x][j - d].getType() != Tile::ORE_COAL && ores[i + x][j - d].getType() != Tile::TEMP_c && ores[i + x][j - d].getType() != Tile::ORE_IRON)
							{
								ores[i + x][j - d].setType(Tile::TEMP_i);
								tiles[i + x][j - d].setType(Tile::DIRT);
							}
						}

					}
				}

			}

		}
	}



	for (int i = 0; i < chunkSize; i++) //Changes the temp slots into their dedicated tile type
	{
		for (int j = 0; j < chunkSize; j++)
		{
			if (ores[i][j].getType() == Tile::TEMP_c)
			{
				//cout << "huh"; //DEBUG
				ores[i][j].setType(Tile::ORE_COAL);
			}
			if (ores[i][j].getType() == Tile::TEMP_i)
			{
				ores[i][j].setType(Tile::ORE_IRON);
			}
		}
	}
	terrainLayer = tiles;
	return ores;
	//std::cout << std::endl << std::endl; //DEBUG
}
//#######################################
//Added/Changes By Dustin
//#######################################
	//Commented out because it looks like debug 
/*
void showBoth(std::vector < std::vector < std::vector<std::string> > > grid)
{
	for (int i = 0; i < grid.size(); i++) //works
	{
		//cout << "huh"; //debugging, please ignore
		for (int j = 0; j < grid[i].size(); j++) //fixed
		{
			//cout << "wut"; //debugging, ignore
			if (grid[i][j][1] == "_") //if there is not ore, then show the tile
			{
				std::cout << grid[i][j][0] << " ";
			}
			else //if there is an ore, show the ore
			{
				std::cout << grid[i][j][1] << " ";
			}
		}
		std::cout << std::endl;
	}
}
*/
//#######################################

//int main()
//{
//	vector < vector < vector<string> > > grid; // vector in a vector in a vector, whoa a 3D vector!
//
//	int xAxis;
//	int yAxis;
//	int high;//grid[yAxis][xAxis][height]
//
//	cout << "Grid of tiles in the lowest grid or the grid of ores above it:" << endl; //description
//	cout << "G = Grass, D = Dirt, L = Lake Water, R = River Water" << endl; //key for pseudo placement for tiles
//	cout << "C = Coal, I = Iron" << endl; //and for ores
//
//	string tile[13] = { "G", "G", "G", "G", "G", "G", "G", "G", "G", "D", "D", "D", "L" }; //the five current possibilities for the Tile vector (will be changed in the future
//																						   //string tile [5] = {"G", "G", "D", "D", "D"};
//																						   //cout << sizeof(tile)/sizeof(tile[0]) << endl; //DEBUG
//	string ore[12] = { "_", "_", "_", "_", "_", "_", "_", "_", "_", "C", "C", "I" };
//	//cout << sizeof(ore) << endl; //DEBUG
//
//	cout << "Insert how high you want your map to be: "; //this let's the user set up the size of the Grid
//	cin >> yAxis;
//	cout << endl;
//	cout << "Insert how wide you want your map to be: ";
//	cin >> xAxis;
//	cout << endl;
//	cout << "Insert the height of the map: ";
//	cin >> high;
//	cout << endl;
//
//	grid = createGrid(xAxis, yAxis, high); //converts the empty 3D vector into a filled grid of Q's. It should not be Q, so there is an error if there are any Q's
//
//										   /* DEBUG */
//										   /*
//										   for (size_t i = 0; i < grid.size(); i++)
//										   for (size_t j = 0; j < grid[i].size(); j++)
//										   for (size_t k = 0; k < grid[i][j].size(); k++)
//										   cout << "tube[" << i << "][" << j << "][" << k << "] = " << grid[i][j][k] << endl;
//										   */
//
//	int tilLen = sizeof(tile) / sizeof(tile[0]);
//	int oreLen = sizeof(ore) / sizeof(ore[0]);
//
//	setTiles(tile, grid, tilLen); //set up the Tiles
//	cout << endl << endl;
//	showTiles(grid); //show the table of Tiles
//
//	setOres(ore, grid, oreLen); //set up the Ores
//	cout << endl << endl;
//	showOres(grid); //show the table of Ores
//
//	cout << endl << endl << endl;
//	showBoth(grid);
//
//	return(0);
//}

/*
For the Ore generation, the ore needs to gain priority. The Ore will generate AFTER the tile. This will prevent ores growing on water,
but the ore will generate over grass OR dirt. If the ore generates over-top the grass, then it will change into a dirt tile.

The Ore needs to be more blob-like. It can't be the same as the lake.

*/

/*
if (ores[i][j][0] == "D") //I BROKE IT!
{
cout << randy; //DEBUG
if (i > 0 && i < ores.size()-1 && j > 0 && j < ores[i].size()-1) //prevents accessing anything outside of the vector
{
/*
if (ores[i+1][j][1] == "C")
{
ores[i][j][1] = "C";
}
*/
/* spreads the ore, but spread too much? Adjust random chance */
/*
if (ores[i+1][j][1] == "C" || ores[i][j+1][1] == "C" || ores[i-1][j][1] == "C" || ores[i][j-1][1] == "C") //checks adjacent tiles for Coal
{
if (ores[i][j][1] == "_")
{
if (randy < 4)
{
cout << "Set";
ores[i][j][1] = "C";
chance++;
}
else
{
cout << "Reset";
chance = 4;
}
}

}
}
*/

/*for (int d = 1; d < l + 1; d++) //LEFT
{
if (j-d >= 0 && ores[i][j-d][0] != "L" && ores[i][j-d][1] != "C")
{
ores[i][j-d][1] = "c";
ores[i][j-d][0] = "D"; //NEED

uu = randy % (l - d + 1);
for (int x = 1; x <= uu; x++)
{
if (i-x >= 0 && ores[i-x][j-d][0] != "L" && ores[i-x][j-d][1] != "C")
{
ores[i-x][j-d][1] = "c";
ores[i-x][j-d][0] = "D";
}
}
dd = randy % (l - d + 1);
for (int x = 1; x <= dd; x++)
{
if (i+x < ores.size() && ores[i+x][j-d][0] != "L" && ores[i+x][j-d][1] != "C")
{
ores[i+x][j-d][1] = "c";
ores[i+x][j-d][0] = "D";
}
}
}
}*/

Generation::Generation()
{
}
