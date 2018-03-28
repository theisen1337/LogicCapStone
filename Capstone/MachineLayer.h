#pragma once


#include "MachineTemplate.h"
#include "transportTemplate.h"
#include "ItemTemplate.h"
#include <vector>

class MachineLayer
{
public:

	std::vector<MachineBase> arrMachines;
	void Init(FastTrack & fast, SlowTrack & slow);
	void Compute();
	void Draw(ALLEGRO_BITMAP * machAtl, std::vector<std::vector<std::string>> &machRef);
	MachineLayer();
	~MachineLayer();
private:
};

