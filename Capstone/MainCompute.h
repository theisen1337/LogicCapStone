#pragma once

#include "MachineLayer.h"
#include "TransportLayer.h"

class MainCompute
{
public:
	void Compute(MachineLayer &ML, TransportLayer &TL);
	void ComputeTPS();

	int getCPS() { return CPS; };

private:
	int CPS = 0, CPSaccum =0;
	double waitticks = 0;

};

