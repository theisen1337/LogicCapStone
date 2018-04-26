#include "ImageAtlas.h"

void ImageAtlas::Initialize()
{
	fs::path pl;

	//Get the file names of terrain folder
	pl = fs::current_path();
	pl /= "Resources//Terrain";
	tempFileNames = getFileNames(pl);
	genRefVect(terrainRef);
	tempFileNames.clear();

	//get file names of items folder
	pl = fs::current_path();
	pl /= "Resources//Items";
	tempFileNames = getFileNames(pl);
	genRefVect(itemRef);
	tempFileNames.clear();

	//get the file names of the machine folder
	pl = fs::current_path();
	pl /= "Resources//Machine";
	tempFileNames = getFileNames(pl);
	genRefVect(machineRef);
	tempFileNames.clear();

	//get the file names of the character folder
	pl = fs::current_path();
	pl /= "Resources//Character";
	tempFileNames = getFileNames(pl);
	genRefVect(characterRef);
	tempFileNames.clear();

	genImageAtlases();

	//std::cout << pl << '\n';
	/*
	for (int i = 0; i < fileNames.size(); i++)
	{
		std::cout << fileNames[i] << '\n';
	}
	*/
}

std::vector<std::string> ImageAtlas::getFileNames(fs::path path)
{
	const fs::directory_iterator end{};
	std::vector<std::string> fileNames;
	for (fs::directory_iterator iter{ path }; iter != end; ++iter)
	{

		if (fs::is_regular_file(*iter))
		{
			fileNames.push_back(iter->path().filename().string());
		}
	}

	return fileNames;
}

void ImageAtlas::genRefVect(std::vector<std::vector<std::string>>& ref)
{
	//Finds the closest two factors for the number of files
	int tempNum = tempFileNames.size();
	int testNum = (int)sqrt(tempNum);
	while (tempNum % testNum != 0)
	{
		testNum--;
	}
	
	//Resize refrence vector to be size of best layout of atlas
	ref.resize(testNum, std::vector<std::string>(tempNum / testNum, ""));

	//Populates the refrence with file names
	for (int i = 0; i < ref.size(); i++)
	{
		for (int j = 0; j < ref[i].size(); j++)
		{
			ref[i][j] = tempFileNames[i+(j*ref.size())];
		}
	}

}

void ImageAtlas::genImageAtlases()
{

	//Generate the Terrain Atlas
	temp = al_create_bitmap((terrainRef.size() * GC::tileDim),(terrainRef[0].size() * GC::tileDim));
	al_set_target_bitmap(temp);
	for (int i = 0; i < terrainRef.size(); i++)
	{
		for (int j = 0; j < terrainRef[i].size(); j++)
		{
			ALLEGRO_BITMAP* t;
			//std::cout << terrainRef[i][j].c_str() << '\n';
			t = al_load_bitmap(("Resources//Terrain//" + terrainRef[i][j]).c_str());
			al_draw_scaled_bitmap(t,
				0,0,
				GC::tileStartDim,GC::tileStartDim,
				(i*GC::tileDim), (j*GC::tileDim),
				GC::tileDim, GC::tileDim, 0);
		}
	}
	al_save_bitmap("Resources//terrainAtlas.png",temp);

	//Generate the Machine Atlas
	temp = al_create_bitmap((machineRef.size() * GC::tileDim), (machineRef[0].size() * GC::tileDim));
	al_set_target_bitmap(temp);
	for (int i = 0; i < machineRef.size(); i++)
	{
		for (int j = 0; j < machineRef[i].size(); j++)
		{
			ALLEGRO_BITMAP* t;

			t = al_load_bitmap(("Resources//Machine//" + machineRef[i][j]).c_str());
			al_draw_scaled_bitmap(t,
				0, 0,
				GC::tileStartDim, GC::tileStartDim,
				(i*GC::tileDim), (j*GC::tileDim),
				GC::tileDim, GC::tileDim, 0);
		}
	}
	al_save_bitmap("Resources//machineAtlas.png", temp);

	//Generate the Character Atlas
	temp = al_create_bitmap((characterRef.size() * GC::charImgDim), (characterRef[0].size() * GC::charImgDim));
	al_set_target_bitmap(temp);
	for (int i = 0; i < characterRef.size(); i++)
	{
		for (int j = 0; j < characterRef[i].size(); j++)
		{
			ALLEGRO_BITMAP* t;

			t = al_load_bitmap(("Resources//Character//" + characterRef[i][j]).c_str());
			al_draw_scaled_bitmap(t,
				0, 0,
				GC::charImgDim, GC::charImgDim,
				(i*GC::charImgDim), (j*GC::charImgDim),
				GC::charImgDim, GC::charImgDim, 0);
		}
	}
	al_save_bitmap("Resources//characterAtlas.png", temp);

	//Generate the Item Atlas
	temp = al_create_bitmap((itemRef.size() * GC::itemImgDim), (itemRef[0].size() * GC::itemImgDim));
	al_set_target_bitmap(temp);
	for (int i = 0; i < itemRef.size(); i++)
	{
		for (int j = 0; j < itemRef[i].size(); j++)
		{
			ALLEGRO_BITMAP* t;

			t = al_load_bitmap(("Resources//Items//" + itemRef[i][j]).c_str());
			al_draw_scaled_bitmap(t,
				0, 0,
				GC::itemImgDim, GC::itemImgDim,
				(i*GC::itemImgDim), (j*GC::itemImgDim),
				GC::itemImgDim, GC::itemImgDim, 0);
		}
	}
	al_save_bitmap("Resources//itemAtlas.png", temp);
}

ALLEGRO_BITMAP* ImageAtlas::LoadImageAtlas(AtlasType type)
{
	switch (type)
	{
	case ImageAtlas::Terrain:
		temp = al_load_bitmap("Resources//terrainAtlas.png");
		return temp;
		break;
	case ImageAtlas::Machine:
		temp = al_load_bitmap("Resources//machineAtlas.png");
		return temp;
		break;
	case ImageAtlas::Item:
		temp = al_load_bitmap("Resources//itemAtlas.png");
		return temp;
		break;
	case ImageAtlas::Character:
		temp = al_load_bitmap("Resources//characterAtlas.png");
		return temp;
		break;
	default:
		return temp;
		break;
	}
}
