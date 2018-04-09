#pragma once
#include <vector>
#include <string>


class OreTemplate
{
public:
	OreTemplate();
	int getNumberOfDifferentOres();
	std::string getNameOfOre(int i);

private:
	void addNewOreType(std::string name);
	int numberOfDifferentOres = 0;
	std::vector<std::string> namesOfOres;

};
