#pragma once

#include "MachineLayer.h"
class MainCompute
{
public:
	void Compute(MachineLayer &ML);
	void ComputeTPS();

	int getCPS() { return CPS; };

private:
	int CPS = 0, CPSaccum =0;
	double waitticks = 0;

};

