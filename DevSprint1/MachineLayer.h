#pragma once


#include "MachineTemplate.h"
#include <vector>

class MachineLayer
{
public:

	std::vector<MachineBase> arrMachines;
	void Compute();
	void Draw();
	MachineLayer();
	~MachineLayer();
};

