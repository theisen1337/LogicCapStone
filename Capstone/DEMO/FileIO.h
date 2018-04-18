#pragma once

#include <string>
#include <vector>

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
};

