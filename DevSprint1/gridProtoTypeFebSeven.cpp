#include <stdio.h>
#include <math.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

/*
    Author's Notes
    - The Algorithm is still being fixed up.
    - The lines of code that are followed by a '//DEBUG' are used for, you guessed it, debugging. The usually show the RNG values or out of place phrases.
    - Any suggestion will be super-duper. Make a comment next to the line or function with an  all-caps 'SUGGEST' or 'SUG' so it's easy to find
    - If your suggestion or "constructive criticisms" are more broad or about the entire prototype itself, then place them in the 'SUGGESTIONS' box below
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




vector < vector < vector<string> > > createGrid(int xAxis, int yAxis, int height) //creates the initial grid using the starting variables
{
    /*Creates the vector*/
    vector < vector < vector<string> > > grid;
    for(int i = 0; i < yAxis; i++) //grid[this][][]
    {
        vector < vector<string> > grid0;
        grid.push_back( grid0 );
        for(int j = 0; j < xAxis; j++) //grid[][this][]
        {
            vector<string> grid1;
            grid[i].push_back( grid1 );
            for(int k = 0; k < height; k++) //grid[][][this]
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
    for(int i = 0; i < tiles.size(); i++) //works
    {
        //cout << "huh"; //DEBUG
        for(int j = 0; j < tiles[i].size(); j++) //fixed
        {
            //cout << "wut"; //DEBUG
            cout << tiles[i][j][0] << " "; //show the current tile but with a space to separate
        }
        cout << endl;
    }
}

void showOres(vector < vector < vector<string> > > ores) //shows the second lowest set; the ores
{
    for(int i = 0; i < ores.size(); i++) //works
    {
        //cout << "huh"; //DEBUG
        for(int j = 0; j < ores[i].size(); j++) //fixed
        {
            //cout << "wut"; //DEBUG
            cout << ores[i][j][1] << " ";
        }
        cout << endl;
    }
}

vector < vector < vector<string> > > setTiles(string tileLetter[], vector < vector < vector<string> > > &tiles) //
{
    int rando = rand() % sizeof(tileLetter);
    cout << sizeof(tileLetter) << endl; //DEBUG
    for (int i = 0; i < tiles.size(); i++)
    {
        for (int j = 0; j < tiles[i].size(); j++)
        {
            int rando = rand() % sizeof(tileLetter);
            string setTile = tileLetter[rando];
            //tiles[i][j].push_back(setTile);
            tiles[i][j][0] = setTile;
            cout << rando; //DEBUG
            //cout << rando; //debugging
            //cout << setTile;
            //cout << tiles[i][j][0];
        }
    }
    cout << endl << endl; //DEBUG
    //This is rigging the system, just to see if this algorithm works
    tiles[1][1][0] = "L"; //RIGGED DEBUG
    tiles[7][7][0] = "L"; //RIGGED DEBUG

    int randy; //for random number generation
    int chance = 4; //% chance of making a new lake. It increases as the lake size increases
    int firstLake = 1;
    for (int i = 0; i < tiles.size(); i++)
    {
        for (int j = 0; j < tiles[i].size(); j++)
        {
            if (tiles[i][j][0] == "L") //for expanding the Lakes
            {
                randy = rand() % chance;
                //we're going to rig the system to make sure that the Lake does increase in the lower or right tiles,
                //therefore making a lake that is at least
                /* DEBUGGING STUFF */
                //if (chance == 3 && firstLake == 1)
                //cout << randy;
                //cout << "Q";
                //tiles[i][j][0] = "Q"; //so this works but not in loop? They taught us NOTHING!
                //cout << tiles[i][j][0];
                //cout << firstLake;

                if (chance == 4 && firstLake == 1)
                {
                    if (randy == 0) //25% chance the first Lake tile will spread downward, leading to another check with 100% spread chance
                    {
                        cout << randy; //DEBUG
                        cout << "d-"; //DEBUG
                        tiles[i+1][j][0] = "L";
                        firstLake = 0; //may or may not require more rigging. The house must always win!!
                    }
                    else if (randy == 1) //25% chance the first Lake tile will spread rightward, leading to another check with 100% spread chance
                    {
                        cout << randy; //DEBUG
                        cout << "r-"; //DEBUG
                        tiles[i][j+1][0] = "L";
                        firstLake = 0;
                    }
                    else //50% chance the first Lake tile will spread downward, leading to another check with 100% spread chance
                    {
                        cout << randy; //DEBUG
                        cout << "b-"; //DEBUG
                        tiles[i+1][j][0] = "L";
                        tiles[i][j+1][0] = "L";
                        firstLake = 0;
                    }
                }

                else
                {
                    if (randy == 0)
                    {
                        cout << randy; //DEBUG
                        cout << "d"; //DEBUG
                        tiles[i+1][j][0] = "L"; //% chance of making the lower tile a lake. also allows for another Lake roll
                        chance++; //decreases the % chance of increasing the Lake size

                    }
                    else if (randy == 1)
                    {
                        cout << randy; //DEBUG
                        cout << "r"; //DEBUG
                        tiles[i][j+1][0] = "L"; //% chance of making the right tile a lake. also allows for another Lake roll
                        chance++; //decreases the % chance of increasing the Lake size
                    }
                    else if (randy == 2 && tiles[i].size())
                    {
                        if (tiles[i-1][j][0] == "L")
                        {
                            cout << "'" + randy; //DEBUG
                            cout << "d"; //DEBUG
                            tiles[i+1][j][0] = "L"; //% chance of making the lower tile a lake. also allows for another Lake roll
                            chance++; //decreases the % chance of increasing the Lake size
                        }
                        else
                        {
                            cout << randy; //DEBUG
                            cout << "u"; //DEBUG
                            tiles[i-1][j][0] = "L"; //% chance of making the upper tile a Lake as well
                            chance++; //decreases the % chance of increasing the Lake size
                        }
                    }
                    else if (randy == 3)
                    {
                        if (tiles[i][j-1][0] == "L")
                        {
                            cout << "'" + randy;
                            cout << "r";
                            tiles[i][j+1][0] = "L"; //% chance of making the lower tile a lake. also allows for another Lake roll
                            chance++; //decreases the % chance of increasing the Lake size
                        }
                        else
                        {
                            cout << randy; //DEBUG
                            cout << "l"; //DEBUG
                            tiles[i][j-1][0] = "L"; //% chance of making the left tile a Lake as well
                            chance++; //decreases the % chance of increasing the Lake size
                        }
                    }
                    else
                    {
                        if (tiles[i+1][j][0] == "L" || tiles[i][j+1][0] == "L")
                        {
                            cout << "Relook"; //the Lake isn't quite done yet, since there is at least 1 more check to make, rightward or downward //DEBUG
                            cout << randy; //DEBUG
                        }
                        else
                        {
                            cout << randy; //DEBUG
                            cout << "Reset"; //DEBUG
                            chance = 4; //returns the Lake change for the first time.
                            firstLake = 1;
                        }
                    }
                }

                cout << endl;
            }
            cout << tiles[i][j][0];
            /*
            else
            {

            }
            */
        }
    }
    cout << endl << endl; //DEBUG
    return tiles;
}

vector < vector < vector<string> > > setOres(string oreLetter[], vector < vector < vector<string> > > &ores)
{
    for (int i = 0; i < ores.size(); i++)
    {
        for (int j = 0; j < ores[i].size(); j++)
        {
            int rando = rand() % sizeof(oreLetter);
            string setOre = oreLetter[rando];
            ores[i][j][1] = setOre;
            //cout << rando; //DEBUG
        }
    }
    cout << endl << endl; //DEBUG
    return ores;
}

int main()
{
    vector < vector < vector<string> > > grid; // vector in a vector in a vector, whoa a 3D vector!

    int xAxis;
    int yAxis;
    int high;//grid[yAxis][xAxis][height]

    cout << "Grid of tiles in the lowest grid or the grid of ores above it:" << endl; //description
    cout << "G = Grass, D = Dirt, L = Lake Water, R = River Water" << endl; //key for pseudo placement for tiles
    cout << "C = Coal, I = Iron" << endl; //and for ores

    string tile [12] = {"G", "G", "G", "G", "G", "G", "D", "D", "D", "D", "L", "R"}; //the five current possibilities for the Tile vector (will be changed in the future
    //cout << sizeof(tile)/sizeof(tile[0]) << endl; //DEBUG
    string ore [8] = {"_", "_", "_", "_", "_", "C", "C", "I"};
    //cout << sizeof(ore) << endl; //DEBUG

    //this let's the user set up the size of the Grid
    cout << "Insert how high you want your map to be: ";
    cin >> yAxis;
    cout << endl;
    cout << "Insert how wide you want your map to be: ";
    cin >> xAxis;
    cout << endl;
    cout << "Insert the height of the map: ";
    cin >> high;
    cout << endl;

    grid = createGrid(xAxis, yAxis, high); //converts the empty 3D vector into a filled grid of Q's. It should not be Q, so there is an error if there are any Q's

    /*where the magic happens*/
    setTiles(tile, grid); //set up the Tiles
    setOres(ore, grid); //set up the Ores
    showTiles(grid); //show the table of Tiles
    showOres(grid); //show the table of Ores

}
