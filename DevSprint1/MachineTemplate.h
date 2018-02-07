#pragma once
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

#include <vector>
#include <string>

class MachineTemplate
{
public:
	MachineTemplate();
	~MachineTemplate();

	void setCraftRecipe(std::vector<std::string, int> recipe);
	std::vector<std::string,int> getCraftRecipe();

	void setTotalWork(float totalWork);
	void setWorkPerSecond(float WorkPerSecond);

	bool isWorking();

	void Compute();

private:
	// MAS = MachineAnimateSheet
	ALLEGRO_BITMAP * MAS_OFF_Image;
	ALLEGRO_BITMAP * MAS_ON_Image;
	ALLEGRO_BITMAP * MAS_IDLE_Image;
	
	// AS = AnimateSheet
	int AS_X, AS_Y;
	int AS_Hieght, AS_Width;
	int AS_rows, AS_Columns;

	//Machine location Varriables
	float PlacementX, placementY;
	int TileX, TileY;

	//Machine Work
	float totalWork, WorkPerSecond;
	float time; // may be depericated
	bool Busy;
	
	//setup vectors for item, such that vector<item> = {{f},{},{}
	//string = item object temp value
	std::vector<std::string, int> CraftRecipe;
	std::vector<std::string, int> InputBuffer;

};

