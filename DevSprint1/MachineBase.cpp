#include "MachineBase.h"
#include "FileIO.h"




MachineBase::MachineBase()
{
	Busy = false;
}




MachineBase::~MachineBase()
{
}

//Recipe information

void MachineBase::setCraftRecipe(std::vector<Stack> recipe)
{
	CraftRecipe = recipe;
	for(int i = 0; i < recipe.size();i++)
		recipe[i].n *= 3;

	InputBuffer = recipe;
}

void MachineBase::setCraftRecipe(std::vector<Stack> recipe,int multiplier)
{
	CraftRecipe = recipe;
	if (!recipe.empty())
	{
		for (int i = 0; i < recipe.size(); i++)
			InputBuffer[i].max = recipe[i].n * multiplier;
	}

	InputBuffer = recipe;
}

void MachineBase::setCraftRecipe(std::vector<Stack> recipe, int *multiplier)
{
	CraftRecipe = recipe;
	for (int i = 0; i < recipe.size(); i++)
		recipe[i].n = multiplier[i];

	InputBuffer = recipe;
}

std::vector<Stack> MachineBase::getCraftRecipe()
{
	return CraftRecipe;
}

//Work for the machine

void MachineBase::setTotalWork(float totalWork)
{
	MachineBase::totalWork = totalWork;
}

float MachineBase::getTotalWork()
{
	return totalWork;
}

void MachineBase::setWorkPerSecond(float WorkPerSecond)
{
	MachineBase::WorkPerSecond = WorkPerSecond;
}

float MachineBase::getWorkPerSecond()
{
	return WorkPerSecond;
}

//

bool MachineBase::isWorking()
{
	return Busy;
}

void MachineBase::doWork()
{
	int AmountofTicksPerSecond = 50; // set to the number of tickets
	totalWork -= (WorkPerSecond / (1.0f*AmountofTicksPerSecond));
}

//Main Meat and potatos

void MachineBase::Compute()
{
	if (Busy)
	{
		doWork();
	}
	else
	{
		for (int n = 0; n < InputBuffer.size; n++)
			if (InputBuffer[n].n < CraftRecipe[n].n)
				return; //end method if there is not enough ingredents for recipe.

		for (int n = 0; n < InputBuffer.size; n++) //Remove the Items in the Input, and use them for the recipe.
			InputBuffer[n].n -= CraftRecipe[n].n;


		Busy = true;
		doWork(); //do one iteration of work for this tick.
	}
}

void MachineBase::Draw()
{
	
}

//Placement methods

void MachineBase::setPLacement(float x, float y)
{
	PlacementX = x;
	placementY = y;
}

float MachineBase::getPlacementX()
{
	return PlacementX;
}

float MachineBase::getPlacementY()
{
	return placementY;
}

void MachineBase::setTile(int x, int y)
{
	TileX = x;
	TileY = y;
}

int MachineBase::getTileX()
{
	return TileX;
}

int MachineBase::getTileY()
{
	return TileY;
}

void MachineBase::setAnimateSheet_OFF(std::string path)
{
	FileIO file;
	MAS_OFF_Image = file.openPicture(path);
	//MAS_OFF_Image =  &pic; //better idlea pass in string and do file load here.
}

void MachineBase::setAnimateSheet_ON(std::string path)
{
	FileIO file;
	MAS_ON_Image = file.openPicture(path);
}

void MachineBase::setAnimateSheet_IDLE(std::string path)
{
	FileIO file;
	MAS_IDLE_Image = file.openPicture(path);
	//MAS_IDLE_Image = &pic;
}


