#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include <windows.h> //delete file
#include <cstdio>

#include "StateManager.h"
#include "allegro5/allegro_image.h"


class FileIO
{
public:
	FileIO();
	~FileIO();

	bool FileExist(std::string path);
	void createFile(std::string path);
	void deleteFile(std::string path);
	bool DirectoryExist(const std::string& dirName);
	void CreateDir(std::string folder);
	std::vector<std::string> readFile(std::string path);

	string openPicture(std::string path);
};

