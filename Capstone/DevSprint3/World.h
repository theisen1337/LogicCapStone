//! Manages the World and the vector of chunks


#pragma once
#include <vector>
#include "Chunk.h"
#include "GlobalConstants.h"

class World
{
private:

public:
	//! 2D vector of the chunks in the world
	std::vector<std::vector<Chunk>> world; 

	//! World Constructor
	World();

	//! World Initalization.
	/*!
		Used to initalize the world after the objects creation.
	*/
	void InitalizeClass();

	//! Chunk Initial Generation.
	/*!
		Used to generate the chunks.
	*/
	void initialGeneration();


	//! Update World Method
	/*!
		Used to update the map when the player able to see chunks that are not generated.
		Used for Infinite Map.
	*/
	void updateWorld(int charWorldW, int charWorldH);
		
	//! World 2D vector Getter.
	std::vector<std::vector<Chunk>>& getChunk() { return world; };

	//! Draw the world to back buffer
	void drawWorld(ALLEGRO_BITMAP* atl, ALLEGRO_DISPLAY &dis, std::vector<std::vector<std::string>> &ref);
};

