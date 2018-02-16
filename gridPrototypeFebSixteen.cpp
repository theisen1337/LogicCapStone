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
        //cout << "huh"; //debugging, please ignore
        for(int j = 0; j < tiles[i].size(); j++) //fixed
        {
            //cout << "wut"; //debugging, ignore
            cout << tiles[i][j][0] << " "; //show the current tile but with a space to separate
        }
        cout << endl;
    }
}

void showOres(vector < vector < vector<string> > > ores) //shows the second lowest set; the ores
{
    for(int i = 0; i < ores.size(); i++) //works
    {
        //cout << "huh"; //debugging, please ignore
        for(int j = 0; j < ores[i].size(); j++) //fixed
        {
            //cout << "wut"; //debugging, ignore
            cout << ores[i][j][1] << " ";
        }
        cout << endl;
    }
}

vector < vector < vector<string> > > setTiles(string tileLetter[], vector < vector < vector<string> > > &tiles, int aLen) //
{

    //int aLen = sizeof(tileLetter)/sizeof(tileLetter[0]); //USED LATER AFTER DEBUGGING IS DONE
    cout << aLen << endl; //DEBUG
    //int ranSize = aLen; //DEBUG
    //cout << ranSize << endl; //DEBUG
    //int rando = rand() % sizeof(tileLetter);
    //int rando = rand() % aLen;
    //cout << sizeof(tileLetter) << endl; //DEBUG
    for (int i = 0; i < tiles.size(); i++)
    {
        for (int j = 0; j < tiles[i].size(); j++)
        {
            //int rando = rand() % sizeof(tileLetter);
            //cout << aLen; //DEBUG
            //int test = aLen; //DEBUG
            //int rando = rand() % test;
            int rando = rand() % aLen; //911 NEED THIS BUT BREAKS THE CODE!! Nevermind, it's actually in the Lake Algorithm below
            //int rando = rand() % 10; //DEBUG
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
    cout << tiles.size()-1 << endl; //DEBUG
    cout << tiles[0].size()-1 << endl; //DEBUG

    //DEBUG STUFF
    for (int i = 0; i < tiles.size(); i++)
    {
        for (int j = 0; j < tiles[i].size(); j++)
        {
            if (tiles[i][j][0] == "L")
            {
                cout << "(" << i << "," << j << ")  ";
            }
        }
    }

    int randy; //for random number generation
    int chance = 4; //% chance of making a new lake. It increases as the lake size increases
    int firstLake = 1;
    /*Lake Algorithm*/
    for (int i = 0; i < tiles.size(); i++)
    {
        for (int j = 0; j < tiles[i].size(); j++)
        {
            if (tiles[i][j][0] == "L") //for expanding the Lakes
            {
                randy = rand() % chance; // NEED
                cout << randy; //DEBUG
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
                    if (randy == 0 && i != tiles.size()-1)
                    {
                        //cout << randy; //DEBUG
                        cout << "d-"; //DEBUG
                        tiles[i+1][j][0] = "L";
                        firstLake = 0; //may or may not require more rigging. The house must always win!!
                    }
                    //25% chance the first Lake tile will spread rightward, leading to another check with 100% spread chance
                    //Cannot happen if already at the right edge, otherwise we get an error for placing an 'L' outside of the grid
                    else if (randy == 1 && j != tiles[i].size()-1)
                    {
                        //cout << randy; //DEBUG
                        cout << "r-"; //DEBUG
                        tiles[i][j+1][0] = "L";
                        firstLake = 0;
                    }
                    //50% chance the first Lake tile will spread downward, leading to another check with 100% spread chance
                    //HOWEVER we might be at the edge, which causes many issues, we will rig it a bit more with THREE OPTIONS
                    else if (randy > 1 && i != tiles.size()-1 && j == tiles[i].size()-1) //if we're not at the bottom, but at the right, then we only change the lower tile
                    {
                        //cout << randy; //DEBUG
                        cout << "bd-"; //DEBUG
                        tiles[i+1][j][0] = "L";
                        //tiles[i][j+1][0] = "L";
                        firstLake = 0;
                    }
                    else if (randy > 1 && i == tiles.size()-1 && j != tiles[i].size()-1) //if we're not at the right but at the bottom, then we only change the right
                    {
                        //cout << randy; //DEBUG
                        cout << "br-"; //DEBUG
                        //tiles[i+1][j][0] = "L";
                        tiles[i][j+1][0] = "L";
                        firstLake = 0;
                    }
                    else if (randy > 1 && i != tiles.size()-1 && j != tiles[i].size()-1) //If we are NOT at the bottom and not the right, then we change both
                    {
                        //cout << randy; //DEBUG
                        cout << "bb-"; //DEBUG
                        tiles[i+1][j][0] = "L";
                        tiles[i][j+1][0] = "L";
                        firstLake = 0;
                    }
                    else
                    {
                        //cout << randy; //DEBUG
                        cout << "n-";
                        firstLake = 0;
                    }
                }
                //DEBUG THIS STUFF BOY

                else
                {
                    //randy = 3; //DEBUG DELETE //0 works//1 works//2 works//check 3
                    if (randy == 0 && i != tiles.size()-1)
                    {
                        //cout << randy; //DEBUG
                        cout << "d"; //DEBUG
                        tiles[i+1][j][0] = "L"; //% chance of making the lower tile a lake. also allows for another Lake roll
                        chance++; //decreases the % chance of increasing the Lake size

                    }
                    else if (randy == 0 && i == tiles.size()-1) //if we're already at the bottom, then we can't just make one below it
                    {
                        //cout << randy; //DEBUG
                        cout << "botEdge"; //DEBUG
                        if (j == tiles.size()-1) //if we are at the very very bottom-right corner of the world.
                        {
                            cout << "resetBotEdge"; //DEBUG reset all variables
                            chance = 4;
                            firstLake = 1;
                        }
                        else
                        {
                            cout << "AboveBotEdge"; //DEBUG
                            tiles[i-1][j][0] = "L"; //small chance of adding another Lake tile above the current Lake tile (chances are, there is already one there)
                        }
                    }
                    else if (randy == 1 && j != tiles[j].size()-1)
                    {
                        //cout << randy; //DEBUG
                        cout << "r"; //DEBUG
                        tiles[i][j+1][0] = "L"; //% chance of making the right tile a lake. also allows for another Lake roll
                        chance++; //decreases the % chance of increasing the Lake size
                    }
                    else if (randy == 1 && j == tiles[i].size()-1)
                    {
                        //cout << randy; //DEBUG
                        cout << "rightEdge";
                        if (i == tiles.size()-1)
                        {
                            cout << "resetRightEdge";
                            chance = 4;
                            firstLake = 1;
                        }
                        else
                        {
                            cout << "LeftRightEdge";
                            tiles[i][j-1][0] = "L"; //small chance of adding a Lake tile to the left. chances are, there is already a Lake tile there.
                        }
                    }
                    else if (randy == 2 && i > 0)
                    {
                        if (tiles[i-1][j][0] == "L" && i != tiles.size()-1)
                        {
                            cout << "|"; //DEBUG
                            cout << "d"; //DEBUG
                            tiles[i+1][j][0] = "L"; //% chance of making the lower tile a lake. also allows for another Lake roll
                            chance++; //decreases the % chance of increasing the Lake size
                        }
                        //TODO ^This here above us^ is trying to spawn a lake outside the world
                        else
                        {
                            //cout << randy; //DEBUG
                            cout << "u"; //DEBUG
                            tiles[i-1][j][0] = "L"; //% chance of making the upper tile a Lake as well
                            chance++; //decreases the % chance of increasing the Lake size
                        }
                    }
                    else if (randy == 3 && j > 0)
                    {
                        if (tiles[i][j-1][0] == "L" && j != tiles[i].size()-1)
                        {
                            cout << "|";
                            cout << "r";
                            tiles[i][j+1][0] = "L"; //% chance of making the lower tile a lake. also allows for another Lake roll
                            chance++; //decreases the % chance of increasing the Lake size
                        }
                        else
                        {
                            //cout << randy; //DEBUG
                            cout << "l"; //DEBUG
                            tiles[i][j-1][0] = "L"; //% chance of making the left tile a Lake as well
                            chance++; //decreases the % chance of increasing the Lake size
                        }
                    }
                    else
                    {
                        cout << randy + "wut"; //DEBUG
                        if (i == tiles.size()-1)
                        {
                            cout << "DownEdgy";
                        }
                        else if (j == tiles[i].size()-1)
                        {
                            cout << "RightEdgy";
                        }
                        else if (tiles[i+1][j][0] == "L" || tiles[i][j+1][0] == "L")
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
        }
    }

    cout << endl << endl; //DEBUG
    return tiles;
}


/* TODO: set priority to the ore, meaning that the ore will spawn no matter what the tile is, THEN change the tile below to a dirt tile*/
vector < vector < vector<string> > > setOres(string oreLetter[], vector < vector < vector<string> > > &ores, int aLen) //NEED TO MAKE BLOBBY
{
    cout << aLen << endl; //DEBUG

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
    for (int i = 0; i < ores.size(); i++) //This simply sets all the ores to a blanks spot. May not be needed in the final build
    {
        for (int j = 0; j < ores[i].size(); j++)
        {
            ores[i][j][1] = "_";
        }
    }
    //NEED
    for (int i = 0; i < ores.size(); i++) //This sets the random ores over the terrain
    {
        for (int j = 0; j < ores[i].size(); j++)
        {
            //if (ores[i][j][0] == "D" || ores[i][j][0] == "G")
            if (ores[i][j][0] == "D")
            {
                randy = rand() % aLen; //NEED
                //rando = 0; //DEBUG
                string setOre = oreLetter[randy];
                ores[i][j][1] = setOre;
                cout << randy; //DEBUG
                cout << oreLetter[randy]; //DEBUG
                cout << "(" << i << "," << j << ") ";
                cout << endl;
            }
        }
    }


    /* TODO: debug algorithm AND change it so coal does not spawn across rivers */


    int up, dwn, l, r, uu, dd, ll, rr; //four different points
    for (int i = 0; i < ores.size(); i++) //This tries to expand the ores
    {
        for (int j = 0; j < ores[i].size(); j++)
        {
            randy = rand() % chance; // NEED
            //cout << randy; //DEBUG

            if (ores[i][j][1] == "C") //if the tile is a Coal
            {

                up = randy % 3 + 1;
                dwn = randy % 3 + 1;
                l = randy % 3 + 1;
                r = randy % 3 + 1;
                //up = 3; //DEBUG
                //dwn = 3; //DEBUG
                //l = 3; //DEBUG
                //r = 3; //DEBUG



                cout << up << " " << r << " " << dwn << " " << l << endl;

                for (int a = 1; a < up + 1; a++) //for all the UPPER tiles. use same loop for the left, right, and lower rows
                {
                    if (i-a >= 0 && ores[i-a][j][0] != "L" && ores[i-a][j][1] != "C")
                    {
                        ores[i-a][j][1] = "c"; //make it a small c as a temp
                        ores[i-a][j][0] = "D"; //NEED

                        ll = randy % (up - a + 1); //leftLeft is a random chance between 0 and (upper limit - #ofLoop) Further description in Notes
                        for (int x = 1; x <= ll; x++)
                        {
                            if (j-x >= 0 && ores[i-a][j-x][1] != "L" && ores[i-a][j-x][1] != "C")
                            {
                                ores[i-a][j-x][1] = "c";
                                ores[i-a][j-x][0] = "D";
                            }
                        }
                        rr = randy % (up - a + 1); //repeat for the other
                        for (int x = 1; x <= rr; x++)
                        {
                            if (j+x < ores[i].size() && ores[i-a][j+x][1] != "L" && ores[i-a][j+x][1] != "C")
                            {
                                ores[i-a][j+x][1] = "c";
                                ores[i-a][j+x][0] = "D";
                            }
                        }
                    }
                }

                for (int b = 1; b < r + 1; b++) //RIGHT
                {
                    if (j+b < ores[i].size() && ores[i][j+b][0] != "L" && ores[i][j+b][1] != "C")
                    {
                        ores[i][j+b][1] = "c";
                        ores[i][j+b][0] = "D"; //NEED

                        uu = randy % (r - b + 1);
                        for (int x = 1; x <= uu; x++)
                        {
                            if (i-x >= 0 && ores[i-x][j+b][0] != "L" && ores[i-x][j+b][1] != "C")
                            {
                                ores[i-x][j+b][1] = "c";
                                ores[i-x][j+b][0] = "D";
                            }
                        }
                        dd = randy % (r - b + 1);
                        for (int x = 1; x <= dd; x++)
                        {
                            if (i+x < ores.size() && ores[i+x][j+b][0] != "L" && ores[i+x][j+b][1] != "C")
                            {
                                ores[i+x][j+b][1] = "c";
                                ores[i+x][j+b][0] = "D";
                            }
                        }

                    }
                }

                for (int c = 1; c < dwn + 1; c++) //LOWER
                {
                    if (i+c < ores.size() && ores[i+c][j][0] != "L" && ores[i+c][j][1] != "C")
                    {
                        ores[i+c][j][1] = "c";
                        ores[i+c][j][0] = "D"; //NEED

                        ll = randy % (dwn - c + 1);
                        for (int x = 1; x <= ll; x++)
                        {
                            if (j-x >= 0 && ores[i+c][j-x][0] != "L" && ores[i+c][j-x][1] != "C")
                            {
                                ores[i+c][j-x][1] = "c";
                                ores[i+c][j-x][0] = "D";
                            }
                        }
                        rr = randy % (dwn - c + 1);
                        for (int x = 1; x <= rr; x++)
                        {
                            if (j+x < ores[i].size() && ores[i+c][j+x][0] != "L" && ores[i+c][j+x][1] != "C")
                            {
                                ores[i+c][j+x][1] = "c";
                                ores[i+c][j+x][0] = "D";
                            }
                        }
                    }
                }


                for (int d = 1; d < l + 1; d++) //LEFT
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
                }

            }

            if (ores[i][j][1] == "I")
            {
                up = randy % 3 + 1;
                dwn = randy % 3 + 1;
                l = randy % 3 + 1;
                r = randy % 3 + 1;
                //up = 3; //DEBUG
                //dwn = 3; //DEBUG
                //l = 3; //DEBUG
                //r = 3; //DEBUG



                cout << up << " " << r << " " << dwn << " " << l << endl;

                for (int a = 1; a < up + 1; a++) //for all the UPPER tiles. use same loop for the left, right, and lower rows
                {
                    if (i-a >= 0 && ores[i-a][j][0] != "L" && ores[i-a][j][1] != "C" && ores[i-a][j][1] != "c" && ores[i-a][j][1] != "I")
                    {
                        ores[i-a][j][1] = "i"; //make it a small c as a temp
                        ores[i-a][j][0] = "D"; //NEED

                        ll = randy % (up - a + 1); //leftLeft is a random chance between 0 and (upper limit - #ofLoop) Further description in Notes
                        for (int x = 1; x <= ll; x++)
                        {
                            if (j-x >= 0 && ores[i-a][j-x][0] != "L" && ores[i-a][j-x][1] != "C" && ores[i-a][j-x][1] != "c" && ores[i-a][j-x][1] != "I")
                            {
                                ores[i-a][j-x][1] = "i";
                                ores[i-a][j-x][0] = "D";
                            }
                        }
                        rr = randy % (up - a + 1); //repeat for the other
                        for (int x = 1; x <= rr; x++)
                        {
                            if (j+x < ores[i].size() && ores[i-a][j+x][0] != "L" && ores[i-a][j-x][1] != "C" && ores[i-a][j-x][1] != "c" && ores[i-a][j-x][1] != "I")
                            {
                                ores[i-a][j+x][1] = "i";
                                ores[i-a][j+x][0] = "D";
                            }
                        }
                    }
                }

                for (int b = 1; b < r + 1; b++) //RIGHT
                {
                    if (j+b < ores[i].size() && ores[i][j+b][0] != "L" && ores[i][j+b][1] != "C" && ores[i][j+b][1] != "c" && ores[i][j+b][1] != "I")
                    {
                        ores[i][j+b][1] = "i";
                        ores[i][j+b][0] = "D"; //NEED

                        uu = randy % (r - b + 1);
                        for (int x = 1; x <= uu; x++)
                        {
                            if (i-x >= 0 && ores[i-x][j+b][0] != "L" && ores[i-x][j+b][1] != "C" && ores[i-x][j+b][1] != "c" && ores[i-x][j+b][1] != "I")
                            {
                                ores[i-x][j+b][1] = "i";
                                ores[i-x][j+b][0] = "D";
                            }
                        }
                        dd = randy % (r - b + 1);
                        for (int x = 1; x <= dd; x++)
                        {
                            if (i+x < ores.size() && ores[i+x][j+b][0] != "L" && ores[i-x][j+b][1] != "C" && ores[i-x][j+b][1] != "c" && ores[i-x][j+b][1] != "I")
                            {
                                ores[i+x][j+b][1] = "i";
                                ores[i+x][j+b][0] = "D";
                            }
                        }
                    }
                }

                for (int c = 1; c < dwn + 1; c++) //LOWER
                {
                    if (i+c < ores.size() && ores[i+c][j][0] != "L" && ores[i+c][j][1] != "C" && ores[i+c][j][1] != "c" && ores[i+c][j][1] != "I")
                    {
                        ores[i+c][j][1] = "i";
                        ores[i+c][j][0] = "D"; //NEED

                        ll = randy % (dwn - c + 1);
                        for (int x = 1; x <= ll; x++)
                        {
                            if (j-x >= 0 && ores[i+c][j-x][0] != "L" && ores[i+c][j-x][1] != "C" && ores[i+c][j-x][1] != "c" && ores[i+c][j-x][1] != "I")
                            {
                                ores[i+c][j-x][1] = "i";
                                ores[i+c][j-x][0] = "D";
                            }
                        }
                        rr = randy % (dwn - c + 1);
                        for (int x = 1; x <= rr; x++)
                        {
                            if (j+x < ores[i].size() && ores[i+c][j+x][0] != "L" && ores[i+c][j+x][1] != "C" && ores[i+c][j+x][1] != "c" && ores[i+c][j+x][1] != "I")
                            {
                                ores[i+c][j+x][1] = "i";
                                ores[i+c][j+x][0] = "D";
                            }
                        }
                    }
                }

                for (int d = 1; d < l + 1; d++) //LEFT
                {
                    if (j-d >= 0 && ores[i][j-d][0] != "L" && ores[i][j-d][1] != "C" && ores[i][j-d][1] != "c" && ores[i][j-d][1] != "I")
                    {
                        ores[i][j-d][1] = "i";
                        ores[i][j-d][0] = "D"; //NEED

                        uu = randy % (l - d + 1);
                        for (int x = 1; x <= uu; x++)
                        {
                            if (i-x >= 0 && ores[i-x][j-d][0] != "L" && ores[i-x][j-d][1] != "C" && ores[i-x][j-d][1] != "c" && ores[i-x][j-d][1] != "I")
                            {
                                ores[i-x][j-d][1] = "i";
                                ores[i-x][j-d][0] = "D";
                            }
                        }

                        dd = randy % (l - d + 1);
                        for (int x = 1; x <= dd; x++)
                        {
                            if (i+x < ores.size() && ores[i+x][j-d][0] != "L" && ores[i+x][j-d][1] != "C" && ores[i+x][j-d][1] != "c" && ores[i+x][j-d][1] != "I")
                            {
                                ores[i+x][j-d][1] = "i";
                                ores[i+x][j-d][0] = "D";
                            }
                        }

                    }
                }

            }

        }
    }
    for (int i = 0; i < ores.size(); i++) //Changes the temp slots into their dedicated tile type
    {
        for (int j = 0; j < ores[i].size(); j++)
        {
            if (ores[i][j][1] == "c")
            {
                //cout << "huh"; //DEBUG
                ores[i][j][1] == "C";
            }
            if (ores[i][j][1] == "i")
            {
                ores[i][j][1] == "I";
            }
        }
    }

    cout << endl << endl; //DEBUG
    return ores;
}

void showBoth(vector < vector < vector<string> > > grid)
{
    for(int i = 0; i < grid.size(); i++) //works
    {
        //cout << "huh"; //debugging, please ignore
        for(int j = 0; j < grid[i].size(); j++) //fixed
        {
            //cout << "wut"; //debugging, ignore
            if (grid[i][j][1] == "_") //if there is not ore, then show the tile
            {
                cout << grid[i][j][0] << " ";
            }
            else //if there is an ore, show the ore
            {
                cout << grid[i][j][1] << " ";
            }
        }
        cout << endl;
    }
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

    string tile [13] = {"G", "G", "G", "G", "G", "G", "G", "G", "G", "D", "D", "D", "L"}; //the five current possibilities for the Tile vector (will be changed in the future
    //string tile [5] = {"G", "G", "D", "D", "D"};
    //cout << sizeof(tile)/sizeof(tile[0]) << endl; //DEBUG
    string ore [12] = {"_", "_", "_", "_", "_", "_", "_", "_", "_", "C", "C", "I"};
    //cout << sizeof(ore) << endl; //DEBUG

    cout << "Insert how high you want your map to be: "; //this let's the user set up the size of the Grid
    cin >> yAxis;
    cout << endl;
    cout << "Insert how wide you want your map to be: ";
    cin >> xAxis;
    cout << endl;
    cout << "Insert the height of the map: ";
    cin >> high;
    cout << endl;

    grid = createGrid(xAxis, yAxis, high); //converts the empty 3D vector into a filled grid of Q's. It should not be Q, so there is an error if there are any Q's

    /* DEBUG */
    /*
    for (size_t i = 0; i < grid.size(); i++)
        for (size_t j = 0; j < grid[i].size(); j++)
            for (size_t k = 0; k < grid[i][j].size(); k++)
                cout << "tube[" << i << "][" << j << "][" << k << "] = " << grid[i][j][k] << endl;
    */

    int tilLen = sizeof(tile)/sizeof(tile[0]);
    int oreLen = sizeof(ore)/sizeof(ore[0]);

    setTiles(tile, grid, tilLen); //set up the Tiles
    cout << endl << endl;
    showTiles(grid); //show the table of Tiles

    setOres(ore, grid, oreLen); //set up the Ores
    cout << endl << endl;
    showOres(grid); //show the table of Ores

    cout << endl << endl << endl;
    showBoth(grid);

    return(0);
}

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

