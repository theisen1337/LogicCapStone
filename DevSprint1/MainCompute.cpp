#include "MainCompute.h"

#include "MachineLayer.h"
#include "TransportLayer.h"



void MainCompute::Compute(MachineLayer &ML, TransportLayer &TL)
{
	
	ML.Compute();
	TL.Compute();
	ComputeTPS();
}

void MainCompute::ComputeTPS()
{
	double t = al_get_time();
	CPSaccum++;
	if (t - waitticks >= 1) {
		CPS = CPSaccum;
		CPSaccum = 0;
		waitticks = t;
	}
}