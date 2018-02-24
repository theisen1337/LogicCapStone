#pragma once
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

#include "Items.h"

#include <vector>
#include <string>


struct Stack 
{
	Items i;
	int n;
	int max;
};

class MachineBase
{
public:
	MachineBase();
	~MachineBase();

	void setCraftRecipe(std::vector<Stack> recipe);
	void setCraftRecipe(std::vector<Stack> recipe, int multiplier);
	void setCraftRecipe(std::vector<Stack> recipe, int *multiplier);

	std::vector<Stack> getCraftRecipe();

	void setTotalWork(float totalWork);
	float getTotalWork();

	void setWorkPerSecond(float WorkPerSecond);
	float getWorkPerSecond();

	bool isWorking();

	void Compute();
	void Draw();

	void setPLacement(float x, float y);
	
	float getPlacementX();
	float getPlacementY();

	void setTile(int x, int y);
	int getTileX();
	int getTileY();

	void setAnimateSheet_OFF(std::string path);
	void setAnimateSheet_ON(std::string path);
	void setAnimateSheet_IDLE(std::string path);

private:

	void doWork();


	// MAS = MachineAnimateSheet
	ALLEGRO_BITMAP * MAS_OFF_Image;
	ALLEGRO_BITMAP * MAS_ON_Image;
	ALLEGRO_BITMAP * MAS_IDLE_Image;



	// AS = AnimateSheet
	int AS_X, AS_Y;				//TODO
	int AS_Hieght, AS_Width;	//TODO
	int AS_rows, AS_Columns;	//TODO

	//Machine location Varriables
	float PlacementX, placementY;
	int TileX, TileY;

	//Machine Work
	float totalWork, WorkPerSecond;
	float time; // may be depericated
	bool Busy;
	
	//setup vectors for Items, such that vector<Items> = {{f},{},{}
	//string = Items object temp value
	std::vector<Stack> CraftRecipe;
	std::vector<Stack> InputBuffer;

	std::vector<Stack> OutBuffer;

};

