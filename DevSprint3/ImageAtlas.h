#pragma once

// Allegro Includes
#include <allegro5/allegro.h>

// Standard Includes
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

// Custom Includes
#include "GlobalConstants.h"

namespace fs = std::experimental::filesystem;

class ImageAtlas
{
private:
	//! Vector to hold file names
	std::vector<std::string> tempFileNames;

	//! 2D vector to be used to reference images to atlas
	std::vector<std::vector<std::string>> terrainRef;

	//! 2D vector to be used to reference images to atlas
	std::vector<std::vector<std::string>> machineRef;

	//! 2D vector to be used to reference images to atlas
	std::vector<std::vector<std::string>> itemRef;

	//! 2D vector to be used to reference images to atlas
	std::vector<std::vector<std::string>> characterRef;

	//! Temp Bitmap to hold the atlases before being saved
	ALLEGRO_BITMAP* temp;
	
public:
	//! Types of Atlases 
	enum AtlasType
	{
		Terrain,
		Machine,
		Item,
		Character
	};

	//! Initialize the Image Atlas Class
	void Initialize();

	//! Get all the file names from a directory
	std::vector<std::string> getFileNames(fs::path path);

	//! Generates the Reference 2D vectors
	void genRefVect(std::vector<std::vector<std::string>> &ref);

	//! Creates all the Image Atlases
	void genImageAtlases();

	//! Return image atlas dependant on Type.
	ALLEGRO_BITMAP* LoadImageAtlas(AtlasType type);

	//! Get Terrain Refrences
	std::vector<std::vector<std::string>> getTerrainRef() { return terrainRef; };
	
	//! Get Machine Refrences
	std::vector<std::vector<std::string>> getMachineRef() { return machineRef; };
	
	//! Get Item Refrences
	std::vector<std::vector<std::string>> getItemRef() { return itemRef; };

	//! Get Character Refrences
	std::vector<std::vector<std::string>> getCharacterRef() { return characterRef; };

};
