#include "MachineBase.h"



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
	for(int i; i < recipe.size();i++)
		recipe[i].n *= 3;

	InputBuffer = recipe;
}

void MachineBase::setCraftRecipe(std::vector<Stack> recipe,int multiplier)
{
	CraftRecipe = recipe;
	for (int i; i < recipe.size(); i++)
		recipe[i].n *= multiplier;

	InputBuffer = recipe;
}

void MachineBase::setCraftRecipe(std::vector<Stack> recipe, int *multiplier)
{
	CraftRecipe = recipe;
	for (int i; i < recipe.size(); i++)
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

//Main Meat and potatos

void MachineBase::Compute()
{
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


