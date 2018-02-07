#include "MachineTemplate.h"



MachineTemplate::MachineTemplate()
{
}


MachineTemplate::~MachineTemplate()
{
}

void MachineTemplate::setCraftRecipe(std::vector<std::string, int> recipe)
{
	CraftRecipe = recipe;
}

std::vector<std::string, int> MachineTemplate::getCraftRecipe()
{
	return std::vector<std::string, int>();
}

void MachineTemplate::setTotalWork(float totalWork)
{
}

void MachineTemplate::setWorkPerSecond(float WorkPerSecond)
{
}

bool MachineTemplate::isWorking()
{
	return false;
}


