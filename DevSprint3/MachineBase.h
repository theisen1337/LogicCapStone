#pragma once

// Allegro Includes
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"

//Imgui for Messagebox
//#include "imgui.h"

// Standard Includes
#include <vector>
#include <string>

// Custom Includes
#include "ItemBase.h"

struct Stack 
{
	ItemBase i;
	int n;
	int max;
};

class MachineBase
{
public:
	//! Constructor
	MachineBase();
	//! Deconstructor
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

	void setPlacement(float x, float y);
	
	float getPlacementX();
	float getPlacementY();

	float getHeight();
	float getWidth();

	void setTile(int x, int y);
	int getTileX();
	int getTileY();
	
	void setInBuffer(std::vector<Stack> input);

	void setOutBuffer(Stack output, int multiplier = 1);
	
	void leftClick();
	void rightClick();

	std::vector<Stack> CraftRecipe;
	std::vector<Stack> InputBuffer;
	Stack OutBuffer;

	void setName(std::string n) { name = n; };
	std::string getName() { return name; };

private:
	//! Performs Work
	void doWork();

	// MAS = MachineAnimateSheet
	ALLEGRO_BITMAP * MAS_OFF_Image;
	ALLEGRO_BITMAP * MAS_ON_Image;
	ALLEGRO_BITMAP * MAS_IDLE_Image;

	//Height, and Width
	float Width = 64;
	float Height = 64;

	//Name
	std::string name;

	// AS = AnimateSheet
	int AS_X, AS_Y;				//TODO
	int AS_Hieght, AS_Width;	//TODO
	int AS_rows, AS_Columns;	//TODO

	//Machine location Varriables
	float placementX, placementY;
	int TileX, TileY;

	//Machine Work
	float totalWork, WorkPerSecond, jobWork;
	float time; // may be depericated
	bool Busy;
	
	//outbuffer variables
	int OutBufferMultiplier = 1;
	
protected:
	//! Changes Animations
	void setAnimateSheet_OFF(std::string path);
	void setAnimateSheet_ON(std::string path);
	void setAnimateSheet_IDLE(std::string path);

};

