#include "typesOfOres.h"

typesOfOres::typesOfOres()
{
	addNewOreType("coal");
	addNewOreType("iron");
}

int typesOfOres::getNumberOfDifferentOres()
{
	return numberOfDifferentOres;
}

std::string typesOfOres::getNameOfOre(int i)
{
	return namesOfOres.at(i);
}

void typesOfOres::addNewOreType(std::string name)
{
	namesOfOres.push_back(name);
	numberOfDifferentOres++;
}
