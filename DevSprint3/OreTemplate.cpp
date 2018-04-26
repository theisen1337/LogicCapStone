#include "OreTemplate.h"

OreTemplate::OreTemplate()
{
	addNewOreType("coal");
}

int OreTemplate::getNumberOfDifferentOres()
{
	return numberOfDifferentOres;
}

std::string OreTemplate::getNameOfOre(int i)
{
	return namesOfOres.at(i);
}

void OreTemplate::addNewOreType(std::string name)
{
	namesOfOres.push_back(name);
	numberOfDifferentOres++;
}
