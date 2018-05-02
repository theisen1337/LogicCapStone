#pragma once

// Allegro Includes
#include "allegro5/allegro_image.h"

// Standard Includes
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <windows.h> //delete file
#include <cstdio>

// Custom Includes
#include "StateManager.h"

class FileIO
{
public:
	//! Constructor
	FileIO();
	//! Deconstructor
	~FileIO();

	//! Checks for File Existance
	bool FileExist(std::string path);
	//! Creates Files
	void createFile(std::string path);
	//! Deletes Files
	void deleteFile(std::string path);
	//! Checks for Directory Existance
	bool DirectoryExist(const std::string& dirName);
	//! Creates Directories
	void CreateDir(std::string folder);
	//! Reads from Files
	std::vector<std::string> readFile(std::string path);
	//! Opens up Images
	string openPicture(std::string path);
};
