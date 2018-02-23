#pragma once


#include "MachineTemplate.h"
#include <vector>

class MachineLayer
{
public:

	std::vector<MachineBase> Layer;
	void Compute();
	void Draw();
	MachineLayer();
	~MachineLayer();
};

