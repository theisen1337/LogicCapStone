#pragma once
#include "MachineTemplate.h"
#include "transportTemplate.h"
#include <vector>

class MachineLayer
{
public:

	std::vector<MachineBase> arrMachines;
	void Init(FastTrack & fast, SlowTrack & slow);
	void Compute();
	void Draw();
	MachineLayer();
	~MachineLayer();
};

