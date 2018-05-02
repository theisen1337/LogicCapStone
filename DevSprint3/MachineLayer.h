#pragma once

// Standard Includes
#include <vector>

// Custom Includes
#include "MachineTemplate.h"
#include "transportTemplate.h"
#include "ItemTemplate.h"

class MachineLayer
{
public:
	//! Constructor
	MachineLayer();
	//! Deconstructor
	~MachineLayer();

	//! Create ARray of Machines
	std::vector<MachineBase> arrMachines;
	//! Initialize Machine Layer
	void Init(FastTrack & fast, SlowTrack & slow);
	//! Perform Layer Computations
	void Compute();
	//! DRaw the Layer
	void Draw();

};

