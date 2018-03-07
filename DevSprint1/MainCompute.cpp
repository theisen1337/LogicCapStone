#include "MainCompute.h"


void MainCompute::Compute(ObjectManager OM)
{
	OM.Compute();
	ComputeTPS();
}

void MainCompute::ComputeTPS()
{
	double t = al_get_time();
	CPSaccum++;
	if (t - waitticks >= 1) {
		GS.getCPS() = CPSaccum;
		CPSaccum = 0;
		waitticks = t;
	}
}