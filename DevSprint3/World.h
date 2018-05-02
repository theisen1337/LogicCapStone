//! Manages the World and the vector of chunks


#pragma once
#include <vector>
#include "Chunk.h"
#include "GlobalConstants.h"
#include "ObjectManager.h"

class World
{
private:

public:
	//! 2D vector of the chunks in the world
	std::vector<std::vector<Chunk>> world; 
	std::vector < std::vector<std::reference_wrapper<Tile>>> mastTiles;
	std::vector < std::vector<std::reference_wrapper <Tile>>> mastOres;

	//! World Constructor
	World();

	//! World Initalization.
	/*!
		Used to initalize the world after the objects creation.
	*/
	void InitalizeClass(ObjectManager &obj);

	//! Chunk Initial Generation.
	/*!
		Used to generate the chunks.
	*/
	void initialGeneration(ObjectManager &obj);


	//! Update World Method
	/*!
		Used to update the map when the player able to see chunks that are not generated.
		Used for Infinite Map.
	*/
	void updateWorld(int charWorldW, int charWorldH);
		
	//! World 2D vector Getter.
	std::vector<std::vector<Chunk>> & getChunk() { return world; };

	//! Draw the world to back buffer
	void drawWorld(ALLEGRO_BITMAP* atl, ALLEGRO_DISPLAY &dis, std::vector<std::vector<std::string>> &ref);

	//! placeholder for biome stat
	vector < vector <int> > biome; //added by brandon

	//! changes biomestat
	vector < vector <int> > bioChange1(vector < vector <int> > &biome); //added by brandon

	//! changes the edges of the chunks
	void borderControl(std::vector<std::vector<Chunk>> &world); //added by brandon, used later for border manipulation


	void popOreLayer(ObjectManager &objm);

	
};

