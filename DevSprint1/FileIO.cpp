#include "FileIO.h"

/*
	A class wrapper for file input/output to be used through-out program.
	This class will be replaced via cross-platform library like Boost.
	or
	https://stackoverflow.com/questions/12774207/fastest-way-to-check-if-a-file-exist-using-standard-c-c11-c

*/




FileIO::FileIO()
{
}

FileIO::~FileIO()
{
}

bool FileIO::FileExist(std::string path)
{
	std::fstream file;
	file.open(path.c_str()); // Try to open for I/O
	if (!file)
	{
		file.clear();
		return false;
	}
	file.close();
	return true;
}
void FileIO::createFile(std::string path)
{
	std::fstream file;
	file.open(path.c_str()); // Try to open for I/O
	if (!file) {
		file.clear();
		file.open(path.c_str(), std::ios::out); // Create using out
	}
	file.close();
}
void FileIO::deleteFile(std::string path)
{
	std::fstream file;
	file.open(path.c_str()); // Try to open for I/O
	if (!file)
	{
		file.clear();
		return;
	}
	file.close();
	remove(path.c_str());
}

bool FileIO::DirectoryExist(const std::string& dirName)
{
	DWORD ftyp = GetFileAttributesA(dirName.c_str());
	if (ftyp == INVALID_FILE_ATTRIBUTES)
		return false;  //something is wrong with your path!

	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
		return true;   // this is a directory!

	return false;    // this is not a directory!
}

void FileIO::CreateDir(std::string folder)
{
	if (CreateDirectory(folder.c_str(), NULL) ||
		ERROR_ALREADY_EXISTS == GetLastError())
	{
		// CopyFile(...)
	}
	else
	{
		// Failed to create directory.
	}
}

std::vector<std::string> FileIO::readFile(std::string path)
{
	std::vector<std::string> filedata;
	std::ifstream inData;
	inData.open(path.c_str());
	while (true) {
		std::string line;
		inData >> line;
		if (inData.eof()) break;
		filedata.push_back(line);
	}
	
	inData.close();
	return filedata;
}

std::string FileIO::openPicture(std::string path)
{
	std::fstream file;
	file.open(path.c_str()); // Try to open for I/O
	if (!file)
	{
		file.clear();
		path = "Terrain//Dev//test.png";
		
		file.open(path.c_str()); // Try to open for I/O
		if (!file)
		{
			file.clear();
			return nullptr;
		}
		file.close();
		return "Terrain//Dev//test.png";
	}
	file.close();
	return path;
}
